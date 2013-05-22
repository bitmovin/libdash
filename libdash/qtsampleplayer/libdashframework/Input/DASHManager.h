/*
 * DASHManager.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_DASHMANAGER_H_
#define LIBDASH_FRAMEWORK_INPUT_DASHMANAGER_H_

#include "../Buffer/MediaObjectBuffer.h"
#include "DASHReceiver.h"
#include "../../Decoder/IVideoObserver.h"
#include "IDASHReceiverObserver.h"
#include "IMediaObjectDecoderObserver.h"
#include "MediaObjectDecoder.h"
#include "libdash.h"
#include "IMPD.h"
#include <QtMultimedia/qaudioformat.h>
#include "IDASHManagerObserver.h"
#include "../Buffer/AudioChunk.h"
#include "../Buffer/IMediaObjectBufferObserver.h"

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class DASHManager : public IDASHReceiverObserver, public IMediaObjectDecoderObserver, public buffer::IMediaObjectBufferObserver
            {
                public:
                    DASHManager             (uint32_t maxCapacity, IDASHManagerObserver *multimediaStream, dash::mpd::IMPD *mpd);
                    virtual ~DASHManager    ();

                    bool        Start                   ();
                    void        Stop                    ();
                    uint32_t    GetPosition             ();
                    void        SetPosition             (uint32_t segmentNumber); // to implement
                    void        SetPositionInMsec       (uint32_t millisec);
                    void        Clear                   ();
                    void        ClearTail               ();
                    void        SetRepresentation       (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);
                    void        EnqueueRepresentation   (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation);

                    void        OnSegmentDownloaded     ();
                    void        OnDecodingFinished      ();
                    void        OnVideoFrameDecoded     (const uint8_t **data, sampleplayer::decoder::videoFrameProperties* props);
                    void        OnAudioSampleDecoded    (const uint8_t **data, sampleplayer::decoder::audioFrameProperties* props);
                    void        OnBufferStateChanged    (uint32_t fillstateInPercent);

                private:
                    bool    CreateAVDecoder ();

                    buffer::MediaObjectBuffer   *buffer;
                    MediaObjectDecoder          *mediaObjectDecoder;
                    DASHReceiver                *receiver;
                    uint32_t                    readSegmentCount;
                    IDASHManagerObserver        *multimediaStream;
                    bool                        isRunning;

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_DASHMANAGER_H_ */
