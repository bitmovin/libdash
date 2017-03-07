/*
 * Timeline.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef TIMELINE_H_
#define TIMELINE_H_

#include "config.h"

#include "ITimeline.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Timeline : public ITimeline, public AbstractMPDElement
        {
            public:
                Timeline             ();
                virtual ~Timeline    ();

                uint64_t    GetStartTime    ()  const;
                uint64_t    GetDuration     ()  const;
                uint32_t    GetRepeatCount  ()  const;

                void    SetStartTime    (uint64_t startTime);
                void    SetDuration     (uint64_t duration);
                void    SetRepeatCount  (uint32_t repeatCount);

            private:
                uint64_t    startTime;
                uint64_t    duration;
                uint32_t    repeatCount;
        };
    }
}

#endif /* TIMELINE_H_ */
