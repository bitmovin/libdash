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

ISegment*   RepresentationHelper::GetInitSegment    (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation, IMPD *mpd)
{
    std::vector<IBaseUrl *> baseurls = BaseUrlResolver::ResolveBaseUrl(mpd, period, adaptationSet, 0, 0, 0);

    /* Check for segment base */
    if(representation->GetSegmentBase())
        return representation->GetSegmentBase()->GetInitialization()->ToSegment(baseurls);

    /* Check for segment list */
    if(representation->GetSegmentList())
        return representation->GetSegmentList()->GetInitialization()->ToSegment(baseurls);

    /* Check for segment template */
    if(representation->GetSegmentTemplate())
        return representation->GetSegmentTemplate()->ToInitializationSegment(baseurls, "", 0);

    /*
    es fehlt noch segtempl.initialization()
    */

    /* Check for base url only */
    /*
     * Wird nicht mehr gehen, weil auch die BaseUrls aufgeloest werden im Resolver ... andere Strategie
     */
    if(representation->GetBaseURLs().size() > 0)
        return representation->GetBaseURLs().at(0)->ToMediaSegment(baseurls);

    return NULL;
}
ISegment*   RepresentationHelper::GetSegment        (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation, uint32_t number, IMPD *mpd)
{
    std::vector<IBaseUrl *> baseurls = BaseUrlResolver::ResolveBaseUrl(mpd, period, adaptationSet, 0, 0, 0);

    /* Check for segment list */
    if(representation->GetSegmentList())
        return representation->GetSegmentList()->GetSegmentURLs().at(number)->ToMediaSegment(baseurls);

    /* Check for segment template */
    if(representation->GetSegmentTemplate())
        return representation->GetSegmentTemplate()->GetMediaSegmentFromNumber(baseurls, "", 0, representation->GetSegmentTemplate()->GetStartNumber() + number);

    return NULL;
}
uint32_t    RepresentationHelper::GetSize           (IRepresentation *representation)
{
    if(representation->GetSegmentList())
        return representation->GetSegmentList()->GetSegmentURLs().size();

    return UINT32_MAX - 1;
}
