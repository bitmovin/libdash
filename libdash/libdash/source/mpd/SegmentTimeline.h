/*
 * SegmentTimeline.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SEGMENTTIMELINE_H_
#define SEGMENTTIMELINE_H_

#include "config.h"

#include "ISegmentTimeline.h"
#include "AbstractMPDElement.h"
#include "Timeline.h"

namespace dash
{
    namespace mpd
    {
        class SegmentTimeline : public ISegmentTimeline, public AbstractMPDElement
        {
            public:
                SegmentTimeline             ();
                virtual ~SegmentTimeline    ();

                std::vector<ITimeline *>&   GetTimelines    ()  const;
                void                        AddTimeline     (Timeline *timeline);

            private:
                std::vector<ITimeline *>    timelines;
        };
    }
}

#endif /* SEGMENTTIMELINE_H_ */
