/*
 * HTTPConnection.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef HTTPCONNECTION_H_
#define HTTPCONNECTION_H_

#include "../libdash/source/portable/Networking.h"
#include "IConnection.h"

#include <sstream>
#include <stdint.h>

#define PEEKBUFFER 4096

namespace libdashtest
{
    class HTTPConnection : public dash::network::IConnection
    {
        public:
            HTTPConnection          ();
            virtual ~HTTPConnection ();

            virtual bool    Init        (dash::network::IChunk *chunk);
            virtual int     Read        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
            virtual int     Peek        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
            virtual bool    Schedule    (dash::network::IChunk *chunk);
            virtual void    CloseSocket ();

            /*
             *  IDASHMetrics
             */
            const std::vector<dash::metrics::ITCPConnection *>&     GetTCPConnectionList    () const;
            const std::vector<dash::metrics::IHTTPTransaction *>&   GetHTTPTransactionList  () const;

        protected:
            int                 httpSocket;
            struct sockaddr_in  addr;
            struct hostent      *hostent;
            uint8_t             *peekBuffer;
            size_t              peekBufferLen;
            int                 contentLength;
            bool                isInit;
            bool                isScheduled;

            std::vector<dash::metrics::ITCPConnection *>    tcpConnections;
            std::vector<dash::metrics::IHTTPTransaction *>  httpTransactions;

            virtual std::string PrepareRequest  (dash::network::IChunk *chunk);
            virtual bool        SendData        (std::string data);
            virtual bool        ParseHeader     ();
            virtual std::string ReadLine        ();
            virtual bool        ConnectToHost   (std::string host, int port);
    };
}

#endif /* HTTPCONNECTION_H_ */
