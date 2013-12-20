/*
 * Event.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung GmbH, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Event.h"

using namespace dash::mpd;

Event::Event    ()  :
            presentationTime(0),
            duration(0),
            id(0)
{
}
Event::~Event   ()
{
}

uint64_t            Event::GetPresentationTime  ()  const
{
    return this->presentationTime;
}
void                Event::SetPresentationTime  (uint64_t presentationTime)
{
    this->presentationTime = presentationTime;
}
uint64_t            Event::GetDuration          ()  const
{
    return this->duration;
}
void                Event::SetDuration          (uint64_t duration)
{
    this->duration = duration;
}
uint32_t            Event::GetId                ()  const
{
    return this->id;
}
void                Event::SetId                (uint32_t id)
{
    this->id = id;
}
