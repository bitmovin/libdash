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

#ifndef SAMPLEPAYER_INPUT_MEDIAOBJECTDECODER_H_
#define SAMPLEPAYER_INPUT_MEDIAOBJECTDECODER_H_

#include "MultiThreading.h"
#include "../Input/IDataReceiver.h"
#include "../Input/IMediaObjectDecoderObserver.h"
#include "../Decoder/LibavDecoder.h"
#include "../Buffer/AVFrameBuffer.h"
#include "MediaObject.h"
#include "../Renderer/IVideoObserver.h"
#include "../helpers/Timing.h"
#include "../helpers/TimingObject.h"

namespace sampleplayer
{
    namespace input
    {
        class MediaObjectDecoder : public IDataReceiver, public renderer::IVideoObserver
        {
            public:
                MediaObjectDecoder          (MediaObject *initSeg, MediaObject *mediaSeg, buffer::AVFrameBuffer *frameBuffer, IMediaObjectDecoderObserver *observer);
                virtual ~MediaObjectDecoder ();

                bool            Start                   ();
                void            Stop                    ();
                void            Notify                  ();
                virtual int     IORead                  (uint8_t *buf, int buf_size);
                virtual void    OnVideoFrameAvailable   (AVFrame* frame);


            private:
                THREAD_HANDLE               threadHandle;
                IMediaObjectDecoderObserver *observer;
                buffer::AVFrameBuffer       *frameBuffer;
                decoder::LibavDecoder       *decoder;
                MediaObject                 *initSegment;
                MediaObject                 *mediaSegment;
                bool                        run;
                bool                        decoderInitialized;

                static void* Decode             (void *data);
        };
    }
}

#endif /* SAMPLEPAYER_INPUT_MEDIAOBJECTDECODER_H_ */
