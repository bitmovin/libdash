/*
 * DASHReceiver.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHReceiver.h"

using namespace libdash::framework::input;
using namespace libdash::framework::buffer;
using namespace libdash::framework::mpd;
using namespace dash::mpd;

DASHReceiver::DASHReceiver          (IMPD *mpd, IDASHReceiverObserver *obs, MediaObjectBuffer *buffer, uint32_t bufferSize) :
              mpd                   (mpd),
              period                (NULL),
              adaptationSet         (NULL),
              representation        (NULL),
              adaptationSetStream   (NULL),
              representationStream  (NULL),
              segmentNumber         (0),
              observer              (obs),
              buffer                (buffer),
              bufferSize            (bufferSize),
              isBuffering           (false)
{
    this->period                = this->mpd->GetPeriods().at(0);
    this->adaptationSet         = this->period->GetAdaptationSets().at(0);
    this->representation        = this->adaptationSet->GetRepresentation().at(0);

    this->adaptationSetStream   = new AdaptationSetStream(mpd, period, adaptationSet);
    this->representationStream  = adaptationSetStream->GetRepresentationStream(this->representation);
    this->segmentOffset         = CalculateSegmentOffset();

    InitializeCriticalSection(&this->monitorMutex);
}
DASHReceiver::~DASHReceiver     ()
{
    delete this->adaptationSetStream;
    DeleteCriticalSection(&this->monitorMutex);
}

bool                        DASHReceiver::Start                     ()
{
    if(this->isBuffering)
        return false;

    this->isBuffering       = true;
    this->bufferingThread   = CreateThreadPortable (DoBuffering, this);

    if(this->bufferingThread == NULL)
    {
        this->isBuffering = false;
        return false;
    }

    return true;
}
void                        DASHReceiver::Stop                      ()
{
    if(!this->isBuffering)
        return;

    this->isBuffering = false;
    this->buffer->SetEOS(true);

    if(this->bufferingThread != NULL)
    {
        JoinThread(this->bufferingThread);
        DestroyThreadPortable(this->bufferingThread);
    }
}
MediaObject*                DASHReceiver::GetNextSegment            ()
{
    ISegment *seg = NULL;

    if(this->segmentNumber >= this->representationStream->GetSize())
        return NULL;

    seg = this->representationStream->GetMediaSegment(this->segmentNumber + this->segmentOffset);

    if (seg != NULL)
    {
        MediaObject *media = new MediaObject(seg, this->representation);
        this->segmentNumber++;
        return media;
    }

    return NULL;
}
MediaObject*                DASHReceiver::GetSegment                (uint32_t segNum)
{
    ISegment *seg = NULL;

    if(segNum >= this->representationStream->GetSize())
        return NULL;

    seg = this->representationStream->GetMediaSegment(segNum + segmentOffset);

    if (seg != NULL)
    {
        MediaObject *media = new MediaObject(seg, this->representation);
        return media;
    }

    return NULL;
}
MediaObject*                DASHReceiver::GetInitSegment            ()
{
    ISegment *seg = NULL;

    seg = this->representationStream->GetInitializationSegment();

    if (seg != NULL)
    {
        MediaObject *media = new MediaObject(seg, this->representation);
        return media;
    }

    return NULL;
}
MediaObject*                DASHReceiver::FindInitSegment           (dash::mpd::IRepresentation *representation)
{
    if (!this->InitSegmentExists(representation))
        return NULL;

    return this->initSegments[representation];
}
uint32_t                    DASHReceiver::GetPosition               ()
{
    return this->segmentNumber;
}
void                        DASHReceiver::SetPosition               (uint32_t segmentNumber)
{
    // some logic here

    this->segmentNumber = segmentNumber;
}
void                        DASHReceiver::SetPositionInMsecs        (uint32_t milliSecs)
{
    // some logic here

    this->positionInMsecs = milliSecs;
}
void                        DASHReceiver::SetRepresentation         (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    EnterCriticalSection(&this->monitorMutex);

    bool periodChanged = false;

    if (this->representation == representation)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return;
    }

    this->representation = representation;

    if (this->adaptationSet != adaptationSet)
    {
        this->adaptationSet = adaptationSet;

        if (this->period != period)
        {
            this->period = period;
            periodChanged = true;
        }

        delete this->adaptationSetStream;
        this->adaptationSetStream = NULL;

        this->adaptationSetStream = new AdaptationSetStream(this->mpd, this->period, this->adaptationSet);
    }

    this->representationStream  = this->adaptationSetStream->GetRepresentationStream(this->representation);
    this->DownloadInitSegment(this->representation);

    if (periodChanged)
    {
        this->segmentNumber = 0;
        this->CalculateSegmentOffset();
    }

    LeaveCriticalSection(&this->monitorMutex);
}
dash::mpd::IRepresentation* DASHReceiver::GetRepresentation         ()
{
    return this->representation;
}
uint32_t                    DASHReceiver::CalculateSegmentOffset    ()
{
    if (mpd->GetType() == "static")
        return 0;

    uint32_t firstSegNum = this->representationStream->GetFirstSegmentNumber();
    uint32_t currSegNum  = this->representationStream->GetCurrentSegmentNumber();
    uint32_t startSegNum = currSegNum - 2*bufferSize;

    return (startSegNum > firstSegNum) ? startSegNum : firstSegNum;
}
void                        DASHReceiver::NotifySegmentDownloaded   ()
{
    this->observer->OnSegmentDownloaded();
}
void                        DASHReceiver::DownloadInitSegment    (IRepresentation* rep)
{
    if (this->InitSegmentExists(rep))
        return;

    MediaObject *initSeg = NULL;
    initSeg = this->GetInitSegment();

    if (initSeg)
    {
        initSeg->StartDownload();
        this->initSegments[rep] = initSeg;
    }
}
bool                        DASHReceiver::InitSegmentExists      (IRepresentation* rep)
{
    if (this->initSegments.find(rep) != this->initSegments.end())
        return true;

    return false;
}

/* Thread that does the buffering of segments */
void*                       DASHReceiver::DoBuffering               (void *receiver)
{
    DASHReceiver *dashReceiver = (DASHReceiver *) receiver;

    dashReceiver->DownloadInitSegment(dashReceiver->GetRepresentation());

    MediaObject *media = dashReceiver->GetNextSegment();

    while(media != NULL && dashReceiver->isBuffering)
    {
        media->StartDownload();

        if (!dashReceiver->buffer->PushBack(media))
            return NULL;

        media->WaitFinished();

        dashReceiver->NotifySegmentDownloaded();

        media = dashReceiver->GetNextSegment();
    }

    dashReceiver->buffer->SetEOS(true);
    return NULL;
}
