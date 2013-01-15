/*
 * IAdaptationSet.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IADAPTATIONSET_H_
#define IADAPTATIONSET_H_

#include "config.h"

#include "IDescriptor.h"
#include "IContentComponent.h"
#include "IBaseUrl.h"
#include "ISegmentBase.h"
#include "ISegmentList.h"
#include "ISegmentTemplate.h"
#include "IRepresentation.h"
#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class IAdaptationSet : public virtual IRepresentationBase
        {
            public:
                virtual ~IAdaptationSet(){}

                virtual const std::vector<IDescriptor *>&       GetAccessibility                ()  const = 0;
                virtual const std::vector<IDescriptor *>&       GetRole                         ()  const = 0;
                virtual const std::vector<IDescriptor *>&       GetRating                       ()  const = 0;
                virtual const std::vector<IDescriptor *>&       GetViewpoint                    ()  const = 0;
                virtual const std::vector<IContentComponent *>& GetContentComponent             ()  const = 0;
                virtual const std::vector<IBaseUrl *>&          GetBaseURLs                     ()  const = 0;
                virtual ISegmentBase*                           GetSegmentBase                  ()  const = 0;
                virtual ISegmentList*                           GetSegmentList                  ()  const = 0;
                virtual ISegmentTemplate*                       GetSegmentTemplate              ()  const = 0;
                virtual const std::vector<IRepresentation *>&   GetRepresentation               ()  const = 0;
                virtual const std::string&                      GetXlinkHref                    ()  const = 0;
                virtual const std::string&                      GetXlinkActuate                 ()  const = 0;
                virtual uint32_t                                GetId                           ()  const = 0;
                virtual uint32_t                                GetGroup                        ()  const = 0;
                virtual const std::string&                      GetLang                         ()  const = 0;
                virtual const std::string&                      GetContentType                  ()  const = 0;
                virtual const std::string&                      GetPar                          ()  const = 0;
                virtual uint32_t                                GetMinBandwidth                 ()  const = 0;
                virtual uint32_t                                GetMaxBandwidth                 ()  const = 0;
                virtual uint32_t                                GetMinWidth                     ()  const = 0;
                virtual uint32_t                                GetMaxWidth                     ()  const = 0;
                virtual uint32_t                                GetMinHeight                    ()  const = 0;
                virtual uint32_t                                GetMaxHeight                    ()  const = 0;
                virtual const std::string&                      GetMinFramerate                 ()  const = 0;
                virtual const std::string&                      GetMaxFramerate                 ()  const = 0;
                virtual bool                                    SegmentAlignmentIsBoolValue     ()  const = 0;
                virtual bool                                    HasSegmentAlignment             ()  const = 0;
                virtual uint32_t                                GetSegmentAligment              ()  const = 0;
                virtual bool                                    SubsegmentAlignmentIsBoolValue  ()  const = 0;
                virtual bool                                    HasSubsegmentAlignment          ()  const = 0;
                virtual uint32_t                                GetSubsegmentAlignment          ()  const = 0;
                virtual uint8_t                                 GetSubsegmentStartsWithSAP      ()  const = 0;
                virtual bool                                    GetBitstreamSwitching           ()  const = 0;
        };
    }
}

#endif /* IADAPTATIONSET_H_ */