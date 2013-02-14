/*
 * MultimediaManager.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_MANAGERS_MULTIMEDIAMANAGER_H_
#define QTSAMPLEPLAYER_MANAGERS_MULTIMEDIAMANAGER_H_

#include "IMPD.h"
#include "../libdashframework/Adaptation/IAdaptationLogic.h"
#include "../libdashframework/Buffer/IBufferObserver.h"
#include "../Renderer/IAudioObserver.h"
#include "../Renderer/IVideoObserver.h"

namespace sampleplayer
{
    namespace managers
    {
        class MultimediaManager
        {
            public:
                MultimediaManager           ();
                virtual ~MultimediaManager  ();

                void Start  ();
                void Stop   ();

                bool SetVideoAdaptationSet      (dash::mpd::IAdaptationSet *adaptationSet);
                bool SetAudioAdaptationSet      (dash::mpd::IAdaptationSet *adaptationSet);

                bool SetVideoAdaptationLogic    (libdash::framework::adaptation::IAdaptationLogic *logic);
                bool SetAudioAdaptationLogic    (libdash::framework::adaptation::IAdaptationLogic *logic);

                void AttachVideoObserver        (renderer::IVideoObserver *videoObserver);
                void AttachAudioObserver        (renderer::IAudioObserver *audioObserver);

                void AttachVideoBufferObserver  (libdash::framework::buffer::IBufferObserver *videoBufferObserver);
                void AttachAudioBufferObserver  (libdash::framework::buffer::IBufferObserver *audioBufferObserver);

                void NotifyVideoObservers       ();
                void NotifyAudioObservers       ();

                void NotifyVideoBufferObservers ();
                void NotifyAudioBufferObservers ();
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_MULTIMEDIAMANAGER_H_ */