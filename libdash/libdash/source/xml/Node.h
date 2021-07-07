/*
 * Node.h
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

#ifndef NODE_H_
#define NODE_H_

#include "config.h"

#include "INode.h"
#include "../helpers/String.h"
#include "../mpd/AdaptationSet.h"
#include "../mpd/BaseUrl.h"
#include "../mpd/ContentComponent.h"
#include "../mpd/ContentPopularityRate.h"
#include "../mpd/ContentProtection.h"
#include "../mpd/Descriptor.h"
#include "../mpd/Event.h"
#include "../mpd/EventStream.h"
#include "../mpd/ExtendedBandwidth.h"
#include "../mpd/FailoverContent.h"
#include "../mpd/FCS.h"
#include "../mpd/InitializationSet.h"
#include "../mpd/Label.h"
#include "../mpd/Latency.h"
#include "../mpd/LeapSecondInformation.h"
#include "../mpd/Metrics.h"
#include "../mpd/ModelPair.h"
#include "../mpd/MPD.h"
#include "../mpd/MultipleSegmentBase.h"
#include "../mpd/OperatingQuality.h"
#include "../mpd/OperatingBandwidth.h"
#include "../mpd/PatchLocation.h"
#include "../mpd/Period.h"
#include "../mpd/PlaybackRate.h"
#include "../mpd/PopularityRate.h"
#include "../mpd/Preselection.h"
#include "../mpd/ProducerReferenceTime.h"
#include "../mpd/ProgramInformation.h"
#include "../mpd/RandomAccess.h"
#include "../mpd/Range.h"
#include "../mpd/Representation.h"
#include "../mpd/RepresentationBase.h"
#include "../mpd/Resync.h"
#include "../mpd/SegmentBase.h"
#include "../mpd/SegmentList.h"
#include "../mpd/SegmentTemplate.h"
#include "../mpd/SegmentTimeline.h"
#include "../mpd/SegmentURL.h"
#include "../mpd/ServiceDescription.h"
#include "../mpd/SubRepresentation.h"
#include "../mpd/Subset.h"
#include "../mpd/Switching.h"
#include "../mpd/URLType.h"
#include "../mpd/UIntPairs.h"
#include "../mpd/UIntPairsWithID.h"
#include "../mpd/UIntVWithID.h"
#include "IHTTPTransaction.h"

namespace dash
{
    namespace xml
    {
        class Node : public INode
        {
            public:
                Node            ();
                Node            (const Node& other);
                virtual ~Node   ();

                const std::vector<INode *>&                 GetNodes            ()  const;
                const std::vector<Node *>&                  GetSubNodes         ()  const;
                std::vector<std::string>                    GetAttributeKeys    ()  const;
                const std::string&                          GetName             ()  const;
                std::string                                 GetText             ()  const;
                const std::map<std::string, std::string>&   GetAttributes       ()  const;
                int                                         GetType             ()  const;
                void                                        SetType             (int type);
                const std::string&                          GetAttributeValue   (std::string key) const;
                void                                        AddSubNode          (Node *node);
                void                                        SetName             (const std::string &name);
                bool                                        HasAttribute        (const std::string& name) const;
                void                                        AddAttribute        (const std::string &key, const std::string &value);
                bool                                        HasText             ()  const;
                void                                        SetText             (const std::string &text);
                void                                        Print               (std::ostream &stream)  const;
                dash::mpd::MPD*                             ToMPD               ()  const;
                void                                        SetMPDPath          (std::string path);

            private:
                void                                        SetCommonValuesForDesc  (dash::mpd::Descriptor& object) const;
                void                                        SetCommonValuesForRep   (dash::mpd::RepresentationBase& object) const;
                void                                        SetCommonValuesForSeg   (dash::mpd::SegmentBase& object) const;
                void                                        SetCommonValuesForMSeg  (dash::mpd::MultipleSegmentBase& object) const;
                dash::mpd::AdaptationSet*                   ToAdaptationSet         ()  const;
                dash::mpd::BaseUrl*                         ToBaseUrl               ()  const;
                dash::mpd::ContentComponent*                ToContentComponent      ()  const;
                dash::mpd::ContentPopularityRate*           ToContentPopularityRate ()  const;
                dash::mpd::ContentProtection*               ToContentProtection     ()  const;
                dash::mpd::Descriptor*                      ToDescriptor            ()  const;
                dash::mpd::Event*                           ToEvent                 ()  const;
                dash::mpd::EventStream*                     ToEventStream           ()  const;
                dash::mpd::ExtendedBandwidth*               ToExtendedBandwidth     ()  const;
                dash::mpd::FailoverContent*                 ToFailoverContent       ()  const;
                dash::mpd::FCS*                             ToFCS                   ()  const;
                dash::mpd::InitializationSet*               ToInitializationSet     ()  const;
                dash::mpd::Label*                           ToLabel                 ()  const;
                dash::mpd::LeapSecondInformation*           ToLeapSecondInformation ()  const;
                dash::mpd::Latency*                         ToLatency               ()  const;
                dash::mpd::Metrics*                         ToMetrics               ()  const;
                dash::mpd::ModelPair*                       ToModelPair             ()  const;
                dash::mpd::OperatingBandwidth*              ToOperatingBandwidth    ()  const;
                dash::mpd::OperatingQuality*                ToOperatingQuality      ()  const;
                dash::mpd::PatchLocation*                   ToPatchLocation         ()  const;
                dash::mpd::Period*                          ToPeriod                ()  const;
                dash::mpd::PlaybackRate*                    ToPlaybackRate          ()  const;
                dash::mpd::PopularityRate*                  ToPopularityRate        ()  const;
                dash::mpd::Preselection*                    ToPreselection          ()  const;
                dash::mpd::ProducerReferenceTime*           ToProducerReferenceTime ()  const;
                dash::mpd::ProgramInformation*              ToProgramInformation    ()  const;
                dash::mpd::RandomAccess*                    ToRandomAccess          ()  const;
                dash::mpd::Range*                           ToRange                 ()  const;
                dash::mpd::Representation*                  ToRepresentation        ()  const;
                dash::mpd::Resync*                          ToResync                ()  const;
                dash::mpd::SegmentBase*                     ToSegmentBase           ()  const;
                dash::mpd::SegmentList*                     ToSegmentList           ()  const;
                dash::mpd::SegmentTemplate*                 ToSegmentTemplate       ()  const;
                dash::mpd::ServiceDescription*              ToServiceDescription    ()  const;
                dash::mpd::Timeline*                        ToTimeline              ()  const;
                dash::mpd::SegmentTimeline*                 ToSegmentTimeline       ()  const;
                dash::mpd::SegmentURL*                      ToSegmentURL            ()  const;
                dash::mpd::SubRepresentation*               ToSubRepresentation     ()  const;
                dash::mpd::Subset*                          ToSubset                ()  const;
                dash::mpd::Switching*                       ToSwitching             ()  const;
                dash::mpd::UIntPairsWithID*                 ToUIntPairsWithID       ()  const;
                dash::mpd::UIntVWithID*                     ToUIntVWithID           ()  const;
                dash::mpd::URLType*                         ToURLType               (dash::metrics::HTTPTransactionType transActType)  const;

                std::vector<Node *>                 subNodes;
                std::map<std::string, std::string>  attributes;
                std::string                         name;
                std::string                         text;
                int                                 type;
                std::string                         mpdPath;

        };
    }
}

#endif /* NODE_H_ */
