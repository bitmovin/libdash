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
using namespace libdash::framework::input;
using namespace dash::mpd;

MediaObjectDecoder::MediaObjectDecoder  (MediaObject* initSegment, MediaObject* mediaSegment, IMediaObjectDecoderObserver *observer) :
                    observer            (observer),
                    initSegment         (initSegment),
                    mediaSegment        (mediaSegment),
                    decoderInitialized  (false),
                    initSegmentOffset   (0),
                    threadHandle        (NULL)
{
    this->decoder = new LibavDecoder(this);
    this->decoder->AttachVideoObserver(this);
    this->decoder->AttachAudioObserver(this);
}
MediaObjectDecoder::~MediaObjectDecoder()
{
    delete this->decoder;
    delete this->mediaSegment;
}

bool    MediaObjectDecoder::Start                   ()
{
    if(!decoder->Init())
        return false;

    this->decoderInitialized = true;
    this->threadHandle = CreateThreadPortable (Decode, this);

    if(this->threadHandle == NULL)
        return false;

    this->run = true;

    return true;
}
void    MediaObjectDecoder::Stop                    ()
{
    if (!this->run)
        return;

    this->run = false;

    if (this->threadHandle != NULL)
    {
        JoinThread(this->threadHandle);
        DestroyThreadPortable(this->threadHandle);
    }
}
void    MediaObjectDecoder::OnVideoDataAvailable    (const uint8_t **data, videoFrameProperties* props)
{
    this->observer->OnVideoFrameDecoded(data, props);
}
void    MediaObjectDecoder::OnAudioDataAvailable    (const uint8_t **data, audioFrameProperties* props)
{
    this->observer->OnAudioSampleDecoded(data, props);
}

void*   MediaObjectDecoder::Decode                  (void *data)
{
    MediaObjectDecoder *mediaObjectDecoder = (MediaObjectDecoder *) data;

    while (mediaObjectDecoder->run && mediaObjectDecoder->decoder->Decode());

    if (mediaObjectDecoder->run)
    {
        mediaObjectDecoder->decoder->Flush();
        mediaObjectDecoder->Notify();
    }

    mediaObjectDecoder->decoder->Stop();

    return NULL;
}
int     MediaObjectDecoder::Read                    (uint8_t *buf, int buf_size)
{
    int ret = 0;
    if (!this->decoderInitialized && this->initSegment)
    {
        ret = this->initSegment->Peek(buf, buf_size, this->initSegmentOffset);
        this->initSegmentOffset += (size_t) ret;
    }

    if (ret == 0)
        ret = this->mediaSegment->Read(buf, buf_size);

    return ret;
}
void    MediaObjectDecoder::Notify                  ()
{
    this->observer->OnDecodingFinished();
}
