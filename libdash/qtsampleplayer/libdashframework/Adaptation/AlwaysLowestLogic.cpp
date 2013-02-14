/*
 * AlwaysLowestLogic.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AlwaysLowestLogic.h"

using namespace libdash::framework::adaptation;
using namespace dash::mpd;

AlwaysLowestLogic::AlwaysLowestLogic    (IAdaptationSet *adaptationSet, IMPD *mpd, uint32_t startSegment) :
                AbstractAdaptationLogic(adaptationSet, mpd, startSegment)
{
    this->baseurls.push_back(this->mpd->GetBaseUrls().at(0));

    this->currentRep = this->adaptationSet->GetRepresentation().at(0);
}
AlwaysLowestLogic::~AlwaysLowestLogic   ()
{
}
MediaObject* AlwaysLowestLogic::GetSegment    ()
{
    /* Sample code that returns always the lowest repesentation (quality) */
    ISegment *seg = NULL;

    if(this->segmentNumber >= this->currentRep->GetSegmentList()->GetSegmentURLs().size() + 1)
        return NULL;

    if(this->segmentNumber == 0)
        seg = this->currentRep->GetSegmentBase()->GetInitialization()->ToSegment(this->baseurls);
    else
        seg = this->currentRep->GetSegmentList()->GetSegmentURLs().at(this->segmentNumber - 1)->ToMediaSegment(this->baseurls);

    MediaObject *media = new MediaObject(seg, this->currentRep);

    this->segmentNumber++;

    return media;
}