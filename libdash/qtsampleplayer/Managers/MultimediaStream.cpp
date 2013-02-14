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
using namespace dash::mpd;

MultimediaStream::MultimediaStream  (IAdaptationSet *adaptationSet, IAdaptationLogic *logic)
{
}
MultimediaStream::~MultimediaStream ()
{
}

bool MultimediaStream::Start                ()
{
    return false;
}
bool MultimediaStream::Stop                 ()
{
    return false;
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
    int w = props->width;
    int h = props->height;

    AVFrame *rgbframe   = avcodec_alloc_frame();
    int     numBytes    = avpicture_get_size(PIX_FMT_RGB32, props->width, props->height);
    uint8_t *buffer     = (uint8_t*)av_malloc(numBytes);

    avpicture_fill((AVPicture*)rgbframe, buffer, PIX_FMT_RGB32, props->width, props->height);

    SwsContext *imgConvertCtx = sws_getContext(props->width, props->height, (PixelFormat)props->pxlFmt, w, h, PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);

    sws_scale(imgConvertCtx, data, props->linesize, 0, props->height, rgbframe->data, rgbframe->linesize);

    QImage image(props->width, props->height, QImage::Format_RGB32);
    int x, y;
    int *src = (int*)rgbframe->data[0];
 
    for (y = 0; y < props->height; y++)
    {
        for (x = 0; x < props->width; x++)
        {
            image.setPixel(x, y, src[x] & 0x00ffffff);
        }
        src += props->width;
    }

    av_free(rgbframe);
    av_free(buffer);

    this->NotifyVideoObservers(image);
}
void MultimediaStream::AttachStreamObserver (IStreamObserver *observer)
{
    this->observers.push_back(observer);
}
