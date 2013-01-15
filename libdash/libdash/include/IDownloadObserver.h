/*
 * IDownloadObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IDOWNLOADOBSERVER_H_
#define IDOWNLOADOBSERVER_H_

#include "config.h"

namespace dash
{
    namespace network
    {
        enum DownloadState
        {
            NOT_STARTED     = 0,
            IN_PROGRESS     = 1,
            REQUEST_ABORT   = 2,
            ABORTED         = 3,
            COMPLETED       = 4
        };
        class IDownloadObserver
        {
            public:
                virtual ~IDownloadObserver(){}

                virtual void OnDownloadRateChanged  (uint64_t bytesDownloaded)  = 0;
                virtual void OnDownloadStateChanged (DownloadState state)       = 0;
        };
    }
}

#endif /* IDOWNLOADOBSERVER_H_ */