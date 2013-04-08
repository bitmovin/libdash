/*
 * LibavDecoder.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBAVDECODER_H_
#define LIBAVDECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>

#if defined _WIN32 || defined _WIN64
#include <Windows.h>
#endif

#include "../Input/IDataReceiver.h"
#include "../Renderer/IVideoObserver.h"
#include "../Renderer/IAudioObserver.h"

namespace sampleplayer
{
    namespace decoder
    {
        struct StreamConfig
        {
            AVStream       *stream;
            AVCodecContext *codecContext;
            int             frameCnt;
        };

        class LibavDecoder
        {
            public:
                LibavDecoder                (input::IDataReceiver *rec, renderer::IVideoObserver *obs);
                virtual ~LibavDecoder       ();

                bool decode                 ();
                bool init                   ();
                void stop                   ();
                void setFrameRate           (uint8_t rate);

            private:
                input::IDataReceiver                    *receiver;
                renderer::IVideoObserver                *observer;
                std::vector <StreamConfig>              streamconfigs;
                unsigned char                           *iobuffer;
                int                                     bufferSize;
                int                                     framerate;
                AVFormatContext                         *avFormatContextPtr;
                AVFrame                                 *picture;
                AVPacket                                avpkt;
                bool                                    errorHappened;

                void                NotifyVideo     (AVFrame *frame, StreamConfig *config);
                void                NotifyAudio     (AVFrame *frame, StreamConfig *config);
                AVFormatContext*    openInput       ();
                void                initStreams     (AVFormatContext *ctx);
                StreamConfig*       getNextFrame    (AVFormatContext *ctx, AVPacket *pkt);
                int                 decodeFrame     (AVFrame *frame, AVPacket *pkt, StreamConfig *streamCfg);
                void                freeConfigs     ();
                void                error           (std::string errormsg, int errorcode);
        };
    }
}
#endif /* LIBAVDECODER_H_ */
