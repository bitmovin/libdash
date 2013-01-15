/*
 * SegmentTimeline.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SegmentTimeline.h"

using namespace dash::mpd;

SegmentTimeline::SegmentTimeline    ()
{
}
SegmentTimeline::~SegmentTimeline   ()
{
    for (size_t i=0; i < this->timelines.size(); i++)
        delete(this->timelines.at(i));
}

std::vector<ITimeline *>&   SegmentTimeline::GetTimelines   ()  const
{
    return (std::vector<ITimeline*> &) this->timelines;
}
void                        SegmentTimeline::AddTimeline    (Timeline *timeline)
{
    this->timelines.push_back(timeline);
}