/*
 * IRepresentation.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IREPRESENTATION_H_
#define IREPRESENTATION_H_

#include "config.h"

#include "IBaseUrl.h"
#include "ISubRepresentation.h"
#include "ISegmentBase.h"
#include "ISegmentList.h"
#include "ISegmentTemplate.h"
#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class IRepresentation : public virtual IRepresentationBase
        {
            public:
                virtual ~IRepresentation(){}

                virtual const std::vector<IBaseUrl *>&              GetBaseURLs                 ()  const = 0;
                virtual const std::vector<ISubRepresentation *>&    GetSubRepresentations       ()  const = 0;
                virtual ISegmentBase*                               GetSegmentBase              ()  const = 0;
                virtual ISegmentList*                               GetSegmentList              ()  const = 0;
                virtual ISegmentTemplate*                           GetSegmentTemplate          ()  const = 0;
                virtual const std::string&                          GetId                       ()  const = 0;
                virtual uint32_t                                    GetBandwidth                ()  const = 0;
                virtual uint32_t                                    GetQualityRanking           ()  const = 0;
                virtual const std::vector<std::string>&             GetDependencyId             ()  const = 0;
                virtual const std::vector<std::string>&             GetMediaStreamStructureId   ()  const = 0;
        };
    }
}

#endif /* IREPRESENTATION_H_ */