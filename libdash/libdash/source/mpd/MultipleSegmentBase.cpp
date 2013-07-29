/*
 * MultipleSegmentBase.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultipleSegmentBase.h"

using namespace dash::mpd;

MultipleSegmentBase::MultipleSegmentBase    () :
                        bitstreamSwitching(NULL),
                        segmentTimeline(NULL),
                        duration(0),
                        startNumber(1)
{
}
MultipleSegmentBase::~MultipleSegmentBase   ()
{
    delete(this->segmentTimeline);
    delete(this->bitstreamSwitching);
}

const ISegmentTimeline *    MultipleSegmentBase::GetSegmentTimeline     ()  const
{
    return (ISegmentTimeline *) this->segmentTimeline;
}
void                        MultipleSegmentBase::SetSegmentTimeline     (SegmentTimeline *segmentTimeline)
{
    this->segmentTimeline = segmentTimeline;
}
const IURLType*             MultipleSegmentBase::GetBitstreamSwitching  ()  const
{
    return this->bitstreamSwitching;
}
void                        MultipleSegmentBase::SetBitstreamSwitching  (URLType *bitstreamSwitching)
{
    this->bitstreamSwitching = bitstreamSwitching;
}
uint32_t                    MultipleSegmentBase::GetDuration            ()  const
{
    return this->duration;
}
void                        MultipleSegmentBase::SetDuration            (uint32_t duration)
{
    this->duration = duration;
}
uint32_t                    MultipleSegmentBase::GetStartNumber         ()  const
{
    return this->startNumber;
}
void                        MultipleSegmentBase::SetStartNumber         (uint32_t startNumber)
{
    this->startNumber = startNumber;
}
