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
using namespace libdash::framework::input;

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
    this->Clear();

    DeleteConditionVariable (&this->full);
    DeleteConditionVariable (&this->empty);
    DeleteCriticalSection   (&this->monitorMutex);
}

bool            MediaObjectBuffer::PushBack         (MediaObject *media)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->mediaobjects.size() >= this->maxcapacity && !this->eos)
        SleepConditionVariableCS(&this->empty, &this->monitorMutex, INFINITE);

    if(this->mediaobjects.size() >= this->maxcapacity)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return false;
    }

    this->mediaobjects.push_back(media);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
    return true;
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

    MediaObject *object = this->mediaobjects.front();

    LeaveCriticalSection(&this->monitorMutex);

    return object;
}
MediaObject*    MediaObjectBuffer::GetFront         ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->mediaobjects.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->mediaobjects.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    MediaObject *object = this->mediaobjects.front();
    this->mediaobjects.pop_front();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();

    return object;
}
uint32_t        MediaObjectBuffer::Length           ()
{
    EnterCriticalSection(&this->monitorMutex);

    uint32_t ret = this->mediaobjects.size();

    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
void            MediaObjectBuffer::PopFront         ()
{
    EnterCriticalSection(&this->monitorMutex);

    this->mediaobjects.pop_front();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
void            MediaObjectBuffer::SetEOS           (bool value)
{
    EnterCriticalSection(&this->monitorMutex);

    for (size_t i = 0; i < this->mediaobjects.size(); i++)
        this->mediaobjects.at(i)->AbortDownload();

    this->eos = value;

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
void            MediaObjectBuffer::AttachObserver   (IMediaObjectBufferObserver *observer)
{
    this->observer.push_back(observer);
}
void            MediaObjectBuffer::Notify           ()
{
    for(size_t i = 0; i < this->observer.size(); i++)
        this->observer.at(i)->OnBufferStateChanged((int)((double)this->mediaobjects.size()/(double)this->maxcapacity*100.0));
}
void            MediaObjectBuffer::ClearTail        ()
{
    EnterCriticalSection(&this->monitorMutex);

    int size = this->mediaobjects.size() - 1;

    if (size < 1)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return;
    }

    MediaObject* object = this->mediaobjects.front();
    this->mediaobjects.pop_front();
    for(int i=0; i < size; i++)
    {
        delete this->mediaobjects.front();
        this->mediaobjects.pop_front();
    }

    this->mediaobjects.push_back(object);
    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
void            MediaObjectBuffer::Clear            ()
{
    EnterCriticalSection(&this->monitorMutex);

    for(int i = 0; i < this->mediaobjects.size(); i++)
        delete this->mediaobjects[i];

    this->mediaobjects.clear();

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
uint32_t        MediaObjectBuffer::Capacity         ()
{
    return this->maxcapacity;
}