/*
 * AdaptationLogicFactory.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AdaptationLogicFactory.h"

using namespace libdash::framework::adaptation;
using namespace dash::mpd;

IAdaptationLogic* AdaptationLogicFactory::Create(LogicType logic, IPeriod *period, IAdaptationSet *adaptationSet, IMPD *mpd, uint32_t bufferSize)
{
    switch(logic)
    {
        case Manual:            return new ManualAdaptation     (period, adaptationSet, mpd, bufferSize);
        case AlwaysLowest:      return new AlwaysLowestLogic    (period, adaptationSet, mpd, bufferSize);

        default:                return new ManualAdaptation     (period, adaptationSet, mpd, bufferSize);
    }
}
