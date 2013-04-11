/*
 * AbstractSetHelper.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AdaptationSetHelper.h"

using namespace libdash::framework::mpd;
using namespace dash::mpd;

std::vector<IAdaptationSet *>   AdaptationSetHelper::GetAudioAdaptationSets (dash::mpd::IPeriod *period)
{
    std::vector<IAdaptationSet *> audioAdaptationSets;
    std::vector<IAdaptationSet *> adaptationSets = period->GetAdaptationSets();

    for (size_t i = 0; i < adaptationSets.size(); i++)
        if (AdaptationSetHelper::IsAudioAdaptationSet(adaptationSets.at(i)))
            audioAdaptationSets.push_back(adaptationSets.at(i));

    return audioAdaptationSets;
}
std::vector<IAdaptationSet *>   AdaptationSetHelper::GetVideoAdaptationSets (dash::mpd::IPeriod *period)
{
    std::vector<IAdaptationSet *> videoAdaptationSets;
    std::vector<IAdaptationSet *> adaptationSets = period->GetAdaptationSets();

    for (size_t i = 0; i < adaptationSets.size(); i++)
        if (AdaptationSetHelper::IsVideoAdaptationSet(adaptationSets.at(i)))
            videoAdaptationSets.push_back(adaptationSets.at(i));

    return videoAdaptationSets;
}
bool                            AdaptationSetHelper::IsAudioAdaptationSet   (dash::mpd::IAdaptationSet *adaptationSet)
{
    return IsContainedInMimeType(adaptationSet, "audio");
}
bool                            AdaptationSetHelper::IsVideoAdaptationSet   (dash::mpd::IAdaptationSet *adaptationSet)
{
    return IsContainedInMimeType(adaptationSet, "video");
}
bool                            AdaptationSetHelper::IsContainedInMimeType  (dash::mpd::IAdaptationSet *adaptationSet, std::string value)
{
    if (adaptationSet->GetMimeType() != "")
        if (adaptationSet->GetMimeType().find(value) != std::string::npos)
            return true;

    for (size_t i = 0; i < adaptationSet->GetRepresentation().size(); i++)
        if (adaptationSet->GetRepresentation().at(i)->GetMimeType() != "")
            if (adaptationSet->GetRepresentation().at(i)->GetMimeType().find(value) != std::string::npos)
                return true;

    return false;
}
