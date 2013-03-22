/*
 * DASHManager.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHManager.h"

using namespace libdash::framework::input;
using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;

using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHManager::DASHManager        (uint32_t maxcapacity, IAdaptationLogic* logic) :
              readSegmentCount  (0),
              maxcapacity       (maxcapacity),
              logic             (logic),
              isDownloading     (false),
              bufferingThread   (NULL)
{
    this->buffer = new MediaObjectBuffer(this->maxcapacity);
}
DASHManager::~DASHManager       ()
{
    this->Stop();
}

bool        DASHManager::Start                          ()
{
    if(this->isDownloading)
        return false;

    this->isDownloading     = true;
    this->bufferingThread   = CreateThreadPortable (DoBuffering, this);

    if(this->bufferingThread == NULL)
    {
        this->isDownloading = false;
        return false;
    }

    return true;
}
void        DASHManager::Stop                           ()
{
    if(!this->isDownloading)
        return;

    this->isDownloading = false;
    this->buffer->SetEOS(true);

    if(this->bufferingThread != NULL)
    {
        WaitForSingleObject(this->bufferingThread, INFINITE);
        DestroyThreadPortable(this->bufferingThread);
    }

    this->buffer->Clear();
}
void        DASHManager::AttachBufferObserver           (IBufferObserver* observer)
{
    this->buffer->AttachObserver(observer);
}
void        DASHManager::AttachDownloadObserver         (IDASHReceiverObserver *observer)
{
    this->observers.push_back(observer);
}
int         DASHManager::Read                           (uint8_t *buf, int buf_size)
{
    /* FFMpeg callback that consumes data from the buffer for decoding */
    MediaObject *media = this->buffer->Front();

    if(media == NULL)
        return 0;

    int ret = media->Read(buf, buf_size);

    if(ret == 0)
        this->buffer->PopFront();
    else
        return ret;

    this->readSegmentCount++;
    this->NotifySegmentDecodingStarted();
    return this->Read(buf, buf_size);
}
void        DASHManager::Clear                          ()
{
    this->buffer->ClearTail();
}
uint32_t    DASHManager::GetPosition                    ()
{
    return this->readSegmentCount;
}
void        DASHManager::NotifySegmentDownloaded        ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnSegmentDownloaded();
}
void        DASHManager::NotifySegmentDecodingStarted   ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnSegmentDecodingStarted();
}

/* Thread that does the buffering of segments */
void*   DASHManager::DoBuffering   (void *receiver)
{
    DASHManager *dashmanager = (DASHManager *) receiver;

    MediaObject *media = dashmanager->logic->GetSegment();

    while(media != NULL && dashmanager->isDownloading)
    {
        media->StartDownload();
        
        if (!dashmanager->buffer->PushBack(media))
            return NULL;

        media->WaitFinished();

        dashmanager->NotifySegmentDownloaded();

        media = dashmanager->logic->GetSegment();
    }

    dashmanager->buffer->SetEOS(true);
    return NULL;
}
