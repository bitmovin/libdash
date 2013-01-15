/*
 * IMPD.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IMPD_H_
#define IMPD_H_

#include "config.h"

#include "IProgramInformation.h"
#include "IBaseUrl.h"
#include "IPeriod.h"
#include "IMetrics.h"

namespace dash
{
    namespace mpd
    {
        class IMPD
        {
            public:
                virtual ~IMPD(){}

                virtual const std::vector<IProgramInformation *>&   GetProgramInformations          ()  const = 0;
                virtual const std::vector<IBaseUrl *>&              GetBaseUrls                     ()  const = 0;
                virtual const std::vector<std::string>&             GetLocations                    ()  const = 0;
                virtual const std::vector<IPeriod *>&               GetPeriods                      ()  const = 0;
                virtual const std::vector<IMetrics *>&              GetMetrics                      ()  const = 0;
                virtual const std::string&                          GetId                           ()  const = 0;
                virtual const std::vector<std::string>&             GetProfiles                     ()  const = 0;
                virtual const std::string&                          GetType                         ()  const = 0;
                virtual const std::string&                          GetAvailabilityStarttime        ()  const = 0;
                virtual const std::string&                          GetAvailabilityEndtime          ()  const = 0;
                virtual const std::string&                          GetMediaPresentationDuration    ()  const = 0;
                virtual const std::string&                          GetMinimumUpdatePeriod          ()  const = 0;
                virtual const std::string&                          GetMinBufferTime                ()  const = 0;
                virtual const std::string&                          GetTimeShiftBufferDepth         ()  const = 0;
                virtual const std::string&                          GetSuggestedPresentationDelay   ()  const = 0;
                virtual const std::string&                          GetMaxSegmentDuration           ()  const = 0;
                virtual const std::string&                          GetMaxSubsegmentDuration        ()  const = 0;
        };
    }
}

#endif /* IMPD_H_ */