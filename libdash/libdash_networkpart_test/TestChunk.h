/*
 * TestChunk.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef TESTCHUNK_H_
#define TESTCHUNK_H_

#include "IChunk.h"

namespace libdashtest
{
    class TestChunk : public dash::network::IChunk
    {
        public:
            TestChunk           (std::string host, size_t port, std::string path, size_t startbyte, size_t endbyte, bool hasByteRange);
            virtual ~TestChunk  ();

            virtual std::string&    AbsoluteURI     ();
            virtual std::string&    Host            ();
            virtual size_t          Port            ();
            virtual std::string&    Path            ();
            virtual std::string&    Range           ();
            virtual size_t          StartByte       ();
            virtual size_t          EndByte         ();
            virtual bool            HasByteRange    ();
            virtual dash::metrics::HTTPTransactionType  GetType();

        private:
            std::string     uri;
            std::string     host;
            size_t          port;
            std::string     path;
            std::string     range;
            size_t          startbyte;
            size_t          endbyte;
            bool            hasByteRange;
    };
}

#endif /* TESTCHUNK_H_ */