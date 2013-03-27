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

#include "../MPD/RepresentationHelper.h"
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
                    ManualAdaptation            (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t bufferSize);
                    virtual ~ManualAdaptation   ();

                    virtual input::MediaObject*     GetSegment          ();
                    virtual uint32_t                GetPosition         ();
                    virtual void                    SetPosition         (uint32_t segmentNumber);
                    virtual void                    SetRepresentation   (dash::mpd::IRepresentation *representation);
                    virtual LogicType               GetType             ();
                    virtual void                    InvokeInitSegment   (bool invoke);

                private:
                    uint32_t                        CalculateSegmentOffset ();

                    dash::mpd::IMPD                                 *mpd;
                    dash::mpd::IPeriod                              *period;
                    dash::mpd::IAdaptationSet                       *adaptationSet;
                    dash::mpd::IRepresentation                      *representation;
                    libdash::framework::mpd::AdaptationSetStream    *adaptationSetStream;
                    libdash::framework::mpd::IRepresentationStream  *representationStream;
                    uint32_t                                        segmentNumber;
                    bool                                            invokeInitSegment;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_ADAPTATION_MANUALADAPTATION_H_ */