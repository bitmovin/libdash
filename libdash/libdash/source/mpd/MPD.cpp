/*
 * MPD.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MPD.h"

using namespace dash::mpd;
using namespace dash::metrics;

MPD::MPD    () :
        id(""),
        type("static"),
        availabilityStarttime(""),
        availabilityEndtime(""),
        mediaPresentationDuration(""),
        minimumUpdatePeriod(""),
        minBufferTime(""),
        timeShiftBufferDepth(""),
        suggestedPresentationDelay(""),
        maxSegmentDuration(""),
        maxSubsegmentDuration("")
{
}
MPD::~MPD   ()
{
    for(size_t i = 0; i < this->programInformations.size(); i++)
        delete(this->programInformations.at(i));
    for(size_t i = 0; i < this->metrics.size(); i++)
        delete(this->metrics.at(i));
    for(size_t i = 0; i < this->periods.size(); i++)
        delete(this->periods.at(i));
    for(size_t i = 0; i < this->baseUrls.size(); i++)
        delete(this->baseUrls.at(i));
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
