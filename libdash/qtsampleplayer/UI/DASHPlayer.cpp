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

DASHPlayer::DASHPlayer  (QtSamplePlayerGui &gui) :
            gui         (&gui)
{
    this->videoElement      = gui.GetVideoElement();
    this->audioElement      = new QTAudioRenderer(&gui);
    this->multimediaManager = new MultimediaManager(this->videoElement, this->audioElement);

    this->multimediaManager->AttachVideoBufferObserver(this);
    this->gui->AddWidgetObserver(this);

    QObject::connect(this, SIGNAL(FillStateChanged(int)), &gui, SLOT(SetBufferFillState(int)));
}
DASHPlayer::~DASHPlayer ()
{
    this->multimediaManager->Stop();
    this->audioElement->StopPlayback();
    this->audioElement = NULL;

    delete(this->multimediaManager);
    delete(this->audioElement);
}

void DASHPlayer::OnStartButtonPressed   (int period, int videoAdaptationSet, int videoRepresentation)
{
    std::string url = this->gui->GetUrl();
    if(!this->multimediaManager->Init(url))
    {
        this->gui->SetStatusBar("Error parsing mpd at: " + url);
        return; // TODO dialog or symbol that indicates that error
    }

    this->gui->SetStatusBar("Successfully parsed MPD at: " + url);

    this->OnSettingsChanged(period, videoAdaptationSet, videoRepresentation);
    this->multimediaManager->Start();
}
void DASHPlayer::OnStopButtonPressed    ()
{
    this->multimediaManager->Stop();
}
void DASHPlayer::OnSettingsChanged      (int period, int videoAdaptationSet, int videoRepresentation)
{
    if(this->multimediaManager->GetMPD() == NULL)
        return; // TODO dialog or symbol that indicates that error

    IPeriod *currentPeriod = this->multimediaManager->GetMPD()->GetPeriods().at(period);

    this->multimediaManager->SetVideoQuality(currentPeriod,
                                             currentPeriod->GetAdaptationSets().at(videoAdaptationSet),
                                             currentPeriod->GetAdaptationSets().at(videoAdaptationSet)->GetRepresentation().at(videoRepresentation));
}
void DASHPlayer::OnBufferStateChanged   (uint32_t fillstateInPercent)
{
    emit FillStateChanged(fillstateInPercent);
}
void DASHPlayer::OnDownloadMPDPressed   (const std::string &url)
{
    if(!this->multimediaManager->Init(url))
    {
        this->gui->SetStatusBar("Error parsing mpd at: " + url);
        return; // TODO dialog or symbol that indicates that error
    }

    this->gui->SetStatusBar("Successfully parsed MPD at: " + url);
    this->gui->SetGuiFields(this->multimediaManager->GetMPD());
}
