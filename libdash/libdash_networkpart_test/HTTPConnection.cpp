/*
 * HTTPConnection.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "HTTPConnection.h"

using namespace libdashtest;
using namespace dash::network;
using namespace dash::metrics;

HTTPConnection::HTTPConnection  () :
                peekBufferLen   (0),
                contentLength   (0),
                isInit          (false),
                isScheduled     (false)
{
    this->peekBuffer = new uint8_t[PEEKBUFFER];
}
HTTPConnection::~HTTPConnection ()
{
    delete[] this->peekBuffer;
    this->CloseSocket();
}

int             HTTPConnection::Read            (uint8_t *data, size_t len, IChunk *chunk)
{
    if(this->peekBufferLen == 0)
    {
        int size = recv(this->httpSocket, (char *)data, len, 0);

        if(size <= 0)
            return 0;

        return size;
    }

    memcpy(data, this->peekBuffer, this->peekBufferLen);
    int ret = this->peekBufferLen;
    this->peekBufferLen = 0;
    return ret;
}
int             HTTPConnection::Peek            (uint8_t *data, size_t len, IChunk *chunk)
{
    if(this->peekBufferLen == 0)
        this->peekBufferLen = this->Read(this->peekBuffer, PEEKBUFFER, chunk);

    int size = len > this->peekBufferLen ? this->peekBufferLen : len;

    memcpy(data, this->peekBuffer, size);
    return size;
}
std::string     HTTPConnection::PrepareRequest  (IChunk *chunk)
{
    std::string request;
    if(!chunk->HasByteRange())
    {
        request = "GET "      + chunk->Path()   + " HTTP/1.1" + "\r\n" +
                  "Host: "    + chunk->Host()   + "\r\n" +
                  "Connection: close\r\n\r\n";
    }
    else
    {
        std::stringstream req;
        req << "GET " << chunk->Path() << " HTTP/1.1\r\n" <<
               "Host: " << chunk->Host() << "\r\n" <<
               "Range: bytes=" << chunk->StartByte() << "-" << chunk->EndByte() << "\r\n" <<
               "Connection: close\r\n\r\n";

        request = req.str();
    }

    return request;
}
bool            HTTPConnection::Init            (IChunk *chunk)
{
    if(this->isInit)
        return false;

    if(!this->ConnectToHost(chunk->Host(), chunk->Port()))
        return false;

    this->isInit = true;

    return this->isInit;
}
bool            HTTPConnection::ParseHeader     ()
{
    std::string line = this->ReadLine();
    
    if(line.size() == 0)
        return false;

    while(line.compare("\r\n"))
    {
        if(!line.compare(0, 14, "Content-Length"))
            this->contentLength = atoi(line.substr(15,line.size()).c_str());

        line = this->ReadLine();

        if(line.size() == 0)
            return false;
    }

    return true;
}
std::string     HTTPConnection::ReadLine        ()
{
    std::stringstream ss;
    char c[1];
    int size = recv(this->httpSocket, c, 1, 0);

    while(size > 0)
    {
        ss << c[0];
        if(c[0] == '\n')
            break;

        size = recv(this->httpSocket, c, 1, 0);
    }

    if(size > 0)
        return ss.str();

    return "";
}
bool            HTTPConnection::SendData        (std::string data)
{
    int size = send(this->httpSocket, data.c_str(), data.size(), 0);
    
    if(size == -1)
        return false;
    if (size != data.length())
        this->SendData(data.substr(size, data.size()));

    return true;
}
void            HTTPConnection::CloseSocket     ()
{
    closesocket(this->httpSocket);
    WSACleanup();
}
bool            HTTPConnection::ConnectToHost   (std::string host, int port)
{
    WSADATA info;

    if(WSAStartup(MAKEWORD(2,0), &info))
      return false;

    this->httpSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    memset(&this->addr, 0, sizeof(this->addr));

    this->hostent           = gethostbyname(host.c_str());
    this->addr.sin_family   = AF_INET;
    this->addr.sin_port     = htons(port);
    int result              = 0;
    char **p                = this->hostent->h_addr_list;
    do
    {
        if(*p == NULL)
            return false;

        addr.sin_addr.s_addr    = *reinterpret_cast<unsigned long*>(*p);
        result                  = connect(this->httpSocket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));

    }while(result == 1);

    return true;
}
bool            HTTPConnection::Schedule        (IChunk *chunk)
{
    if(!this->isInit)
        return false;
    if(this->isScheduled)
        return false;

    if(this->SendData(this->PrepareRequest(chunk)))
    {
        this->isScheduled = this->ParseHeader();
        return this->isScheduled;
    }

    return false;
}

const std::vector<ITCPConnection *>&        HTTPConnection::GetTCPConnectionList    () const
{
    return tcpConnections;
}
const std::vector<IHTTPTransaction *>&      HTTPConnection::GetHTTPTransactionList  () const
{
    return httpTransactions;
}
