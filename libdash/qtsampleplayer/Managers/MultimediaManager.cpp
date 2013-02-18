/*
 * MultimediaManager.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultimediaManager.h"
#include "../libdashframework/Adaptation/ManualAdaptation.h"
#include "../libdashframework/Adaptation/AlwaysLowestLogic.h"

using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;
using namespace sampleplayer::managers;
using namespace sampleplayer::renderer;
using namespace dash::mpd;

#define SEGMENTBUFFER_SIZE 20

MultimediaManager::MultimediaManager    (QTGLRenderer *videoelement) :
                   videoelement         (videoelement),
                   mpd                  (NULL),
                   videoAdaptationSet   (NULL),
                   videoRepresentation  (NULL),
                   videoLogic           (NULL),
                   videoStream          (NULL),
                   run                  (false)
{
    this->manager = CreateDashManager();
}
MultimediaManager::~MultimediaManager   ()
{
    this->Stop();
}

void    MultimediaManager::OnVideoFrameAvailable        (const QImage& image, dash::mpd::IAdaptationSet *adaptationSet)
{
    this->videoelement->setImage(image);
    this->videoelement->update();
}
void    MultimediaManager::OnAudioSampleAvailable       ()
{
}
IMPD*   MultimediaManager::GetMPD                       ()
{
    return this->mpd;
}
bool    MultimediaManager::Init                         (const std::string& url)
{
    this->mpd = this->manager->Open((char *)url.c_str());
    
    if(this->mpd == NULL)
        return false;

    this->videoAdaptationSet = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0);
    this->videoRepresentation = this->videoAdaptationSet->GetRepresentation().at(0);

    return true;
}
void    MultimediaManager::Start                        ()
{
    /* Global Start button for start must be added to interface*/
    if(this->run)
    {
        this->Stop();
    }
    
    this->InitChain(0);

    this->videoStream->Start();
    this->run = true;
}
void    MultimediaManager::Stop                         ()
{
    if(this->run)
    {
        this->videoStream->Stop();
        delete this->videoStream;
        delete this->videoLogic;
        this->videoStream = NULL;
        this->videoLogic = NULL;
    }
    this->run = false;
}
bool    MultimediaManager::SetVideoAdaptationSet        (IAdaptationSet *adaptationSet)
{

    if(this->videoAdaptationSet != adaptationSet)
    {
        this->videoAdaptationSet = adaptationSet;
        if(this->run)
        {
            int position = this->videoLogic->GetPosition();
            this->Stop();
        
            this->InitChain(position);
            this->videoStream->Start();

            this->run = true;
        }
    }
    return true;
}
bool    MultimediaManager::SetAudioAdaptationSet        (IAdaptationSet *adaptationSet)
{
    //MUST NOT BE IMPLEMENTED YET
    return false;
}
bool    MultimediaManager::SetVideoRepresenation        (dash::mpd::IRepresentation *representation)
{
    if(this->run && representation != this->videoRepresentation)
    {
        this->videoStream->Clear();
        this->videoLogic->SetRepresentation(representation);
    }
    this->videoRepresentation = representation;
    return true;
}
bool    MultimediaManager::SetAudioRepresenation        (dash::mpd::IRepresentation *representation)
{
    ///MUST NOT BE IMPLEMENTED YET
    return false;
}
bool    MultimediaManager::SetVideoAdaptationLogic      (libdash::framework::adaptation::LogicType type)
{
    //Currently unused, always using ManualAdaptation.
    return true;
}
bool    MultimediaManager::SetAudioAdaptationLogic      (libdash::framework::adaptation::LogicType type)
{
    /* MUST NOT BE IMPLEMENTED YET */
    return false;
}
void    MultimediaManager::NotifyVideoObservers         ()
{
    /* Notify DASHPLayer onVideoDataAvailable which does the scaling and forwards the frame to the renderer */
}
void    MultimediaManager::NotifyAudioObservers         ()
{
    /* MUST NOT BE IMPLEMENTED YET */
}
void    MultimediaManager::AttachVideoBufferObserver    (IBufferObserver *videoBufferObserver)
{
    this->videoBufferObservers.push_back(videoBufferObserver);
}
void    MultimediaManager::AttachAudioBufferObserver    (IBufferObserver *audioBufferObserver)
{
}
void    MultimediaManager::NotifyVideoBufferObservers   ()
{
}
void    MultimediaManager::NotifyAudioBufferObservers   ()
{
}
void    MultimediaManager::InitChain                    (uint32_t position)
{
    this->videoLogic = new ManualAdaptation(this->videoAdaptationSet, this->mpd);
    this->videoLogic->SetPosition(position);
    this->videoLogic->SetRepresentation(this->videoRepresentation);

    this->videoStream = new MultimediaStream(this->videoAdaptationSet, this->videoLogic, SEGMENTBUFFER_SIZE, 0, 0);
    this->videoStream->AttachStreamObserver(this);

    for(int i=0; i < this->videoBufferObservers.size(); i++)
    {
        this->videoStream->AttachBufferObserver(this->videoBufferObservers.at(i));
    }
}