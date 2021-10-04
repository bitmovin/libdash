/*
 * Period.h
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

#ifndef PERIOD_H_
#define PERIOD_H_

#include "config.h"

#include "IPeriod.h"
#include "BaseUrl.h"
#include "AdaptationSet.h"
#include "Subset.h"
#include "SegmentBase.h"
#include "SegmentList.h"
#include "SegmentTemplate.h"
#include "Descriptor.h"
#include "Label.h"
#include "EventStream.h"
#include "ContentProtection.h"
#include "ServiceDescription.h"
#include "Preselection.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Period : public IPeriod, public AbstractMPDElement
        {
            public:
                Period          ();
                virtual ~Period ();

                const std::vector<IBaseUrl *>&            GetBaseURLs               ()  const;
                ISegmentBase*                             GetSegmentBase            ()  const;
                ISegmentList*                             GetSegmentList            ()  const;
                ISegmentTemplate*                         GetSegmentTemplate        ()  const;
                const IDescriptor *                       GetAssetIdentifier        ()  const;
                const std::vector<IEventStream *>&        GetEventStreams           ()  const;
                const std::vector<IServiceDescription *>& GetServiceDescriptions    ()  const;
                const std::vector<IContentProtection *>&  GetContentProtections     ()  const;
                const std::vector<IAdaptationSet *>&      GetAdaptationSets         ()  const;
                const std::vector<ISubset *>&             GetSubsets                ()  const;
                const std::vector<IDescriptor *>&         GetSupplementalProperties ()  const;
                const std::vector<ILabel *>&              GetGroupLabels            ()  const;
                const std::vector<IPreselection *>&       GetPreselections          ()  const;
                const std::string&                        GetXlinkHref              ()  const;
                const std::string&                        GetXlinkActuate           ()  const;
                const std::string&                        GetXlinkType              ()  const;
                const std::string&                        GetXlinkShow              ()  const;
                const std::string&                        GetId                     ()  const;
                const std::string&                        GetStart                  ()  const;
                const std::string&                        GetDuration               ()  const;
                bool                                      GetBitstreamSwitching     ()  const;

                void    AddBaseURL                  (BaseUrl *baseURL);
                void    SetSegmentBase              (SegmentBase *segmentBase);
                void    SetSegmentList              (SegmentList *segmentList);
                void    SetSegmentTemplate          (SegmentTemplate *segmentTemplate);
                void    SetAssetIdentifier          (Descriptor *assetIdentifier);
                void    AddEventStream              (EventStream *eventStream);
                void    AddServiceDescription       (ServiceDescription* serviceDescription);
                void    AddContentProtection        (ContentProtection *contentProtection);
                void    AddAdaptationSet            (AdaptationSet *AdaptationSet);
                void    AddSubset                   (Subset *subset);
                void    AddSupplementalProperty     (Descriptor *supplementalProperty);
                void    AddGroupLabel               (Label *groupLabel);
                void    AddPreselection             (Preselection *preselection);
                void    SetXlinkHref                (const std::string& xlinkHref);
                void    SetXlinkActuate             (const std::string& xlinkActuate);
                void    SetXlinkType                (const std::string& xlinkType);
                void    SetXlinkShow                (const std::string& xlinkShow);
                void    SetId                       (const std::string& id);
                void    SetStart                    (const std::string& start);
                void    SetDuration                 (const std::string& duration);
                void    SetBitstreamSwitching       (bool value);

            private:
                std::vector<BaseUrl *>              baseURLs;
                SegmentBase                         *segmentBase;
                SegmentList                         *segmentList;
                SegmentTemplate                     *segmentTemplate;
                Descriptor                          *assetIdentifier;
                std::vector<EventStream *>          eventStreams;
                std::vector<ServiceDescription *>   serviceDescriptions;
                std::vector<ContentProtection *>    contentProtections;
                std::vector<AdaptationSet *>        adaptationSets;
                std::vector<Subset *>               subsets;
                std::vector<Descriptor *>           supplementalProperties;
                std::vector<Label *>                groupLabels;
                std::vector<Preselection *>         preselections;
                std::string                         xlinkHref;
                std::string                         xlinkActuate;
                std::string                         xlinkType;
                std::string                         xlinkShow;
                std::string                         id;
                std::string                         start;
                std::string                         duration;
                bool                                isBitstreamSwitching;
        };
    }
}

#endif /* PERIOD_H_ */
