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
using namespace sampleplayer;
using namespace sampleplayer::renderer;
using namespace sampleplayer::managers;
using namespace dash::mpd;
using namespace std;

DASHPlayer::DASHPlayer  (QtSamplePlayerGui& gui) : gui(&gui)
{
    this->manager           = CreateDashManager();
    this->videoElement      = new QTGLRenderer(this->gui);
    this->multimediaManager = new MultimediaManager(this->videoElement);

    this->gui->AddWidgetObserver(this);
    this->OnURLChanged(NULL, this->gui->GetUrl());
    
}
DASHPlayer::~DASHPlayer ()
{
    delete(this->videoElement);
}

void DASHPlayer::OnStartButtonPressed   (QtSamplePlayerGui* widget, const std::string& url)
{
    this->mpd = this->manager->Open((char*)url.c_str());

    if(this->mpd != NULL)
    {
        this->gui->SetStatusBar("Successfully parsed MPD at: " + url);

        this->currentAdaptation = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0);
        this->currentRepresentation = this->currentAdaptation->GetRepresentation().at(0);

        this->multimediaManager->SetVideoAdaptationSet(this->currentAdaptation);
        this->multimediaManager->SetVideoAdaptationLogic(new AlwaysLowestLogic(this->currentAdaptation, this->mpd));
        this->multimediaManager->Start();
    }
    else
    {
        this->gui->SetStatusBar("Error parsing mpd at: " + url);
    }
}
void DASHPlayer::OnStopButtonPressed    (QtSamplePlayerGui* widget)
{
}
void DASHPlayer::OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
}
void DASHPlayer::OnURLChanged           (QtSamplePlayerGui* widget, const std::string& url)
{

}