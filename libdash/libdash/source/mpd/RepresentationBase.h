/*
 * RepresentationBase.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef REPRESENTATIONBASE_H_
#define REPRESENTATIONBASE_H_

#include "config.h"

#include "IRepresentationBase.h"
#include "Descriptor.h"
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

                const std::vector<IDescriptor *>&   GetFramePacking                 () const;
                const std::vector<IDescriptor *>&   GetAudioChannelConfiguration    () const;
                const std::vector<IDescriptor *>&   GetContentProtection            () const;
                const std::vector<std::string>&     GetProfiles                     () const;
                uint32_t                            GetWidth                        () const;
                uint32_t                            GetHeight                       () const;
                std::string                         GetSar                          () const;
                std::string                         GetFrameRate                    () const;
                std::string                         GetAudioSamplingRate            () const;
                std::string                         GetMimeType                     () const;
                const std::vector<std::string>&     GetSegmentProfiles              () const;
                const std::vector<std::string>&     GetCodecs                       () const;
                double                              GetMaximumSAPPeriod             () const;
                uint8_t                             GetStartWithSAP                 () const;
                double                              GetMaxPlayoutRate               () const;
                bool                                HasCodingDependency             () const;
                std::string                         GetScanType                     () const;

                void    AddFramePacking                 (Descriptor *framePacking);
                void    AddAudioChannelConfiguration    (Descriptor *audioChannelConfiguration);
                void    AddContentProtection            (Descriptor *contentProtection);
                void    SetProfiles                     (const std::string& profiles);
                void    SetWidth                        (uint32_t width);
                void    SetHeight                       (uint32_t height);
                void    SetSar                          (const std::string& sar);
                void    SetFrameRate                    (const std::string& frameRate);
                void    SetAudioSamplingRate            (const std::string& audioSamplingRate);
                void    SetMimeType                     (const std::string& mimeType);
                void    SetSegmentProfiles              (const std::string& segmentProfiles);
                void    SetCodecs                       (const std::string& codecs);
                void    SetMaximumSAPPeriod             (double maximumSAPPeroid);
                void    SetStartWithSAP                 (uint8_t startWithSAP);
                void    SetMaxPlayoutRate               (double maxPlayoutRate);
                void    SetCodingDependency             (bool codingDependency);
                void    SetScanType                     (const std::string& scanType);

            protected:
                std::vector<Descriptor *>   framePacking;
                std::vector<Descriptor *>   audioChannelConfiguration;
                std::vector<Descriptor *>   contentProtection;
                std::vector<std::string>    profiles;
                uint32_t                    width;
                uint32_t                    height;
                std::string                 sar;
                std::string                 frameRate;
                std::string                 audioSamplingRate;
                std::string                 mimeType;
                std::vector<std::string>    segmentProfiles;
                std::vector<std::string>    codecs;
                double                      maximumSAPPeriod;
                uint8_t                     startWithSAP;
                double                      maxPlayoutRate;
                bool                        codingDependency;
                std::string                 scanType;
        };
    }
}
#endif /* REPRESENTATIONBASE_H_ */
