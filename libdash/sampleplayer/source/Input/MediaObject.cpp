/*
 * MediaObject.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MediaObject.h"

using namespace sampleplayer::input;
using namespace dash::mpd;
using namespace dash::network;

MediaObject::MediaObject    (ISegment *segment, IRepresentation *rep) :
             segment        (segment),
             rep            (rep)
{
    InitializeConditionVariable (&this->stateChanged);
    InitializeCriticalSection   (&this->stateLock);
}
MediaObject::~MediaObject   ()
{
    DeleteConditionVariable (&this->stateChanged);
    DeleteCriticalSection   (&this->stateLock);
}

bool    MediaObject::StartDownload          ()
{
    this->segment->AttachDownloadObserver(this);
    return this->segment->StartDownload();
}
void    MediaObject::WaitFinished           ()
{
    EnterCriticalSection(&this->stateLock);

    while(this->state != COMPLETED && this->state != ABORTED)
        SleepConditionVariableCS(&this->stateChanged, &this->stateLock, INFINITE);

    LeaveCriticalSection(&this->stateLock);
}
void    MediaObject::OnDownloadStateChanged (DownloadState state)
{
    EnterCriticalSection(&this->stateLock);

    this->state = state;

    WakeAllConditionVariable(&this->stateChanged);
    LeaveCriticalSection(&this->stateLock);
}
void    MediaObject::OnDownloadRateChanged  (uint64_t bytesDownloaded)
{
}
int     MediaObject::Read                   (uint8_t *data, size_t len)
{
    return this->segment->Read(data, len);
}
int     MediaObject::Peek                   (uint8_t *data, size_t len)
{
    return this->segment->Peek(data, len);
}