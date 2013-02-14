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

using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;
using namespace sampleplayer::managers;
using namespace sampleplayer::renderer;
using namespace dash::mpd;

MultimediaManager::MultimediaManager    ()
{
    /* This class manages the download and decocding process
     * Note multiple downloading/decoding threads must be handled in parallel when switching between adaptationsets or when audio and video is separated
     */
}
MultimediaManager::~MultimediaManager   ()
{
}

void MultimediaManager::Start                       ()
{
    /* Global Start button for start must be added to interface*/
}
void MultimediaManager::Stop                        ()
{
    /* Global Stop button for stop must be added to interface*/
}
bool MultimediaManager::SetVideoAdaptationSet       (IAdaptationSet *adaptationSet)
{
    /*Steps:
     * Init new DASHReceiver and decoder 
     * Download Init segment
     * Download segment according to last segment of other adaptationset
     */
    return false;
}
bool MultimediaManager::SetAudioAdaptationSet       (IAdaptationSet *adaptationSet)
{
    /* MUST NOT BE IMPLEMENTED YET */
    return false;
}
bool MultimediaManager::SetVideoAdaptationLogic     (IAdaptationLogic *logic)
{
    /* Set AdaptationLogic of Video DASHReceiver */
    return false;
}
bool MultimediaManager::SetAudioAdaptationLogic     (IAdaptationLogic *logic)
{
    /* MUST NOT BE IMPLEMENTED YET */
    return false;
}
void MultimediaManager::AttachVideoObserver         (IVideoObserver *videoObserver)
{
}
void MultimediaManager::AttachAudioObserver         (IAudioObserver *audioObserver)
{
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
