/*
 * MediaObject.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef MEDIAOBJECT_H_
#define MEDIAOBJECT_H_

#include "IMPD.h"
#include "IDownloadObserver.h"
#include "MultiThreading.h"

namespace sampleplayer
{
    namespace input
    {
        class MediaObject : public dash::network::IDownloadObserver
        {
            public:
                MediaObject             (dash::mpd::ISegment *segment, dash::mpd::IRepresentation *rep);
                virtual ~MediaObject    ();

                bool    StartDownload   ();
                void    WaitFinished    ();
                int     Read            (uint8_t *data, size_t len);
                int     Peek            (uint8_t *data, size_t len);

                virtual void    OnDownloadStateChanged  (dash::network::DownloadState state);
                virtual void    OnDownloadRateChanged   (uint64_t bytesDownloaded);

            private:
                dash::mpd::ISegment             *segment;
                dash::mpd::IRepresentation      *rep;
                dash::network::DownloadState    state;

                mutable CRITICAL_SECTION    stateLock;
                mutable CONDITION_VARIABLE  stateChanged;
        };
    }
}

#endif /* MEDIAOBJECT_H_ */