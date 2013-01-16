/*
 * IPeriod.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IPERIOD_H_
#define IPERIOD_H_

#include "config.h"

#include "IMPDElement.h"
#include "IBaseUrl.h"
#include "ISegmentBase.h"
#include "ISegmentList.h"
#include "ISegmentTemplate.h"
#include "IAdaptationSet.h"
#include "ISubset.h"

namespace dash
{
    namespace mpd
    {
        class IPeriod : public virtual IMPDElement
        {
            public:
                virtual ~IPeriod(){}

                virtual const std::vector<IBaseUrl *>&          GetBaseURLs             ()  const = 0;
                virtual ISegmentBase*                           GetSegmentBase          ()  const = 0;
                virtual ISegmentList*                           GetSegmentList          ()  const = 0;
                virtual ISegmentTemplate*                       GetSegmentTemplate      ()  const = 0;
                virtual const std::vector<IAdaptationSet *>&    GetAdaptationSets       ()  const = 0;
                virtual const std::vector<ISubset *>&           GetSubsets              ()  const = 0;
                virtual const std::string&                      GetXlinkHref            ()  const = 0;
                virtual const std::string&                      GetXlinkActuate         ()  const = 0;
                virtual const std::string&                      GetId                   ()  const = 0;
                virtual const std::string&                      GetStart                ()  const = 0;
                virtual const std::string&                      GetDuration             ()  const = 0;
                virtual bool                                    GetBitstreamSwitching   ()  const = 0;

        };
    }
}

#endif /* IPERIOD_H_ */