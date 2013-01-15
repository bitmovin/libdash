/*
 * Timeline.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Timeline.h"

using namespace dash::mpd;

Timeline::Timeline    ()  :
                startTime(0),
                duration(0),
                repeatCount(0)
{
}
Timeline::~Timeline   ()
{
}

uint32_t    Timeline::GetStartTime     ()  const
{
    return this->startTime;
}
void        Timeline::SetStartTime     (uint32_t startTime) 
{
    this->startTime = startTime;
}
uint32_t    Timeline::GetDuration      ()  const
{
    return this->duration;
}
void        Timeline::SetDuration      (uint32_t duration) 
{
    this->duration = duration;
}
uint32_t    Timeline::GetRepeatCount   ()  const
{
    return this->repeatCount;
}
void        Timeline::SetRepeatCount   (uint32_t repeatCount)
{
    this->repeatCount = repeatCount;
}