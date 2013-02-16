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
    this->videoElement      = new QTGLRenderer(this->gui);
    this->multimediaManager = new MultimediaManager(this->videoElement);

    this->multimediaManager->AttachVideoBufferObserver(this);
    this->gui->AddWidgetObserver(this);
    this->OnURLChanged(NULL, this->gui->GetUrl());

    QObject::connect(this, SIGNAL(FillStateChanged(int)), &gui, SLOT(SetBufferFillState(int)));
}
DASHPlayer::~DASHPlayer ()
{
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
void DASHPlayer::OnCheckboxChanged      (QtSamplePlayerGui* widget, bool state)
{
    if(state)
    {
        this->multimediaManager->SetVideoAdaptationLogic(new AlwaysLowestLogic(this->currentAdaptation, this->mpd));
    }
    else
    {
        this->multimediaManager->SetVideoAdaptationLogic(new ManualAdaptation(this->currentAdaptation, this->mpd));
    }
}
void DASHPlayer::OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
    
    IAdaptationSet *newAdaptionSet = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(video_adaption);
    IRepresentation* newRepresentation = newAdaptionSet->GetRepresentation().at(video_representation);
    if(this->currentAdaptation == newAdaptionSet)
    {
        if(this->currentRepresentation != newRepresentation)
        {
            this->currentRepresentation = newRepresentation;
            this->multimediaManager->SetVideoRepresenation(this->currentRepresentation);
        }
    }
    else
    {
        this->currentAdaptation = newAdaptionSet;
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

        this->currentAdaptation = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0);
        this->currentRepresentation = this->currentAdaptation->GetRepresentation().at(0);
        this->multimediaManager->SetVideoAdaptationSet(this->currentAdaptation);
        this->multimediaManager->SetVideoAdaptationLogic(new ManualAdaptation(this->currentAdaptation, this->mpd));
    }
    else
    {
        this->gui->SetStatusBar("Error parsing mpd at: " + url);
    }
}
void DASHPlayer::OnBufferStateChanged   (uint32_t fillstateInPercent)
{
    //cout << "Buffer filled: " << fillstateInPercent << endl;
    emit FillStateChanged(fillstateInPercent);
}