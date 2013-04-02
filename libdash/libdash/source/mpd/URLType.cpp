/*
 * URLType.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "URLType.h"

using namespace dash::mpd;
using namespace dash::helpers;
using namespace dash::metrics;

URLType::URLType    () :
            sourceURL(""),
            range("")
{
}
URLType::~URLType   ()
{
}

const std::string&  URLType::GetSourceURL   ()  const
{
    return this->sourceURL;
}
void                URLType::SetSourceURL   (const std::string& sourceURL)
{
    this->sourceURL = sourceURL;
}
const std::string&  URLType::GetRange       ()  const
{
    return this->range;
}
void                URLType::SetRange       (const std::string& range)
{
    this->range = range;
}
void                URLType::SetType        (HTTPTransactionType type)
{
    this->type = type;
}
ISegment*           URLType::ToSegment      (const std::vector<IBaseUrl *>& baseurls) const
{
    Segment *seg = new Segment();
    
    if(seg->Init(baseurls, this->sourceURL, this->range, this->type))
        return seg;

    delete(seg);

    return NULL;
}
