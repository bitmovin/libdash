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

#ifndef CCNCONNECTION_H_
#define CCNCONNECTION_H_

#include "../libdash/source/portable/Networking.h"
#include "IConnection.h"

#include <string>
#include <stdint.h>
#include <iostream>
#include <sstream>

extern "C" {
#include <ccn/fetch.h>
#include <ccn/ccn.h>
#include <ccn/charbuf.h>
#include <ccn/uri.h>
#include <ccn/header.h>
}

#define CCN_DEFAULT_TIMEOUT    -1
#define CCN_VERSION_TIMEOUT    400
#define CCN_HEADER_TIMEOUT     400
#define CCN_CHUNK_SIZE         4096
#define CCN_MAX_CCN_GET_TRYS   3
#define CCN_FETCH_MAX_BUFFERS  8
#define BLOCKSIZE              32768
#define PEEKBUFFER             4096

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class CCNConnection : public dash::network::IConnection
            {
                public:
                    CCNConnection          ();
                    virtual ~CCNConnection ();

                    virtual bool    Init        (dash::network::IChunk *chunk);
                    virtual int     Read        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
                    virtual int     Peek        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
                    virtual bool    Schedule    (dash::network::IChunk *chunk);
                    /*
                     *  IDASHMetrics
                     */
                    const std::vector<dash::metrics::ITCPConnection *>&     GetTCPConnectionList    () const;
                    const std::vector<dash::metrics::IHTTPTransaction *>&   GetHTTPTransactionList  () const;

                protected:
                    struct ccn                  *ccnConn;
                    struct ccn_fetch            *cf;
                    struct ccn_fetch_stream     *fs;
                    struct ccn_charbuf          *i_name, *p_name;
                    struct ccn_charbuf          *interest_template;
                    int                         ccn_get_timeout;
                    bool                        b_last;
                    int                         sum;
                    uint64_t                    i_pos;
                    bool                        isConn;
                    uint8_t                     *peekBuffer;
                    size_t                      peekBufferLen;
                    int                         contentLength;
                    bool                        isInit;
                    bool                        isScheduled;

                    std::vector<dash::metrics::ITCPConnection *>    tcpConnections;
                    std::vector<dash::metrics::IHTTPTransaction *>  httpTransactions;

                    virtual std::string PrepareRequest  (dash::network::IChunk *chunk);
                    virtual bool        SendData        (std::string data);
                    virtual bool        Connect   ();
            };
        }
    }
}

#endif /* CCNCONNECTION_H_ */
