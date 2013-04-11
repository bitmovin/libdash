/*
 * ManualAdaptation.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ManualAdaptation.h"

using namespace dash::mpd;
using namespace sampleplayer::adaptation;
using namespace sampleplayer::input;
using namespace sampleplayer::mpd;

ManualAdaptation::ManualAdaptation          (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t bufferSize) :
                  AbstractAdaptationLogic   (period, adaptationSet, mpd, bufferSize),
                  period                    (period),
                  adaptationSet             (adaptationSet),
                  adaptationSetStream       (NULL),
                  representationStream      (NULL),
                  mpd                       (mpd),
                  segmentNumber             (0),
                  invokeInitSegment         (false)
{
    this->representation        = this->adaptationSet->GetRepresentation().at(0);
    this->adaptationSetStream   = new AdaptationSetStream(mpd, period, adaptationSet);
    this->representationStream  = adaptationSetStream->GetRepresentationStream(this->representation);
    this->segmentOffset         = CalculateSegmentOffset();
}
ManualAdaptation::~ManualAdaptation         ()
{
    delete(adaptationSetStream);
}

LogicType                   ManualAdaptation::GetType               ()
{
    return adaptation::Manual;
}
MediaObject*                ManualAdaptation::GetSegment            ()
{
    ISegment *seg = NULL;

    if(this->segmentNumber >= this->representationStream->GetSize() + 1)
        return NULL;

    seg = this->representationStream->GetMediaSegment(this->segmentNumber + segmentOffset);

    if (seg != NULL)
    {
        MediaObject *media = new MediaObject(seg, this->representation);
        this->segmentNumber++;
        return media;
    }

    return NULL;
}
MediaObject*                ManualAdaptation::GetInitSegment            ()
{
    ISegment *seg = NULL;

    seg = this->representationStream->GetInitializationSegment();

    if (seg != NULL)
    {
        MediaObject *media = new MediaObject(seg, this->representation);
        return media;
    }

    return NULL;
}
uint32_t                    ManualAdaptation::GetPosition           ()
{
    return this->segmentNumber;
}
void                        ManualAdaptation::SetPosition           (uint32_t segmentNumber)
{
    this->segmentNumber = segmentNumber;
}
void                        ManualAdaptation::SetRepresentation     (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation)
{
    if (this->representation == representation)
        return;

    this->representation = representation;

    if (this->adaptationSet != adaptationSet)
    {
        this->adaptationSet = adaptationSet;
        this->period = period;

        this->adaptationSetStream = new AdaptationSetStream(this->mpd, this->period, this->adaptationSet);
    }

    this->representationStream  = adaptationSetStream->GetRepresentationStream(representation);
}
dash::mpd::IRepresentation* ManualAdaptation::GetRepresentation ()
{
    return this->representation;
}
void                        ManualAdaptation::InvokeInitSegment     (bool invoke)
{
    this->invokeInitSegment = invoke;
}
uint32_t                    ManualAdaptation::CalculateSegmentOffset()
{
    if (mpd->GetType() == "static")
        return 0;

    uint32_t firstSegNum = this->representationStream->GetFirstSegmentNumber();
    uint32_t currSegNum  = this->representationStream->GetCurrentSegmentNumber();
    uint32_t startSegNum = currSegNum - 2*bufferSize;

    return (startSegNum > firstSegNum) ? startSegNum : firstSegNum;
}