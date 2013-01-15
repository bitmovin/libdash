/*
 * ISegmentURL.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISEGMENTURL_H_
#define ISEGMENTURL_H_

#include "config.h"

#include "ISegment.h"
#include "IBaseUrl.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentURL
        {
            public:
                virtual ~ISegmentURL(){}

                virtual const std::string&  GetMediaURI     ()  const = 0;
                virtual const std::string&  GetMediaRange   ()  const = 0;
                virtual const std::string&  GetIndexURI     ()  const = 0;
                virtual const std::string&  GetIndexRange   ()  const = 0;
                virtual ISegment*           ToMediaSegment  (const std::vector<IBaseUrl *>& baseurls) const = 0;
                virtual ISegment*           ToIndexSegment  (const std::vector<IBaseUrl *>& baseurls) const = 0;

        };
    }
}

#endif /* ISEGMENTURL_H_ */