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

#ifndef SAMPLEPLAYER_MPD_RERPRESENTATIONSTREAMFACTORY_H_
#define SAMPLEPLAYER_MPD_RERPRESENTATIONSTREAMFACTORY_H_

#include "IRepresentationStream.h"
#include "SingleMediaSegmentStream.h"
#include "SegmentListStream.h"
#include "SegmentTemplateStream.h"
#include "IRepresentation.h"

namespace sampleplayer
{
    namespace mpd
    {
        class RepresentationStreamFactory
        {
            public:
                static IRepresentationStream* Create(sampleplayer::mpd::RepresentationStreamType type, dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period,
                                                     dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);

        };
    }
}

#endif /* SAMPLEPLAYER_MPD_RERPRESENTATIONSTREAMFACTORY_H_ */
