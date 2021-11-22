/*
 * OperatingQuality.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "OperatingQuality.h"

using namespace dash::mpd;

OperatingQuality::OperatingQuality    ()  :
            mediaType("any")
{
}
OperatingQuality::~OperatingQuality   ()
{
}

const std::string&                         OperatingQuality::GetMediaType                ()  const
{
    return this->mediaType;
}
void                                       OperatingQuality::SetMediaType                (const std::string& mediaType)
{
    this->mediaType = mediaType;
}
uint32_t                                   OperatingQuality::GetMin                      ()  const
{
    return this->min;
}
void                                       OperatingQuality::SetMin                      (uint32_t min)
{
    this->min = min;
}
uint32_t                                   OperatingQuality::GetMax                      ()  const
{
    return this->max;
}
void                                       OperatingQuality::SetMax                      (uint32_t max)
{
    this->max = max;
}
uint32_t                                   OperatingQuality::GetTarget                   ()  const
{
    return this->target;
}
void                                       OperatingQuality::SetTarget                   (uint32_t target)
{
    this->target = target;
}
const std::string&                         OperatingQuality::GetType                     ()  const
{
    return this->type;
}
void                                       OperatingQuality::SetType                     (const std::string& type)
{
    this->type = type;
}
uint32_t                                   OperatingQuality::GetMaxDifference            ()  const
{
    return this->maxDifference;
}
void                                       OperatingQuality::SetMaxDifference            (uint32_t maxDifference)
{
    this->maxDifference = maxDifference;
}