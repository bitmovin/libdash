/*
 * MultimediaStream.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_MANAGERS_MULTIMEDIASTREAM_H_
#define QTSAMPLEPLAYER_MANAGERS_MULTIMEDIASTREAM_H_

#include "IMPD.h"
#include "IStreamObserver.h"
#include "../libdashframework/Adaptation/IAdaptationLogic.h"
#include "../Decoder/IAudioObserver.h"
#include "../Decoder/IVideoObserver.h"

#include <vector>

namespace sampleplayer
{
    namespace managers
    {
        class MultimediaStream : public decoder::IAudioObserver, public decoder::IVideoObserver
        {
            public:
                MultimediaStream            (dash::mpd::IAdaptationSet *adaptationSet, libdash::framework::adaptation::IAdaptationLogic *logic);
                virtual ~MultimediaStream   ();

                bool Start                  ();
                bool Stop                   ();
                void AttachStreamObserver   (IStreamObserver *observer);
                void NotifyVideoObservers   (const QImage& image);

                virtual void OnAudioDataAvailable (const uint8_t **data, decoder::audioFrameProperties* props);
                virtual void OnVideoDataAvailable (const uint8_t **data, decoder::videoFrameProperties* props);

            private:
                std::vector<IStreamObserver *>                      observers;
                dash::mpd::IAdaptationSet                           *adaptationSet;
                libdash::framework::adaptation::IAdaptationLogic    *logic;
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_MULTIMEDIASTREAM_H_ */