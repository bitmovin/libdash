/*
 * AdaptationLogic.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AdaptationLogic.h"

using namespace sampleplayer::input;
using namespace dash::mpd;

AdaptationLogic::AdaptationLogic    (IMPD *mpd) :
                 mpd                (mpd)
{
    this->baseurls.push_back(this->mpd->GetBaseUrls().at(0));
}
AdaptationLogic::AdaptationLogic    (IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation) :
                 mpd                (mpd),
                 period             (period),
                 adaptationSet      (adaptationSet),
                 representation     (representation)
{
    this->baseurls.push_back(this->mpd->GetBaseUrls().at(0));
}
AdaptationLogic::~AdaptationLogic   ()
{
}

MediaObject* AdaptationLogic::GetSegment(uint32_t number)
{
    ISegment *seg = NULL;

    /* Big Buck Bunny 480p only */
    if(number >= this->representation->GetSegmentList()->GetSegmentURLs().size() + 1)
        return NULL;

    seg = this->representation->GetSegmentList()->GetSegmentURLs().at(number - 1)->ToMediaSegment(this->baseurls); 
    //*/

    /* Red Bull 1080p Segment Template */
    //seg = this->representation->GetSegmentTemplate()->GetMediaSegmentFromNumber(this->baseurls, this->representation->GetId(), this->representation->GetBandwidth(), number);

    MediaObject *media = new MediaObject(seg, this->representation);

    return media;
}
MediaObject* AdaptationLogic::GetInitSegment()
{
    ISegment *seg = NULL;

    /* Big Buck Bunny 480p only */
    seg = this->representation->GetSegmentList()->GetInitialization()->ToSegment(this->baseurls);

    /* Red Bull 1080p Segment Template */
    //seg = this->representation->GetSegmentTemplate()->ToInitializationSegment(this->baseurls, this->representation->GetId(), this->representation->GetBandwidth());

    MediaObject *media = new MediaObject(seg, this->representation);
    return media;
}
void        AdaptationLogic::SetRepresentation   (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation)
{
    this->period            = period;
    this->adaptationSet     = adaptationSet;
    this->representation    = representation;
}
IRepresentation*    AdaptationLogic::GetRepresentation   ()
{
    return this->representation;
}