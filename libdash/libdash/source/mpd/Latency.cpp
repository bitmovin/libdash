/*
 * Latency.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Latency.h"

using namespace dash::mpd;

Latency::Latency    ()
{
}
Latency::~Latency   ()
{
    for (size_t i=0; i < this->qltpairs.size(); i++)
        delete(this->qltpairs.at(i));
}

const std::vector<IUIntPairsWithID *>&     Latency::GetQualityLatencyType        ()  const
{
    return (std::vector<IUIntPairsWithID *> &) this->qltpairs;
}
void                                       Latency::AddQualityLatencyType        (UIntPairsWithID* qlt)
{
    this->qltpairs.push_back(qlt);
}
uint32_t                                   Latency::GetReferenceId               ()  const
{
    return this->referenceId;
}
void                                       Latency::SetReferenceId               (uint32_t referenceId)
{
    this->referenceId = referenceId;
}
uint32_t                                   Latency::GetTarget                    ()  const
{
    return this->target;
}
void                                       Latency::SetTarget                    (uint32_t target)
{
    this->target = target;
}
uint32_t                                   Latency::GetMax                       ()  const
{
    return this->max;
}
void                                       Latency::SetMax                       (uint32_t max)
{
    this->max = max;
}
uint32_t                                   Latency::GetMin                       ()  const
{
    return this->min;
}
void                                       Latency::SetMin                       (uint32_t min)
{
    this->min = min;
}