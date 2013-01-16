/*
 * ISegmentTimeline.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISEGMENTTIMELINE_H_
#define ISEGMENTTIMELINE_H_

#include "config.h"

#include "ITimeline.h"
#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentTimeline : public virtual IMPDElement
        {
            public:
                virtual ~ISegmentTimeline(){}

                virtual std::vector<ITimeline *>&   GetTimelines ()  const = 0;
        };
    }
}

#endif /* ISEGMENTTIMELINE_H_ */