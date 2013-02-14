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

DASHReceiver::DASHReceiver  (uint32_t maxcapacity, IAdaptationLogic* logic) :
              count         (0),
              maxcapacity   (maxcapacity),
              logic         (logic)
{
    this->buffer = new MediaObjectBuffer(this->maxcapacity);
}
DASHReceiver::~DASHReceiver ()
{
    this->Stop();
}
bool    DASHReceiver::Start                 ()
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
void    DASHReceiver::Stop                  ()
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
void    DASHReceiver::AtachBufferObserver   (IBufferObserver* observer)
{
    this->buffer->AttachObserver(observer);
}
int     DASHReceiver::Read                  (uint8_t *buf, int buf_size)
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

    return this->Read(buf, buf_size);
}

/* Thread that does the buffering of segments */
void*   DASHReceiver::DoBuffering   (void *receiver)
{
    DASHReceiver *dashreceiver = (DASHReceiver *) receiver;

    uint32_t number = 0;

    MediaObject *media = dashreceiver->logic->GetSegment(number);

    while(media != NULL && dashreceiver->isDownloading)
    {
        media->StartDownload();
        media->WaitFinished();
        dashreceiver->buffer->Push(media);
        number++;

        media = dashreceiver->logic->GetSegment(number);
    }

    dashreceiver->buffer->SetEOS(true);
    return NULL;
}