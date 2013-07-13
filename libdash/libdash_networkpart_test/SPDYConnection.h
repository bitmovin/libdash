/*
 * SPDYConnection.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Created on: 7/4/2013
 * Author: Christopher Mueller <christopher.mueller@bitmovin.net>
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SPDYCONNECTION_H
#define SPDYCONNECTION_H

#include "../libdash/source/portable/Networking.h"
#include "../libdash/source/portable/MultiThreading.h"
#include "../libdash/source/helpers/SyncedBlockStream.h"
#include "IConnection.h"
#include "SPDYChunk.h"

#include <queue>
#include <iostream>
#include <sstream>
#include <stdint.h>

#define PEEKBUFFER 4096

#include <spdylay/spdylay.h>

namespace libdashtest
{
    class SPDYConnection : public dash::network::IConnection
    {
        public:
            SPDYConnection          ();
            virtual ~SPDYConnection ();

            /******************************
             *  IConnection
             ******************************/
            virtual bool    Init        (dash::network::IChunk *chunk);
            virtual int     Read        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
            virtual int     Peek        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
            virtual bool    Schedule    (dash::network::IChunk *chunk);
            virtual void    Close       ();

            /******************************
             *  IDASHMetrics
             ******************************/
            const std::vector<dash::metrics::ITCPConnection *>&     GetTCPConnectionList    () const;
            const std::vector<dash::metrics::IHTTPTransaction *>&   GetHTTPTransactionList  () const;

            uint64_t                                        contentLength;
            uint64_t                                        bytesRead;

        private:
            THREAD_HANDLE                                   dlThread;
            int                                             httpSocket;
            struct sockaddr_in                              addr;
            struct hostent                                  *hostent;
            spdylay_session                                 *session;
            spdylay_session_callbacks                       *callbacks;
            bool                                            isInit;
            std::vector<dash::metrics::ITCPConnection *>    tcpConnections;
            std::vector<dash::metrics::IHTTPTransaction *>  httpTransactions;
            dash::helpers::SyncedBlockStream                blockStream;
            std::queue<SPDYChunk *>                         chunkQueue;
            std::string                                     hostname;

            virtual bool ConnectToHost (std::string host, int port);

            /******************************
             *  SPDY
             ******************************/
            static void* StartSPDYDownload (void *);

            static ssize_t  SpdyNetSend         (spdylay_session *session, const uint8_t *data, size_t length, int flags, void *user_data);
            static ssize_t  SpdyNetRead         (spdylay_session *session, uint8_t *buf, size_t length, int flags, void *user_data);
            static void     SpdyChunkAvailable  (spdylay_session *session, uint8_t flags, int32_t stream_id, const uint8_t *data, size_t len, void *user_data);
            static void     SpdyCtrlFrame       (spdylay_session *session, spdylay_frame_type type, spdylay_frame *frame, void *user_data);

            bool    SubmitRequest       (std::string path, std::string host);
            void    SpdySynReply        (spdylay_frame *frame);
            void    PrintFrameType      (spdylay_frame_type type);
    };
}

#endif // SPDYCONNECTION_H
