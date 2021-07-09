/*
 * BaseUrl.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "BaseUrl.h"

using namespace dash::mpd;

BaseUrl::BaseUrl    () :
            url(""),
            serviceLocation(""),
            byteRange(""),
            timeShiftBufferDepth(""),
            rangeAccess(false)
{
}
BaseUrl::~BaseUrl   ()
{
}

const std::string& BaseUrl::GetUrl                          ()  const
{
    return this->url;
}
void               BaseUrl::SetUrl                          (const std::string& url)
{
    this->url = url;
}
const std::string& BaseUrl::GetServiceLocation              ()  const
{
    return this->serviceLocation;
}
void               BaseUrl::SetServiceLocation              (const std::string& serviceLocation)
{
    this->serviceLocation = serviceLocation;
}
const std::string& BaseUrl::GetByteRange                    ()  const
{
    return this->byteRange;
}
void               BaseUrl::SetByteRange                    (const std::string& byteRange)
{
    this->byteRange = byteRange;
}
double             BaseUrl::GetAvailabilityTimeOffset       ()  const
{
    return this->availabilityTimeOffset;
}
void               BaseUrl::SetAvailabilityTimeOffset       (double availabilityTimeOffset)
{
    this->availabilityTimeOffset = availabilityTimeOffset;
}
bool               BaseUrl::IsAvailabilityTimeComplete      ()  const
{
    return this->availabilityTimeComplete;
}
void               BaseUrl::SetAvailabilityTimeComplete     (bool availabilityTimeComplete)
{
    this->availabilityTimeComplete = availabilityTimeComplete;
}
const std::string& BaseUrl::GetTimeShiftBufferDepth         ()  const
{
    return this->timeShiftBufferDepth;
}
void               BaseUrl::SetTimeShiftBufferDepth         (const std::string& timeShiftBufferDepth)
{
    this->timeShiftBufferDepth = timeShiftBufferDepth;
}
bool               BaseUrl::HasRangeAccess                  ()  const
{
    return this->rangeAccess;
}
void               BaseUrl::SetRangeAccess                  (bool rangeAccess)
{
    this->rangeAccess = rangeAccess;
}                
ISegment*          BaseUrl::ToMediaSegment                  (const std::vector<IBaseUrl *>& baseurls) const
{
    Segment *seg = new Segment();

    if(seg->Init(baseurls, this->url, this->byteRange, dash::metrics::MediaSegment))
        return seg;

    delete(seg);

    return NULL;
}
