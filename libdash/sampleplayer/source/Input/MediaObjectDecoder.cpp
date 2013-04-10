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
using namespace sampleplayer::helpers;

MediaObjectDecoder::MediaObjectDecoder  (MediaObject* initSegment, MediaObject* mediaSegment, AVFrameBuffer *frameBuffer, IMediaObjectDecoderObserver *observer) : 
                    observer            (observer),
                    frameBuffer         (frameBuffer),
                    initSegment         (initSegment),
                    mediaSegment        (mediaSegment),
                    decoderInitialized  (false),
                    initSegmentOffset   (0)
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
    Timing::AddTiming(new TimingObject("AV Decoder started (before decoder->init())"));

    if(!decoder->init())
        return false;

    Timing::AddTiming(new TimingObject("after decoder->init()"));

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
    {
        ret = this->initSegment->Peek(buf, buf_size, this->initSegmentOffset);
        this->initSegmentOffset += (size_t) ret;
    }

    if (ret == 0) 
    {
        ret = this->mediaSegment->Read(buf, buf_size);
        Timing::AddTiming(new TimingObject("  ## IOREAD Media Segment read..."));
    }

    return ret;
}
void*   MediaObjectDecoder::Decode  (void *data)
{

    Timing::AddTiming(new TimingObject("  AV Decoder Decode thread started..."));

    MediaObjectDecoder *mediaDecodingThread = (MediaObjectDecoder *) data;

    while(mediaDecodingThread->decoder->decode() && mediaDecodingThread->run);

    Timing::AddTiming(new TimingObject("    AV Decoder finished decoding (before notify())..."));

    mediaDecodingThread->Notify();

    mediaDecodingThread->decoder->stop();

    Timing::AddTiming(new TimingObject("  AV Decoder Decode thread before deletion"));

    delete mediaDecodingThread;
    return NULL;
}
void    MediaObjectDecoder::OnVideoFrameAvailable   (AVFrame* frame)
{
    this->frameBuffer->PushBack(frame);
}
