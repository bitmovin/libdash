/*
 * SegmentList.cpp
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

#include "SegmentList.h"

using namespace dash::mpd;

SegmentList::SegmentList    () :
                xlinkHref(""),
                xlinkActuate("onRequest"),
                xlinkType("simple"),
                xlinkShow("embed")
{
}
SegmentList::~SegmentList   ()
{
    for (size_t i = 0; i < segmentURLs.size(); i++)
        delete(this->segmentURLs.at(i));
}

const std::vector<ISegmentURL*>& SegmentList::GetSegmentURLs    ()  const
{
    return (std::vector<ISegmentURL*> &) this->segmentURLs;
}
void                            SegmentList::AddSegmentURL      (SegmentURL *segmentURL)
{
    this->segmentURLs.push_back(segmentURL);
}
const std::string&              SegmentList::GetXlinkHref       ()  const
{
    return this->xlinkHref;
}
void                            SegmentList::SetXlinkHref       (const std::string& xlinkHref)
{
    this->xlinkHref = xlinkHref;
}
const std::string&              SegmentList::GetXlinkActuate    ()  const
{
    return this->xlinkActuate;
}
void                            SegmentList::SetXlinkActuate    (const std::string& xlinkActuate)
{
    this->xlinkActuate = xlinkActuate;
}
const std::string&              SegmentList::GetXlinkType       ()  const
{
    return this->xlinkType;
}
void                            SegmentList::SetXlinkType       (const std::string& xlinkType)
{
    this->xlinkType = xlinkType;
}
const std::string&              SegmentList::GetXlinkShow       ()  const
{
    return this->xlinkShow;
}
void                            SegmentList::SetXlinkShow       (const std::string& xlinkShow)
{
    this->xlinkShow = xlinkShow;
}