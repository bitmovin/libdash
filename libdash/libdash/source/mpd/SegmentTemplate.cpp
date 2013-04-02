/*
 * SegmentTemplate.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SegmentTemplate.h"

using namespace dash::mpd;
using namespace dash::metrics;

SegmentTemplate::SegmentTemplate    () :
                    media(""),
                    index(""),
                    initialization(""),
                    bitstreamSwitching("")
{
}
SegmentTemplate::~SegmentTemplate   ()
{
}

const std::string&  SegmentTemplate::Getmedia                       ()  const
{
    return this->media;
}
void                SegmentTemplate::SetMedia                       (const std::string& media)
{
    this->media = media;
}
const std::string&  SegmentTemplate::Getindex                       ()  const
{
    return this->index;
}
void                SegmentTemplate::SetIndex                       (const std::string& index)
{
    this->index = index;
}
const std::string&  SegmentTemplate::Getinitialization              ()  const
{
    return this->initialization;
}
void                SegmentTemplate::SetInitialization              (const std::string& initialization)
{
    this->initialization = initialization;
}
const std::string&  SegmentTemplate::GetbitstreamSwitching          ()  const
{
    return this->bitstreamSwitching;
}
void                SegmentTemplate::SetBitstreamSwitching          (const std::string& bitstreamSwitching)
{
    this->bitstreamSwitching = bitstreamSwitching;
}
ISegment*           SegmentTemplate::ToInitializationSegment        (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const
{
    return ToSegment(this->initialization, baseurls, representationID, bandwidth, dash::metrics::InitializationSegment);
}
ISegment*           SegmentTemplate::ToBitstreamSwitchingSegment    (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const
{
    return ToSegment(this->bitstreamSwitching, baseurls, representationID, bandwidth, dash::metrics::BitstreamSwitchingSegment);
}
ISegment*           SegmentTemplate::GetMediaSegmentFromNumber      (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const
{
    return ToSegment(this->media, baseurls, representationID, bandwidth, dash::metrics::MediaSegment, number);
}
ISegment*           SegmentTemplate::GetIndexSegmentFromNumber      (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const
{
    return ToSegment(this->index, baseurls, representationID, bandwidth, dash::metrics::IndexSegment, number);
}
ISegment*           SegmentTemplate::GetMediaSegmentFromTime        (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const
{
    return ToSegment(this->media, baseurls, representationID, bandwidth, dash::metrics::MediaSegment, 0, time);
}
ISegment*           SegmentTemplate::GetIndexSegmentFromTime        (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const
{
    return ToSegment(this->index, baseurls, representationID, bandwidth, dash::metrics::IndexSegment, 0, time);
}
std::string         SegmentTemplate::ReplaceParameters              (const std::string& uri, const std::string& representationID, uint32_t bandwidth, uint32_t number, uint32_t time) const
{
    std::vector<std::string> chunks;
    std::string replacedUri = "";

    dash::helpers::String::Split(uri, '$', chunks);

    if (chunks.size() > 1) 
    {
        for(size_t i = 0; i < chunks.size(); i++) 
        {
            if ( chunks.at(i) == "RepresentationID") {
                chunks.at(i) = representationID;
                continue;
            }

            if (chunks.at(i).find("Bandwidth") == 0)
            {
                FormatChunk(chunks.at(i), bandwidth);
                continue;
            }

            if (chunks.at(i).find("Number") == 0)
            {
                FormatChunk(chunks.at(i), number);
                continue;
            }

            if (chunks.at(i).find("Time") == 0)
            {
                FormatChunk(chunks.at(i), time);
                continue;
            }
        }

        for(size_t i = 0; i < chunks.size(); i++) 
            replacedUri += chunks.at(i);

        return replacedUri;
    }
    else
    {
        replacedUri = uri;
        return replacedUri;
    }
}
void                SegmentTemplate::FormatChunk                    (std::string& uri, uint32_t number) const
{
    char formattedNumber [50];
    size_t pos = 0;
    std::string formatTag = "%01d";

    if ( (pos = uri.find("%0")) != std::string::npos)
        formatTag = uri.substr(pos).append("d");

    sprintf(formattedNumber, formatTag.c_str(), number);
    uri = formattedNumber;
}
ISegment*           SegmentTemplate::ToSegment                      (const std::string& uri, const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, HTTPTransactionType type, uint32_t number, uint32_t time) const
{
    Segment *seg = new Segment();

    if(seg->Init(baseurls, ReplaceParameters(uri, representationID, bandwidth, number, time), "", type))
        return seg;

    delete(seg);

    return NULL;
}