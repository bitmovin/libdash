/*
 * MPD.h
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

#ifndef MPD_H_
#define MPD_H_

#include "config.h"

#include "IMPD.h"
#include "ProgramInformation.h"
#include "BaseUrl.h"
#include "ContentProtection.h"
#include "Descriptor.h"
#include "Period.h"
#include "Metrics.h"
#include "AbstractMPDElement.h"
#include "ServiceDescription.h"
#include "LeapSecondInformation.h"
#include "PatchLocation.h"
#include "InitializationSet.h"
#include "UIntVWithID.h"
#include "../metrics/HTTPTransaction.h"
#include "../metrics/TCPConnection.h"

namespace dash
{
    namespace mpd
    {
        class MPD : public IMPD, public AbstractMPDElement
        {
            public:
                MPD         ();
                virtual ~MPD();

                const std::vector<IProgramInformation *>&   GetProgramInformations          ()  const;
                const std::vector<IBaseUrl *>&              GetBaseUrls                     ()  const;
                const std::vector<std::string>&             GetLocations                    ()  const;
                const std::vector<IPatchLocation *>&        GetPatchLocations               ()  const;
                const std::vector<IServiceDescription *>&   GetServiceDescriptions          ()  const;
                const std::vector<IInitializationSet *>&    GetInitializationSets           ()  const;
                const std::vector<IUIntVWithID *>&          GetInitializationGroups         ()  const;
                const std::vector<IUIntVWithID *>&          GetInitializationPresentations  ()  const;
                const std::vector<IContentProtection *>&    GetContentProtections           ()  const;
                const std::vector<IPeriod *>&               GetPeriods                      ()  const;
                const std::vector<IMetrics *>&              GetMetrics                      ()  const;
                const std::vector<IDescriptor *>&           GetEssentialProperties          ()  const;
                const std::vector<IDescriptor *>&           GetSupplementalProperties       ()  const;
                const std::vector<IDescriptor *>&           GetUTCTimings                   ()  const;
                const ILeapSecondInformation *              GetLeapSecondInformation        ()  const;
                const std::string&                          GetId                           ()  const;
                const std::vector<std::string>&             GetProfiles                     ()  const;
                const std::string&                          GetType                         ()  const;
                const std::string&                          GetAvailabilityStarttime        ()  const;
                const std::string&                          GetAvailabilityEndtime          ()  const;
                const std::string&                          GetPublishTime                  ()  const;
                const std::string&                          GetMediaPresentationDuration    ()  const;
                const std::string&                          GetMinimumUpdatePeriod          ()  const;
                const std::string&                          GetMinBufferTime                ()  const;
                const std::string&                          GetTimeShiftBufferDepth         ()  const;
                const std::string&                          GetSuggestedPresentationDelay   ()  const;
                const std::string&                          GetMaxSegmentDuration           ()  const;
                const std::string&                          GetMaxSubsegmentDuration        ()  const;
                IBaseUrl*                                   GetMPDPathBaseUrl               ()  const;
                uint32_t                                    GetFetchTime                    ()  const;

                const std::vector<dash::metrics::ITCPConnection *>&     GetTCPConnectionList    () const;
                const std::vector<dash::metrics::IHTTPTransaction *>&   GetHTTPTransactionList  () const;
                void                                                    AddTCPConnection        (dash::metrics::TCPConnection *tcpConn);
                void                                                    AddHTTPTransaction      (dash::metrics::HTTPTransaction *httpTransAct);

                void    AddProgramInformation           (ProgramInformation *programInformation);
                void    AddBaseUrl                      (BaseUrl *url);
                void    AddLocation                     (const std::string& location);
                void    AddPatchLocation                (PatchLocation *patchLocation);
                void    AddServiceDescription           (ServiceDescription* serviceDescription);
                void    AddInitializationSet            (InitializationSet* initializationSet);
                void    AddInitializationGroup          (UIntVWithID* initializationGroup);
                void    AddInitializationPresentation   (UIntVWithID* initializationPresentation);
                void    AddContentProtection            (ContentProtection *contentProtection);
                void    AddPeriod                       (Period *period);
                void    AddMetrics                      (Metrics *metrics);
                void    AddEssentialProperty            (Descriptor *essentialProperty);
                void    AddSupplementalProperty         (Descriptor *supplementalProperty);
                void    AddUTCTiming                    (Descriptor *utcTiming);
                void    SetLeapSecondInformation        (LeapSecondInformation *leapSecondInformation);
                void    SetId                           (const std::string& id);
                void    SetProfiles                     (const std::string& profiles);
                void    SetType                         (const std::string& type);
                void    SetAvailabilityStarttime        (const std::string& availabilityStarttime);
                void    SetAvailabilityEndtime          (const std::string& availabilityEndtime);
                void    SetPublishTime                  (const std::string& publishTime);
                void    SetMediaPresentationDuration    (const std::string& mediaPresentationDuration);
                void    SetMinimumUpdatePeriod          (const std::string& minimumUpdatePeriod);
                void    SetMinBufferTime                (const std::string& minBufferTime);
                void    SetTimeShiftBufferDepth         (const std::string& timeShiftBufferDepth);
                void    SetSuggestedPresentationDelay   (const std::string& suggestedPresentationDelay);
                void    SetMaxSegmentDuration           (const std::string& maxSegmentDuration);
                void    SetMaxSubsegmentDuration        (const std::string& maxSubsegmentDuration);
                void    SetMPDPathBaseUrl               (BaseUrl *path);
                void    SetFetchTime                    (uint32_t fetchTimeInSec);

            private:
                std::vector<ProgramInformation *>   programInformations;
                std::vector<BaseUrl *>              baseUrls;
                std::vector<std::string>            locations;
                std::vector<PatchLocation *>        patchLocations;
                std::vector<ServiceDescription *>   serviceDescriptions;
                std::vector<InitializationSet *>    initializationSets;
                std::vector<UIntVWithID *>          initializationGroups;
                std::vector<UIntVWithID *>          initializationPresentations;
                std::vector<ContentProtection *>    contentProtections;
                std::vector<Period *>               periods;
                std::vector<Metrics *>              metrics;
                std::vector<Descriptor *>           essentialProperties;
                std::vector<Descriptor *>           supplementalProperties;
                std::vector<Descriptor *>           utcTimings;
                LeapSecondInformation               *leapSecondInformation;
                std::string                         id;
                std::vector<std::string>            profiles;
                std::string                         type;
                std::string                         availabilityStarttime;
                std::string                         availabilityEndtime;
                std::string                         publishTime;
                std::string                         mediaPresentationDuration;
                std::string                         minimumUpdatePeriod;
                std::string                         minBufferTime;
                std::string                         timeShiftBufferDepth;
                std::string                         suggestedPresentationDelay;
                std::string                         maxSegmentDuration;
                std::string                         maxSubsegmentDuration;
                BaseUrl                             *mpdPathBaseUrl;
                uint32_t                            fetchTime;

                std::vector<dash::metrics::TCPConnection *>     tcpConnections;
                std::vector<dash::metrics::HTTPTransaction *>   httpTransactions;
        };
    }
}
#endif /* MPD_H_ */
