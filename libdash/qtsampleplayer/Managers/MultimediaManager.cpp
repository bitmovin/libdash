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

MultimediaManager::MultimediaManager    (QTGLRenderer *videoelement) :
                   videoelement         (videoelement),
                   mpd                  (NULL),
                   videoAdaptationSet   (NULL),
                   videoLogic           (NULL),
                   videoStream          (NULL),
                   run                  (false)
{
    this->manager = CreateDashManager();
}
MultimediaManager::~MultimediaManager   ()
{
}

void MultimediaManager::OnVideoFrameAvailable       (const QImage& image, dash::mpd::IAdaptationSet *adaptationSet)
{
    this->videoelement->setImage(image);
    this->videoelement->update();
}
void MultimediaManager::OnAudioSampleAvailable      ()
{
}
bool MultimediaManager::Init                        (const std::string& url)
{
    this->mpd = this->manager->Open((char*)url.c_str());
    
    if(this->mpd == NULL)
        return false;

    return true;
}
void MultimediaManager::Start                       ()
{
    /* Global Start button for start must be added to interface*/
    if(this->videoStream != NULL)
    {
        if(this->run)
        {
            this->videoStream->Stop();
        }
        delete this->videoStream;
    }
    this->videoLogic->SetPosition(0);
    this->videoStream = new MultimediaStream(this->videoAdaptationSet, this->videoLogic, 20, 0, 0);
    this->videoStream->AttachStreamObserver(this);

    for(int i=0; i < this->videoBufferObservers.size(); i++)
    {
        this->videoStream->AttachBufferObserver(this->videoBufferObservers.at(i));
    }

    this->videoStream->Start();
    this->run = true;
}
void MultimediaManager::Stop                        ()
{
    if(this->videoStream)
        this->videoStream->Stop();

    this->run = false;
}
bool MultimediaManager::SetVideoAdaptationSet       (IAdaptationSet *adaptationSet)
{
    //Steps:
     // Init new DASHReceiver and decoder 
     // Download Init segment
     // Download segment according to last segment of other adaptationset
     
    this->videoAdaptationSet = adaptationSet;
    return true;
}
bool MultimediaManager::SetAudioAdaptationSet       (IAdaptationSet *adaptationSet)
{
    //MUST NOT BE IMPLEMENTED YET
    return false;
}
bool MultimediaManager::SetVideoRepresenation       (dash::mpd::IRepresentation *representation)
{
    this->videoStream->Clear();
    this->videoLogic->SetRepresentation(representation);

    return true;
}
bool MultimediaManager::SetAudioRepresenation       (dash::mpd::IRepresentation *representation)
{
    ///MUST NOT BE IMPLEMENTED YET
    return false;
}
bool MultimediaManager::SetVideoAdaptationLogic     (IAdaptationLogic *logic)
{
    this->videoLogic = logic;
    return true;
}
bool MultimediaManager::SetAudioAdaptationLogic     (IAdaptationLogic *logic)
{
    /* MUST NOT BE IMPLEMENTED YET */
    return false;
}
void MultimediaManager::NotifyVideoObservers        ()
{
    /* Notify DASHPLayer onVideoDataAvailable which does the scaling and forwards the frame to the renderer */
}
void MultimediaManager::NotifyAudioObservers        ()
{
    /* MUST NOT BE IMPLEMENTED YET */
}
void MultimediaManager::AttachVideoBufferObserver   (IBufferObserver *videoBufferObserver)
{
    this->videoBufferObservers.push_back(videoBufferObserver);
}
void MultimediaManager::AttachAudioBufferObserver   (IBufferObserver *audioBufferObserver)
{
}
void MultimediaManager::NotifyVideoBufferObservers  ()
{
}
void MultimediaManager::NotifyAudioBufferObservers  ()
{
}
