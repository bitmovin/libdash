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

#ifndef DASHRECEIVER_H_
#define DASHRECEIVER_H_

#include "IDataReceiver.h"
#include "MediaObjectBuffer.h"
#include "AdaptationLogic.h"
#include "IDownloadObserver.h"
#include "libdash.h"
#include <string>
#include <queue>
#include "IBufferObserver.h"

namespace sampleplayer
{
    namespace input
    {


        class DASHReceiver : public IDataReceiver
        {
            public:
                DASHReceiver            (uint32_t maxcapacity, AdaptationLogic* logic);
                virtual ~DASHReceiver   ();

                bool Start                  ();
                void Stop                   ();
                void AtachBufferObserver    (IBufferObserver* observer);

                virtual int IORead (uint8_t *buf, int buf_size);

            private:
                MediaObjectBuffer           *buffer;
                int                         count;
                uint32_t                    maxcapacity;
                AdaptationLogic             *logic;
                THREAD_HANDLE               bufferingThread;
                bool                        run;

                /* Thread that does the buffering of segments */
                static void* DoBuffering (void *receiver);
        };
    }
}

#endif /* DASHRECEIVER_H_ */