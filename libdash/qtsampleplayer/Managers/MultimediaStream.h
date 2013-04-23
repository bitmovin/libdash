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
#include "../libdashframework/Input/DASHManager.h"
#include "../libdashframework/Buffer/IBufferObserver.h"
#include "../libdashframework/Adaptation/IAdaptationLogic.h"
#include <QtMultimedia/qaudioformat.h>
#include "../libdashframework/Input/IDASHManagerObserver.h"
#include "../libdashframework/Buffer/AudioChunkBuffer.h"

namespace sampleplayer
{
    namespace managers
    {
        class MultimediaStream : public libdash::framework::input::IDASHManagerObserver
        {
            public:
                MultimediaStream            (dash::mpd::IMPD *mpd, uint32_t segmentBufferSize, uint32_t frameBufferSize, uint32_t sampleBufferSize);
                virtual ~MultimediaStream   ();

                bool        Start                   ();
                void        Stop                    ();
                void        StopDownload            ();
                bool        StartDownload           ();
                void        Clear                   ();
                uint32_t    GetPosition             ();
                void        SetPosition             (uint32_t segmentNumber);
                void        SetPositionInMsec       (uint32_t milliSecs);

                void        AddFrame                (QImage *frame);
                QImage*     GetFrame                ();

                void                                    AddSamples  (libdash::framework::buffer::AudioChunk* samples);
                libdash::framework::buffer::AudioChunk* GetSamples  ();

                //void        AddSubtitle             ();
                //SubtitleObj* GetSubtitle              ();

                void        SetRepresentation       (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);
                void        EnqueueRepresentation   (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);
                void        SetAdaptationLogic      (libdash::framework::adaptation::IAdaptationLogic *logic);

                void        AttachStreamObserver    (IStreamObserver *observer);
                void        AttachBufferObserver    (libdash::framework::buffer::IBufferObserver *observer);
                void        NotifyVideoObservers    (const QImage& image);
                void        NotifyAudioObservers    (const QAudioFormat& format, const char *data, qint64 len);

            private:
                std::vector<IStreamObserver *>                      observers;
                dash::mpd::IMPD                                     *mpd;
                libdash::framework::adaptation::IAdaptationLogic    *logic;
                libdash::framework::input::DASHManager              *dashManager;
                libdash::framework::buffer::QImageBuffer            *frameBuffer;
                libdash::framework::buffer::AudioChunkBuffer        *sampleBuffer;
                // subtitle buffer
                uint32_t                                            segmentBufferSize;
                uint32_t                                            frameBufferSize;
                uint32_t                                            sampleBufferSize;

                void Init ();
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_MULTIMEDIASTREAM_H_ */
