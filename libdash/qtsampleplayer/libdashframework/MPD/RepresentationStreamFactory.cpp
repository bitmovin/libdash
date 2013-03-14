/*
 * RepresentationStreamFactory.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "RepresentationStreamFactory.h"

using namespace libdash::framework::mpd;
using namespace dash::mpd;

IRepresentationStream*  RepresentationStreamFactory::Create(RepresentationStreamType type, IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    switch(type)
    {
        case SingleMediaSegment: return new SingleMediaSegmentStream(mpd, period, adaptationSet, representation);
        case SegmentList:        return new SegmentListStream       (mpd, period, adaptationSet, representation);
        case SegmentTemplate:    return new SegmentTemplateStream   (mpd, period, adaptationSet, representation);

        default:                 return NULL;
    }
}
