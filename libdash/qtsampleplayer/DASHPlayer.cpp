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
    this->renderer->update();
}
/* Shows how to combine QT and SDL */
void* DASHPlayer::RenderVideo   (void *dashplayer)
{
    DASHPlayer      *player     = (DASHPlayer *) dashplayer;
    DASHReceiver    *receiver   = new DASHReceiver(30, player->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0), player->mpd); // Init a DASHReceiver with a buffer size of 30 Segments

    receiver->Init("http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/BigBuckBunny/bunny_2s_480p_only/bunny_Desktop.mpd");

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
