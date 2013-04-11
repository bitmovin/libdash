/*
 * AdaptationLogicFactory.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SAMPLEPLAYER_ADAPTATION_ADAPTATIONLOGICFACTORY_H_
#define SAMPLEPLAYER_ADAPTATION_ADAPTATIONLOGICFACTORY_H_

#include "IAdaptationLogic.h"
#include "ManualAdaptation.h"

namespace sampleplayer
{
    namespace adaptation
    {
        class AdaptationLogicFactory
        {
            public:
                static IAdaptationLogic* Create(sampleplayer::adaptation::LogicType logic, 
                                                dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, 
                                                dash::mpd::IMPD *mpd, uint32_t bufferSize);
        };
    }
}

#endif /* SAMPLEPLAYER_ADAPTATION_ADAPTATIONLOGICFACTORY_H_ */
