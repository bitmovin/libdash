/*
 * RepresentationHelper.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "RepresentationHelper.h"

using namespace dash::mpd;
using namespace libdash::framework::mpd;

ISegment*   RepresentationHelper::GetInitSegment    (IRepresentation *representation, const std::vector<IBaseUrl *>& baseurls)
{
    return representation->GetSegmentBase()->GetInitialization()->ToSegment(baseurls);
}
ISegment*   RepresentationHelper::GetSegment        (IRepresentation *representation, const std::vector<IBaseUrl *>& baseurls, uint32_t number)
{
    return representation->GetSegmentList()->GetSegmentURLs().at(number)->ToMediaSegment(baseurls);
}
uint32_t    RepresentationHelper::GetSize           (IRepresentation *representation)
{
    return representation->GetSegmentList()->GetSegmentURLs().size();
}
