/*
 * ModelPair.cpp
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ModelPair.h"

using namespace dash::mpd;

ModelPair::ModelPair    () :
                bufferTime(""),
                bandwidth(0)
{
}

ModelPair::~ModelPair   ()
{
}

const std::string&                      ModelPair::GetBufferTime                     ()  const
{
    return this->bufferTime;
}
void                                    ModelPair::SetBufferTime                     (const std::string& bufferTime)
{
    this->bufferTime = bufferTime;
}
uint64_t                                ModelPair::GetBandwidth                      ()  const
{
    return this->bandwidth;
}
void                                    ModelPair::SetBandwidth                      (uint64_t bandwidth)
{
    this->bandwidth = bandwidth;
}