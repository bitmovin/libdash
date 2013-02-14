/*
 * DASHPlayer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DASHPLAYER_H_
#define DASHPLAYER_H_

#include <iostream>
#include <sstream>

#include "libdash.h"
#include "IDASHPlayerGuiObserver.h"
#include "Renderer/QTGLRenderer.h"
#include "Renderer/IVideoObserver.h"
#include "Decoder/LibavDecoder.h"
#include "libdashframework/Input/DASHReceiver.h"
#include "libdashframework/Portable/MultiThreading.h"
#include "libdashframework/Buffer/IBufferObserver.h"
#include "libdashframework/Adaptation/AlwaysLowestLogic.h"

namespace sampleplayer
{
    class DASHPlayer : public IDASHPlayerGuiObserver, public renderer::IVideoObserver, public libdash::framework::buffer::IBufferObserver
    {
        public:
            DASHPlayer          (QtSamplePlayerGui& gui);
            virtual ~DASHPlayer ();

            virtual void OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation);
            virtual void OnURLChanged           (QtSamplePlayerGui* widget, const std::string& url);
            virtual void onVideoDataAvailable   (const uint8_t **data, renderer::videoFrameProperties *props);

        private:
            dash::IDASHManager                      *manager;
            dash::mpd::IMPD                         *mpd;
            sampleplayer::renderer::QTGLRenderer    *renderer;
            QtSamplePlayerGui                       *gui;
            THREAD_HANDLE                           testThread;
            dash::mpd::IAdaptationSet               *currentAdaptation;
            dash::mpd::IRepresentation              *currentRepresentation;
            bool                                    run;

            static void* RenderVideo (void *dashplayer);

    };
}
#endif /* DASHPLAYER_H_ */
