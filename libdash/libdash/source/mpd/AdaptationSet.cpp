/*
 * AdaptationSet.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AdaptationSet.h"
#include <cstdlib>

using namespace dash::mpd;

AdaptationSet::AdaptationSet    () :
                segmentBase(NULL),
                segmentList(NULL),
                segmentTemplate(NULL),
                xlinkHref(""),
                xlinkActuate("onRequest"),
                id(0),
                lang(""),
                contentType(""),
                par(""),
                minBandwidth(0),
                maxBandwidth(0),
                minWidth(0),
                maxWidth(0),
                minHeight(0),
                maxHeight(0),
                minFramerate(""),
                maxFramerate(""),
                segmentAlignmentIsBool(true),
                subsegmentAlignmentIsBool(true),
                usesSegmentAlignment(false),
                usesSubsegmentAlignment(false),
                segmentAlignment(0),
                subsegmentAlignment(0),
                isBitstreamSwitching(false)
{
}
AdaptationSet::~AdaptationSet   ()
{
    for(size_t i = 0; i < this->accessibility.size(); i++)
        delete(this->accessibility.at(i));
    for(size_t i = 0; i < this->role.size(); i++)
        delete(this->role.at(i));
    for(size_t i = 0; i < this->rating.size(); i++)
        delete(this->rating.at(i));
    for(size_t i = 0; i < this->viewpoint.size(); i++)
        delete(this->viewpoint.at(i));
    for(size_t i = 0; i < this->contentComponent.size(); i++)
        delete(this->contentComponent.at(i));
    for(size_t i = 0; i < this->baseURLs.size(); i++)
        delete(this->baseURLs.at(i));
    for(size_t i = 0; i < this->representation.size(); i++)
        delete(this->representation.at(i));

    delete(segmentBase);
    delete(segmentList);
    delete(segmentTemplate);
}

const std::vector<IDescriptor *>&       AdaptationSet::GetAccessibility                 ()  const
{
    return (std::vector<IDescriptor *> &) this->accessibility;
}
void                                    AdaptationSet::AddAccessibity                   (Descriptor *accessibility)
{
    this->accessibility.push_back(accessibility);
}
const std::vector<IDescriptor *>&       AdaptationSet::GetRole                          ()  const
{
    return (std::vector<IDescriptor *> &) this->role;
}
void                                    AdaptationSet::AddRole                          (Descriptor *role)
{
    this->role.push_back(role);
}
const std::vector<IDescriptor *>&       AdaptationSet::GetRating                        ()  const
{
    return (std::vector<IDescriptor *> &) this->rating;
}
void                                    AdaptationSet::AddRating                        (Descriptor *rating)
{
    this->rating.push_back(rating);
}
const std::vector<IDescriptor *>&       AdaptationSet::GetViewpoint                     ()  const
{
    return (std::vector<IDescriptor *> &) this->viewpoint;
}
void                                    AdaptationSet::AddViewpoint                     (Descriptor *viewpoint)
{
    this->viewpoint.push_back(viewpoint);
}
const std::vector<IContentComponent *>& AdaptationSet::GetContentComponent              ()  const
{
    return (std::vector<IContentComponent *> &) this->contentComponent;
}
void                                    AdaptationSet::AddContentComponent              (ContentComponent *contentComponent)
{
    this->contentComponent.push_back(contentComponent);
}
const std::vector<IBaseUrl *>&          AdaptationSet::GetBaseURLs                      ()  const
{
    return (std::vector<IBaseUrl *> &) this->baseURLs;
}
void                                    AdaptationSet::AddBaseURL                       (BaseUrl *baseUrl)
{
    this->baseURLs.push_back(baseUrl);
}
ISegmentBase*                           AdaptationSet::GetSegmentBase                   ()  const
{
    return this->segmentBase;
}
void                                    AdaptationSet::SetSegmentBase                   (SegmentBase *segmentBase)
{
    this->segmentBase = segmentBase;
}
ISegmentList*                           AdaptationSet::GetSegmentList                   ()  const
{
    return this->segmentList;
}
void                                    AdaptationSet::SetSegmentList                   (SegmentList *segmentList)
{
    this->segmentList = segmentList;
}
ISegmentTemplate*                       AdaptationSet::GetSegmentTemplate               ()  const
{
    return this->segmentTemplate;
}
void                                    AdaptationSet::SetSegmentTemplate               (SegmentTemplate *segmentTemplate) 
{
    this->segmentTemplate = segmentTemplate;
}
const std::vector<IRepresentation *>&   AdaptationSet::GetRepresentation                ()  const
{
    return (std::vector<IRepresentation *> &) this->representation;
}
void                                    AdaptationSet::AddRepresentation                (Representation *representation)
{
    this->representation.push_back(representation);
}
const std::string&                      AdaptationSet::GetXlinkHref                     ()  const
{
    return this->xlinkHref;
}
void                                    AdaptationSet::SetXlinkHref                     (const std::string& xlinkHref)
{
    this->xlinkHref = xlinkHref;
}
const std::string&                      AdaptationSet::GetXlinkActuate                  ()  const
{
    return this->xlinkActuate;
}
void                                    AdaptationSet::SetXlinkActuate                  (const std::string& xlinkActuate)
{
    this->xlinkActuate = xlinkActuate;
}
uint32_t                                AdaptationSet::GetId                            ()  const
{
    return this->id;
}
void                                    AdaptationSet::SetId                            (uint32_t id)
{
    this->id = id;
}
uint32_t                                AdaptationSet::GetGroup                         ()  const
{
    return this->group;
}
void                                    AdaptationSet::SetGroup                         (uint32_t group)
{
    this->group = group;
}
const std::string&                      AdaptationSet::GetLang                          ()  const
{
    return this->lang;
}
void                                    AdaptationSet::SetLang                          (const std::string& lang)
{
    this->lang = lang;
}
const std::string&                      AdaptationSet::GetContentType                   ()  const
{
    return this->contentType;
}
void                                    AdaptationSet::SetContentType                   (const std::string& contentType)
{
    this->contentType = contentType;
}
const std::string&                      AdaptationSet::GetPar                           ()  const
{
    return this->par;
}
void                                    AdaptationSet::SetPar                           (const std::string& par)
{
    this->par = par;
}
uint32_t                                AdaptationSet::GetMinBandwidth                  ()  const
{
    return this->minBandwidth;
}
void                                    AdaptationSet::SetMinBandwidth                  (uint32_t minBandwidth)
{
    this->minBandwidth = minBandwidth;
}
uint32_t                                AdaptationSet::GetMaxBandwidth                  ()  const
{
    return this->maxBandwidth;
}
void                                    AdaptationSet::SetMaxBandwidth                  (uint32_t maxBandwidth)
{
    this->maxBandwidth = maxBandwidth;
}
uint32_t                                AdaptationSet::GetMinWidth                      ()  const
{
    return this->minWidth;
}
void                                    AdaptationSet::SetMinWidth                      (uint32_t minWidth)
{
    this->minWidth = minWidth;
}
uint32_t                                AdaptationSet::GetMaxWidth                      ()  const
{
    return this->maxWidth;
}
void                                    AdaptationSet::SetMaxWidth                      (uint32_t maxWidth)
{
    this->maxWidth = maxWidth;
}
uint32_t                                AdaptationSet::GetMinHeight                     ()  const
{
    return this->minHeight;
}
void                                    AdaptationSet::SetMinHeight                     (uint32_t minHeight)
{
    this->minHeight = minHeight;
}
uint32_t                                AdaptationSet::GetMaxHeight                     ()  const
{
    return this->maxHeight;
}
void                                    AdaptationSet::SetMaxHeight                     (uint32_t maxHeight)
{
    this->maxHeight = maxHeight;
}
const std::string&                      AdaptationSet::GetMinFramerate                  ()  const
{
    return this->minFramerate;
}
void                                    AdaptationSet::SetMinFramerate                  (const std::string& minFramerate)
{
    this->minFramerate = minFramerate;
}
const std::string&                      AdaptationSet::GetMaxFramerate                  ()  const
{
    return this->maxFramerate;
}
void                                    AdaptationSet::SetMaxFramerate                  (const std::string& maxFramerate)
{
    this->maxFramerate = maxFramerate;
}
bool                                    AdaptationSet::SegmentAlignmentIsBoolValue      () const
{
    return this->segmentAlignmentIsBool;
}
bool                                    AdaptationSet::SubsegmentAlignmentIsBoolValue   () const
{
    return this->subsegmentAlignmentIsBool;
}
bool                                    AdaptationSet::HasSegmentAlignment              () const
{
    return this->usesSegmentAlignment;
}
bool                                    AdaptationSet::HasSubsegmentAlignment           () const
{
    return this->usesSubsegmentAlignment;
}
uint32_t                                AdaptationSet::GetSegmentAligment               ()  const
{
    return this->segmentAlignment;
}
void                                    AdaptationSet::SetSegmentAlignment              (const std::string& segmentAlignment)
{
    if (segmentAlignment == "true" || segmentAlignment == "True" || segmentAlignment == "TRUE") 
    {
        this->segmentAlignmentIsBool = true;
        this->usesSegmentAlignment = true;
        return;
    }
    
    if (segmentAlignment == "false" || segmentAlignment == "False" || segmentAlignment == "FALSE") 
    {
        this->segmentAlignmentIsBool = true;
        this->usesSegmentAlignment = false;
        return;
    }

    this->segmentAlignmentIsBool = false;
    this->segmentAlignment = strtoul(segmentAlignment.c_str(), NULL, 10);
}
void                                    AdaptationSet::SetSubsegmentAlignment           (const std::string& subsegmentAlignment)
{
    if (subsegmentAlignment == "true" || subsegmentAlignment == "True" || subsegmentAlignment == "TRUE") 
    {
        this->subsegmentAlignmentIsBool = true;
        this->usesSubsegmentAlignment = true;
        return;
    }
    
    if (subsegmentAlignment == "false" || subsegmentAlignment == "False" || subsegmentAlignment == "FALSE") 
    {
        this->subsegmentAlignmentIsBool = true;
        this->usesSubsegmentAlignment = false;
        return;
    }

    this->subsegmentAlignmentIsBool = false;
    this->subsegmentAlignment = strtoul(subsegmentAlignment.c_str(), NULL, 10);
}
uint32_t                                AdaptationSet::GetSubsegmentAlignment           ()  const
{
    return this->subsegmentAlignment;
}
uint8_t                                 AdaptationSet::GetSubsegmentStartsWithSAP       ()  const
{
    return this->subsegmentStartsWithSAP;
}
void                                    AdaptationSet::SetSubsegmentStartsWithSAP       (uint8_t subsegmentStartsWithSAP)
{
    this->subsegmentStartsWithSAP = subsegmentStartsWithSAP;
}
bool                                    AdaptationSet::GetBitstreamSwitching            () const
{
    return this->isBitstreamSwitching;
}
void                                    AdaptationSet::SetBitstreamSwitching            (bool value)
{
    this->isBitstreamSwitching = value;
}
