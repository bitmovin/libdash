/*
 * DASHPlayer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHPlayer.h"

using namespace sampleplayer;
using namespace sampleplayer::decoder;
using namespace sampleplayer::input;
using namespace sampleplayer::renderer;
using namespace dash::mpd;
using namespace std;

DASHPlayer::DASHPlayer  (QtSamplePlayerGui& gui) : gui(&gui)
{
    this->manager = CreateDashManager();
    this->mpd = this->manager->Open("http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/BigBuckBunny/bunny_2s_480p_only/bunny_Desktop.mpd");
    this->renderer = new QTGLRenderer(this->gui);

    this->testThread = CreateThreadPortable (RenderVideo, this);

    this->gui->addWidgetObserver(this);
}
DASHPlayer::~DASHPlayer ()
{

}

void DASHPlayer::OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
    stringstream ss;
    ss << "Selected video adaption: " << video_adaption << " video_repr: " << video_representation << " Audio adaption:  " << audio_adaption << " Audio repr: " << audio_representation;
    this->gui->setStatusBar(ss.str());
}
void DASHPlayer::OnURLChanged           (QtSamplePlayerGui* widget, const std::string& url)
{
    if(this->mpd != NULL)
    {
        this->gui->setStatusBar("Gotcha MPD");
        this->gui->setGuiFields(this->mpd);
    }
    else
    {
        this->gui->setStatusBar("Error parsing mpd at: " + url);
    }
}
void DASHPlayer::onVideoDataAvailable   (const uint8_t **data, videoFrameProperties* props)
{
    int w = props->width;
    int h = props->height;

    AVFrame *pFrameRGB  = avcodec_alloc_frame();
    int     numBytes    = avpicture_get_size(PIX_FMT_RGB32, props->width, props->height);
    uint8_t *buffer     = (uint8_t*)malloc(numBytes);

    avpicture_fill((AVPicture*)pFrameRGB, buffer, PIX_FMT_RGB32, props->width, props->height);

    SwsContext *imgConvertCtx = sws_getContext(props->width, props->height, (PixelFormat)props->pxlFmt, w, h, PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);

    sws_scale(imgConvertCtx, data, props->linesize, 0, props->height, pFrameRGB->data, pFrameRGB->linesize);

    QImage image(props->width, props->height, QImage::Format_RGB32);
    int x, y;
    int *src = (int*)pFrameRGB->data[0];
 
    for (y = 0; y < props->height; y++)
    {
        for (x = 0; x < props->width; x++)
        {
            image.setPixel(x, y, src[x] & 0x00ffffff);
        }
        src += props->width;
    }

    this->renderer->setImage(image);
    this->renderer->update();
}
/* Shows how to combine QT and SDL */
void* DASHPlayer::RenderVideo   (void *dashplayer)
{
    DASHPlayer      *player     = (DASHPlayer *) dashplayer;
    DASHReceiver    *receiver   = new DASHReceiver(30, player->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0), player->mpd); // Init a DASHReceiver with a buffer size of 30 Segments

    receiver->Start();

    LibavDecoder *decoder = new LibavDecoder(receiver);

    decoder->attachVideoObserver(player);
    decoder->setFrameRate(24);
    decoder->init();
    
    bool eos = false;

    while(!eos)
    {
        eos = !decoder->decode();
    }

    decoder->stop();
    return NULL;
}
