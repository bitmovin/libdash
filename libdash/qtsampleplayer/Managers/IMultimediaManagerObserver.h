/*
 * IMultimediaManagerObserver.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_MANAGERS_IMULTIMEDIAMANAGEROBSERVER_H_
#define QTSAMPLEPLAYER_MANAGERS_IMULTIMEDIAMANAGEROBSERVER_H_

#include <stdint.h>

namespace sampleplayer
{
    namespace managers
    {
        class IMultimediaManagerObserver
        {
            public:
                virtual ~IMultimediaManagerObserver () {}

                virtual void OnVideoBufferStateChanged          (uint32_t fillstateInPercent) = 0;
                virtual void OnVideoSegmentBufferStateChanged   (uint32_t fillstateInPercent) = 0;
                virtual void OnAudioBufferStateChanged          (uint32_t fillstateInPercent) = 0;
                virtual void OnAudioSegmentBufferStateChanged   (uint32_t fillstateInPercent) = 0;
                // todo subtitles
        };
    }
}
#endif /* QTSAMPLEPLAYER_MANAGERS_IMULTIMEDIAMANAGEROBSERVER_H_ */
