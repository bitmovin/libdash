/*
 * RandomAccess.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "RandomAccess.h"

using namespace dash::mpd;

RandomAccess::RandomAccess    ()  :
                 type("closed")
{
}
RandomAccess::~RandomAccess   ()
{
}

uint32_t                                RandomAccess::GetInterval               ()  const
{
    return this->interval;
}
void                                    RandomAccess::SetInterval               (uint32_t interval)
{
    this->interval = interval;
}
const std::string&                      RandomAccess::GetType                   ()  const
{
    return this->type;
}
void                                    RandomAccess::SetType                   (const std::string& type)
{
    this->type = type;
}
const std::string&                      RandomAccess::GetMinBufferTime          ()  const
{
    return this->minBufferTime;
}
void                                    RandomAccess::SetMinBufferTime          (const std::string& minBufferTime)
{
    this->minBufferTime = minBufferTime;
}
uint32_t                                RandomAccess::GetBandwidth              ()  const
{
    return this->bandwidth;
}
void                                    RandomAccess::SetBandwidth              (uint32_t bandwidth)
{
    this->bandwidth = bandwidth;
}