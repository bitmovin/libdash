/*
 * DASHReceiver.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHReceiver.h"

using namespace libdash::framework::input;
using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;

using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHReceiver::DASHReceiver      (uint32_t maxcapacity, IAdaptationLogic* logic) :
              readSegmentCount  (0),
              maxcapacity       (maxcapacity),
              logic             (logic),
              isDownloading     (false)
{
    this->buffer = new MediaObjectBuffer(this->maxcapacity);
}
DASHReceiver::~DASHReceiver     ()
{
    this->Stop();
}

bool        DASHReceiver::Start                         ()
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
void        DASHReceiver::Stop                          ()
{
    if(!this->isDownloading)
        return;

    this->isDownloading = false;

    if(this->bufferingThread != NULL)
    {
        WaitForSingleObject(this->bufferingThread, INFINITE);
        DestroyThreadPortable(this->bufferingThread);
    }
}
void        DASHReceiver::AttachBufferObserver          (IBufferObserver* observer)
{
    this->buffer->AttachObserver(observer);
}
void        DASHReceiver::AttachDownloadObserver        (IDASHReceiverObserver *observer)
{
    this->observers.push_back(observer);
}
int         DASHReceiver::Read                          (uint8_t *buf, int buf_size)
{
    /* FFMpeg callback that consumes data from the buffer for decoding */
    MediaObject *media = this->buffer->Front();

    if(media == NULL)
        return 0;

    int ret = media->Read(buf, buf_size);

    if(ret == 0)
        this->buffer->Pop();
    else
        return ret;

    this->readSegmentCount++;
    this->NotifySegmentDecodingStarted();
    return this->Read(buf, buf_size);
}
void        DASHReceiver::Clear                         ()
{
    this->buffer->Clear();
}
uint32_t    DASHReceiver::GetPosition                   ()
{
    return this->readSegmentCount;
}
void        DASHReceiver::NotifySegmentDownloaded       ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnSegmentDownloaded();
}
void        DASHReceiver::NotifySegmentDecodingStarted  ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnSegmentDecodingStarted();
}

/* Thread that does the buffering of segments */
void*   DASHReceiver::DoBuffering   (void *receiver)
{
    DASHReceiver *dashreceiver = (DASHReceiver *) receiver;

    MediaObject *media = dashreceiver->logic->GetSegment();

    while(media != NULL && dashreceiver->isDownloading)
    {
        media->StartDownload();
        dashreceiver->buffer->Push(media);
        media->WaitFinished();

        dashreceiver->NotifySegmentDownloaded();

        media = dashreceiver->logic->GetSegment();
    }

    dashreceiver->buffer->SetEOS(true);
    return NULL;
}
