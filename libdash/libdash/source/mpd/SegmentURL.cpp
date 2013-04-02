/*
 * SegmentURL.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SegmentURL.h"

using namespace dash::mpd;
using namespace dash::helpers;

SegmentURL::SegmentURL    () :
            mediaURI(""),
            mediaRange(""),
            indexURI(""),
            indexRange("")
{
}
SegmentURL::~SegmentURL   ()
{
}

const std::string&  SegmentURL::GetMediaURI     ()  const
{
    return this->mediaURI;
}
void                SegmentURL::SetMediaURI     (const std::string& mediaURI)
{
    this->mediaURI = mediaURI;
}
const std::string&  SegmentURL::GetMediaRange   ()  const
{
    return this->mediaRange;
}
void                SegmentURL::SetMediaRange   (const std::string& mediaRange)
{
    this->mediaRange = mediaRange;
}
const std::string&  SegmentURL::GetIndexURI     ()  const
{
    return this->indexURI;
}
void                SegmentURL::SetIndexURI     (const std::string& indexURI)
{
    this->indexURI = indexURI;
}
const std::string&  SegmentURL::GetIndexRange   ()  const
{
    return this->indexRange;
}
void                SegmentURL::SetIndexRange   (const std::string& indexRange)
{
    this->indexRange = indexRange;
}
ISegment*           SegmentURL::ToMediaSegment  (const std::vector<IBaseUrl *>& baseurls) const
{
    Segment *seg = new Segment();
    
    if(seg->Init(baseurls, this->mediaURI, this->mediaRange, dash::metrics::MediaSegment))
        return seg;

    delete(seg);

    return NULL;
}
ISegment*           SegmentURL::ToIndexSegment  (const std::vector<IBaseUrl *>& baseurls) const
{
    Segment *seg = new Segment();
    
    if(seg->Init(baseurls, this->indexURI, this->indexRange, dash::metrics::IndexSegment))
        return seg;

    delete(seg);

    return NULL;
}
