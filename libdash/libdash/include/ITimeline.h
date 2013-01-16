/*
 * ITimeline.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ITIMELINE_H_
#define ITIMELINE_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ITimeline : public virtual IMPDElement
        {
            public:
                virtual ~ITimeline(){}

                virtual uint32_t    GetStartTime    ()  const = 0;
                virtual uint32_t    GetDuration     ()  const = 0;
                virtual uint32_t    GetRepeatCount  ()  const = 0;
        };
    }
}

#endif /* ITIMELINE_H_ */