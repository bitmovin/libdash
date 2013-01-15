/*
 * IURLType.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IURLTYPE_H_
#define IURLTYPE_H_

#include "config.h"

#include "ISegment.h"
#include "IBaseUrl.h"

namespace dash
{
    namespace mpd
    {
        class IURLType
        {
            public:
                virtual ~IURLType(){}

                virtual const std::string&  GetSourceURL    ()  const = 0;
                virtual const std::string&  GetRange        ()  const = 0;
                virtual ISegment*           ToSegment       (const std::vector<IBaseUrl *>& baseurls) const = 0;
        };
    }
}

#endif /* IURLTYPE_H_ */