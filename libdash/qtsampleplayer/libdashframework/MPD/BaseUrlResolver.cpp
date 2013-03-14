/*
 * BaseUrlResolver.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "BaseUrlResolver.h"

using namespace dash::mpd;
using namespace libdash::framework::mpd;

std::vector<dash::mpd::IBaseUrl *> BaseUrlResolver::ResolveBaseUrl(IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet,
                                                                   size_t mpdBaseUrl, size_t periodBaseUrl, size_t adaptationSetBaseUrl)
{
    std::vector<dash::mpd::IBaseUrl *> urls;

    if (mpd->GetBaseUrls().size() > 0)
    {
        if (mpd->GetBaseUrls().size() > mpdBaseUrl)
            urls.push_back(mpd->GetBaseUrls().at(mpdBaseUrl));
        else
            urls.push_back(mpd->GetBaseUrls().at(0));
    }
    if (period->GetBaseURLs().size() > 0)
    {
        if (period->GetBaseURLs().size() > periodBaseUrl)
            urls.push_back(period->GetBaseURLs().at(periodBaseUrl));
        else
            urls.push_back(period->GetBaseURLs().at(0));
    }
    if (adaptationSet->GetBaseURLs().size() > 0)
    {
        if (adaptationSet->GetBaseURLs().size() > adaptationSetBaseUrl)
            urls.push_back(adaptationSet->GetBaseURLs().at(adaptationSetBaseUrl));
        else
            urls.push_back(adaptationSet->GetBaseURLs().at(0));
    }

    if (urls.size() > 0)
    {
        if (urls.at(0)->GetUrl().substr(0,7) != "http://" && urls.at(0)->GetUrl().substr(0,8) != "https://")
        {
            urls.push_back(mpd->GetMPDPathBaseUrl());
            size_t lastPos = urls.size() - 1;
            IBaseUrl *absoluteUrl = urls.at(lastPos);
            for (size_t i = lastPos; i > 0; i--)
            {
                urls[i] = urls[i-1];
            }
            urls[0] = absoluteUrl;
        }
    }
    else 
    {
        urls.push_back(mpd->GetMPDPathBaseUrl());
    }

    return urls;
}
