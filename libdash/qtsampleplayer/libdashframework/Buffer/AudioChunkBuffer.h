/*
 * QAudioChunkBuffer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_BUFFER_AUDIOCHUNKBUFFER_H_
#define LIBDASH_FRAMEWORK_BUFFER_AUDIOCHUNKBUFFER_H_

#include "../Portable/MultiThreading.h"
#include <deque>
#include "AudioChunk.h"

namespace libdash
{
    namespace framework
    {
        namespace buffer
        {
            class AudioChunkBuffer
            {
                public:
                    AudioChunkBuffer           (uint32_t maxcapacity);
                    virtual ~AudioChunkBuffer  ();

                    bool        PushBack    (AudioChunk *frame);
                    AudioChunk* Front       ();
                    AudioChunk* GetFront    ();
                    void        PopFront    ();
                    void        ClearTail   ();
                    void        Clear       ();
                    void        SetEOS      (bool value);
                    uint32_t    Length      ();
                    uint32_t    Capacity    ();

                private:
                    std::deque<AudioChunk *>    frames;
                    bool                        eos;
                    uint32_t                    maxcapacity;
                    mutable CRITICAL_SECTION    monitorMutex;
                    mutable CONDITION_VARIABLE  full;
                    mutable CONDITION_VARIABLE  empty;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_BUFFER_AUDIOCHUNKBUFFER_H_ */