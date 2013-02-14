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

using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;
using namespace libdash::framework::input;

using namespace sampleplayer;
using namespace sampleplayer::decoder;
using namespace sampleplayer::renderer;
using namespace dash::mpd;
using namespace std;

DASHPlayer::DASHPlayer  (QtSamplePlayerGui& gui) : gui(&gui)
{
    this->manager = CreateDashManager();
    this->testThread = NULL;
    this->renderer = new QTGLRenderer(this->gui);
    this->gui->AddWidgetObserver(this);
    this->OnURLChanged(NULL, this->gui->GetUrl());
    
}
DASHPlayer::~DASHPlayer ()
{

}

void DASHPlayer::OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
    this->gui->SetStatusBar("Switching representation...");
    if(this->testThread != NULL)
    {
        this->run = false;
        WaitForSingleObject(this->testThread, INFINITE);
        DestroyThreadPortable(this->testThread);
    }
    this->currentAdaptation = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(video_adaption);
    this->currentRepresentation = this->currentAdaptation->GetRepresentation().at(video_representation);

    this->run = true;
    this->testThread = CreateThreadPortable (RenderVideo, this);

    this->gui->SetStatusBar("Successfully switched representation");
}
void DASHPlayer::OnURLChanged           (QtSamplePlayerGui* widget, const std::string& url)
{
    if(this->testThread != NULL)
    {
        this->run = false;
        WaitForSingleObject(this->testThread, INFINITE);
        DestroyThreadPortable(this->testThread);
    }

    this->mpd = this->manager->Open((char*)url.c_str());

    if(this->mpd != NULL)
    {
        this->gui->SetStatusBar("Successfully parsed MPD at: " + url);
        this->gui->SetGuiFields(this->mpd);

        this->currentAdaptation = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0);
        this->currentRepresentation = this->currentAdaptation->GetRepresentation().at(0);

        this->run = true;
        this->testThread = CreateThreadPortable (RenderVideo, this);
    }
    else
    {
        this->gui->SetStatusBar("Error parsing mpd at: " + url);
    }
}
void DASHPlayer::onVideoDataAvailable   (const uint8_t **data, videoFrameProperties* props)
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

    this->renderer->setImage(image);
    this->renderer->update();
}

/* Shows how to combine QT and SDL */
void* DASHPlayer::RenderVideo   (void *dashplayer)
{
    DASHPlayer          *player     = (DASHPlayer *) dashplayer;
    AlwaysLowestLogic   *logic      = new AlwaysLowestLogic(player->currentAdaptation, player->mpd);
    DASHReceiver        *receiver   = new DASHReceiver(30, logic);


    receiver->AtachBufferObserver(player);
    player->gui->SetBufferFillState(0);
    receiver->Start();

    LibavDecoder *decoder = new LibavDecoder(receiver);

    decoder->AttachVideoObserver(player);
    decoder->SetFrameRate(24);
    decoder->Init();
    
    bool eos = false;

    while(!eos && player->run)
    {
        eos = !decoder->Decode();
    }

    decoder->Stop();
    receiver->Stop();

    delete decoder;
    delete receiver;

    return NULL;
}