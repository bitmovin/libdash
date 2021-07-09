/*
 * OperatingBandwidth.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "OperatingBandwidth.h"

using namespace dash::mpd;

OperatingBandwidth::OperatingBandwidth    ()  :
            mediaType("all")
{
}
OperatingBandwidth::~OperatingBandwidth   ()
{
}

const std::string&                         OperatingBandwidth::GetMediaType                ()  const
{
    return this->mediaType;
}
void                                       OperatingBandwidth::SetMediaType                (const std::string& mediaType)
{
    this->mediaType = mediaType;
}
uint32_t                                   OperatingBandwidth::GetMin                      ()  const
{
    return this->min;
}
void                                       OperatingBandwidth::SetMin                      (uint32_t min)
{
    this->min = min;
}
uint32_t                                   OperatingBandwidth::GetMax                      ()  const
{
    return this->max;
}
void                                       OperatingBandwidth::SetMax                      (uint32_t max)
{
    this->max = max;
}
uint32_t                                   OperatingBandwidth::GetTarget                   ()  const
{
    return this->target;
}
void                                       OperatingBandwidth::SetTarget                   (uint32_t target)
{
    this->target = target;
}