/*
 * IMetrics.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IMETRICS_H_
#define IMETRICS_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"
#include "IRange.h"

namespace dash
{
    namespace mpd
    {
        class IMetrics : public virtual IMPDElement
        {
            public:
                virtual ~IMetrics(){}

                virtual const std::vector<IDescriptor *>&   GetReportings   ()  const = 0;
                virtual const std::vector<IRange *>&        GetRanges       ()  const = 0;
                virtual const std::string&                  GetMetrics      ()  const = 0;

        };
    }
}

#endif /* IMETRICS_H_ */