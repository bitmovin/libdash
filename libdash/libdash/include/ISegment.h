/*
 * ISegment.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISEGMENT_H_
#define ISEGMENT_H_

#include "config.h"

#include "IDownloadableChunk.h"

namespace dash
{
    namespace mpd
    {
        class ISegment : public virtual network::IDownloadableChunk
        {
            public:
                virtual ~ISegment(){}

                virtual void    AbsoluteURI  (std::string uri)   = 0;
                virtual void    Host         (std::string host)  = 0;
                virtual void    Port         (size_t port)       = 0;
                virtual void    Path         (std::string path)  = 0;
                virtual void    Range        (std::string range) = 0;
                virtual void    StartByte    (size_t startByte)  = 0;
                virtual void    EndByte      (size_t endByte)    = 0;
                virtual void    HasByteRange (bool hasByteRange) = 0;
        };
    }
}

#endif /* ISEGMENT_H_ */