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
#include "../Renderer/QTGLRenderer.h"
#include "../Managers/MultimediaManager.h"
#include "../libdashframework/Adaptation/AlwaysLowestLogic.h"
#include "../libdashframework/Adaptation/ForcedLogic.h"

namespace sampleplayer
{
    class DASHPlayer : public IDASHPlayerGuiObserver
    {
        public:
            DASHPlayer          (QtSamplePlayerGui& gui);
            virtual ~DASHPlayer ();

            virtual void OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation);
            virtual void OnURLChanged           (QtSamplePlayerGui* widget, const std::string& url);
            virtual void OnStartButtonPressed   (QtSamplePlayerGui* widget);
            virtual void OnStopButtonPressed    (QtSamplePlayerGui* widget);
            virtual void OnCheckboxChanged      (QtSamplePlayerGui* widget, bool state);

        private:
            dash::IDASHManager                                  *manager;
            dash::mpd::IMPD                                     *mpd;
            sampleplayer::renderer::QTGLRenderer                *videoElement;
            QtSamplePlayerGui                                   *gui;
            dash::mpd::IAdaptationSet                           *currentAdaptation;
            dash::mpd::IRepresentation                          *currentRepresentation;
            sampleplayer::managers::MultimediaManager           *multimediaManager;

    };
}
#endif /* DASHPLAYER_H_ */
