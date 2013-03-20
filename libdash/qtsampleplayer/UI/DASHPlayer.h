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
#include <QObject.h>
#include "libdash.h"
#include "IDASHPlayerGuiObserver.h"
#include "../Renderer/QTGLRenderer.h"
#include "../Renderer/QTAudioRenderer.h"
#include "../Managers/MultimediaManager.h"
#include "../libdashframework/Adaptation/AlwaysLowestLogic.h"
#include "../libdashframework/Adaptation/ManualAdaptation.h"
#include "../libdashframework/Buffer/IBufferObserver.h"
#include "../libdashframework/MPD/AdaptationSetHelper.h"

namespace sampleplayer
{
    class DASHPlayer : public IDASHPlayerGuiObserver, public libdash::framework::buffer::IBufferObserver
    {
        Q_OBJECT

        public:
            DASHPlayer          (QtSamplePlayerGui& gui);
            virtual ~DASHPlayer ();

            virtual void OnSettingsChanged      (int period, int videoAdaptationSet, int videoRepresentation, int audioAdaptationSet, int audioRepresentation);
            virtual void OnStartButtonPressed   (int period, int videoAdaptationSet, int videoRepresentation, int audioAdaptationSet, int audioRepresentation);
            virtual void OnStopButtonPressed    ();
            virtual void OnBufferStateChanged   (uint32_t fillstateInPercent);
            virtual void OnDownloadMPDPressed   (const std::string &url);

        private:
            dash::mpd::IMPD                             *mpd;
            sampleplayer::renderer::QTGLRenderer        *videoElement;
            sampleplayer::renderer::QTAudioRenderer     *audioElement;
            QtSamplePlayerGui                           *gui;
            sampleplayer::managers::MultimediaManager   *multimediaManager;

        signals:
            void FillStateChanged(int fillStateInPercent);

    };
}
#endif /* DASHPLAYER_H_ */
