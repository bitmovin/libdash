/*
 * IStreamObserver.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_MANAGERS_STREAMOBSERVER_H_
#define QTSAMPLEPLAYER_MANAGERS_STREAMOBSERVER_H_

#include <stdint.h>

namespace sampleplayer
{
    namespace managers
    {
        enum StreamType
        {
            AUDIO    = (1u << 0),
            VIDEO    = (1u << 1),
            SUBTITLE = (1u << 2),
        };

        class IStreamObserver
        {
            public:
                virtual ~IStreamObserver () {}

                virtual void OnSegmentDownloaded    ()  = 0;
                virtual void OnSegmentBufferStateChanged    (StreamType type, uint32_t fillstateInPercent) = 0;
                virtual void OnVideoBufferStateChanged      (uint32_t fillstateInPercent)                  = 0;
                virtual void OnAudioBufferStateChanged      (uint32_t fillstateInPercent)                  = 0;

        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_STREAMOBSERVER_H_ */
