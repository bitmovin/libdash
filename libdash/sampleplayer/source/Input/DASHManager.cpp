/*
 * DASHManager.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHManager.h"

using namespace sampleplayer::input;
using namespace sampleplayer::buffer;
using namespace sampleplayer::helpers;
using namespace sampleplayer::adaptation;
using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHManager::DASHManager        (AVFrameBuffer *frameBuffer, uint32_t maxcapacity, IMPD *mpd) :
             frameBuffer        (frameBuffer),
             readSegmentCount   (0),
             maxcapacity        (maxcapacity),
             logic              (logic),
             isDownloading      (false),
             bufferingThread    (NULL),
             currentPeriod          (0),
             currentAdaptationSet   (0),
             currentRepresentation  (0),
             mpd                (mpd)
{
    this->buffer = new MediaObjectBuffer(this->maxcapacity);
    this->logic  = AdaptationLogicFactory::Create(Manual, mpd->GetPeriods().at(0), mpd->GetPeriods().at(0)->GetAdaptationSets().at(0), mpd, this->maxcapacity);

    av_register_all();
}
DASHManager::~DASHManager       ()
{
    this->Stop();
}

bool        DASHManager::Start              ()
{
    if(this->isDownloading)
        return false;

    this->isDownloading     = true;
    this->bufferingThread   = CreateThreadPortable (DoBuffering, this);

    if(this->bufferingThread == NULL)
    {
        this->isDownloading = false;
        return false;
    }

    this->CreateAVDecoder();

    return true;
}
void        DASHManager::Stop               ()
{
    if(!this->isDownloading)
        return;

    this->isDownloading = false;
    this->buffer->SetEOS(true);

    if(this->bufferingThread != NULL)
    {
        WaitForSingleObject(this->bufferingThread, INFINITE);
        DestroyThreadPortable(this->bufferingThread);
    }

    //this->buffer->Clear();
}
void        DASHManager::Clear              ()
{
    this->buffer->ClearTail();
}
uint32_t    DASHManager::GetPosition        ()
{
    return this->readSegmentCount;
}
void        DASHManager::OnDecodingFinished ()
{
    //Timing::WriteToFile("../bin/DecodingInterval.txt");

    this->CreateAVDecoder();
    Timing::AddTiming(new TimingObject("    AV Decoder created..."));
}

/* Thread that does the buffering of segments */
void*   DASHManager::DoBuffering   (void *receiver)
{
    DASHManager *dashmanager = (DASHManager *) receiver;

    /*  Get InitSegment and download it right away */
    dashmanager->DownloadInitSegment(dashmanager->logic->GetRepresentation()); 
    dashmanager->readSegmentCount++;

    MediaObject *media = dashmanager->logic->GetSegment();

    while(media != NULL && dashmanager->isDownloading)
    {
        media->StartDownload();

        if (!dashmanager->buffer->PushBack(media))
            return NULL;

        media->WaitFinished();

        dashmanager->readSegmentCount++;

        /*if (dashmanager->readSegmentCount == 2)
        {
            Timing::SetDecoderStartTime();
            dashmanager->CreateAVDecoder();
            Timing::AddTiming(new TimingObject("    AV Decoder created..."));
        }*/

        media = dashmanager->logic->GetSegment();
    }

    dashmanager->buffer->SetEOS(true);
    return NULL;
}
bool    DASHManager::CreateAVDecoder    ()
{
    MediaObject *mediaObject            = this->buffer->GetFront();
    MediaObject *initSegForMediaObject  = this->initSegments[mediaObject->GetRepresentation()];

    this->mediaObjectDecoder = new MediaObjectDecoder(initSegForMediaObject, mediaObject, this->frameBuffer, this);
    return this->mediaObjectDecoder->Start();
}
void    DASHManager::SetRepresentation  (dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IRepresentation *representation)
{
    if (this->logic->GetRepresentation() == representation)
        return;

    this->logic->SetRepresentation(period, adaptationSet, representation);
    this->DownloadInitSegment(representation);
}
void    DASHManager::ChangePeriod           ()
{
    size_t numOfPeriods = mpd->GetPeriods().size();
    if (numOfPeriods == 1)
        return;

    currentPeriod = ++currentPeriod % numOfPeriods;

    this->SetRepresentation(mpd->GetPeriods().at(currentPeriod),
                            mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(0),
                            mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(0)->GetRepresentation().at(0)
                            );
}
void    DASHManager::ChangeAdaptationSet    ()
{
    size_t numOfAdaptationSets = mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().size();
    if (numOfAdaptationSets == 1)
        return;

    currentAdaptationSet = ++currentAdaptationSet % numOfAdaptationSets;

    this->SetRepresentation(mpd->GetPeriods().at(currentPeriod),
                            mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(currentAdaptationSet),
                            mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(currentAdaptationSet)->GetRepresentation().at(0)
                            );
}
void    DASHManager::ChangeRepresentation   ()
{
    size_t numOfReps = mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(currentAdaptationSet)->GetRepresentation().size();
    if (numOfReps == 1)
        return;

    currentRepresentation = ++currentRepresentation % numOfReps;

    this->SetRepresentation(mpd->GetPeriods().at(currentPeriod),
                            mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(currentAdaptationSet),
                            mpd->GetPeriods().at(currentPeriod)->GetAdaptationSets().at(currentAdaptationSet)->GetRepresentation().at(currentRepresentation)
                            );
}
void    DASHManager::DownloadInitSegment    (IRepresentation* rep)
{
    if (this->InitSegmentExists(rep))
        return;

    MediaObject *initSeg = NULL;
    initSeg = this->logic->GetInitSegment();
    initSeg->StartDownload();

    this->initSegments[this->logic->GetRepresentation()] = initSeg;
}
bool    DASHManager::InitSegmentExists      (IRepresentation* rep)
{
    if (this->initSegments.find(rep) != this->initSegments.end())
        return true;

    return false;
}
