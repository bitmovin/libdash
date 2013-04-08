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

using namespace sampleplayer::input;
using namespace sampleplayer::buffer;
using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHManager::DASHManager        (AVFrameBuffer *frameBuffer, uint32_t maxcapacity, IMPD *mpd) :
             frameBuffer        (frameBuffer),
             readSegmentCount   (0),
             maxcapacity        (maxcapacity),
             logic              (logic),
             isDownloading      (false),
             bufferingThread    (NULL)
{
    this->buffer = new MediaObjectBuffer(this->maxcapacity);
    this->logic  = new AdaptationLogic(mpd);
}
DASHManager::~DASHManager       ()
{
    this->Stop();
}

bool        DASHManager::Start              ()
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
void        DASHManager::Stop               ()
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

    //this->buffer->Clear();
}
void        DASHManager::Clear              ()
{
    this->buffer->ClearTail();
}
uint32_t    DASHManager::GetPosition        ()
{
    return this->readSegmentCount;
}
void        DASHManager::OnDecodingFinished ()
{
    if (this->mediaObjectDecoder)
        this->mediaObjectDecoder->Stop();

    this->initSegment = this->logic->GetInitSegment();
    this->initSegment->StartDownload();
    this->initSegment->WaitFinished();

    this->CreateAVDecoder();
}

/* Thread that does the buffering of segments */
void*   DASHManager::DoBuffering   (void *receiver)
{
    DASHManager *dashmanager = (DASHManager *) receiver;

    /* Get InitSegment and download it right away */
    dashmanager->initSegment = dashmanager->logic->GetInitSegment();
    dashmanager->initSegment->StartDownload();
    dashmanager->initSegment->WaitFinished();
    dashmanager->readSegmentCount++;

    MediaObject *media = dashmanager->logic->GetSegment(dashmanager->readSegmentCount);

    while(media != NULL && dashmanager->isDownloading)
    {
        media->StartDownload();

        if (!dashmanager->buffer->PushBack(media))
            return NULL;

        media->WaitFinished();
        dashmanager->readSegmentCount++;

        if (dashmanager->readSegmentCount == 2)
            dashmanager->CreateAVDecoder();

        media = dashmanager->logic->GetSegment(dashmanager->readSegmentCount);
    }

    dashmanager->buffer->SetEOS(true);
    return NULL;
}
bool    DASHManager::CreateAVDecoder    ()
{
    this->mediaObjectDecoder = new MediaObjectDecoder(this->initSegment, this->buffer->GetFront(), this->frameBuffer, this);
    return this->mediaObjectDecoder->Start();
}
