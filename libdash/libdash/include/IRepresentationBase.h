/*
 * IRepresentationBase.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IREPRESENTATIONBASE_H_
#define IREPRESENTATIONBASE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"

namespace dash
{
    namespace mpd
    {
        class IRepresentationBase : public virtual IMPDElement
        {
            public:
                virtual ~IRepresentationBase(){}

                virtual const std::vector<IDescriptor *>&   GetFramePacking                 () const = 0;
                virtual const std::vector<IDescriptor *>&   GetAudioChannelConfiguration    () const = 0;
                virtual const std::vector<IDescriptor *>&   GetContentProtection            () const = 0;
                virtual const std::vector<std::string>&     GetProfiles                     () const = 0;
                virtual uint32_t                            GetWidth                        () const = 0;
                virtual uint32_t                            GetHeight                       () const = 0;
                virtual std::string                         GetSar                          () const = 0;
                virtual std::string                         GetFrameRate                    () const = 0;
                virtual std::string                         GetAudioSamplingRate            () const = 0;
                virtual std::string                         GetMimeType                     () const = 0;
                virtual const std::vector<std::string>&     GetSegmentProfiles              () const = 0;
                virtual const std::vector<std::string>&     GetCodecs                       () const = 0;
                virtual double                              GetMaximumSAPPeriod             () const = 0;
                virtual uint8_t                             GetStartWithSAP                 () const = 0;
                virtual double                              GetMaxPlayoutRate               () const = 0;
                virtual bool                                HasCodingDependency             () const = 0;
                virtual std::string                         GetScanType                     () const = 0;

        };
    }
}

#endif /* IREPRESENTATIONBASE_H_ */