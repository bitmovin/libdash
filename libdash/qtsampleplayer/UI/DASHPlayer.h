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
#include "../Managers/MultimediaManager.h"
#include "../libdashframework/Adaptation/AlwaysLowestLogic.h"
#include "../libdashframework/Adaptation/ManualAdaptation.h"
#include "../libdashframework/Buffer/IBufferObserver.h"

namespace sampleplayer
{
    class DASHPlayer : public IDASHPlayerGuiObserver, public libdash::framework::buffer::IBufferObserver
    {
        Q_OBJECT

        public:
            DASHPlayer          (QtSamplePlayerGui& gui);
            virtual ~DASHPlayer ();

            virtual void OnSettingsChanged      (QtSamplePlayerGui* widget, int video_adaption, int video_representation);
            virtual void OnStartButtonPressed   (QtSamplePlayerGui* widget);
            virtual void OnStopButtonPressed    (QtSamplePlayerGui* widget);
            virtual void OnCheckboxChanged      (QtSamplePlayerGui* widget, bool isAutomatic);
            virtual void OnBufferStateChanged   (uint32_t fillstateInPercent);
            virtual void OnDownloadMPDPressed   (const std::string &url);

        private:
            dash::mpd::IMPD                             *mpd;
            sampleplayer::renderer::QTGLRenderer        *videoElement;
            QtSamplePlayerGui                           *gui;
            sampleplayer::managers::MultimediaManager   *multimediaManager;

            void InitMultimediaStreams();

        signals:
            void FillStateChanged(int fillStateInPercent);

    };
}
#endif /* DASHPLAYER_H_ */
