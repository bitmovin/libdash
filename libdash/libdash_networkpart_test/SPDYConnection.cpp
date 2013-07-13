/*
 * SPDYConnection.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Created on: 7/4/2013
 * Author: Christopher Mueller <christopher.mueller@bitmovin.net>
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SPDYConnection.h"

using namespace libdashtest;
using namespace dash::metrics;
using namespace dash::helpers;

SPDYConnection::SPDYConnection  () :
    dlThread        (NULL),
    httpSocket      (-1),
    hostent         (NULL),
    session         (NULL),
    callbacks       (NULL),
    isInit          (false),
    contentLength   (0),
    bytesRead       (0)
{

}
SPDYConnection::~SPDYConnection ()
{

}

bool                                        SPDYConnection::ConnectToHost           (std::string host, int port)
{
    WSADATA info;

    if (WSAStartup(MAKEWORD(2,0), &info))
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

    } while (result == 1);

    return true;
}
bool                                        SPDYConnection::Init                    (dash::network::IChunk *chunk)
{
    if (this->isInit)
        return true;

    if (chunk == NULL)
        return false;

    if (!this->ConnectToHost(chunk->Host(), chunk->Port()))
        return false;

    this->callbacks = (spdylay_session_callbacks *) malloc(sizeof(spdylay_session_callbacks));
    memset(callbacks, 0, sizeof(spdylay_session_callbacks));

    callbacks->send_callback                 = &this->SpdyNetSend;
    callbacks->recv_callback                 = &this->SpdyNetRead;
    callbacks->on_data_chunk_recv_callback   = &this->SpdyChunkAvailable;
    callbacks->on_ctrl_recv_callback         = &this->SpdyCtrlFrame;

    if (spdylay_session_client_new(&this->session, SPDYLAY_PROTO_SPDY2, this->callbacks, this))
        return false;

    this->chunkQueue.push(new SPDYChunk(chunk));

    this->dlThread = CreateThreadPortable(StartSPDYDownload, this);

    if (!this->dlThread)
        return false;

    if (!this->SubmitRequest(chunk->Path(), chunk->Host()))
        return false;

    this->isInit    = true;
    this->hostname  = chunk->Host();

    return this->isInit;
}
bool                                        SPDYConnection::SubmitRequest           (std::string path, std::string host)
{
    const char *nv[15];

    nv[0] = ":method";          nv[1] = "GET";
    nv[2] = ":path";            nv[3] = path.c_str();
    nv[4] = ":version";         nv[5] = "HTTP/1.1";
    nv[6] = ":scheme";          nv[7] = "http";
    nv[8] = ":host";            nv[9] = host.c_str();
    nv[10] = "Accept-Encoding"; nv[11] = "";
    nv[12] = "user-agent";      nv[13] = "spdylay/"SPDYLAY_VERSION;
    nv[14] = NULL;

    if (spdylay_submit_request(this->session, 0, nv, NULL, this) < 0)
        return false;

    if (spdylay_session_send(this->session))
        return false;

    return true;
}
void*                                       SPDYConnection::StartSPDYDownload       (void *spdy_con)
{
    spdylay_session *session = ((SPDYConnection *) spdy_con)->session;

    while (!spdylay_session_recv(session));

    return NULL;
}
bool                                        SPDYConnection::Schedule                (dash::network::IChunk *chunk)
{
    if(chunk->Host() != this->hostname)
        return false;

    if(!this->isInit)
        return false;

    this->chunkQueue.push(new SPDYChunk(chunk));

    if (!this->SubmitRequest(chunk->Path(), chunk->Host()))
    {
        this->chunkQueue.pop();
        return false;
    }

    return true;
}
int                                         SPDYConnection::Read                    (uint8_t *data, size_t len, dash::network::IChunk *chunk)
{
    if (!this->chunkQueue.front())
        return 0;

    if (this->chunkQueue.front()->bytesRead == this->chunkQueue.front()->contentLength && this->chunkQueue.front()->contentLength)
    {
        this->chunkQueue.pop();
        return 0;
    }

    int bytesRead = this->chunkQueue.front()->blockStream.GetBytes(data, len);
    this->chunkQueue.front()->bytesRead += bytesRead;
    return bytesRead;
}
int                                         SPDYConnection::Peek                    (uint8_t *data, size_t len, dash::network::IChunk *chunk)
{
    return this->blockStream.PeekBytes(data, len);
}
void                                        SPDYConnection::Close                   ()
{
    closesocket(this->httpSocket);
    WSACleanup();
}
const std::vector<ITCPConnection *>&        SPDYConnection::GetTCPConnectionList    () const
{
    return tcpConnections;
}
const std::vector<IHTTPTransaction *>&      SPDYConnection::GetHTTPTransactionList  () const
{
    return httpTransactions;
}
ssize_t                                     SPDYConnection::SpdyNetSend             (spdylay_session *session, const uint8_t *data, size_t length, int flags, void *user_data)
{
    SPDYConnection *spdycon = (SPDYConnection *) user_data;

    return send(spdycon->httpSocket, data, length, 0);
}
ssize_t                                     SPDYConnection::SpdyNetRead             (spdylay_session *session, uint8_t *buf, size_t length, int flags, void *user_data)
{
    SPDYConnection *spdycon = (SPDYConnection *) user_data;

    size_t ret = recv(spdycon->httpSocket, buf, length, 0);

    return ret;
}
void                                        SPDYConnection::SpdyChunkAvailable      (spdylay_session *session, uint8_t flags, int32_t stream_id, const uint8_t *data, size_t len, void *user_data)
{
    SPDYConnection *spdycon = (SPDYConnection *) user_data;

    block_t *block = AllocBlock(len);
    memcpy(block->data, data, len);

    spdycon->chunkQueue.front()->blockStream.PushBack(block);
}
void                                        SPDYConnection::SpdySynReply            (spdylay_frame *frame)
{
    int i = 0;
    while (frame->syn_reply.nv[i] != NULL)
    {
        std::cout << frame->syn_reply.nv[i] << " : " << frame->syn_reply.nv[i + 1] << std::endl;
        if (!strncasecmp(frame->syn_reply.nv[i], "Content-Length", 14))
        {
            this->chunkQueue.front()->contentLength = atoi(frame->syn_reply.nv[i + 1]);
        }
        i++;
    }
}
void                                        SPDYConnection::PrintFrameType          (spdylay_frame_type type)
{
    switch (type)
    {
        case SPDYLAY_SYN_STREAM:        std::cout << "SPDYLAY_SYN_STREAM" << std::endl;       return;
        case SPDYLAY_SYN_REPLY:         std::cout << "SPDYLAY_SYN_REPLY" << std::endl;        return;
        case SPDYLAY_RST_STREAM:        std::cout << "SPDYLAY_RST_STREAM" << std::endl;       return;
        case SPDYLAY_SETTINGS:          std::cout << "SPDYLAY_SETTINGS" << std::endl;         return;
        case SPDYLAY_NOOP:              std::cout << "SPDYLAY_NOOP" << std::endl;             return;
        case SPDYLAY_PING:              std::cout << "SPDYLAY_PING" << std::endl;             return;
        case SPDYLAY_GOAWAY:            std::cout << "SPDYLAY_GOAWAY" << std::endl;           return;
        case SPDYLAY_HEADERS:           std::cout << "SPDYLAY_HEADERS" << std::endl;          return;
        case SPDYLAY_WINDOW_UPDATE:     std::cout << "SPDYLAY_WINDOW_UPDATE" << std::endl;    return;
        case SPDYLAY_CREDENTIAL:        std::cout << "SPDYLAY_CREDENTIAL" << std::endl;       return;

        default: std::cout << "Frame type not known!" << std::endl;
    }
}
void                                        SPDYConnection::SpdyCtrlFrame           (spdylay_session *session, spdylay_frame_type type, spdylay_frame *frame, void *user_data)
{
    SPDYConnection *spdycon = (SPDYConnection *) user_data;

    spdycon->PrintFrameType(type);

    if (type == SPDYLAY_SYN_REPLY)
        spdycon->SpdySynReply(frame);
}
