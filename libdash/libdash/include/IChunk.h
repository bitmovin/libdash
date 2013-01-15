/*
 * IChunk.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ICHUNK_H_
#define ICHUNK_H_

#include "config.h"

namespace dash
{
    namespace network
    {
        class IChunk
        {
            public:
                virtual ~IChunk(){}

                virtual std::string&    AbsoluteURI     ()  = 0;
                virtual std::string&    Host            ()  = 0;
                virtual size_t          Port            ()  = 0;
                virtual std::string&    Path            ()  = 0;
                virtual std::string&    Range           ()  = 0;
                virtual size_t          StartByte       ()  = 0;
                virtual size_t          EndByte         ()  = 0;
                virtual bool            HasByteRange    ()  = 0;
        };
    }
}

#endif /* ICHUNK_H_ */