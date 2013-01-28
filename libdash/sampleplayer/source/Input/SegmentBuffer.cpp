/*
 * SegmentBuffer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SegmentBuffer.h"

using namespace sampleplayer::input;
using namespace dash::mpd;
using namespace dash::network;

SegmentBuffer::SegmentBuffer    (uint32_t maxcapacity) :
               eos              (false),
               maxcapacity      (maxcapacity)
{
    InitializeConditionVariable (&this->full);
    InitializeConditionVariable (&this->empty);
    InitializeCriticalSection   (&this->monitorMutex);
}
SegmentBuffer::~SegmentBuffer   ()
{
    DeleteConditionVariable (&this->full);
    DeleteConditionVariable (&this->empty);
    DeleteCriticalSection   (&this->monitorMutex);

    while(!this->segments.empty())
    {
        delete(this->segments.front());
        this->segments.pop();
    }
}

void        SegmentBuffer::Push     (ISegment *segment)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->segments.size() >= this->maxcapacity && !this->eos)
        SleepConditionVariableCS(&this->empty, &this->monitorMutex, INFINITE);

    if(this->segments.size() >= this->maxcapacity)
    {
        delete(segment);
        LeaveCriticalSection(&this->monitorMutex);
        return;
    }

    this->segments.push(segment);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
ISegment*   SegmentBuffer::Front    ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->segments.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->segments.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    LeaveCriticalSection(&this->monitorMutex);

    return this->segments.front();
}
void        SegmentBuffer::Pop      ()
{
    EnterCriticalSection(&this->monitorMutex);

    delete(this->segments.front());
    this->segments.pop();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
}
void        SegmentBuffer::SetEOS   (bool value)
{
    EnterCriticalSection(&this->monitorMutex);

    this->eos = value;

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
