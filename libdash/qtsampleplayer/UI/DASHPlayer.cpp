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
#include <iostream>

using namespace libdash::framework::adaptation;
using namespace sampleplayer;
using namespace sampleplayer::renderer;
using namespace sampleplayer::managers;
using namespace dash::mpd;
using namespace std;

DASHPlayer::DASHPlayer  (QtSamplePlayerGui& gui) : 
                        gui(&gui)
{
    this->manager           = CreateDashManager();
    this->videoElement      = gui.GetVideoElement();
    this->multimediaManager = new MultimediaManager(this->videoElement);

    this->multimediaManager->AttachVideoBufferObserver(this);
    this->gui->AddWidgetObserver(this);
    this->OnURLChanged(NULL, this->gui->GetUrl());

    QObject::connect(this, SIGNAL(FillStateChanged(int)), &gui, SLOT(SetBufferFillState(int)));
}
DASHPlayer::~DASHPlayer ()
{
    this->multimediaManager->Stop();
    delete(this->multimediaManager);
    delete(this->videoElement);
}

void DASHPlayer::OnStartButtonPressed   (QtSamplePlayerGui* widget)
{
    this->multimediaManager->Start();
}
void DASHPlayer::OnStopButtonPressed    (QtSamplePlayerGui* widget)
{
    this->multimediaManager->Stop();
}
void DASHPlayer::OnCheckboxChanged      (QtSamplePlayerGui* widget, bool isAutomatic)
{
    if(isAutomatic)
        this->multimediaManager->SetVideoAdaptationLogic(new AlwaysLowestLogic(this->videoAdaptationSet, this->mpd));
    else
        this->multimediaManager->SetVideoAdaptationLogic(new ManualAdaptation(this->videoAdaptationSet, this->mpd));
}
void DASHPlayer::OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
    IAdaptationSet *newAdaptionSet = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(video_adaption);
    IRepresentation* newRepresentation = newAdaptionSet->GetRepresentation().at(video_representation);
    if(this->videoAdaptationSet == newAdaptionSet)
    {
        if(this->videoRepresentation != newRepresentation)
        {
            this->videoRepresentation = newRepresentation;
            this->multimediaManager->SetVideoRepresenation(this->videoRepresentation);
        }
    }
    else
    {
        this->videoAdaptationSet = newAdaptionSet;
        this->multimediaManager->SetVideoAdaptationSet(newAdaptionSet);
    }
}
void DASHPlayer::OnURLChanged           (QtSamplePlayerGui* widget, const std::string& url)
{
    this->mpd = this->manager->Open((char*)url.c_str());
    if(this->mpd != NULL)
    {
        this->gui->SetStatusBar("Successfully parsed MPD at: " + url);
        this->gui->SetGuiFields(this->mpd);

        this->videoAdaptationSet = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0);
        this->videoRepresentation = this->videoAdaptationSet->GetRepresentation().at(0);
        this->multimediaManager->SetVideoAdaptationSet(this->videoAdaptationSet);
        this->multimediaManager->SetVideoAdaptationLogic(new ManualAdaptation(this->videoAdaptationSet, this->mpd));
    }
    else
    {
        this->gui->SetStatusBar("Error parsing mpd at: " + url);
    }
}
void DASHPlayer::OnBufferStateChanged   (uint32_t fillstateInPercent)
{
    emit FillStateChanged(fillstateInPercent);
}