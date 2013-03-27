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
using namespace libdash::framework::input;
using namespace dash::mpd;

AlwaysLowestLogic::AlwaysLowestLogic        (IPeriod *period, IAdaptationSet *adaptationSet, IMPD *mpd, uint32_t bufferSize) :
                   AbstractAdaptationLogic  (period, adaptationSet, mpd, bufferSize),
                   period                   (period),
                   adaptationSet            (adaptationSet),
                   mpd                      (mpd),
                   segmentNumber            (0)
{
    this->baseurls.push_back(this->mpd->GetBaseUrls().at(0));

    this->representation = this->adaptationSet->GetRepresentation().at(0);
}
AlwaysLowestLogic::~AlwaysLowestLogic   ()
{
}

LogicType       AlwaysLowestLogic::GetType      ()
{
    return adaptation::AlwaysLowest;
}
MediaObject*    AlwaysLowestLogic::GetSegment   ()
{
    /* Sample code that returns always the lowest repesentation (quality) */
    ISegment *seg = NULL;

    if(this->segmentNumber >= this->representation->GetSegmentList()->GetSegmentURLs().size() + 1)
        return NULL;

    if(this->segmentNumber == 0 || this->invokeInitSegment)
    {
        seg = this->representation->GetSegmentBase()->GetInitialization()->ToSegment(this->baseurls);
        this->invokeInitSegment = false;
    }
    else
    {
        seg = this->representation->GetSegmentList()->GetSegmentURLs().at(this->segmentNumber - 1)->ToMediaSegment(this->baseurls);
    }
    MediaObject *media = new MediaObject(seg, this->representation);

    this->segmentNumber++;

    return media;
}
void            AlwaysLowestLogic::InvokeInitSegment   (bool invoke)
{
    this->invokeInitSegment = invoke;
}