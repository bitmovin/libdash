/*
 * IMultipleSegmentBase.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IMULTIPLESEGMENTBASE_H_
#define IMULTIPLESEGMENTBASE_H_

#include "config.h"

#include "ISegmentTimeline.h"
#include "ISegmentBase.h"
#include "IURLType.h"

namespace dash
{
    namespace mpd
    {
        class IMultipleSegmentBase : public virtual ISegmentBase
        {
            public:
                virtual ~IMultipleSegmentBase(){}

                virtual const ISegmentTimeline*     GetSegmentTimeline      ()  const = 0;
                virtual const IURLType*             GetBitstreamSwitching   ()  const = 0;
                virtual uint32_t                    GetDuration             ()  const = 0;
                virtual uint32_t                    GetStartNumber          ()  const = 0;
        };
    }
}

#endif /* IMULTIPLESEGMENTBASE_H_ */