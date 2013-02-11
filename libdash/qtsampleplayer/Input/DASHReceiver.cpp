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

using namespace sampleplayer::input;
using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHReceiver::DASHReceiver  (uint32_t maxcapacity) :
              manager       (NULL),
              mpd           (NULL),
              count         (0),
              maxcapacity   (maxcapacity)
{
    this->buffer    = new MediaObjectBuffer(this->maxcapacity);
    this->manager   = CreateDashManager();
}
DASHReceiver::~DASHReceiver ()
{
    delete(this->manager);
}

bool    DASHReceiver::Init                      (std::string mpdurl)
{
    this->mpd = this->manager->Open((char *)mpdurl.c_str());

    if(this->mpd == NULL)
        return false;

    this->logic = new AdaptationLogic(this->mpd);

    this->bufferingThread = CreateThreadPortable (DoBuffering, this);

    if(this->bufferingThread == NULL)
        return false;

    return true;
}
int     DASHReceiver::IORead                    (uint8_t *buf, int buf_size)
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

    return this->IORead(buf, buf_size);
}

/* Thread that does the buffering of segments */
void*   DASHReceiver::DoBuffering   (void *receiver)
{
    DASHReceiver *dashreceiver = (DASHReceiver *) receiver;

    uint32_t number = 0;

    MediaObject *media = dashreceiver->logic->GetSegment(number);

    while(media != NULL)
    {
        media->StartDownload();
        media->WaitFinished();
        dashreceiver->buffer->Push(media);
        number++;

        media = dashreceiver->logic->GetSegment(number);

        std::cout << "Buffer size in segments: " << dashreceiver->buffer->Length() << std::endl;
    }

    dashreceiver->buffer->SetEOS(true);
    return NULL;
}