/*
 * MPD.cpp
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

#include "MPD.h"

using namespace dash::mpd;
using namespace dash::metrics;

MPD::MPD    () :
        leapSecondInformation(NULL),
        id(""),
        type("static"),
        availabilityStarttime(""),
        availabilityEndtime(""),
        publishTime(""),
        mediaPresentationDuration(""),
        minimumUpdatePeriod(""),
        minBufferTime(""),
        timeShiftBufferDepth(""),
        suggestedPresentationDelay(""),
        maxSegmentDuration(""),
        maxSubsegmentDuration("")
{
    this->mpdPathBaseUrl = NULL;
}
MPD::~MPD   ()
{
    for(size_t i = 0; i < this->programInformations.size(); i++)
        delete(this->programInformations.at(i));
    for(size_t i = 0; i < this->metrics.size(); i++)
        delete(this->metrics.at(i));
    for(size_t i = 0; i < this->essentialProperties.size(); i++)
        delete(this->essentialProperties.at(i));
    for(size_t i = 0; i < this->supplementalProperties.size(); i++)
        delete(this->supplementalProperties.at(i));
    for(size_t i = 0; i < this->utcTimings.size(); i++)
        delete(this->utcTimings.at(i));
    for(size_t i = 0; i < this->contentProtections.size(); i++)
        delete(this->contentProtections.at(i));
    for(size_t i = 0; i < this->periods.size(); i++)
        delete(this->periods.at(i));
    for(size_t i = 0; i < this->baseUrls.size(); i++)
        delete(this->baseUrls.at(i));
    for(size_t i = 0; i < this->serviceDescriptions.size(); i++)
        delete(this->serviceDescriptions.at(i));
    for(size_t i = 0; i < this->initializationSets.size(); i++)
        delete(this->initializationSets.at(i));
    for(size_t i = 0; i < this->initializationGroups.size(); i++)
        delete(this->initializationGroups.at(i));
    for(size_t i = 0; i < this->initializationPresentations.size(); i++)
        delete(this->initializationPresentations.at(i));
    if (this->mpdPathBaseUrl)
        delete(this->mpdPathBaseUrl);
    
    delete(leapSecondInformation);
}

const std::vector<IProgramInformation *>&   MPD::GetProgramInformations             () const 
{
    return (std::vector<IProgramInformation *> &) this->programInformations;
}
void                                        MPD::AddProgramInformation              (ProgramInformation *programInformation)
{
    this->programInformations.push_back(programInformation);
}
const std::vector<IBaseUrl*>&               MPD::GetBaseUrls                        () const
{
    return (std::vector<IBaseUrl*> &) this->baseUrls;
}
void                                        MPD::AddBaseUrl                         (BaseUrl *url)
{
    this->baseUrls.push_back(url);
}
const std::vector<std::string>&             MPD::GetLocations                       () const
{
    return this->locations;
}
void                                        MPD::AddLocation                        (const std::string& location)
{
    this->locations.push_back(location);
}
const std::vector<IPatchLocation*>&         MPD::GetPatchLocations                  () const
{
    return (std::vector<IPatchLocation*> &) this->patchLocations;
}
void                                        MPD::AddPatchLocation                   (PatchLocation *patchLocation)
{
    this->patchLocations.push_back(patchLocation);
}
const std::vector<IServiceDescription *>&   MPD::GetServiceDescriptions             () const 
{
    return (std::vector<IServiceDescription *> &) this->serviceDescriptions;
}
void                                        MPD::AddServiceDescription              (ServiceDescription *serviceDescription)
{
    this->serviceDescriptions.push_back(serviceDescription);
}
const std::vector<IInitializationSet *>&    MPD::GetInitializationSets              () const 
{
    return (std::vector<IInitializationSet *> &) this->initializationSets;
}
void                                        MPD::AddInitializationSet               (InitializationSet *initializationSet)
{
    this->initializationSets.push_back(initializationSet);
}
const std::vector<IUIntVWithID *>&          MPD::GetInitializationGroups            () const 
{
    return (std::vector<IUIntVWithID *> &) this->initializationGroups;
}
void                                        MPD::AddInitializationGroup             (UIntVWithID *initializationGroup)
{
    this->initializationGroups.push_back(initializationGroup);
}
const std::vector<IUIntVWithID *>&          MPD::GetInitializationPresentations     () const 
{
    return (std::vector<IUIntVWithID *> &) this->initializationPresentations;
}
void                                        MPD::AddInitializationPresentation      (UIntVWithID *initializationPresentation)
{
    this->initializationPresentations.push_back(initializationPresentation);
}
const std::vector<IContentProtection *>&    MPD::GetContentProtections              () const 
{
    return (std::vector<IContentProtection *> &) this->contentProtections;
}
void                                        MPD::AddContentProtection               (ContentProtection *contentProtection)
{
    this->contentProtections.push_back(contentProtection);
}
const std::vector<IPeriod*>&                MPD::GetPeriods                         () const 
{
    return (std::vector<IPeriod*> &) this->periods;
}
void                                        MPD::AddPeriod                          (Period *period)
{
    this->periods.push_back(period);
}
const std::vector<IMetrics *>&              MPD::GetMetrics                         () const 
{
    return (std::vector<IMetrics *> &) this->metrics;
}
void                                        MPD::AddMetrics                         (Metrics *metrics)
{
    this->metrics.push_back(metrics);
}
const std::vector<IDescriptor *>&           MPD::GetEssentialProperties             () const 
{
    return (std::vector<IDescriptor *> &) this->essentialProperties;
}
void                                        MPD::AddEssentialProperty               (Descriptor *essentialProperty)
{
    this->essentialProperties.push_back(essentialProperty);
}
const std::vector<IDescriptor *>&           MPD::GetSupplementalProperties          () const 
{
    return (std::vector<IDescriptor *> &) this->supplementalProperties;
}
void                                        MPD::AddSupplementalProperty            (Descriptor *supplementalProperty)
{
    this->supplementalProperties.push_back(supplementalProperty);
}
const std::vector<IDescriptor *>&           MPD::GetUTCTimings                      () const 
{
    return (std::vector<IDescriptor *> &) this->utcTimings;
}
void                                        MPD::AddUTCTiming                       (Descriptor *utcTiming)
{
    this->utcTimings.push_back(utcTiming);
}
const ILeapSecondInformation *              MPD::GetLeapSecondInformation           ()  const
{
    return this->leapSecondInformation;
}
void                                        MPD::SetLeapSecondInformation           (LeapSecondInformation *leapSecondInformation)
{
    this->leapSecondInformation = leapSecondInformation;
}
const std::string&                          MPD::GetId                              ()  const
{
    return this->id;
}
void                                        MPD::SetId                              (const std::string& id)
{
    this->id = id;
}
const std::vector<std::string>&             MPD::GetProfiles                        ()  const
{
    return this->profiles;
}
void                                        MPD::SetProfiles                        (const std::string& profiles)
{
    dash::helpers::String::Split(profiles, ',', this->profiles);
}
const std::string&                          MPD::GetType                            ()  const
{
    return this->type;
}
void                                        MPD::SetType                            (const std::string& type)
{
    this->type = type;
}
const std::string&                          MPD::GetAvailabilityStarttime           ()  const
{
    return this->availabilityStarttime;
}
void                                        MPD::SetAvailabilityStarttime           (const std::string& availabilityStarttime)
{
    this->availabilityStarttime = availabilityStarttime;
}
const std::string&                          MPD::GetPublishTime                     ()  const
{
    return this->publishTime;
}
void                                        MPD::SetPublishTime                     (const std::string& publishTime)
{
    this->publishTime = publishTime;
}
const std::string&                          MPD::GetAvailabilityEndtime             ()  const
{
    return this->availabilityEndtime;
}
void                                        MPD::SetAvailabilityEndtime             (const std::string& availabilityEndtime)
{
    this->availabilityEndtime = availabilityEndtime;
}
const std::string&                          MPD::GetMediaPresentationDuration       ()  const
{
    return this->mediaPresentationDuration;
}
void                                        MPD::SetMediaPresentationDuration       (const std::string& mediaPresentationDuration)
{
    this->mediaPresentationDuration = mediaPresentationDuration;
}
const std::string&                          MPD::GetMinimumUpdatePeriod             ()  const
{
    return this->minimumUpdatePeriod;
}
void                                        MPD::SetMinimumUpdatePeriod             (const std::string& minimumUpdatePeriod)
{
    this->minimumUpdatePeriod = minimumUpdatePeriod;
}
const std::string&                          MPD::GetMinBufferTime                   ()  const
{
    return this->minBufferTime;
}
void                                        MPD::SetMinBufferTime                   (const std::string& minBufferTime)
{
    this->minBufferTime = minBufferTime;
}
const std::string&                          MPD::GetTimeShiftBufferDepth            ()  const
{
    return this->timeShiftBufferDepth;
}
void                                        MPD::SetTimeShiftBufferDepth            (const std::string& timeShiftBufferDepth)
{
    this->timeShiftBufferDepth = timeShiftBufferDepth;
}
const std::string&                          MPD::GetSuggestedPresentationDelay      ()  const
{
    return this->suggestedPresentationDelay;
}
void                                        MPD::SetSuggestedPresentationDelay      (const std::string& suggestedPresentationDelay)
{
    this->suggestedPresentationDelay = suggestedPresentationDelay;
}
const std::string&                          MPD::GetMaxSegmentDuration              ()  const
{
    return this->maxSegmentDuration;
}
void                                        MPD::SetMaxSegmentDuration              (const std::string& maxSegmentDuration)
{
    this->maxSegmentDuration = maxSegmentDuration;
}
const std::string&                          MPD::GetMaxSubsegmentDuration           ()  const
{
    return this->maxSubsegmentDuration;
}
void                                        MPD::SetMaxSubsegmentDuration           (const std::string& maxSubsegmentDuration)
{
    this->maxSubsegmentDuration = maxSubsegmentDuration;
}
IBaseUrl*                                   MPD::GetMPDPathBaseUrl                  ()  const
{
    return this->mpdPathBaseUrl;
}
void                                        MPD::SetMPDPathBaseUrl                  (BaseUrl *mpdPath)
{
    this->mpdPathBaseUrl = mpdPath;
}
uint32_t                                    MPD::GetFetchTime                       ()  const
{
    return this->fetchTime;
}
void                                        MPD::SetFetchTime                       (uint32_t fetchTimeInSec)
{
    this->fetchTime = fetchTimeInSec;
}


const std::vector<ITCPConnection *>&        MPD::GetTCPConnectionList    () const
{
    return (std::vector<ITCPConnection *> &) this->tcpConnections;
}
void                                        MPD::AddTCPConnection        (TCPConnection *tcpConn)
{
    this->tcpConnections.push_back(tcpConn);
}
const std::vector<IHTTPTransaction *>&      MPD::GetHTTPTransactionList  () const
{
    return (std::vector<IHTTPTransaction *> &) this->httpTransactions;
}
void                                        MPD::AddHTTPTransaction      (HTTPTransaction *httpTransAct)
{
    this->httpTransactions.push_back(httpTransAct);
}
