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

    /* Big Buck Bunny 480p only */
    //this->lowestRep = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRepresentation().at(0);

    /* Red Bull Segment Template 1080p, highest bitrate */
    this->lowestRep = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(4)->GetRepresentation().at(3);
}
AdaptationLogic::~AdaptationLogic   ()
{
}

MediaObject* AdaptationLogic::GetSegment(uint32_t number)
{
    ISegment *seg = NULL;

    /* Big Buck Bunny 480p only
    if(number >= this->lowestRep->GetSegmentList()->GetSegmentURLs().size() + 1)
        return NULL;

    if(number == 0)
        seg = this->lowestRep->GetSegmentList()->GetInitialization()->ToSegment(this->baseurls);
    else
        seg = this->lowestRep->GetSegmentList()->GetSegmentURLs().at(number - 1)->ToMediaSegment(this->baseurls);
    */

    /* Red Bull 1080p Segment Template */
    seg = this->lowestRep->GetSegmentTemplate()->GetMediaSegmentFromNumber(this->baseurls, this->lowestRep->GetId(), this->lowestRep->GetBandwidth(), number);

    MediaObject *media = new MediaObject(seg, this->lowestRep);

    return media;
}
MediaObject* AdaptationLogic::GetInitSegment()
{
    ISegment *seg = NULL;

    /* Big Buck Bunny 480p only */
    //seg = this->lowestRep->GetSegmentList()->GetInitialization()->ToSegment(this->baseurls);

    /* Red Bull 1080p Segment Template */
    seg = this->lowestRep->GetSegmentTemplate()->ToInitializationSegment(this->baseurls, this->lowestRep->GetId(), this->lowestRep->GetBandwidth());

    MediaObject *media = new MediaObject(seg, this->lowestRep);
    return media;
}
