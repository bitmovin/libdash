/*
 * AVFrameBuffer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AVFrameBuffer.h"

using namespace sampleplayer::buffer;
using namespace dash::mpd;
using namespace dash::network;

AVFrameBuffer::AVFrameBuffer    (uint32_t maxcapacity) :
               eos              (false),
               maxcapacity      (maxcapacity)
{
    InitializeConditionVariable (&this->full);
    InitializeConditionVariable (&this->empty);
    InitializeCriticalSection   (&this->monitorMutex);
}
AVFrameBuffer::~AVFrameBuffer   ()
{
    this->Clear();

    DeleteConditionVariable (&this->full);
    DeleteConditionVariable (&this->empty);
    DeleteCriticalSection   (&this->monitorMutex);
}

bool            AVFrameBuffer::PushBack         (AVFrame *frame)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->frames.size() >= this->maxcapacity && !this->eos)
        SleepConditionVariableCS(&this->empty, &this->monitorMutex, INFINITE);

    if(this->frames.size() >= this->maxcapacity)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return false;
    }

    AVFrame *avFrame = CopyAVFrame(frame);
    this->frames.push_back(avFrame);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);

    return true;
}
AVFrame*        AVFrameBuffer::Front            ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->frames.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->frames.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    AVFrame *frame = this->frames.front();

    LeaveCriticalSection(&this->monitorMutex);

    return frame;
}
AVFrame*        AVFrameBuffer::GetFront         ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->frames.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->frames.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    AVFrame *frame = this->frames.front();
    this->frames.pop_front();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);

    return frame;
}
uint32_t        AVFrameBuffer::Length           ()
{
    EnterCriticalSection(&this->monitorMutex);

    uint32_t ret = this->frames.size();

    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
void            AVFrameBuffer::PopFront         ()
{
    EnterCriticalSection(&this->monitorMutex);

    this->frames.pop_front();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
}
void            AVFrameBuffer::SetEOS           (bool value)
{
    EnterCriticalSection(&this->monitorMutex);

    this->eos = value;

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
void            AVFrameBuffer::ClearTail        ()
{
    EnterCriticalSection(&this->monitorMutex);

    int size = this->frames.size() - 1;

    AVFrame* frame = this->frames.front();
    this->frames.pop_front();
    for(int i=0; i < size; i++)
    {
        delete this->frames.front();
        this->frames.pop_front();
    }

    this->frames.push_back(frame);
    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
void            AVFrameBuffer::Clear            ()
{
    EnterCriticalSection(&this->monitorMutex);

    for(size_t i=0; i < this->frames.size(); i++)
    {
        delete this->frames.front();
        this->frames.pop_front();
    }

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
uint32_t        AVFrameBuffer::Capacity         ()
{
    return this->maxcapacity;
}
AVFrame*        AVFrameBuffer::CopyAVFrame      (AVFrame *frame)
{
    PixelFormat pixfmt  = (PixelFormat)frame->format;
    int         h       = frame->height;
    int         w       = frame->width;
    AVFrame *avFrame    = avcodec_alloc_frame();

    int     numBytes    = avpicture_get_size(pixfmt, w, h);
    uint8_t *buffer     = (uint8_t*)av_malloc(numBytes);

    avpicture_fill((AVPicture*)avFrame, buffer, pixfmt, w, h);
    av_picture_copy((AVPicture *)avFrame, (AVPicture *) frame, pixfmt, w, h);

    avFrame->width  = w;
    avFrame->height = h;
    avFrame->format = pixfmt;

    return avFrame;
}