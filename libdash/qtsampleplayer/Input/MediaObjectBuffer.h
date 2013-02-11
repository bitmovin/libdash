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

#ifndef MEDIAOBJECTBUFFER_H_
#define MEDIAOBJECTBUFFER_H_

#include "MediaObject.h"
#include "MultiThreading.h"
#include <queue>

namespace sampleplayer
{
    namespace input
    {
        class MediaObjectBuffer
        {
            public:
                MediaObjectBuffer             (uint32_t maxcapacity);
                virtual ~MediaObjectBuffer    ();

                void            Push    (MediaObject *media);
                MediaObject*    Front   ();
                void            Pop     ();
                void            SetEOS  (bool value);
                uint32_t        Length  ();

            private:
                std::queue<MediaObject *>   mediaobjects;
                bool                        eos;
                uint32_t                    maxcapacity;
                mutable CRITICAL_SECTION    monitorMutex;
                mutable CONDITION_VARIABLE  full;
                mutable CONDITION_VARIABLE  empty;
        };
    }
}

#endif /* MEDIADATABUFFER_H_ */