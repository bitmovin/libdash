/*
 * RepresentationBase.h
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

#ifndef REPRESENTATIONBASE_H_
#define REPRESENTATIONBASE_H_

#include "config.h"

#include "IRepresentationBase.h"
#include "ContentProtection.h"
#include "Descriptor.h"
#include "EventStream.h"
#include "Label.h"
#include "Switching.h"
#include "ContentPopularityRate.h"
#include "ProducerReferenceTime.h"
#include "RandomAccess.h"
#include "Resync.h"
#include "../helpers/String.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class RepresentationBase : public virtual IRepresentationBase, public AbstractMPDElement
        {
            public:
                RepresentationBase          ();
                virtual ~RepresentationBase ();

                const std::vector<IDescriptor *>&              GetFramePacking                 () const;
                const std::vector<IDescriptor *>&              GetAudioChannelConfiguration    () const;
                const std::vector<IContentProtection *>&       GetContentProtections           () const;
                const IDescriptor *                            GetOutputProtection             () const;
                const std::vector<IDescriptor *>&              GetEssentialProperties          () const;
                const std::vector<IDescriptor *>&              GetSupplementalProperties       () const;
                const std::vector<IEventStream *>&             GetEventStreams                 () const;
                const std::vector<ISwitching *>&               GetSwitchings                   () const;
                const std::vector<IRandomAccess *>&            GetRandomAccesses               () const;
                const std::vector<ILabel *>&                   GetGroupLabels                  () const;
                const std::vector<ILabel *>&                   GetLabels                       () const;
                const std::vector<IContentPopularityRate *>&   GetContentPopularityRates       () const;
                const std::vector<IProducerReferenceTime *>&   GetProducerReferenceTimes       () const;
                const std::vector<IResync *>&                  GetResyncs                      () const;
                const std::vector<std::string>&                GetProfiles                     () const;
                uint32_t                                       GetWidth                        () const;
                uint32_t                                       GetHeight                       () const;
                std::string                                    GetSar                          () const;
                std::string                                    GetFrameRate                    () const;
                std::string                                    GetAudioSamplingRate            () const;
                std::string                                    GetMimeType                     () const;
                const std::vector<std::string>&                GetSegmentProfiles              () const;
                const std::vector<std::string>&                GetCodecs                       () const;
                const std::vector<std::string>&                GetContainerProfiles            () const;
                double                                         GetMaximumSAPPeriod             () const;
                uint8_t                                        GetStartWithSAP                 () const;
                double                                         GetMaxPlayoutRate               () const;
                bool                                           HasCodingDependency             () const;
                std::string                                    GetScanType                     () const;
                uint32_t                                       GetSelectionPriority            () const;
                std::string                                    GetTag                          () const;

                void    AddFramePacking                 (Descriptor *framePacking);
                void    AddAudioChannelConfiguration    (Descriptor *audioChannelConfiguration);
                void    AddContentProtection            (ContentProtection *contentProtection);
                void    SetOutputProtection             (Descriptor *outputProtection);
                void    AddEssentialProperty            (Descriptor *essentialProperty);
                void    AddSupplementalProperty         (Descriptor *supplementalProperty);
                void    AddEventStream                  (EventStream *eventStream);
                void    AddSwitching                    (Switching *switching);
                void    AddRandomAccess                 (RandomAccess *randomAccess);
                void    AddGroupLabel                   (Label *groupLabel);
                void    AddLabel                        (Label *label);
                void    AddContentPopularityRate        (ContentPopularityRate *contentPopularityRate);
                void    AddProducerReferenceTime        (ProducerReferenceTime *producerReferenceTime);
                void    AddResync                       (Resync *resync);
                void    SetProfiles                     (const std::string& profiles);
                void    SetWidth                        (uint32_t width);
                void    SetHeight                       (uint32_t height);
                void    SetSar                          (const std::string& sar);
                void    SetFrameRate                    (const std::string& frameRate);
                void    SetAudioSamplingRate            (const std::string& audioSamplingRate);
                void    SetMimeType                     (const std::string& mimeType);
                void    SetSegmentProfiles              (const std::string& segmentProfiles);
                void    SetCodecs                       (const std::string& codecs);
                void    SetContainerProfiles            (const std::string& containerProfiles);
                void    SetMaximumSAPPeriod             (double maximumSAPPeroid);
                void    SetStartWithSAP                 (uint8_t startWithSAP);
                void    SetMaxPlayoutRate               (double maxPlayoutRate);
                void    SetCodingDependency             (bool codingDependency);
                void    SetScanType                     (const std::string& scanType);
                void    SetSelectionPriority            (uint32_t selectionPriority);
                void    SetTag                          (const std::string& tag);

            protected:
                std::vector<Descriptor *>              framePacking;
                std::vector<Descriptor *>              audioChannelConfiguration;
                std::vector<ContentProtection *>       contentProtections;
                Descriptor*                            outputProtection;
                std::vector<Descriptor *>              essentialProperties;
                std::vector<Descriptor *>              supplementalProperties;
                std::vector<EventStream *>             eventStreams;
                std::vector<Switching *>               switchings;
                std::vector<RandomAccess *>            randomAccesses;
                std::vector<Label *>                   groupLabels;
                std::vector<Label *>                   labels;
                std::vector<ContentPopularityRate *>   contentPopularityRates;
                std::vector<ProducerReferenceTime *>   producerReferenceTimes;
                std::vector<Resync *>                  resyncs;
                std::vector<std::string>               profiles;
                uint32_t                               width;
                uint32_t                               height;
                std::string                            sar;
                std::string                            frameRate;
                std::string                            audioSamplingRate;
                std::string                            mimeType;
                std::vector<std::string>               segmentProfiles;
                std::vector<std::string>               codecs;
                std::vector<std::string>               containerProfiles;
                double                                 maximumSAPPeriod;
                uint8_t                                startWithSAP;
                double                                 maxPlayoutRate;
                bool                                   codingDependency;
                std::string                            scanType;
                uint32_t                               selectionPriority;
                std::string                            tag;
        };
    }
}
#endif /* REPRESENTATIONBASE_H_ */
