/*
 * Representation.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Representation.h"

using namespace dash::mpd;

Representation::Representation  () :
                segmentBase     (NULL),
                segmentList     (NULL),
                segmentTemplate (NULL),
                id(""),
                bandwidth       (0),
                qualityRanking  (0)
{
}
Representation::~Representation ()
{
    for(size_t i = 0; i < this->baseURLs.size(); i++)
        delete(this->baseURLs.at(i));
    for(size_t i = 0; i < this->subRepresentations.size(); i++)
        delete(this->subRepresentations.at(i));

    delete(this->segmentTemplate);
    delete(this->segmentBase);
    delete(this->segmentList);
}

const std::vector<IBaseUrl *>&              Representation::GetBaseURLs                 () const
{
    return (std::vector<IBaseUrl *> &) this->baseURLs;
}
void                                        Representation::AddBaseURL                  (BaseUrl *baseUrl)
{
    this->baseURLs.push_back(baseUrl);
}
const std::vector<ISubRepresentation *>&    Representation::GetSubRepresentations       () const
{
    return (std::vector<ISubRepresentation *> &) this->subRepresentations;
}
void                                        Representation::AddSubRepresentation        (SubRepresentation *subRepresentation)
{
    this->subRepresentations.push_back(subRepresentation);
}
ISegmentBase*                               Representation::GetSegmentBase              () const
{
    return this->segmentBase;
}
void                                        Representation::SetSegmentBase              (SegmentBase *segmentBase)
{
    this->segmentBase = segmentBase;
}
ISegmentList*                               Representation::GetSegmentList              () const
{
    return this->segmentList;
}
void                                        Representation::SetSegmentList              (SegmentList *segmentList)
{
    this->segmentList = segmentList;
}
ISegmentTemplate*                           Representation::GetSegmentTemplate          () const
{
    return this->segmentTemplate;
}
void                                        Representation::SetSegmentTemplate          (SegmentTemplate *segmentTemplate) 
{
    this->segmentTemplate = segmentTemplate;
}
const std::string&                          Representation::GetId                       () const
{
    return this->id;
}
void                                        Representation::SetId                       (const std::string &id)
{
    this->id = id;
}
uint32_t                                    Representation::GetBandwidth                () const
{
    return this->bandwidth;
}
void                                        Representation::SetBandwidth                (uint32_t bandwidth)
{
    this->bandwidth = bandwidth;
}
uint32_t                                    Representation::GetQualityRanking           () const
{
    return this->qualityRanking;
}
void                                        Representation::SetQualityRanking           (uint32_t qualityRanking)
{
    this->qualityRanking = qualityRanking;
}
const std::vector<std::string>&             Representation::GetDependencyId             () const
{
    return this->dependencyId;
}
void                                        Representation::SetDependencyId             (const std::string &dependencyId)
{
    dash::helpers::String::Split(dependencyId, ' ', this->dependencyId);
}
const std::vector<std::string>&             Representation::GetMediaStreamStructureId   () const
{
    return this->mediaStreamStructureId;
}
void                                        Representation::SetMediaStreamStructureId   (const std::string& mediaStreamStructureId)
{
    dash::helpers::String::Split(mediaStreamStructureId, ' ', this->mediaStreamStructureId);
}
