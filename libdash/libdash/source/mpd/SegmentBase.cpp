/*
 * SegmentBase.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SegmentBase.h"

using namespace dash::mpd;

SegmentBase::SegmentBase    ()  :
                initialization(NULL),
                representationIndex(NULL),
                timescale(1),
                presentationTimeOffset(0),
                indexRange(""),
                indexRangeExact(false)
{
}
SegmentBase::~SegmentBase   ()
{
    delete(this->initialization);
    delete(this->representationIndex);
}

const IURLType*     SegmentBase::GetInitialization          ()  const
{
    return this->initialization;
}
void                SegmentBase::SetInitialization          (URLType *initialization)
{
    this->initialization = initialization;
}
const IURLType*     SegmentBase::GetRepresentationIndex     ()  const
{
    return this->representationIndex;
}
void                SegmentBase::SetRepresentationIndex     (URLType *representationIndex)
{
    this->representationIndex = representationIndex;
}
uint32_t            SegmentBase::GetTimescale               ()  const
{
    return this->timescale;
}
void                SegmentBase::SetTimescale               (uint32_t timescale)
{
    this->timescale = timescale;
}
uint32_t            SegmentBase::GetPresentationTimeOffset  ()  const
{
    return this->presentationTimeOffset;
}
void                SegmentBase::SetPresentationTimeOffset  (uint32_t presentationTimeOffset)
{
    this->presentationTimeOffset = presentationTimeOffset;
}
const std::string&  SegmentBase::GetIndexRange              ()  const
{
    return this->indexRange;
}
void                SegmentBase::SetIndexRange              (const std::string& indexRange)
{
    this->indexRange = indexRange;
}
bool                SegmentBase::HasIndexRangeExact         ()  const
{
    return this->indexRangeExact;
}
void                SegmentBase::SetIndexRangeExact         (bool indexRangeExact)
{
    this->indexRangeExact = indexRangeExact;
}
