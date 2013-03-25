/*
 * TCPConnection.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

#include "ITCPConnection.h"

namespace dash
{
    namespace metrics
    {
        class TCPConnection : public ITCPConnection
        {
            public:
                TCPConnection          ();
                virtual ~TCPConnection ();

                uint32_t                TCPId                   () const;
                const std::string&      DestinationAddress      () const;
                double                  ConnectionOpenedTime    () const;
                double                  ConnectionClosedTime    () const;
                uint64_t                ConnectionTime          () const;

                void    SetTCPId                (uint32_t tcpId);
                void    SetDestinationAddress   (const std::string& destAddress);
                void    SetConnectionOpenedTime (double tOpen);
                void    SetConnectionClosedTime (double tClose);
                void    SetConnectionTime       (uint64_t tConnect);

            private:
                uint32_t        tcpId;
                std::string     dest;
                double          tOpen;
                double          tClose;
                uint64_t        tConnect;
        };
    }
}

#endif /* TCPCONNECTION_H_ */
