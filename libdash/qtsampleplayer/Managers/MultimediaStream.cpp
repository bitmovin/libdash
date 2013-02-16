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

MultimediaStream::MultimediaStream  (IAdaptationSet *adaptationSet, IAdaptationLogic *logic, uint32_t bufferSize, uint32_t width, uint32_t height) :
                  adaptationSet     (adaptationSet),
                  logic             (logic),
                  bufferSize        (bufferSize),
                  width             (width),
                  height            (height),
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

void MultimediaStream::Init                 ()
{
    this->receiver          = new DASHReceiver(this->bufferSize, this->logic);
    this->decodingThread    = new DecodingThread(this->receiver, this, this);
}
bool MultimediaStream::Start                ()
{
    if(!receiver->Start())
        return false;

    if(!this->decodingThread->Start())
        return false;

    return true;
}
void MultimediaStream::Stop                 ()
{
    this->StopDownload();
    this->decodingThread->Stop();
}
void MultimediaStream::StopDownload         ()
{
    this->receiver->Stop();
}
void MultimediaStream::Clear                ()
{
    this->receiver->Clear();
}
void MultimediaStream::NotifyVideoObservers (const QImage& image)
{
    for(size_t i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->OnVideoFrameAvailable(image, this->adaptationSet);
}
void MultimediaStream::OnAudioDataAvailable (const uint8_t **data, audioFrameProperties* props)
{
}
void MultimediaStream::OnVideoDataAvailable (const uint8_t **data, videoFrameProperties* props)
{
    /* After first stable version integrate scaling to width height of constructor */
    int w = props->width;
    int h = props->height;

    if(this->width > 0)
        w = this->width;
    if(this->height > 0)
        h = this->height;

    AVFrame *rgbframe   = avcodec_alloc_frame();
    int     numBytes    = avpicture_get_size(PIX_FMT_RGB32, w, h);
    uint8_t *buffer     = (uint8_t*)av_malloc(numBytes);

    avpicture_fill((AVPicture*)rgbframe, buffer, PIX_FMT_RGB32, w, h);

    SwsContext *imgConvertCtx = sws_getContext(props->width, props->height, (PixelFormat)props->pxlFmt, w, h, PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);

    sws_scale(imgConvertCtx, data, props->linesize, 0, h, rgbframe->data, rgbframe->linesize);

    QImage image(w, h, QImage::Format_RGB32);
    int x, y;
    int *src = (int*)rgbframe->data[0];
 
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            image.setPixel(x, y, src[x] & 0x00ffffff);
        }
        src += w;
    }

    this->NotifyVideoObservers(image);

    av_free(rgbframe);
    av_free(buffer);
}
void MultimediaStream::AttachStreamObserver (IStreamObserver *observer)
{
    this->observers.push_back(observer);
}
void MultimediaStream::AttachBufferObserver (libdash::framework::buffer::IBufferObserver *observer)
{
    this->receiver->AtachBufferObserver(observer);
}
