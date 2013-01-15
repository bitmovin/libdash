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

using namespace sampleplayer::input;
using namespace dash;
using namespace dash::network;
using namespace dash::mpd;

DASHReceiver::DASHReceiver  () :
              manager       (NULL),
              mpd           (NULL),
              adaptationset (NULL),
              count         (0)
{
    this->manager = CreateDashManager();
}
DASHReceiver::~DASHReceiver ()
{
    delete(this->manager);
}

bool    DASHReceiver::Init                      (std::string mpdurl)
{
    this->mpd = this->manager->Open((char *)mpdurl.c_str());

    if(this->mpd == NULL)
        return false;


    this->baseurls.push_back(this->mpd->GetBaseUrls().at(0));

    this->adaptationset  = this->mpd->GetPeriods().at(0)->GetAdaptationSets().at(0);
    this->representation = this->adaptationset->GetRepresentation().at(0);

    this->AddSegmentToBuffer(count++, this->representation);

    return true;
}
void    DASHReceiver::OnDownloadStateChanged    (DownloadState state)
{
    if(state == COMPLETED)
        this->AddSegmentToBuffer(count++, this->representation);
}
void    DASHReceiver::OnDownloadRateChanged     (uint64_t bytesDownloaded)
{
}
void    DASHReceiver::AddSegmentToBuffer        (int number, dash::mpd::IRepresentation *rep)
{
    dash::mpd::ISegment *seg = NULL;

    if(number >= rep->GetSegmentList()->GetSegmentURLs().size() + 1)
    {
        this->segmentbuffer.SetEOS(true);
        return;
    }

    if(number == 0)
        seg = rep->GetSegmentBase()->GetInitialization()->ToSegment(this->baseurls);
    else
        seg = rep->GetSegmentList()->GetSegmentURLs().at(number - 1)->ToMediaSegment(this->baseurls);

    seg->AttachDownloadObserver(this);
    seg->StartDownload();
    this->segmentbuffer.Push(seg);
}
int     DASHReceiver::IORead                    (uint8_t *buf, int buf_size )
{
    ISegment *seg = this->segmentbuffer.Front();

    if(seg == NULL)
        return 0;

    int ret = seg->Read(buf, buf_size);

    if(ret == 0)
    {
        this->segmentbuffer.Pop();
        return this->IORead(buf, buf_size);
    }

    return ret;
}