/*
 * DownloadStateManager.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DownloadStateManager.h"

using namespace dash::network;

DownloadStateManager::DownloadStateManager  () :
                     state                  (NOT_STARTED)
{
    InitializeConditionVariable (&this->stateChanged);
    InitializeCriticalSection   (&this->stateLock);
}
DownloadStateManager::~DownloadStateManager ()
{
    DeleteConditionVariable (&this->stateChanged);
    DeleteCriticalSection   (&this->stateLock);
}

DownloadState   DownloadStateManager::State         () const
{
    EnterCriticalSection(&this->stateLock);

    DownloadState ret = this->state;

    LeaveCriticalSection(&this->stateLock);

    return ret;
}
void            DownloadStateManager::State         (DownloadState state)
{
    EnterCriticalSection(&this->stateLock);

    this->state = state;

    this->Notify();
    WakeAllConditionVariable(&this->stateChanged);
    LeaveCriticalSection(&this->stateLock);
}
void            DownloadStateManager::WaitState     (DownloadState state) const
{
    EnterCriticalSection(&this->stateLock);

    while(this->state != state)
        SleepConditionVariableCS(&this->stateChanged, &this->stateLock, INFINITE);

    LeaveCriticalSection(&this->stateLock);
}
void            DownloadStateManager::CheckAndWait  (DownloadState check, DownloadState wait) const
{
    EnterCriticalSection(&this->stateLock);

    if(this->state == check)
        while(this->state != wait)
            SleepConditionVariableCS(&this->stateChanged, &this->stateLock, INFINITE);

    LeaveCriticalSection(&this->stateLock);
}
void            DownloadStateManager::Attach        (IDownloadObserver *observer)
{
    EnterCriticalSection(&this->stateLock);
    this->observers.push_back(observer);
    LeaveCriticalSection(&this->stateLock);
}
void            DownloadStateManager::Detach        (IDownloadObserver *observer)
{
    EnterCriticalSection(&this->stateLock);

    uint32_t pos = -1;

    for(size_t i = 0; i < this->observers.size(); i++)
        if(this->observers.at(i) == observer)
            pos = i;

    if(pos != -1)
        this->observers.erase(this->observers.begin() + pos);

    LeaveCriticalSection(&this->stateLock);
}
void            DownloadStateManager::Notify        ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnDownloadStateChanged(this->state);
}
void            DownloadStateManager::CheckAndSet   (DownloadState check, DownloadState set)
{
    EnterCriticalSection(&this->stateLock);

    if(this->state == check)
        this->state = set;

    LeaveCriticalSection(&this->stateLock);
}
