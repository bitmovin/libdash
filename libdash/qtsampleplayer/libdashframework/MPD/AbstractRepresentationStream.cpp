/*
 * AbstractRepresentationStream.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AbstractRepresentationStream.h"

using namespace libdash::framework::mpd;
using namespace dash::mpd;

AbstractRepresentationStream::AbstractRepresentationStream  (IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation) :
                              mpd                           (mpd),
                              period                        (period),
                              adaptationSet                 (adaptationSet),
                              representation                (representation)
{
}
AbstractRepresentationStream::~AbstractRepresentationStream ()
{
}

void        AbstractRepresentationStream::SetBaseUrls               (const std::vector<dash::mpd::IBaseUrl *> baseurls)
{
    this->baseUrls.clear();

    for (size_t i = 0; i < baseurls.size(); i++)
        this->baseUrls.push_back(baseurls.at(i));
}
uint32_t    AbstractRepresentationStream::GetSize                   ()
{
    return UINT32_MAX - 1;
}
uint32_t    AbstractRepresentationStream::GetFirstSegmentNumber     ()
{
    if (this->mpd->GetType() == "dynamic")
    {
        uint32_t currTime   = TimeResolver::GetCurrentTimeInSec();
        uint32_t availStT   = TimeResolver::GetUTCDateTimeInSec(this->mpd->GetAvailabilityStarttime());
        uint32_t duration   = this->GetAverageSegmentDuration();
        uint32_t timeshift  = TimeResolver::GetDurationInSec(this->mpd->GetTimeShiftBufferDepth());

        return (currTime - duration - availStT - timeshift ) / duration;
    }

    return 0;
}
uint32_t    AbstractRepresentationStream::GetCurrentSegmentNumber   ()
{
    if (this->mpd->GetType() == "dynamic")
    {
        uint32_t currTime = TimeResolver::GetCurrentTimeInSec();
        uint32_t duration = this->GetAverageSegmentDuration();
        uint32_t availStT = TimeResolver::GetUTCDateTimeInSec(this->mpd->GetAvailabilityStarttime());

        return (currTime - duration - availStT) / duration;
    }

    return 0;
}
uint32_t    AbstractRepresentationStream::GetLastSegmentNumber      ()
{
    if (this->mpd->GetType() == "dynamic")
    {
        uint32_t currTime   = TimeResolver::GetCurrentTimeInSec();
        uint32_t duration = this->GetAverageSegmentDuration();
        uint32_t availStT   = TimeResolver::GetUTCDateTimeInSec(this->mpd->GetAvailabilityStarttime());
        uint32_t checkTime  = mpd->GetFetchTime() + 
                              TimeResolver::GetDurationInSec(this->mpd->GetMinimumUpdatePeriod());

        return ( ((checkTime > currTime) ? currTime : checkTime) - duration - availStT) / duration;
    }

    return 0;
}
uint32_t    AbstractRepresentationStream::GetAverageSegmentDuration ()
{
    return 1;
}
std::string AbstractRepresentationStream::StatusInformation         ()
{
    std::stringstream text;

    text << "Number of segments = " << this->GetSize() << std::endl;

    if (this->representation->GetWidth() && this->representation->GetHeight())
    {
        text << "Resolution = " << this->representation->GetWidth() << " x " << this->representation->GetHeight() << std::endl;
    }
    else if (this->adaptationSet->GetWidth() && this->adaptationSet->GetHeight())
    {
        text << "Resolution = " << this->adaptationSet->GetWidth() << " x " << this->adaptationSet->GetHeight() << std::endl;
    }

    if (!this->representation->GetAudioSamplingRate().empty())
    {
        text << "Sampling Rate = " << this->representation->GetAudioSamplingRate() << std::endl;
    }
    else if (!this->adaptationSet->GetAudioSamplingRate().empty())
    {
        text << "Sampling Rate = " << this->adaptationSet->GetAudioSamplingRate() << std::endl;
    }

    if (this->representation->GetBandwidth())
    {
        text << "Bandwidth = " << this->representation->GetBandwidth() << " bps" << std::endl;
    }

    text << "AVG Segment Duration = " << this->GetAverageSegmentDuration() << "s" << std::endl;

    return text.str();
}
