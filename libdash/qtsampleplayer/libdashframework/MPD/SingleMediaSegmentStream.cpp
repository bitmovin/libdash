/*
 * SingleMediaSegmentStream.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SingleMediaSegmentStream.h"

using namespace dash::mpd;
using namespace libdash::framework::mpd;

SingleMediaSegmentStream::SingleMediaSegmentStream      (IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation) :
                          AbstractRepresentationStream  (mpd, period, adaptationSet, representation)
{
    this->baseUrls = BaseUrlResolver::ResolveBaseUrl(mpd, period, adaptationSet, 0, 0, 0);
}
SingleMediaSegmentStream::~SingleMediaSegmentStream     ()
{
}
ISegment*                   SingleMediaSegmentStream::GetInitializationSegment      ()
{
    if (this->representation->GetSegmentBase())
    {
        /* TODO: check whether @sourceURL and/or @range is available in SegmentBase.Initialization, see Table 13 */

        if (this->representation->GetSegmentBase()->GetInitialization())
            return this->representation->GetSegmentBase()->GetInitialization()->ToSegment(baseUrls);
    }

    return NULL;
}
ISegment*                   SingleMediaSegmentStream::GetIndexSegment               (size_t segmentNumber)
{
    /* segmentNumber is not used in this case */
    if (this->representation->GetSegmentBase())
    {
        if (this->representation->GetSegmentBase()->GetRepresentationIndex())
            return this->representation->GetSegmentBase()->GetRepresentationIndex()->ToSegment(baseUrls);
    }

    return NULL;
}
ISegment*                   SingleMediaSegmentStream::GetMediaSegment               (size_t segmentNumber)
{
    /* segmentNumber equals the desired BaseUrl */
    if (this->representation->GetBaseURLs().size() > segmentNumber)
        return this->representation->GetBaseURLs().at(segmentNumber)->ToMediaSegment(baseUrls);

    return this->representation->GetBaseURLs().at(0)->ToMediaSegment(baseUrls);
}
ISegment*                   SingleMediaSegmentStream::GetBitstreamSwitchingSegment  ()
{
    /* not possible */
    return NULL;
}
RepresentationStreamType    SingleMediaSegmentStream::GetStreamType                 ()
{
    return SingleMediaSegment;
}
uint32_t                    SingleMediaSegmentStream::GetFirstSegmentNumber           ()
{
    return 0;
}
uint32_t                    SingleMediaSegmentStream::GetCurrentSegmentNumber         ()
{
    return 0;
}
uint32_t                    SingleMediaSegmentStream::GetLastSegmentNumber            ()
{
    return 0;
}