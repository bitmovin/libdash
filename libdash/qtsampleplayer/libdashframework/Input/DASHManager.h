/*
 * DASHManager.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_DASHMANAGER_H_
#define LIBDASH_FRAMEWORK_INPUT_DASHMANAGER_H_

#include "IDataReceiver.h"
#include "../Buffer/MediaObjectBuffer.h"
#include "../Adaptation/IAdaptationLogic.h"

#include "IDASHReceiverObserver.h"
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
            class DASHManager : public IDataReceiver
            {
                public:
                    DASHManager             (uint32_t maxcapacity, adaptation::IAdaptationLogic *logic);
                    virtual ~DASHManager    ();

                    bool        Start                           ();
                    void        Stop                            ();
                    uint32_t    GetPosition                     ();
                    void        Clear                           ();
                    void        AttachBufferObserver            (buffer::IBufferObserver *observer);
                    void        AttachDownloadObserver          (IDASHReceiverObserver *observer);
                    void        NotifySegmentDownloaded         ();
                    void        NotifySegmentDecodingStarted    ();
                    virtual int Read                            (uint8_t *buf, int buf_size);

                private:
                    std::vector<IDASHReceiverObserver *>    observers;
                    buffer::MediaObjectBuffer               *buffer;
                    uint32_t                                readSegmentCount;
                    uint32_t                                maxcapacity;
                    adaptation::IAdaptationLogic            *logic;
                    THREAD_HANDLE                           bufferingThread;
                    bool                                    isDownloading;

                    /* Thread that does the buffering of segments */
                    static void* DoBuffering (void *receiver);
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_DASHMANAGER_H_ */