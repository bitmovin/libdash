/*
 * MediaObjectDecoder.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_MEDIAOBJECTDECODER_H_
#define LIBDASH_FRAMEWORK_INPUT_MEDIAOBJECTDECODER_H_

#include "../Portable/MultiThreading.h"
#include "../Input/IDataReceiver.h"
#include "../Input/IMediaObjectDecoderObserver.h"
#include "../../Decoder/LibavDecoder.h"
#include "../../Decoder/IAudioObserver.h"
#include "../../Decoder/IVideoObserver.h"
#include "MediaObject.h"

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class MediaObjectDecoder : public IDataReceiver, public sampleplayer::decoder::IAudioObserver, public sampleplayer::decoder::IVideoObserver
            {
                public:
                    MediaObjectDecoder          (MediaObject *initSeg, MediaObject *mediaSeg, IMediaObjectDecoderObserver *observer); 
                    virtual ~MediaObjectDecoder ();

                    bool            Start                   ();
                    void            Stop                    ();
                    virtual int     Read                    (uint8_t *buf, int buf_size);
                    virtual void    OnVideoDataAvailable    (const uint8_t **data, sampleplayer::decoder::videoFrameProperties* props);
                    virtual void    OnAudioDataAvailable    (const uint8_t **data, sampleplayer::decoder::audioFrameProperties* props);

                private:
                    THREAD_HANDLE                       threadHandle;
                    IMediaObjectDecoderObserver         *observer;
                    sampleplayer::decoder::LibavDecoder *decoder;
                    MediaObject                         *initSegment;
                    MediaObject                         *mediaSegment;
                    bool                                run;
                    bool                                decoderInitialized;
                    size_t                              initSegmentOffset;

                    static void*    Decode      (void *data);
                    void            Notify      ();
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_MEDIAOBJECTDECODER_H_ */
