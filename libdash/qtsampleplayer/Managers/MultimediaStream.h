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
#include "../libdashframework/Buffer/Buffer.h"
#include "../libdashframework/Buffer/AudioChunk.h"
#include <QImage>

namespace sampleplayer
{
    namespace managers
    {
        class MultimediaStream : public libdash::framework::input::IDASHManagerObserver, public libdash::framework::buffer::IBufferObserver
        {
            public:
                MultimediaStream            (StreamType type, dash::mpd::IMPD *mpd, uint32_t segmentBufferSize, uint32_t frameBufferSize, uint32_t sampleBufferSize);
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

                void        OnSegmentBufferStateChanged (uint32_t fillstateInPercent);
                void        OnBufferStateChanged   (libdash::framework::buffer::BufferType type, uint32_t fillstateInPercent);

            private:
                std::vector<IStreamObserver *>                      observers;
                dash::mpd::IMPD                                     *mpd;
                libdash::framework::adaptation::IAdaptationLogic    *logic;
                libdash::framework::input::DASHManager              *dashManager;
                libdash::framework::buffer::Buffer<QImage>          *frameBuffer;
                libdash::framework::buffer::Buffer<libdash::framework::buffer::AudioChunk> *sampleBuffer;
                // subtitle buffer
                uint32_t                                            segmentBufferSize;
                uint32_t                                            frameBufferSize;
                uint32_t                                            sampleBufferSize;
                StreamType                                          type;

                void Init ();
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_MULTIMEDIASTREAM_H_ */
