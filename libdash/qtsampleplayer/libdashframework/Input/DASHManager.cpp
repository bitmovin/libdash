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
using namespace libdash::framework::buffer;
using namespace sampleplayer::decoder;

using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHManager::DASHManager        (uint32_t maxCapacity, IDASHManagerObserver* stream, IMPD* mpd) :
             readSegmentCount   (0),
             receiver           (NULL),
             mediaObjectDecoder (NULL),
             multimediaStream   (stream),
             isRunning          (false)
{
    this->buffer    = new MediaObjectBuffer(maxCapacity);
    this->buffer->AttachObserver(this);

    this->receiver  = new DASHReceiver(mpd, this, this->buffer, maxCapacity);
}
DASHManager::~DASHManager       ()
{
    this->Stop();
    delete this->receiver;
    delete this->buffer;

    this->receiver = NULL;
    this->buffer   = NULL;
}

bool        DASHManager::Start                  ()
{
    if (!this->receiver->Start())
        return false;

    if (!this->CreateAVDecoder())
        return false;

    this->isRunning = true;
    return true;
}
void        DASHManager::Stop                   ()
{
    if (!this->isRunning)
        return;

    this->isRunning = false;

    this->receiver->Stop();
    this->mediaObjectDecoder->Stop();
    this->buffer->Clear();
}
uint32_t    DASHManager::GetPosition            ()
{
    return this->receiver->GetPosition();
}
void        DASHManager::SetPosition            (uint32_t segmentNumber)
{
    this->receiver->SetPosition(segmentNumber);
}
void        DASHManager::SetPositionInMsec      (uint32_t milliSecs)
{
    this->receiver->SetPositionInMsecs(milliSecs);
}
void        DASHManager::Clear                  ()
{
    this->buffer->Clear();
}
void        DASHManager::ClearTail              ()
{
    this->buffer->ClearTail();
}
void        DASHManager::SetRepresentation      (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    this->receiver->SetRepresentation(period, adaptationSet, representation);
    //this->buffer->ClearTail();
}
void        DASHManager::EnqueueRepresentation  (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    this->receiver->SetRepresentation(period, adaptationSet, representation);
}
void        DASHManager::OnVideoFrameDecoded    (const uint8_t **data, videoFrameProperties* props)
{
    /* TODO: some error handling here */
    if (data == NULL || props->fireError)
        return;

    int w = props->width;
    int h = props->height;

    AVFrame *rgbframe   = avcodec_alloc_frame();
    int     numBytes    = avpicture_get_size(PIX_FMT_RGB24, w, h);
    uint8_t *buffer     = (uint8_t*)av_malloc(numBytes);

    avpicture_fill((AVPicture*)rgbframe, buffer, PIX_FMT_RGB24, w, h);

    SwsContext *imgConvertCtx = sws_getContext(props->width, props->height, (PixelFormat)props->pxlFmt, w, h, PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);

    sws_scale(imgConvertCtx, data, props->linesize, 0, h, rgbframe->data, rgbframe->linesize);

    QImage *image = new QImage(w, h, QImage::Format_RGB32);
    uint8_t *src = (uint8_t *)rgbframe->data[0];

    for (size_t y = 0; y < h; y++)
    {
        QRgb *scanLine = (QRgb *)image->scanLine(y);

        for (size_t x = 0; x < w; x++)
            scanLine[x] = qRgb(src[3 * x], src[3 * x + 1], src[3 * x + 2]);

        src += rgbframe->linesize[0];
    }

    this->multimediaStream->AddFrame(image);

    av_free(rgbframe);
    av_free(buffer);
}
void        DASHManager::OnAudioSampleDecoded   (const uint8_t **data, audioFrameProperties* props)
{
    /* TODO: some error handling here */
    if (data == NULL || props->fireError)
        return;

    QAudioFormat *format = new QAudioFormat();
    format->setSampleRate(props->sampleRate);
    format->setChannelCount(props->channels);
    format->setSampleSize(16);
    format->setCodec("audio/pcm");
    format->setByteOrder(QAudioFormat::LittleEndian);
    format->setSampleType(QAudioFormat::SignedInt);

    AudioChunk *samples = new AudioChunk(format, (char*)data[0], props->linesize);

    this->multimediaStream->AddSamples(samples);
}
void        DASHManager::OnBufferStateChanged   (uint32_t fillstateInPercent)
{
    this->multimediaStream->OnSegmentBufferStateChanged(fillstateInPercent);
}
void        DASHManager::OnSegmentDownloaded    ()
{
    this->readSegmentCount++;

    // notify observers
}
void        DASHManager::OnDecodingFinished     ()
{
    if (this->isRunning)
        this->CreateAVDecoder();
}
bool        DASHManager::CreateAVDecoder        ()
{
    MediaObject *mediaObject            = this->buffer->GetFront();

    // initSegForMediaObject may be NULL => BaseUrls
    if (!mediaObject)
        return false;

    MediaObject *initSegForMediaObject  = this->receiver->FindInitSegment(mediaObject->GetRepresentation());

    this->mediaObjectDecoder = new MediaObjectDecoder(initSegForMediaObject, mediaObject, this);
    return this->mediaObjectDecoder->Start();
}
