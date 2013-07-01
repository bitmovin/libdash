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

#include "../libdashframework/Input/IDataReceiver.h"
#include "../libdashframework/Portable/MultiThreading.h"
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
                LibavDecoder                (libdash::framework::input::IDataReceiver *rec);
                virtual ~LibavDecoder       ();

                bool Decode                 ();
                bool Init                   ();
                void Stop                   ();
                void AttachVideoObserver    (IVideoObserver *observer);
                void AttachAudioObserver    (IAudioObserver *observer);
                void Flush                  ();

            private:
                libdash::framework::input::IDataReceiver    *receiver;
                std::vector <StreamConfig>                  streamconfigs;
                std::vector <IVideoObserver*>               videoObservers;
                std::vector <IAudioObserver*>               audioObservers;
                unsigned char                               *iobuffer;
                int                                         bufferSize;
                AVFormatContext                             *avFormatContextPtr;
                AVFrame                                     *frame;
                AVPacket                                    avpkt;
                bool                                        errorHappened;

                AVFormatContext*    OpenInput       ();
                void                InitStreams     (AVFormatContext *ctx);
                StreamConfig*       GetNextPacket   (AVFormatContext *ctx, AVPacket *pkt);
                int                 DecodeMedia     (AVFrame *frame, AVPacket *pkt, StreamConfig *streamCfg, int *gotFrame);
                int                 DecodeFrame     (AVFrame *frame, AVPacket *pkt, StreamConfig *streamCfg);
                void                FreeConfigs     ();
                void                Error           (std::string errormsg, int errorcode);
                void                Notify          (AVFrame *frame, StreamConfig *config);
                void                NotifyVideo     (AVFrame *frame, StreamConfig *config);
                void                NotifyAudio     (AVFrame *frame, StreamConfig *config);
                StreamConfig*       FindStreamConfig(int streamIndex);

        };
    }
}
#endif /* LIBAVDECODER_H_ */
