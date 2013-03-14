/*
 * RepresentationStreamFactory.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_RERPRESENTATIONSTREAMFACTORY_H_
#define LIBDASH_FRAMEWORK_MPD_RERPRESENTATIONSTREAMFACTORY_H_

#include "IRepresentationStream.h"
#include "SingleMediaSegmentStream.h"
#include "SegmentListStream.h"
#include "SegmentTemplateStream.h"
#include "IRepresentation.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            class RepresentationStreamFactory
            {
                public:
                    static IRepresentationStream* Create(libdash::framework::mpd::RepresentationStreamType type, dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period,
                                                         dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_MPD_RERPRESENTATIONSTREAMFACTORY_H_ */
