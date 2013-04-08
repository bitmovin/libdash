/*
 * MediaObjectDecoder.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MediaObjectDecoder.h"

using namespace sampleplayer::decoder;
using namespace sampleplayer::input;
using namespace sampleplayer::buffer;
using namespace dash::mpd;

MediaObjectDecoder::MediaObjectDecoder  (MediaObject* initSegment, MediaObject* mediaSegment, AVFrameBuffer *frameBuffer, IMediaObjectDecoderObserver *observer) : 
                    observer            (observer),
                    frameBuffer         (frameBuffer),
                    initSegment         (initSegment),
                    mediaSegment        (mediaSegment),
                    decoderInitialized  (false)
{
    this->decoder = new LibavDecoder(this, this);
    this->decoder->setFrameRate(24);
}
MediaObjectDecoder::~MediaObjectDecoder()
{
    //this->Stop();
    delete(this->decoder);
}

bool    MediaObjectDecoder::Start   ()
{
    if(!decoder->init())
        return false;

    this->run = true;
    this->decoderInitialized = true;
    this->threadHandle = CreateThreadPortable (Decode, this);

    if(this->threadHandle == NULL)
        return false;

    return true;
}
void    MediaObjectDecoder::Stop    ()
{
    this->run = false;
    WaitForSingleObject(this->threadHandle, INFINITE);
}
void    MediaObjectDecoder::Notify  ()
{
    this->observer->OnDecodingFinished();
}
int     MediaObjectDecoder::IORead  (uint8_t *buf, int buf_size)
{
    int ret = 0;
    if (!this->decoderInitialized)
        ret = this->initSegment->Read(buf, buf_size);

    if (ret == 0)
        ret = this->mediaSegment->Read(buf, buf_size);

    return ret;
}
void*   MediaObjectDecoder::Decode  (void *data)
{
    MediaObjectDecoder *mediaDecodingThread = (MediaObjectDecoder *) data;

    while(mediaDecodingThread->decoder->decode() && mediaDecodingThread->run);

    mediaDecodingThread->Notify();
    mediaDecodingThread->decoder->stop();

    delete mediaDecodingThread;
    return NULL;
}
void    MediaObjectDecoder::OnVideoFrameAvailable   (AVFrame* frame)
{
    this->frameBuffer->PushBack(frame);
}
