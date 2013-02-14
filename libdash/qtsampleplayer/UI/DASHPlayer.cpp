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
    delete(this->renderer);
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

/* Shows how to combine QT and SDL */
void* DASHPlayer::RenderVideo   (void *dashplayer)
{
    DASHPlayer          *player     = (DASHPlayer *) dashplayer;
    AlwaysLowestLogic   *logic      = new AlwaysLowestLogic(player->currentAdaptation, player->mpd);
    DASHReceiver        *receiver   = new DASHReceiver(30, logic);

    player->gui->SetBufferFillState(0);
    receiver->Start();

    LibavDecoder *decoder = new LibavDecoder(receiver);

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