/*
 * Node.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Node.h"
#include <cstdlib>

using namespace dash::xml;
using namespace dash::metrics;

Node::Node  ()
{
}
Node::Node  (const Node& other) :
    name(other.name),
    text(other.text),
    type(other.type),
    attributes(other.attributes)
{
    for (size_t i = 0; i < other.subNodes.size(); i++)
        this->subNodes.push_back(new Node(*(other.subNodes.at(i))));
}
Node::~Node ()
{
    for(size_t i = 0; i < this->subNodes.size(); i++)
        delete(this->subNodes.at(i));
}

dash::mpd::ProgramInformation*              Node::ToProgramInformation  ()  const
{
    dash::mpd::ProgramInformation *programInformation = new dash::mpd::ProgramInformation();

    if (this->HasAttribute("lang"))
    {
        programInformation->SetLang(this->GetAttributeValue("lang"));
    }
    if (this->HasAttribute("moreInformationURL"))
    {
        programInformation->SetMoreInformationURL(this->GetAttributeValue("moreInformationURL"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "Title")
        {
            programInformation->SetTitle(subNodes.at(i)->GetText());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Source")
        {
            programInformation->SetSource(subNodes.at(i)->GetText());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Copyright")
        {
            programInformation->SetCopyright(subNodes.at(i)->GetText());
            continue;
        }
        programInformation->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    programInformation->AddRawAttributes(this->attributes);
    return programInformation;
}
dash::mpd::BaseUrl*                         Node::ToBaseUrl             ()  const
{
    dash::mpd::BaseUrl *baseUrl = new dash::mpd::BaseUrl();

    if(this->HasAttribute("serviceLocation"))
    {
        baseUrl->SetServiceLocation(this->GetAttributeValue("serviceLocation"));
    }
    if(this->HasAttribute("byteRange"))
    {
        baseUrl->SetByteRange(this->GetAttributeValue("byteRange"));
    }
    if (this->GetText() == "./")
    {
        baseUrl->SetUrl(this->mpdPath);
    }
    else 
    {
        baseUrl->SetUrl(this->GetText());
    }

    baseUrl->AddRawAttributes(this->attributes);
    return baseUrl;
}
dash::mpd::Descriptor*                      Node::ToDescriptor          ()  const
{
    dash::mpd::Descriptor *descriptor = new dash::mpd::Descriptor();
    std::vector<Node *> subNodes = this->GetSubNodes();

    if (this->HasAttribute("schemeIdUri"))
    {
        descriptor->SetSchemeIdUri(this->GetAttributeValue("schemeIdUri"));
    }
    if (this->HasAttribute("value"))
    {
        descriptor->SetValue(this->GetAttributeValue("value"));
    }
    
    for(size_t i = 0; i < subNodes.size(); i++)
    {
        descriptor->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    descriptor->AddRawAttributes(this->attributes);
    return descriptor;
}
dash::mpd::ContentComponent*                Node::ToContentComponent    ()  const
{
    dash::mpd::ContentComponent *contentComponent = new dash::mpd::ContentComponent();
    std::vector<Node *> subNodes = this->GetSubNodes();

    if (this->HasAttribute("id"))
    {
        contentComponent->SetId(strtoul(this->GetAttributeValue("id").c_str(), NULL, 10));
    }
    if (this->HasAttribute("lang"))
    {
        contentComponent->SetLang(this->GetAttributeValue("lang"));
    }
    if (this->HasAttribute("contentType"))
    {
        contentComponent->SetContentType(this->GetAttributeValue("contentType"));
    }
    if (this->HasAttribute("par"))
    {
        contentComponent->SetPar(this->GetAttributeValue("par"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "Accessibility")
        {
            contentComponent->AddAccessibity(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Role")
        {
            contentComponent->AddRole(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Rating")
        {
            contentComponent->AddRating(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Viewpoint")
        {
            contentComponent->AddViewpoint(subNodes.at(i)->ToDescriptor());
            continue;
        }
        contentComponent->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    contentComponent->AddRawAttributes(this->attributes);
    return contentComponent;
}
dash::mpd::URLType*                         Node::ToURLType             (HTTPTransactionType type)  const
{
    dash::mpd::URLType* urlType = new dash::mpd::URLType();
    
    if (this->HasAttribute("sourceURL"))
    {
        urlType->SetSourceURL(this->GetAttributeValue("sourceURL"));
    }
    if (this->HasAttribute("range"))
    {
        urlType->SetRange(this->GetAttributeValue("range"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        urlType->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    urlType->SetType(type);
    urlType->AddRawAttributes(this->attributes);
    return urlType;
}
dash::mpd::SegmentBase*                     Node::ToSegmentBase         ()  const
{
    dash::mpd::SegmentBase* segmentBase = new dash::mpd::SegmentBase();
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForSeg(*segmentBase);

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() != "Initialization" && subNodes.at(i)->GetName() != "RepresentationIndex")
            segmentBase->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    segmentBase->AddRawAttributes(this->attributes);
    return segmentBase;
}
dash::mpd::Timeline*                        Node::ToTimeline            ()  const
{
    dash::mpd::Timeline* timeline = new dash::mpd::Timeline();

    if (this->HasAttribute("t"))
    {
        timeline->SetStartTime(strtoul(this->GetAttributeValue("t").c_str(), NULL, 10));
    }
    if (this->HasAttribute("d"))
    {
        timeline->SetDuration(strtoul(this->GetAttributeValue("d").c_str(), NULL, 10));
    }
    if (this->HasAttribute("r"))
    {
        timeline->SetRepeatCount(strtoul(this->GetAttributeValue("r").c_str(), NULL, 10));
    }

    timeline->AddRawAttributes(this->attributes);
    return timeline;
}
dash::mpd::SegmentTimeline*                 Node::ToSegmentTimeline     ()  const
{
    dash::mpd::SegmentTimeline* segmentTimeline = new dash::mpd::SegmentTimeline();

    std::vector<Node *> subNodes = this->GetSubNodes();
    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "S")
        {
            segmentTimeline->AddTimeline(subNodes.at(i)->ToTimeline());
            continue;
        }
        segmentTimeline->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    segmentTimeline->AddRawAttributes(this->attributes);
    return segmentTimeline;
}
dash::mpd::SegmentURL*                      Node::ToSegmentURL          ()  const
{
    dash::mpd::SegmentURL *segmentUrl = new dash::mpd::SegmentURL();

    if (this->HasAttribute("media"))
    {
        segmentUrl->SetMediaURI(this->GetAttributeValue("media"));
    }
    if (this->HasAttribute("mediaRange"))
    {
        segmentUrl->SetMediaRange(this->GetAttributeValue("mediaRange"));
    }
    if (this->HasAttribute("index"))
    {
        segmentUrl->SetIndexURI(this->GetAttributeValue("index"));
    }
    if (this->HasAttribute("indexRange"))
    {
        segmentUrl->SetIndexRange(this->GetAttributeValue("indexRange"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        segmentUrl->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    segmentUrl->AddRawAttributes(this->attributes);
    return segmentUrl;
}
dash::mpd::SegmentList*                     Node::ToSegmentList         ()  const
{
    dash::mpd::SegmentList* segmentList = new dash::mpd::SegmentList();
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForMSeg(*segmentList);

    if (this->HasAttribute("xlink:href"))
    {
        segmentList->SetXlinkHref(this->GetAttributeValue("xlink:href"));
    }
    if (this->HasAttribute("xlink:actuate"))
    {
        segmentList->SetXlinkActuate(this->GetAttributeValue("xlink:actuate"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "SegmentURL")
        {
            segmentList->AddSegmentURL(subNodes.at(i)->ToSegmentURL());
            continue;
        }
        if (subNodes.at(i)->GetName() != "SegmentTimeline" && subNodes.at(i)->GetName() != "BitstreamSwitching" &&
            subNodes.at(i)->GetName() != "Initialization" && subNodes.at(i)->GetName() != "RepresentationIndex")
            segmentList->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    segmentList->AddRawAttributes(this->attributes);
    return segmentList;
}
dash::mpd::SegmentTemplate*                 Node::ToSegmentTemplate     ()  const
{
    dash::mpd::SegmentTemplate *segmentTemplate = new dash::mpd::SegmentTemplate();
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForMSeg(*segmentTemplate);

    if (this->HasAttribute("media"))
    {
        segmentTemplate->SetMedia(this->GetAttributeValue("media"));
    }
    if (this->HasAttribute("index"))
    {
        segmentTemplate->SetIndex(this->GetAttributeValue("index"));
    }
    if (this->HasAttribute("initialization"))
    {
        segmentTemplate->SetInitialization(this->GetAttributeValue("initialization"));
    }
    if (this->HasAttribute("bitstreamSwitching"))
    {
        segmentTemplate->SetBitstreamSwitching(this->GetAttributeValue("bitstreamSwitching"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() != "SegmentTimeline" && subNodes.at(i)->GetName() != "BitstreamSwitching" &&
            subNodes.at(i)->GetName() != "Initialization" && subNodes.at(i)->GetName() != "RepresentationIndex")
            segmentTemplate->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    segmentTemplate->AddRawAttributes(this->attributes);
    return segmentTemplate;
}
dash::mpd::SubRepresentation*               Node::ToSubRepresentation   ()  const
{
    dash::mpd::SubRepresentation* subRepresentation = new dash::mpd::SubRepresentation();
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForRep(*subRepresentation);

    if (this->HasAttribute("level"))
    {
        subRepresentation->SetLevel(strtoul(this->GetAttributeValue("level").c_str(), NULL, 10));
    }
    if (this->HasAttribute("dependencyLevel"))
    {
        subRepresentation->SetDependencyLevel(this->GetAttributeValue("dependencyLevel"));
    }
    if (this->HasAttribute("bandwidth"))
    {
        subRepresentation->SetBandWidth(strtoul(this->GetAttributeValue("bandwidth").c_str(), NULL, 10));
    }
    if (this->HasAttribute("contentComponent"))
    {
        subRepresentation->SetContentComponent(this->GetAttributeValue("contentComponent"));
    }
    for (size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() != "FramePacking" && subNodes.at(i)->GetName() != "AudioChannelConfiguration" && subNodes.at(i)->GetName() != "ContentProtection")
            subRepresentation->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    subRepresentation->AddRawAttributes(this->attributes);
    return subRepresentation;
}
dash::mpd::Representation*                  Node::ToRepresentation      ()  const
{
    dash::mpd::Representation* representation = new dash::mpd::Representation();
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForRep(*representation);

    if (this->HasAttribute("id"))
    {
        representation->SetId(this->GetAttributeValue("id"));
    }
    if (this->HasAttribute("bandwidth"))
    {
        representation->SetBandwidth(strtoul(this->GetAttributeValue("bandwidth").c_str(), NULL, 10));
    }
    if (this->HasAttribute("qualityRanking"))
    {
        representation->SetQualityRanking(strtoul(this->GetAttributeValue("qualityRanking").c_str(), NULL, 10));
    }
    if (this->HasAttribute("dependencyId"))
    {
        representation->SetDependencyId(this->GetAttributeValue("dependencyId"));
    }
    if (this->HasAttribute("mediaStreamStructureId"))
    {
        representation->SetMediaStreamStructureId(this->GetAttributeValue("mediaStreamStructureId"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "BaseURL")
        {
            representation->AddBaseURL(subNodes.at(i)->ToBaseUrl());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SubRepresentation")
        {
            representation->AddSubRepresentation(subNodes.at(i)->ToSubRepresentation());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentBase")
        {
            representation->SetSegmentBase(subNodes.at(i)->ToSegmentBase());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentList")
        {
            representation->SetSegmentList(subNodes.at(i)->ToSegmentList());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentTemplate")
        {
            representation->SetSegmentTemplate(subNodes.at(i)->ToSegmentTemplate());
            continue;
        }
        if (subNodes.at(i)->GetName() != "FramePacking" && subNodes.at(i)->GetName() != "AudioChannelConfiguration" && subNodes.at(i)->GetName() != "ContentProtection")
            representation->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    representation->AddRawAttributes(this->attributes);
    return representation;
}
dash::mpd::AdaptationSet*                   Node::ToAdaptationSet       ()  const
{
    dash::mpd::AdaptationSet *adaptationSet = new dash::mpd::AdaptationSet();
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForRep(*adaptationSet);

    if (this->HasAttribute("xlink:href"))
    {
        adaptationSet->SetXlinkHref(this->GetAttributeValue("xlink:href"));
    }
    if (this->HasAttribute("xlink:actuate"))
    {
        adaptationSet->SetXlinkActuate(this->GetAttributeValue("xlink:actuate"));
    }
    if (this->HasAttribute("id"))
    {
        adaptationSet->SetId(strtoul(this->GetAttributeValue("id").c_str(), NULL, 10));
    }
    if (this->HasAttribute("group"))
    {
        adaptationSet->SetGroup(strtoul(this->GetAttributeValue("group").c_str(), NULL, 10));
    }
    if (this->HasAttribute("lang"))
    {
        adaptationSet->SetLang(this->GetAttributeValue("lang"));
    }
    if (this->HasAttribute("contentType"))
    {
        adaptationSet->SetContentType(this->GetAttributeValue("contentType"));
    }
    if (this->HasAttribute("par"))
    {
        adaptationSet->SetPar(this->GetAttributeValue("par"));
    }
    if (this->HasAttribute("minBandwidth"))
    {
        adaptationSet->SetMinBandwidth(strtoul(this->GetAttributeValue("minBandwidth").c_str(), NULL, 10));
    }
    if (this->HasAttribute("maxBandwidth"))
    {
        adaptationSet->SetMaxBandwidth(strtoul(this->GetAttributeValue("maxBandwidth").c_str(), NULL, 10));
    }
    if (this->HasAttribute("minWidth"))
    {
        adaptationSet->SetMinWidth(strtoul(this->GetAttributeValue("minWidth").c_str(), NULL, 10));
    }
    if (this->HasAttribute("maxWidth"))
    {
        adaptationSet->SetMaxWidth(strtoul(this->GetAttributeValue("maxWidth").c_str(), NULL, 10));
    }
    if (this->HasAttribute("minHeight"))
    {
        adaptationSet->SetMinHeight(strtoul(this->GetAttributeValue("minHeight").c_str(), NULL, 10));
    }
    if (this->HasAttribute("maxHeight"))
    {
        adaptationSet->SetMaxHeight(strtoul(this->GetAttributeValue("maxHeight").c_str(), NULL, 10));
    }
    if (this->HasAttribute("minFrameRate"))
    {
        adaptationSet->SetMinFramerate(this->GetAttributeValue("minFrameRate"));
    }
    if (this->HasAttribute("maxFrameRate"))
    {
        adaptationSet->SetMaxFramerate(this->GetAttributeValue("maxFrameRate"));
    }
    if (this->HasAttribute("segmentAlignment"))
    {
        adaptationSet->SetSegmentAlignment(this->GetAttributeValue("segmentAlignment"));
    }
    if (this->HasAttribute("subsegmentAlignment"))
    {
        adaptationSet->SetSubsegmentAlignment(this->GetAttributeValue("subsegmentAlignment"));
    }
    if (this->HasAttribute("subsegmentStartsWithSAP"))
    {
        adaptationSet->SetMaxHeight((uint8_t) strtoul(this->GetAttributeValue("subsegmentStartsWithSAP").c_str(), NULL, 10));
    }
    if (this->HasAttribute("bitstreamSwitching"))
    {
        adaptationSet->SetBitstreamSwitching(dash::helpers::String::ToBool(this->GetAttributeValue("bitstreamSwitching")));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "Accessibility")
        {
            adaptationSet->AddAccessibity(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Role")
        {
            adaptationSet->AddRole(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Rating")
        {
            adaptationSet->AddRating(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Viewpoint")
        {
            adaptationSet->AddViewpoint(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "ContentComponent")
        {
            adaptationSet->AddContentComponent(subNodes.at(i)->ToContentComponent());
            continue;
        }
        if (subNodes.at(i)->GetName() == "BaseURL")
        {
            adaptationSet->AddBaseURL(subNodes.at(i)->ToBaseUrl());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentBase")
        {
            adaptationSet->SetSegmentBase(subNodes.at(i)->ToSegmentBase());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentList")
        {
            adaptationSet->SetSegmentList(subNodes.at(i)->ToSegmentList());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentTemplate")
        {
            adaptationSet->SetSegmentTemplate(subNodes.at(i)->ToSegmentTemplate());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Representation")
        {
            adaptationSet->AddRepresentation(subNodes.at(i)->ToRepresentation());
            continue;
        }
        if (subNodes.at(i)->GetName() != "FramePacking" && subNodes.at(i)->GetName() != "AudioChannelConfiguration" && subNodes.at(i)->GetName() != "ContentProtection")
            adaptationSet->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    adaptationSet->AddRawAttributes(this->attributes);
    return adaptationSet;
}
dash::mpd::Subset*                          Node::ToSubset              ()  const
{
    dash::mpd::Subset *subset = new dash::mpd::Subset();

    if (this->HasAttribute("contains"))
    {
        subset->SetSubset(this->GetAttributeValue("contains"));
    }

    subset->AddRawAttributes(this->attributes);
    return subset;
}
dash::mpd::Period*                          Node::ToPeriod              ()  const
{
    dash::mpd::Period *period = new dash::mpd::Period();
    std::vector<Node *> subNodes = this->GetSubNodes();

    if (this->HasAttribute("xlink:href"))
    {
        period->SetXlinkHref(this->GetAttributeValue("xlink:href"));
    }
    if (this->HasAttribute("xlink:actuate"))
    {
        period->SetXlinkActuate(this->GetAttributeValue("xlink:actuate"));
    }
    if (this->HasAttribute("id"))
    {
        period->SetId(this->GetAttributeValue("id"));
    }
    if (this->HasAttribute("start"))
    {
        period->SetStart(this->GetAttributeValue("start"));
    }
    if (this->HasAttribute("duration"))
    {
        period->SetDuration(this->GetAttributeValue("duration"));
    }
    if (this->HasAttribute("bitstreamSwitching"))
    {
        period->SetBitstreamSwitching(dash::helpers::String::ToBool(this->GetAttributeValue("bitstreamSwitching")));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "BaseURL")
        {
            period->AddBaseURL(subNodes.at(i)->ToBaseUrl());
            continue;
        }
        if (subNodes.at(i)->GetName() == "AdaptationSet")
        {
            period->AddAdaptationSet(subNodes.at(i)->ToAdaptationSet());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Subset")
        {
            period->AddSubset(subNodes.at(i)->ToSubset());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentBase")
        {
            period->SetSegmentBase(subNodes.at(i)->ToSegmentBase());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentList")
        {
            period->SetSegmentList(subNodes.at(i)->ToSegmentList());
            continue;
        }
        if (subNodes.at(i)->GetName() == "SegmentTemplate")
        {
            period->SetSegmentTemplate(subNodes.at(i)->ToSegmentTemplate());
            continue;
        }
        period->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }    

    period->AddRawAttributes(this->attributes);
    return period;
}
dash::mpd::Range*                           Node::ToRange               ()  const
{
    dash::mpd::Range* range = new dash::mpd::Range();

    if (this->HasAttribute("starttime"))
    {
        range->SetStarttime(this->GetAttributeValue("starttime"));
    }
    if (this->HasAttribute("duration"))
    {
        range->SetDuration(this->GetAttributeValue("duration"));
    }

    return range;
}
dash::mpd::Metrics*                         Node::ToMetrics             ()  const
{
    dash::mpd::Metrics* metrics = new dash::mpd::Metrics();

    if (this->HasAttribute("metrics"))
    {
        metrics->SetMetrics(this->GetAttributeValue("metrics"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "Reporting")
        {
            metrics->AddReporting(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Range")
        {
            metrics->AddRange(subNodes.at(i)->ToRange());
            continue;
        }
        metrics->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    metrics->AddRawAttributes(this->attributes);
    return metrics;
}
dash::mpd::MPD*                             Node::ToMPD                 ()  const
{
    dash::mpd::MPD *mpd = new dash::mpd::MPD();
    std::vector<Node *> subNodes = this->GetSubNodes();

    if (this->HasAttribute("id"))
    {
        mpd->SetId(this->GetAttributeValue("id"));
    }
    if (this->HasAttribute("profiles"))
    {
        mpd->SetProfiles(this->GetAttributeValue("profiles"));
    }
    if (this->HasAttribute("type"))
    {
        mpd->SetType(this->GetAttributeValue("type"));
    }
    if (this->HasAttribute("availabilityStartTime"))
    {
        mpd->SetAvailabilityStarttime(this->GetAttributeValue("availabilityStartTime"));
    }
    if (this->HasAttribute("availabilityEndTime"))
    {
        mpd->SetAvailabilityEndtime(this->GetAttributeValue("availabilityEndTime"));
    }
    if (this->HasAttribute("mediaPresentationDuration"))
    {
        mpd->SetMediaPresentationDuration(this->GetAttributeValue("mediaPresentationDuration"));
    }
    if (this->HasAttribute("minimumUpdatePeriod"))
    {
        mpd->SetMinimumUpdatePeriod(this->GetAttributeValue("minimumUpdatePeriod"));
    }
    if (this->HasAttribute("minBufferTime"))
    {
        mpd->SetMinBufferTime(this->GetAttributeValue("minBufferTime"));
    }
    if (this->HasAttribute("timeShiftBufferDepth"))
    {
        mpd->SetTimeShiftBufferDepth(this->GetAttributeValue("timeShiftBufferDepth"));
    }
    if (this->HasAttribute("suggestedPresentationDelay"))
    {
        mpd->SetSuggestedPresentationDelay(this->GetAttributeValue("suggestedPresentationDelay"));
    }
    if (this->HasAttribute("maxSegmentDuration"))
    {
        mpd->SetMaxSegmentDuration(this->GetAttributeValue("maxSegmentDuration"));
    }
    if (this->HasAttribute("maxSubsegmentDuration"))
    {
        mpd->SetMaxSubsegmentDuration(this->GetAttributeValue("maxSubsegmentDuration"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "ProgramInformation")
        {
            mpd->AddProgramInformation(subNodes.at(i)->ToProgramInformation());
            continue;
        }
        if (subNodes.at(i)->GetName() == "BaseURL")
        {
            mpd->AddBaseUrl(subNodes.at(i)->ToBaseUrl());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Location")
        {
            mpd->AddLocation(subNodes.at(i)->GetText());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Period")
        {
            mpd->AddPeriod(subNodes.at(i)->ToPeriod());
            continue;
        }
        if (subNodes.at(i)->GetName() == "Metrics")
        {
            mpd->AddMetrics(subNodes.at(i)->ToMetrics());
            continue;
        }
        mpd->AddAdditionalSubNode((xml::INode *) new Node(*(subNodes.at(i))));
    }

    dash::mpd::BaseUrl *mpdPathBaseUrl = new dash::mpd::BaseUrl();
    mpdPathBaseUrl->SetUrl(mpdPath);
    mpd->SetMPDPathBaseUrl(mpdPathBaseUrl);

    mpd->AddRawAttributes(this->attributes);
    return mpd;
}
void                                        Node::SetMPDPath            (std::string path)
{
    this->mpdPath = path;
}

const std::vector<INode*>&                  Node::GetNodes              ()  const
{
    return (std::vector<INode*> &) this->subNodes;
}
const std::vector<Node*>&                   Node::GetSubNodes           ()  const
{
    return this->subNodes;
}
void                                        Node::AddSubNode            (Node *node)
{
    this->subNodes.push_back(node);
}
const std::string&                          Node::GetName               ()  const
{
    return this->name;
}
void                                        Node::SetName               (const std::string &name)
{
    this->name = name;
}
const std::string&                          Node::GetAttributeValue     (std::string key)   const
{
    //return this->attributes[key];
    return this->attributes.find(key)->second;
}
bool                                        Node::HasAttribute          (const std::string& name) const
{
    if(this->attributes.find(name) != this->attributes.end())
        return true;

    return false;
}
void                                        Node::AddAttribute          (const std::string &key, const std::string &value)
{
    this->attributes[key] = value;
}
std::vector<std::string>                    Node::GetAttributeKeys      ()  const
{
    std::vector<std::string> keys;
    std::map<std::string, std::string>::const_iterator it;

    for(it = this->attributes.begin(); it != this->attributes.end(); ++it)
    {
        keys.push_back(it->first);
    }
    return keys;
}
bool                                        Node::HasText               ()  const
{
    return false;
}
std::string                                 Node::GetText               () const
{
    if(this->type == 3)
        return this->text;
    else
    {
        if(this->subNodes.size())
            return this->subNodes[0]->GetText();
        else
            return "";
    }
}
void                                        Node::SetText               (const std::string &text)
{
    this->text = text;
}
void                                        Node::Print                 (std::ostream &stream)  const
{
    stream << this->name;
    std::vector<std::string> keys = this->GetAttributeKeys();
    for(size_t i = 0; i < keys.size(); i++)
        stream << " " << keys.at(i) << "=" << this->GetAttributeValue(keys.at(i));

    stream << std::endl;
}
const std::map<std::string,std::string>&    Node::GetAttributes         ()  const
{
    return this->attributes;
}
int                                         Node::GetType               ()  const
{
    return this->type;
}
void                                        Node::SetType               (int type)
{
    this->type = type;
}
void                                        Node::SetCommonValuesForRep (dash::mpd::RepresentationBase& object) const
{
    std::vector<Node *> subNodes = this->GetSubNodes();

    if (this->HasAttribute("profiles"))
    {
        object.SetProfiles(this->GetAttributeValue("profiles"));
    }
    if (this->HasAttribute("width"))
    {
        object.SetWidth(strtoul(this->GetAttributeValue("width").c_str(), NULL, 10));
    }
    if (this->HasAttribute("height"))
    {
        object.SetHeight(strtoul(this->GetAttributeValue("height").c_str(), NULL, 10));
    }
    if (this->HasAttribute("sar"))
    {
        object.SetSar(this->GetAttributeValue("sar"));
    }
    if (this->HasAttribute("frameRate"))
    {
        object.SetFrameRate(this->GetAttributeValue("frameRate"));
    }
    if (this->HasAttribute("audioSamplingRate"))
    {
        object.SetAudioSamplingRate(this->GetAttributeValue("audioSamplingRate"));
    }
    if (this->HasAttribute("mimeType"))
    {
        object.SetMimeType(this->GetAttributeValue("mimeType"));
    }
    if (this->HasAttribute("segmentProfiles"))
    {
        object.SetSegmentProfiles(this->GetAttributeValue("segmentProfiles"));
    }
    if (this->HasAttribute("codecs"))
    {
        object.SetCodecs(this->GetAttributeValue("codecs"));
    }
    if (this->HasAttribute("maximumSAPPeriod"))
    {
        object.SetMaximumSAPPeriod(strtod(this->GetAttributeValue("maximumSAPPeriod").c_str(), NULL));
    }
    if (this->HasAttribute("startWithSAP"))
    {
        object.SetStartWithSAP((uint8_t) strtoul(this->GetAttributeValue("startWithSAP").c_str(), NULL, 10));
    }
    if (this->HasAttribute("maxPlayoutRate"))
    {
        object.SetMaxPlayoutRate(strtod(this->GetAttributeValue("maxPlayoutRate").c_str(), NULL));
    }
    if (this->HasAttribute("codingDependency"))
    {
        object.SetCodingDependency(dash::helpers::String::ToBool(this->GetAttributeValue("codingDependency")));
    }
    if (this->HasAttribute("scanType"))
    {
        object.SetScanType(this->GetAttributeValue("scanType"));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "FramePacking")
        {
            object.AddFramePacking(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "AudioChannelConfiguration")
        {
            object.AddAudioChannelConfiguration(subNodes.at(i)->ToDescriptor());
            continue;
        }
        if (subNodes.at(i)->GetName() == "ContentProtection")
        {
            object.AddContentProtection(subNodes.at(i)->ToDescriptor());
            continue;
        }
    }
}
void                                        Node::SetCommonValuesForSeg (dash::mpd::SegmentBase& object) const
{
    std::vector<Node *> subNodes = this->GetSubNodes();

    if (this->HasAttribute("timescale"))
    {
        object.SetTimescale(strtoul(this->GetAttributeValue("timescale").c_str(), NULL, 10));
    }
    if (this->HasAttribute("presentationTimeOffset"))
    {
        object.SetPresentationTimeOffset(strtoul(this->GetAttributeValue("presentationTimeOffset").c_str(), NULL, 10));
    }
    if (this->HasAttribute("indexRange"))
    {
        object.SetIndexRange(this->GetAttributeValue("indexRange"));
    }
    if (this->HasAttribute("indexRangeExact"))
    {
        object.SetIndexRangeExact(dash::helpers::String::ToBool(this->GetAttributeValue("indexRangeExact")));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "Initialization")
        {
            object.SetInitialization(subNodes.at(i)->ToURLType(dash::metrics::InitializationSegment));
            continue;
        }
        if (subNodes.at(i)->GetName() == "RepresentationIndex")
        {
            object.SetRepresentationIndex(subNodes.at(i)->ToURLType(dash::metrics::IndexSegment));
            continue;
        }
    }
}
void                                        Node::SetCommonValuesForMSeg(dash::mpd::MultipleSegmentBase& object) const
{
    std::vector<Node *> subNodes = this->GetSubNodes();

    SetCommonValuesForSeg(object);

    if (this->HasAttribute("duration"))
    {
        object.SetDuration(strtoul(this->GetAttributeValue("duration").c_str(), NULL, 10));
    }
    if (this->HasAttribute("startNumber"))
    {
        object.SetStartNumber(strtoul(this->GetAttributeValue("startNumber").c_str(), NULL, 10));
    }

    for(size_t i = 0; i < subNodes.size(); i++)
    {
        if (subNodes.at(i)->GetName() == "SegmentTimeline")
        {
            object.SetSegmentTimeline(subNodes.at(i)->ToSegmentTimeline());
            continue;
        }
        if (subNodes.at(i)->GetName() == "BitstreamSwitching")
        {
            object.SetBitstreamSwitching(subNodes.at(i)->ToURLType(dash::metrics::BitstreamSwitchingSegment));
            continue;
        }
    }

}