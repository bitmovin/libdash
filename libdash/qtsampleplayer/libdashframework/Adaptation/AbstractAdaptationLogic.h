/*
 * AbstractAdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_

#include "MediaObject.h"
#include "IAdaptationLogic.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class AbstractAdaptationLogic : public IAdaptationLogic
            {
                public:
                    AbstractAdaptationLogic                         (dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t startSegment);
                    virtual ~AbstractAdaptationLogic                ();

                    virtual uint32_t     GetSegmentNumber           ();
                    virtual void         SetSegmentNumber           (uint32_t segmentNumber);

            protected:
                    dash::mpd::IAdaptationSet           *adaptationSet;
                    dash::mpd::IMPD                     *mpd;
                    dash::mpd::IRepresentation          *currentRep;
                    std::vector<dash::mpd::IBaseUrl *>  baseurls;
                    uint32_t                            segmentNumber;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_ */
