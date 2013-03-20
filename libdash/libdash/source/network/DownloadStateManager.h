/*
 * DownloadStateManager.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DOWNLOADSTATEMANAGER_H_
#define DOWNLOADSTATEMANAGER_H_

#include "config.h"

#include "IDownloadObserver.h"
#include "../portable/MultiThreading.h"

namespace dash
{
    namespace network
    {
        class DownloadStateManager
        {
            public:
                DownloadStateManager            ();
                virtual ~DownloadStateManager   ();

                DownloadState   State           () const;
                void            WaitState       (DownloadState state) const;
                void            CheckAndWait    (DownloadState check, DownloadState wait) const;
                void            CheckAndSet     (DownloadState check, DownloadState set);
                void            State           (DownloadState state);
                void            Attach          (IDownloadObserver *observer);
                void            Detach          (IDownloadObserver *observer);

            private:
                DownloadState               state;
                mutable CRITICAL_SECTION    stateLock;
                mutable CONDITION_VARIABLE  stateChanged;

                std::vector<IDownloadObserver *>    observers;

                void Notify ();
        };
    }
}

#endif /* DOWNLOADSTATEMANAGER_H_ */
