/*
 * BaseUrl.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "BaseUrl.h"

using namespace dash::mpd;

BaseUrl::BaseUrl    () :
            url(""),
            serviceLocation(""),
            byteRange("")
{
}
BaseUrl::~BaseUrl   ()
{
}

const std::string&  BaseUrl::GetUrl             ()  const
{
    return this->url;
}
void                BaseUrl::SetUrl             (const std::string& url)
{
    this->url = url;
}
const std::string&  BaseUrl::GetServiceLocation ()  const
{
    return this->serviceLocation;
}
void                BaseUrl::SetServiceLocation (const std::string& serviceLocation)
{
    this->serviceLocation = serviceLocation;
}
const std::string&  BaseUrl::GetByteRange       ()  const
{
    return this->byteRange;
}
void                BaseUrl::SetByteRange       (const std::string& byteRange)
{
    this->byteRange = byteRange;
}
ISegment*           BaseUrl::ToMediaSegment     (const std::vector<IBaseUrl *>& baseurls) const
{
    Segment *seg = new Segment();

    if(seg->Init(baseurls, this->url, this->byteRange, dash::metrics::MediaSegment))
        return seg;

    delete(seg);

    return NULL;
}
