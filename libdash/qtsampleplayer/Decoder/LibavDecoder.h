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

#include "../libdashframework/Input/IDataReceiver.h"
#include "IVideoObserver.h"
#include "IAudioObserver.h"

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
                LibavDecoder                     (libdash::framework::input::IDataReceiver *rec);
                virtual ~LibavDecoder            ();

                bool Decode                 ();
                bool Init                   ();
                void Stop                   ();
                void AttachVideoObserver    (IVideoObserver *observer);
                void AttachAudioObserver    (IAudioObserver *observer);
                void SetFrameRate           (uint8_t rate);

            private:
                libdash::framework::input::IDataReceiver    *receiver;
                std::vector <StreamConfig>                  streamconfigs;
                std::vector <IVideoObserver*>               videoObservers;
                std::vector <IAudioObserver*>               audioObservers;
                unsigned char                               *iobuffer;
                int                                         bufferSize;
                int                                         framerate;
                AVFormatContext                             *avFormatContextPtr;
                AVFrame                                     *frame;
                AVPacket                                    avpkt;

                AVFormatContext*    OpenInput       ();
                void                InitStreams     (AVFormatContext *ctx);
                StreamConfig*       GetNextFrame    (AVFormatContext *ctx, AVPacket *pkt);
                int                 DecodeFrame     (AVFrame *frame, AVPacket *pkt, StreamConfig *streamCfg);
                void                FreeConfigs     ();
                void                Error           (std::string errormsg, int errorcode);
                void                NotifyVideo     (AVFrame *frame, StreamConfig *config);
                void                NotifyAudio     (AVFrame *frame, StreamConfig *config);

                bool errorHappened;
        };
    }
}
#endif /* LIBAVDECODER_H_ */
