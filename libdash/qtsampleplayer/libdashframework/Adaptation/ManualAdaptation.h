/*
 * ManualAdaptation.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_MANUALADAPTATION_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_MANUALADAPTATION_H_

#include "AbstractAdaptationLogic.h"
#include "../MPD/AdaptationSetStream.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class ManualAdaptation : public AbstractAdaptationLogic
            {
                public:
                    ManualAdaptation            (dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet);
                    virtual ~ManualAdaptation   ();

                    virtual LogicType               GetType             ();

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_MANUALADAPTATION_H_ */
