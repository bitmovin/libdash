/*
 * AlwaysLowestLogic.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_ALWAYSLOWESTLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_ALWAYSLOWESTLOGIC_H_

#include "IMPD.h"
#include "IAdaptationLogic.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class AlwaysLowestLogic : public IAdaptationLogic
            {
                public:
                    AlwaysLowestLogic           (dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd);
                    virtual ~AlwaysLowestLogic  ();

                    MediaObject* GetSegment (uint32_t number);

                private:
                    dash::mpd::IAdaptationSet           *adaptationSet;
                    dash::mpd::IMPD                     *mpd;
                    dash::mpd::IRepresentation          *currentRep;
                    std::vector<dash::mpd::IBaseUrl *>  baseurls;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ALWAYSLOWESTLOGIC_H_ */