/*
 * MediaObjectBuffer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SAMPLEPLAYER_BUFFER_MEDIAOBJECTBUFFER_H_
#define SAMPLEPLAYER_BUFFER_MEDIAOBJECTBUFFER_H_

#include "../Input/MediaObject.h"
#include "../Input/MultiThreading.h"
#include <deque>

namespace sampleplayer
{
    namespace buffer
    {
        class MediaObjectBuffer
        {
            public:
                MediaObjectBuffer                           (uint32_t maxcapacity);
                virtual ~MediaObjectBuffer                  ();

                bool                        PushBack        (input::MediaObject *media);
                input::MediaObject*         Front           ();
                input::MediaObject*         GetFront        ();
                void                        PopFront        ();
                void                        ClearTail       ();
                void                        Clear           ();
                void                        SetEOS          (bool value);
                uint32_t                    Length          ();
                uint32_t                    Capacity        ();

            private:
                std::deque<input::MediaObject *>    mediaobjects;
                bool                                eos;
                uint32_t                            maxcapacity;
                mutable CRITICAL_SECTION            monitorMutex;
                mutable CONDITION_VARIABLE          full;
                mutable CONDITION_VARIABLE          empty;
        };
    }
}

#endif /* SAMPLEPLAYER_BUFFER_MEDIAOBJECTBUFFER_H_ */