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
#include "AbstractAdaptationLogic.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class AlwaysLowestLogic : public AbstractAdaptationLogic
            {
                public:
                    AlwaysLowestLogic           (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t bufferSize);
                    virtual ~AlwaysLowestLogic  ();

                    virtual input::MediaObject*     GetSegment          ();
                    virtual LogicType               GetType             ();
                    virtual void                    InvokeInitSegment   (bool invoke);

                private:
                    std::vector<dash::mpd::IBaseUrl *>  baseurls;
                    dash::mpd::IPeriod                  *period;
                    dash::mpd::IRepresentation          *representation;
                    dash::mpd::IAdaptationSet           *adaptationSet;
                    dash::mpd::IMPD                     *mpd;
                    uint32_t                            segmentNumber;
                    bool                                invokeInitSegment;

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ALWAYSLOWESTLOGIC_H_ */