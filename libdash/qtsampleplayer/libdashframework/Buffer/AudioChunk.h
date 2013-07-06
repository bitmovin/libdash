/*
 * AudioChunk.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_BUFFER_AUDIOCHUNK_H_
#define QTSAMPLEPLAYER_BUFFER_AUDIOCHUNK_H_

#include "config.h"
#include <QtMultimedia/qaudioformat.h>

namespace libdash
{
    namespace framework
    {
        namespace buffer
        {
            class AudioChunk
            {
                public:
                    AudioChunk          (QAudioFormat *format, char* data, qint64 dataLength);
                    virtual ~AudioChunk ();

                    char*           Data    ();
                    qint64          Length  ();
                    QAudioFormat*   Format  ();

                private:
                    uint64_t        chunkLength;
                    char*           data;
                    QAudioFormat    *format;
            };
        }
    }
}

#endif /* QTSAMPLEPLAYER_BUFFER_AUDIOCHUNK_H_ */
