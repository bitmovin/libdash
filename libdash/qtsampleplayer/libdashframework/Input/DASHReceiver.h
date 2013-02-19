/*
 * DASHReceiver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_
#define LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_

#include "IDataReceiver.h"
#include "../Buffer/MediaObjectBuffer.h"
#include "../Adaptation/IAdaptationLogic.h"

#include "IDownloadObserver.h"
#include "libdash.h"
#include <string>
#include <queue>

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class DASHReceiver : public IDataReceiver
            {
                public:
                    DASHReceiver            (uint32_t maxcapacity, adaptation::IAdaptationLogic *logic);
                    virtual ~DASHReceiver   ();

                    bool Start                  ();
                    void Stop                   ();
                    void Clear                  ();
                    void AtachBufferObserver    (buffer::IBufferObserver *observer);

                    virtual int Read (uint8_t *buf, int buf_size);

                private:
                    buffer::MediaObjectBuffer       *buffer;
                    int                             count;
                    uint32_t                        maxcapacity;
                    adaptation::IAdaptationLogic    *logic;
                    THREAD_HANDLE                   bufferingThread;
                    bool                            isDownloading;

                    /* Thread that does the buffering of segments */
                    static void* DoBuffering (void *receiver);
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_ */