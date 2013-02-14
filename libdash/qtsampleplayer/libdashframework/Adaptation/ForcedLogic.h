/*
 * ForcedLogic.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_FORCEDLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_FORCEDLOGIC_H_

#include "IMPD.h"
#include "AbstractAdaptationLogic.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class ForcedLogic : public AbstractAdaptationLogic
            {
                public:
                    ForcedLogic           (dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t startSegment);
                    virtual ~ForcedLogic  ();

                    MediaObject* GetSegment ();

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_FORCEDLOGIC_H_ */