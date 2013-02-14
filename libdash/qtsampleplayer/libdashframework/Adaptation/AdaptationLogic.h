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

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_ADAPTATIONLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_ADAPTATIONLOGIC_H_

#include "IMPD.h"
#include "MediaObject.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class AdaptationLogic
            {
                public:
                    AdaptationLogic             (dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd);
                    virtual ~AdaptationLogic    ();

                    MediaObject* GetSegment (uint32_t number);
                    void SetRepresentation      (dash::mpd::IRepresentation* representation);

                private:
                    dash::mpd::IAdaptationSet           *adaptationSet;
                    dash::mpd::IMPD                     *mpd;
                    dash::mpd::IRepresentation          *currentRep;
                    std::vector<dash::mpd::IBaseUrl *>  baseurls;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ADAPTATIONLOGIC_H_ */