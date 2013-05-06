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
#include "MultimediaStream.h"
#include "IMultimediaManagerObserver.h"
#include "../libdashframework/Adaptation/IAdaptationLogic.h"
#include "../libdashframework/Adaptation/AdaptationLogicFactory.h"
#include "../Renderer/QTGLRenderer.h"
#include "../Renderer/QTAudioRenderer.h"
#include "../libdashframework/Portable/MultiThreading.h"
#include "../libdashframework/Buffer/AudioChunk.h"
#include <QtMultimedia/qaudiooutput.h>

namespace sampleplayer
{
    namespace managers
    {
        class MultimediaManager : public IStreamObserver
        {
            public:
                MultimediaManager           (renderer::QTGLRenderer *videoElement, renderer::QTAudioRenderer *audioElement);
                virtual ~MultimediaManager  ();

                bool                Init    (const std::string& url);
                void                Start   ();
                void                Stop    ();
                dash::mpd::IMPD*    GetMPD  ();

                bool SetVideoQuality      (dash::mpd::IPeriod* period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);
                bool SetAudioQuality      (dash::mpd::IPeriod* period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);

                bool SetVideoAdaptationLogic    (libdash::framework::adaptation::LogicType type);
                bool SetAudioAdaptationLogic    (libdash::framework::adaptation::LogicType type);

                void AttachManagerObserver  (IMultimediaManagerObserver *observer);

                void SetFrameRate               (double frameRate);

                /* IStreamObserver */
                void OnSegmentDownloaded        ();
                void OnSegmentBufferStateChanged(StreamType type, uint32_t fillstateInPercent);
                void OnVideoBufferStateChanged  (uint32_t fillstateInPercent);
                void OnAudioBufferStateChanged  (uint32_t fillstateInPercent);



            private:
                dash::IDASHManager                                          *manager;
                dash::mpd::IMPD                                             *mpd;
                renderer::QTGLRenderer                                      *videoElement;
                renderer::QTAudioRenderer                                   *audioElement;
                dash::mpd::IPeriod                                          *period;
                dash::mpd::IAdaptationSet                                   *videoAdaptationSet;
                dash::mpd::IRepresentation                                  *videoRepresentation;
                libdash::framework::adaptation::IAdaptationLogic            *videoLogic;
                MultimediaStream                                            *videoStream;
                dash::mpd::IAdaptationSet                                   *audioAdaptationSet;
                dash::mpd::IRepresentation                                  *audioRepresentation;
                libdash::framework::adaptation::IAdaptationLogic            *audioLogic;
                MultimediaStream                                            *audioStream;
                std::vector<IMultimediaManagerObserver *>                   managerObservers;
                bool                                                        isStarted;
                uint64_t                                                    framesDisplayed;
                uint64_t                                                    segmentsDownloaded;
                CRITICAL_SECTION                                            monitorMutex;
                double                                                      frameRate;

                THREAD_HANDLE                                               videoRendererHandle;
                THREAD_HANDLE                                               audioRendererHandle;
                bool                                                        isVideoRendering;
                bool                                                        isAudioRendering;

                /* Threads for Rendering Audio & Video */
                bool            StartVideoRenderingThread   ();
                void            StopVideoRenderingThread    ();
                static void*    RenderVideo                 (void *data);

                bool            StartAudioRenderingThread   ();
                void            StopAudioRenderingThread    ();
                static void*    RenderAudio                 (void *data);

                void    InitVideoRendering  (uint32_t offset);
                void    InitAudioPlayback   (uint32_t offset);
                void    StopVideo           ();
                void    StopAudio           ();

                /* IMultimediaManager Notifiers */
                void NotifyVideoBufferObservers         (uint32_t fillstateInPercent);
                void NotifyVideoSegmentBufferObservers  (uint32_t fillstateInPercent);
                void NotifyAudioBufferObservers         (uint32_t fillstateInPercent);
                void NotifyAudioSegmentBufferObservers  (uint32_t fillstateInPercent);
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_MULTIMEDIAMANAGER_H_ */