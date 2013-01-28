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
#include "SegmentBuffer.h"
#include "IAdaptationSet.h"
#include "IDownloadObserver.h"
#include "libdash.h"
#include <string>
#include <queue>

namespace sampleplayer
{
    namespace input
    {
        class DASHReceiver : public IDataReceiver, public dash::network::IDownloadObserver
        {
            public:
                DASHReceiver            (uint32_t maxcapacity);
                virtual ~DASHReceiver   ();

                bool Init(std::string mpdurl);

                virtual int     IORead                  (uint8_t *buf, int buf_size );
                virtual void    OnDownloadStateChanged  (dash::network::DownloadState state);
                virtual void    OnDownloadRateChanged   (uint64_t bytesDownloaded);

            private:
                dash::IDASHManager                  *manager;
                dash::mpd::IMPD                     *mpd;
                SegmentBuffer                       *segmentbuffer;
                std::vector<dash::mpd::IBaseUrl *>  baseurls;
                dash::mpd::IAdaptationSet           *adaptationset;
                dash::mpd::IRepresentation          *representation;
                int                                 count;
                uint32_t                            maxcapacity;

                void AddSegmentToBuffer(int number, dash::mpd::IRepresentation *rep);
        };
    }
}

#endif /* DASHRECEIVER_H_ */