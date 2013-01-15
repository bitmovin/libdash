/*
 * PersistentHTTPConnection.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PERSISTENTHTTPCONNECTION_H_
#define PERSISTENTHTTPCONNECTION_H_

#include "HTTPConnection.h"
#include "HTTPChunk.h"
#include "../libdash/source/portable/MultiThreading.h"

#include <queue>

#define RETRY 5

namespace libdashtest
{
    class PersistentHTTPConnection : public HTTPConnection
    {
        public:
            PersistentHTTPConnection            ();
            virtual ~PersistentHTTPConnection   ();

            virtual int     Peek        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
            virtual int     Read        (uint8_t *data, size_t len, dash::network::IChunk *chunk);
            virtual bool    Init        (dash::network::IChunk *chunk);
            virtual bool    Schedule    (dash::network::IChunk *chunk);

        private:
            std::queue<HTTPChunk *> chunkQueue;
            std::string             hostname;
            CRITICAL_SECTION        monitorMutex;
            CONDITION_VARIABLE      chunkFinished;
            uint64_t                bytesDownloadedChunk;

        protected:
            virtual std::string PrepareRequest  (dash::network::IChunk *chunk);
            bool                InitChunk       (dash::network::IChunk *chunk);
            bool                Reconnect       (dash::network::IChunk *chunk);
    };
}

#endif /* PERSISTENTHTTPCONNECTION_H_ */