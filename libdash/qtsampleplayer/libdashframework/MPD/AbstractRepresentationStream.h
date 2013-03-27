/*
 * AbstractRepresentationStream.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_ABSTRACTREPRESENTATIONSTREAM_H_
#define LIBDASH_FRAMEWORK_MPD_ABSTRACTREPRESENTATIONSTREAM_H_

#include "IRepresentationStream.h"
#include "IBaseUrl.h"
#include "IRepresentation.h"
#include "IAdaptationSet.h"
#include "IMPD.h"
#include "IPeriod.h"
#include "BaseUrlResolver.h"
#include "TimeResolver.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            class AbstractRepresentationStream : public IRepresentationStream
            {
                public:
                    AbstractRepresentationStream            (dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet,
                                                             dash::mpd::IRepresentation *representation);
                    virtual ~AbstractRepresentationStream   ();

                    virtual dash::mpd::ISegment*        GetInitializationSegment        () = 0;
                    virtual dash::mpd::ISegment*        GetIndexSegment                 (size_t segmentNumber) = 0;
                    virtual dash::mpd::ISegment*        GetMediaSegment                 (size_t segmentNumber) = 0;
                    virtual dash::mpd::ISegment*        GetBitstreamSwitchingSegment    () = 0;
                    virtual RepresentationStreamType    GetStreamType                   () = 0;

                    virtual uint32_t                    GetSize                         ();
                    virtual uint32_t                    GetFirstSegmentNumber           ();
                    virtual uint32_t                    GetCurrentSegmentNumber         ();
                    virtual uint32_t                    GetLastSegmentNumber            ();
                    virtual uint32_t                    GetAverageSegmentDuration       ();

                protected:
                    virtual void                        SetBaseUrls                     (const std::vector<dash::mpd::IBaseUrl *> baseurls);

                    std::vector<dash::mpd::IBaseUrl *>  baseUrls;
                    dash::mpd::IMPD                     *mpd;
                    dash::mpd::IPeriod                  *period;
                    dash::mpd::IAdaptationSet           *adaptationSet;
                    dash::mpd::IRepresentation          *representation;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_ */
