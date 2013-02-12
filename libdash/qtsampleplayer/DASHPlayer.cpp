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

using namespace dash::sampleplayer;
using namespace dash::mpd;
using namespace std;

DASHPlayer::DASHPlayer  (QtSamplePlayerGui& gui) : gui(&gui)
{
    this->manager = CreateDashManager();

    this->gui->addWidgetObserver(this);
}
DASHPlayer::~DASHPlayer ()
{

}

void DASHPlayer::OnSettingsChanged  (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
    stringstream ss;
    ss << "Selected video adaption: " << video_adaption << " video_repr: " << video_representation << " Audio adaption:  " << audio_adaption << " Audio repr: " << audio_representation;
    this->gui->setStatusBar(ss.str());
}
void DASHPlayer::OnURLChanged       (QtSamplePlayerGui* widget, const std::string& url)
 {
    this->mpd = this->manager->Open((char*)url.c_str());
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
