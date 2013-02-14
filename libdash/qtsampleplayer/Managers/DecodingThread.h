/*
 * DecodingThread.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_MANAGERS_DECODINGTHREAD_H_
#define QTSAMPLEPLAYER_MANAGERS_DECODINGTHREAD_H_

#include "../libdashframework/Portable/MultiThreading.h"
#include "../libdashframework/Input/IDataReceiver.h"
#include "../Decoder/LibavDecoder.h"
#include "../Decoder/IAudioObserver.h"
#include "../Decoder/IVideoObserver.h"

namespace sampleplayer
{
    namespace managers
    {
        class DecodingThread
        {
            public:
                DecodingThread          (libdash::framework::input::IDataReceiver *receiver, decoder::IAudioObserver *audioObserver, decoder::IVideoObserver *videoObserver);
                virtual ~DecodingThread ();

                bool Start  ();
                void Stop   ();

            private:
                THREAD_HANDLE                               threadHandle;
                libdash::framework::input::IDataReceiver    *receiver;
                decoder::IAudioObserver                     *audioObserver;
                decoder::IVideoObserver                     *videoObserver;
                decoder::LibavDecoder                       *decoder;
                bool                                        run;

                static void* Decode (void *data);
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_DECODINGTHREAD_H_ */