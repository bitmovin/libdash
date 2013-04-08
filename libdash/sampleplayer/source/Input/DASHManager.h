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

#ifndef SAMPLEPLAYER_INPUT_DASHMANAGER_H_
#define SAMPLEPLAYER_INPUT_DASHMANAGER_H_

#include "../Buffer/MediaObjectBuffer.h"
#include "AdaptationLogic.h"
#include "IMediaObjectDecoderObserver.h"
#include "MediaObjectDecoder.h"
#include "libdash.h"
#include "../Buffer/AVFrameBuffer.h"
#include "IMPD.h"

namespace sampleplayer
{
    namespace input
    {
        class DASHManager : public IMediaObjectDecoderObserver
        {
            public:
                DASHManager             (buffer::AVFrameBuffer* frameBuffer, uint32_t maxcapacity, dash::mpd::IMPD *mpd);
                virtual ~DASHManager    ();

                bool        Start               ();
                void        Stop                ();
                uint32_t    GetPosition         ();
                void        Clear               ();
                void        OnDecodingFinished  ();

            private:
                buffer::MediaObjectBuffer   *buffer;
                buffer::AVFrameBuffer       *frameBuffer;
                MediaObjectDecoder          *mediaObjectDecoder;
                uint32_t                    readSegmentCount;
                uint32_t                    maxcapacity;
                AdaptationLogic             *logic;
                THREAD_HANDLE               bufferingThread;
                bool                        isDownloading;
                MediaObject                 *initSegment;

                /* Thread that does the buffering of segments */
                static void*    DoBuffering     (void *receiver);
                bool            CreateAVDecoder ();

        };
    }
}

#endif /* SAMPLEPLAYER_INPUT_DASHMANAGER_H_ */
