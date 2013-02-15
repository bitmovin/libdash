/*
 * MediaObjectBuffer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MediaObjectBuffer.h"

using namespace libdash::framework::buffer;
using namespace libdash::framework::adaptation;

using namespace dash::mpd;
using namespace dash::network;

MediaObjectBuffer::MediaObjectBuffer    (uint32_t maxcapacity) :
                   eos                  (false),
                   maxcapacity          (maxcapacity)
{
    InitializeConditionVariable (&this->full);
    InitializeConditionVariable (&this->empty);
    InitializeCriticalSection   (&this->monitorMutex);
}
MediaObjectBuffer::~MediaObjectBuffer   ()
{
    DeleteConditionVariable (&this->full);
    DeleteConditionVariable (&this->empty);
    DeleteCriticalSection   (&this->monitorMutex);

    while(!this->mediaobjects.empty())
    {
        delete(this->mediaobjects.front());
        this->mediaobjects.pop();
    }
}

void            MediaObjectBuffer::Push             (MediaObject *media)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->mediaobjects.size() >= this->maxcapacity && !this->eos)
        SleepConditionVariableCS(&this->empty, &this->monitorMutex, INFINITE);

    if(this->mediaobjects.size() >= this->maxcapacity)
    {
        delete(media);
        LeaveCriticalSection(&this->monitorMutex);
        return;
    }

    this->mediaobjects.push(media);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
MediaObject*    MediaObjectBuffer::Front            ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->mediaobjects.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->mediaobjects.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    LeaveCriticalSection(&this->monitorMutex);

    return this->mediaobjects.front();
}
uint32_t        MediaObjectBuffer::Length           ()
{
    EnterCriticalSection(&this->monitorMutex);

    uint32_t ret = this->mediaobjects.size();

    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
void            MediaObjectBuffer::Pop              ()
{
    EnterCriticalSection(&this->monitorMutex);

    delete(this->mediaobjects.front());
    this->mediaobjects.pop();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
void            MediaObjectBuffer::SetEOS           (bool value)
{
    EnterCriticalSection(&this->monitorMutex);

    this->eos = value;

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
void            MediaObjectBuffer::AttachObserver   (IBufferObserver *observer)
{
    this->observer.push_back(observer);
}
void            MediaObjectBuffer::Notify           ()
{
}
void            MediaObjectBuffer::Clear            ()
{
    EnterCriticalSection(&this->monitorMutex);

    int size = this->mediaobjects.size()-1;

    MediaObject* object = this->mediaobjects.front();
    this->mediaobjects.pop();
    for(int i=0; i < size; i++)
    {
        delete this->mediaobjects.front();
        this->mediaobjects.pop();
    }

    this->mediaobjects.push(object);
    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
uint32_t        MediaObjectBuffer::Capacity         ()
{
    return this->maxcapacity;
}