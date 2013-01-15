/*
 * IRange.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IRANGE_H_
#define IRANGE_H_

#include "config.h"

namespace dash
{
    namespace mpd
    {
        class IRange
        {
            public:
                virtual ~IRange(){}

                virtual const std::string&  GetStarttime    ()  const = 0;
                virtual const std::string&  GetDuration     ()  const = 0;

        };
    }
}

#endif /* IRANGE_H_ */