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

#include "IStreamObserver.h"
#include "../Decoder/IAudioObserver.h"
#include "../Decoder/IVideoObserver.h"

namespace sampleplayer
{
    namespace managers
    {
        class MultimediaStream : public decoder::IAudioObserver, public decoder::IVideoObserver
        {
            public:
                MultimediaStream            ();
                virtual ~MultimediaStream   ();

                virtual void OnAudioDataAvailable (const uint8_t **data, decoder::audioFrameProperties* props);
                virtual void OnVideoDataAvailable (const uint8_t **data, decoder::videoFrameProperties* props);

                void AttachStreamObserver (IStreamObserver *observer);

            private:
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_MULTIMEDIASTREAM_H_ */