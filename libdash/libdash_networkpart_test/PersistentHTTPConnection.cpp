/*
 * PersistentHTTPConnection.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "PersistentHTTPConnection.h"

using namespace libdashtest;
using namespace dash::network;

PersistentHTTPConnection::PersistentHTTPConnection  () :
                          HTTPConnection            ()
{
    InitializeConditionVariable (&this->chunkFinished);
    InitializeCriticalSection   (&this->monitorMutex);
}
PersistentHTTPConnection::~PersistentHTTPConnection ()
{
    DeleteConditionVariable(&this->chunkFinished);
    DeleteCriticalSection(&this->monitorMutex);
}

int                 PersistentHTTPConnection::Peek              (uint8_t *data, size_t len, IChunk *chunk)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->chunkQueue.front()->Chunk() != chunk && this->chunkQueue.size() > 0)
        SleepConditionVariableCS(&this->chunkFinished, &this->monitorMutex, INFINITE);

    HTTPChunk *front = this->chunkQueue.front();

    if(this->chunkQueue.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return -1;
    }
    if(front->BytesLeft() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return 0;
    }
    if(front->HeaderParsed() == false)
    {
        this->ParseHeader();
        front->HeaderParsed(true);
        front->ContentLength(this->contentLength);
    }

    if(len > front->BytesLeft())
        len = (size_t) front->BytesLeft();

    size_t ret = HTTPConnection::Peek(data, len, chunk);

    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
int                 PersistentHTTPConnection::Read              (uint8_t *data, size_t len, IChunk *chunk)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->chunkQueue.front()->Chunk() != chunk && this->chunkQueue.size() > 0)
        SleepConditionVariableCS(&this->chunkFinished, &this->monitorMutex, INFINITE);

    HTTPChunk *front = this->chunkQueue.front();

    if(this->chunkQueue.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return -1;
    }
    if(front->HeaderParsed() == false)
    {
        this->ParseHeader();
        front->HeaderParsed(true);
        front->ContentLength(this->contentLength);
    }
    if(front->BytesLeft() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        delete(front);
        this->chunkQueue.pop();
        WakeAllConditionVariable(&this->chunkFinished);
        return 0;
    }

    if(len > front->BytesLeft())
        len = (size_t) front->BytesLeft();

    size_t ret = HTTPConnection::Read(data, len, chunk);

    if(ret > 0)
        front->AddBytesRead(ret);

    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
std::string         PersistentHTTPConnection::PrepareRequest    (IChunk *chunk)
{
    std::string request;
    if(!chunk->HasByteRange())
    {
        request = "GET "    + chunk->Path() + " HTTP/1.1" + "\r\n" +
                  "Host: "  + chunk->Host() + "\r\n\r\n";
    }
    else
    {
        std::stringstream req;
        req << "GET " << chunk->Path() << " HTTP/1.1\r\n" <<
               "Host: " << chunk->Host() << "\r\n" <<
               "Range: bytes=" << chunk->StartByte() << "-" << chunk->EndByte() << "\r\n\r\n";

        request = req.str();
    }
    return request;
}
bool                PersistentHTTPConnection::Init              (IChunk *chunk)
{
    if(this->isInit && chunk->Host() != this->hostname)
        return false;

    if(this->isInit && chunk->Host() == this->hostname)
        return true;

    if(!this->ConnectToHost(chunk->Host(), chunk->Port()))
        return false;

    this->hostname = chunk->Host();
    this->isInit   = true;

    return this->isInit;
}
bool                PersistentHTTPConnection::Schedule          (IChunk *chunk)
{
    if(chunk->Host() != this->hostname)
        return false;

    if(!this->isInit)
        return false;

    if(this->SendData(this->PrepareRequest(chunk)))
    {
        this->chunkQueue.push(new HTTPChunk(chunk));
        return true;
    }

    return false;
}
bool                PersistentHTTPConnection::InitChunk         (IChunk *chunk)
{
    if(this->ParseHeader())
        return true;

    if(!this->Reconnect(chunk))
        return false;

    if(this->ParseHeader())
        return true;

    return false;
}
bool                PersistentHTTPConnection::Reconnect         (IChunk *chunk)
{
    int         retry   = 0;
    std::string request = this->PrepareRequest(chunk);

    while(retry < RETRY)
    {
        if(this->ConnectToHost(chunk->Host(), chunk->Port()))
            if(this->SendData(request))
                return true;

        retry++;
    }

    return false;
}
