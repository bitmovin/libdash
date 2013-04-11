/*
 * AdaptationSetStream.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SAMPLEPLAYER_MPD_ADAPTATIONSETSTREAM_H_
#define SAMPLEPLAYER_MPD_ADAPTATIONSETSTREAM_H_

#include "IRepresentationStream.h"
#include "IRepresentation.h"
#include "IMPD.h"
#include "IPeriod.h"
#include "IAdaptationSet.h"
#include "RepresentationStreamFactory.h"
#include "BaseUrlResolver.h"

namespace sampleplayer
{
    namespace mpd
    {
        class AdaptationSetStream
        {
            public:
                AdaptationSetStream             (dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet);
                virtual ~AdaptationSetStream    ();

                IRepresentationStream*      GetRepresentationStream             (dash::mpd::IRepresentation *representation);

            private:
                RepresentationStreamType    DetermineRepresentationStreamType   (dash::mpd::IRepresentation *representation);
                void                        Initialize                          ();

                std::map<dash::mpd::IRepresentation *, IRepresentationStream *> representations;
                dash::mpd::IMPD                                                 *mpd;
                dash::mpd::IPeriod                                              *period;
                dash::mpd::IAdaptationSet                                       *adaptationSet;

        };
    }
}
#endif /* SAMPLEPLAYER_MPD_ADAPTATIONSETSTREAM_H_ */
