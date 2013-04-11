
/*
 * AbstractRepresentationStream.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AdaptationSetStream.h"

using namespace sampleplayer::mpd;
using namespace dash::mpd;

AdaptationSetStream::AdaptationSetStream (IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet) :
                     mpd                 (mpd),
                     period              (period),
                     adaptationSet       (adaptationSet)
{
    Initialize();
}
AdaptationSetStream::~AdaptationSetStream()
{
    std::map<IRepresentation *, IRepresentationStream *>::iterator iter;
    for (iter = representations.begin(); iter != representations.end(); ++iter)
    {
        delete(iter->second);
    }
}
IRepresentationStream*      AdaptationSetStream::GetRepresentationStream            (IRepresentation *representation)
{
    return this->representations.find(representation)->second;
}
RepresentationStreamType    AdaptationSetStream::DetermineRepresentationStreamType  (IRepresentation *representation)
{
    /* check on Representation Level */
    if (representation->GetSegmentList())
        return sampleplayer::mpd::SegmentList;

    if (representation->GetSegmentTemplate())
        return sampleplayer::mpd::SegmentTemplate;

    if (representation->GetSegmentBase() || representation->GetBaseURLs().size() > 0)
        return sampleplayer::mpd::SingleMediaSegment;

    /* check on AdaptationSet Level */
    if (this->adaptationSet->GetSegmentList())
        return sampleplayer::mpd::SegmentList;

    if (this->adaptationSet->GetSegmentTemplate())
        return sampleplayer::mpd::SegmentTemplate;

    if (this->adaptationSet->GetSegmentBase())
        return sampleplayer::mpd::SingleMediaSegment;

    /* check on Period Level */
    if (this->period->GetSegmentList())
        return sampleplayer::mpd::SegmentList;

    if (this->period->GetSegmentTemplate())
        return sampleplayer::mpd::SegmentTemplate;

    if (this->period->GetSegmentBase())
        return sampleplayer::mpd::SingleMediaSegment;

    return sampleplayer::mpd::UNDEFINED;
}
void                        AdaptationSetStream::Initialize()
{
    for (size_t i = 0; i < adaptationSet->GetRepresentation().size(); i++)
    {
        IRepresentation *representation = adaptationSet->GetRepresentation().at(i);
        RepresentationStreamType type   = DetermineRepresentationStreamType(representation);
        representations[representation] = RepresentationStreamFactory::Create(type, mpd, period, adaptationSet, representation);
    }
}
