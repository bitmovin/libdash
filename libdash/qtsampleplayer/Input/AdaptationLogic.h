/*
 * AdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ADAPTATIONLOGIC_H_
#define ADAPTATIONLOGIC_H_

#include "IMPD.h"
#include "MediaObject.h"

namespace sampleplayer
{
    namespace input
    {
        class AdaptationLogic
        {
            public:
                AdaptationLogic             (dash::mpd::IMPD *mpd);
                virtual ~AdaptationLogic    ();

                MediaObject* GetSegment(uint32_t number);

            private:
                dash::mpd::IMPD                     *mpd;
                dash::mpd::IRepresentation          *lowestRep;
                std::vector<dash::mpd::IBaseUrl *>  baseurls;
        };
    }
}

#endif /* ADAPTATIONLOGIC_H_ */