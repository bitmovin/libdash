/*
 * SegmentBuffer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SEGMENTBUFFER_H_
#define SEGMENTBUFFER_H_

#include "ISegment.h"
#include "../../../libdash/source/portable/MultiThreading.h"
#include <queue>

namespace sampleplayer
{
    namespace input
    {
        class SegmentBuffer
        {
            public:
                SegmentBuffer           (uint32_t maxcapacity);
                virtual ~SegmentBuffer  ();

                void                    Push    (dash::mpd::ISegment *segment);
                dash::mpd::ISegment*    Front   ();
                void                    Pop     ();
                void                    SetEOS  (bool value);

            private:
                std::queue<dash::mpd::ISegment *>   segments;
                bool                                eos;
                uint32_t                            maxcapacity;
                mutable CRITICAL_SECTION            monitorMutex;
                mutable CONDITION_VARIABLE          full;
                mutable CONDITION_VARIABLE          empty;
        };
    }
}

#endif /* SEGMENTBUFFER_H_ */