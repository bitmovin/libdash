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
                   videoAdaptationSet   (NULL),
                   videoLogic           (NULL),
                   stream               (NULL),
                   run                  (false)
{
    /* This class manages the download and decocding process
     * Note multiple downloading/decoding threads must be handled in parallel when switching between adaptationsets or when audio and video is separated
     */
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
void MultimediaManager::Start                       ()
{
    /* Global Start button for start must be added to interface*/
    if(this->stream != NULL)
    {
        if(this->run)
        {
            this->stream->Stop();
        }
        delete this->stream;    
    }
    this->stream = new MultimediaStream(this->videoAdaptationSet, this->videoLogic, 20, 0, 0);
    this->stream->AttachStreamObserver(this);

    for(int i=0; i < this->videoBufferObserver.size(); i++)
    {
        this->stream->AttachBufferObserver(this->videoBufferObserver.at(i));
    }

    this->stream->Start();
    this->run = true;
}
void MultimediaManager::Stop                        ()
{
    this->stream->Stop();
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
    this->stream->Clear();
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
    this->videoBufferObserver.push_back(videoBufferObserver);
    if(this->stream != NULL)
    {
        this->stream->AttachBufferObserver(videoBufferObserver);
    }
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
