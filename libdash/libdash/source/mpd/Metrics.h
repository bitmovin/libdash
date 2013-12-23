/*
 * Metrics.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef METRICS_H_
#define METRICS_H_

#include "config.h"

#include <string>
#include <vector>

#include "IMetrics.h"
#include "Descriptor.h"
#include "Range.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Metrics : public IMetrics, public AbstractMPDElement
        {
            public:
                Metrics             ();
                virtual ~Metrics    ();

                const std::vector<IDescriptor *>&   GetReportings   ()  const;
                const std::vector<IRange *>&        GetRanges       ()  const;
                const std::string&                  GetMetrics      ()  const;
                const std::string&                  GetStartTime    ()  const;
                const std::string&                  GetDuration     ()  const;

                void    AddReporting    (Descriptor *reporting);
                void    AddRange        (Range *range);
                void    SetMetrics      (const std::string& metrics);
                void    SetStartTime    (const std::string& startTime);
                void    SetDuration     (const std::string& duration);

            private:
                std::vector<Descriptor *>   reportings;
                std::vector<Range *>        ranges;
                std::string                 metrics;
                std::string                 startTime;
                std::string                 duration;
        };
    }
}

#endif /* METRICS_H_ */
