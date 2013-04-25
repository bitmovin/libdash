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

#include "libdash.h"
#include "IMPD.h"

#include "IDASHReceiverObserver.h"
#include "../Buffer/MediaObjectBuffer.h"
#include "../MPD/AdaptationSetStream.h"
#include "../MPD/IRepresentationStream.h"
#include "../Portable/MultiThreading.h"

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class DASHReceiver
            {
                public:
                    DASHReceiver            (dash::mpd::IMPD *mpd, IDASHReceiverObserver *obs, buffer::MediaObjectBuffer *buffer, uint32_t bufferSize);
                    virtual ~DASHReceiver   ();

                    bool                        Start                   ();
                    void                        Stop                    ();
                    input::MediaObject*         GetNextSegment          ();
                    input::MediaObject*         GetSegment              (uint32_t segmentNumber);
                    input::MediaObject*         GetInitSegment          ();
                    input::MediaObject*         FindInitSegment         (dash::mpd::IRepresentation *representation);
                    uint32_t                    GetPosition             ();
                    void                        SetPosition             (uint32_t segmentNumber);
                    void                        SetPositionInMsecs      (uint32_t milliSecs);
                    dash::mpd::IRepresentation* GetRepresentation       ();
                    void                        SetRepresentation       (dash::mpd::IPeriod *period,
                                                                         dash::mpd::IAdaptationSet *adaptationSet,
                                                                         dash::mpd::IRepresentation *representation);

                private:
                    uint32_t        CalculateSegmentOffset  ();
                    void            NotifySegmentDownloaded ();
                    void            DownloadInitSegment     (dash::mpd::IRepresentation* rep);
                    bool            InitSegmentExists       (dash::mpd::IRepresentation* rep);

                    static void*    DoBuffering             (void *receiver);

                    std::map<dash::mpd::IRepresentation*, MediaObject*> initSegments;
                    buffer::MediaObjectBuffer                           *buffer;
                    IDASHReceiverObserver                               *observer;
                    dash::mpd::IMPD                                     *mpd;
                    dash::mpd::IPeriod                                  *period;
                    dash::mpd::IAdaptationSet                           *adaptationSet;
                    dash::mpd::IRepresentation                          *representation;
                    mpd::AdaptationSetStream                            *adaptationSetStream;
                    mpd::IRepresentationStream                          *representationStream;
                    uint32_t                                            segmentNumber;
                    uint32_t                                            positionInMsecs;
                    uint32_t                                            segmentOffset;
                    uint32_t                                            bufferSize;
                    CRITICAL_SECTION                                    monitorMutex;

                    THREAD_HANDLE   bufferingThread;
                    bool            isBuffering;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_ */
