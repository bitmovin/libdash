/*
 * Metrics.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "../mpd/Metrics.h"

using namespace dash::mpd;

Metrics::Metrics    () :
            metrics("")
{
}
Metrics::~Metrics   ()
{
    for(size_t i = 0; i < this->reportings.size(); i++)
        delete(this->reportings.at(i));
    for(size_t i = 0; i < this->ranges.size(); i++)
        delete(this->ranges.at(i));
}

const std::vector<IDescriptor *>&   Metrics::GetReportings  ()  const
{
    return (std::vector<IDescriptor *> &)this->reportings;
}
void                                Metrics::AddReporting   (Descriptor *reporting)
{
    this->reportings.push_back(reporting);
}
const std::vector<IRange *>&        Metrics::GetRanges      ()  const
{
    return (std::vector<IRange *> &)this->ranges;
}
void                                Metrics::AddRange       (Range *range)
{
    this->ranges.push_back(range);
}
const std::string&                  Metrics::GetMetrics     ()  const
{
    return this->metrics;
}
void                                Metrics::SetMetrics     (const std::string& metrics)
{
    this->metrics = metrics;
}
