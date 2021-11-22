/*
 * UIntPairs.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "UIntPairs.h"

using namespace dash::mpd;

UIntPairs::UIntPairs    ()    
{
}
UIntPairs::~UIntPairs   ()
{
}

uint32_t            UIntPairs::GetLatency    ()  const
{
    return this->latency;
}
void                UIntPairs::SetLatency    (uint32_t latency) 
{
    this->latency = latency;
}
uint32_t            UIntPairs::GetQuality    ()  const
{
    return this->quality;
}
void                UIntPairs::SetQuality    (uint32_t quality) 
{
    this->quality = quality;
}