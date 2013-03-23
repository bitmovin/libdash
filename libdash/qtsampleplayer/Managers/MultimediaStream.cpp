/*
 * MultimediaStream.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultimediaStream.h"

using namespace sampleplayer::managers;
using namespace sampleplayer::decoder;
using namespace libdash::framework::adaptation;
using namespace libdash::framework::input;
using namespace dash::mpd;

MultimediaStream::MultimediaStream  (IAdaptationSet *adaptationSet, IAdaptationLogic *logic, uint32_t bufferSize) :
                  adaptationSet     (adaptationSet),
                  logic             (logic),
                  bufferSize        (bufferSize),
                  receiver          (NULL),
                  decodingThread    (NULL)
{
    this->Init();
}
MultimediaStream::~MultimediaStream ()
{
    this->Stop();
    delete(this->decodingThread);
    delete(this->receiver);
}

uint32_t    MultimediaStream::GetPosition               ()
{
    return this->receiver->GetPosition();
}
void        MultimediaStream::Init                      ()
{
    this->receiver          = new DASHManager(this->bufferSize, this->logic);
    this->decodingThread    = new DecodingThread(this->receiver, this, this);

    this->receiver->AttachDownloadObserver(this);
}
bool        MultimediaStream::Start                     ()
{
    if(!this->StartDownload())
        return false;

    if(!this->StartDecoding())
        return false;

    return true;
}
bool        MultimediaStream::StartDecoding             ()
{
    if(!this->decodingThread->Start())
        return false;

    return true;
}
bool        MultimediaStream::StartDownload             ()
{
    if(!receiver->Start())
        return false;

    return true;
}
void        MultimediaStream::Stop                      ()
{
    this->StopDownload();
    this->decodingThread->Stop();
}
void        MultimediaStream::StopDownload              ()
{
    this->receiver->Stop();
}
void        MultimediaStream::Clear                     ()
{
    this->receiver->Clear();
}
void        MultimediaStream::NotifyVideoObservers      (const QImage &image)
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnVideoFrameAvailable(image, this->adaptationSet);
}
void        MultimediaStream::NotifyAudioObservers      (const QAudioFormat &format, const char *data, qint64 len)
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnAudioSampleAvailable(format, data, len);
}
void        MultimediaStream::OnAudioDataAvailable      (const uint8_t **data, audioFrameProperties *props)
{
    QAudioFormat format;
    format.setSampleRate(props->sampleRate);
    format.setChannelCount(props->channels);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    this->NotifyAudioObservers(format, (char*)data[0], props->linesize);
}
void        MultimediaStream::OnVideoDataAvailable      (const uint8_t **data, videoFrameProperties *props)
{
    int w = props->width;
    int h = props->height;

    AVFrame *rgbframe   = avcodec_alloc_frame();
    int     numBytes    = avpicture_get_size(PIX_FMT_RGB24, w, h);
    uint8_t *buffer     = (uint8_t*)av_malloc(numBytes);

    avpicture_fill((AVPicture*)rgbframe, buffer, PIX_FMT_RGB24, w, h);

    SwsContext *imgConvertCtx = sws_getContext(props->width, props->height, (PixelFormat)props->pxlFmt, w, h, PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);

    sws_scale(imgConvertCtx, data, props->linesize, 0, h, rgbframe->data, rgbframe->linesize);

    QImage image(w, h, QImage::Format_RGB32);
    uint8_t *src = (uint8_t *)rgbframe->data[0];

    for (size_t y = 0; y < h; y++)
    {
        QRgb *scanLine = (QRgb *)image.scanLine(y);

        for (size_t x = 0; x < w; x++)
            scanLine[x] = qRgb(src[3 * x], src[3 * x + 1], src[3 * x + 2]);

        src += rgbframe->linesize[0];
    }

    this->NotifyVideoObservers(image);

    av_free(rgbframe);
    av_free(buffer);
}
void        MultimediaStream::AttachStreamObserver      (IStreamObserver *observer)
{
    this->observers.push_back(observer);
}
void        MultimediaStream::AttachBufferObserver      (libdash::framework::buffer::IBufferObserver *observer)
{
    this->receiver->AttachBufferObserver(observer);
}
void        MultimediaStream::OnSegmentDecodingStarted  ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnVideoSegmentDecodingStarted();
}
void        MultimediaStream::OnSegmentDownloaded       ()
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnVideoSegmentDownloaded();
}
