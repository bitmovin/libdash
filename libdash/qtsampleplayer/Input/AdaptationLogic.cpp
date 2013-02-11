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

    this->lowestRep = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRepresentation().at(0);
}
AdaptationLogic::~AdaptationLogic   ()
{
}

MediaObject* AdaptationLogic::GetSegment(uint32_t number)
{
    /* Put your code for the adaptation here and comment the sample code */

    /* Sample code that returns always the lowest repesentation (quality) */
    ISegment *seg = NULL;

    if(number >= this->lowestRep->GetSegmentList()->GetSegmentURLs().size() + 1)
        return NULL;

    if(number == 0)
        seg = this->lowestRep->GetSegmentBase()->GetInitialization()->ToSegment(this->baseurls);
    else
        seg = this->lowestRep->GetSegmentList()->GetSegmentURLs().at(number - 1)->ToMediaSegment(this->baseurls);

    MediaObject *media = new MediaObject(seg, this->lowestRep);

    return media;
}