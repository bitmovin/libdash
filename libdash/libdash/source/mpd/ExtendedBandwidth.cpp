/*
 * ExtendedBandwidth.cpp
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ExtendedBandwidth.h"

using namespace dash::mpd;

ExtendedBandwidth::ExtendedBandwidth    () :
                vbr(false)
{
}
ExtendedBandwidth::~ExtendedBandwidth   ()
{
    for (size_t i=0; i < this->modelPairs.size(); i++)
        delete(this->modelPairs.at(i));
}

const std::vector<IModelPair *>&   ExtendedBandwidth::GetModelPairs        ()  const
{
    return (std::vector<IModelPair*> &) this->modelPairs;
}
void                               ExtendedBandwidth::AddModelPair         (ModelPair *modelPair)
{
    this->modelPairs.push_back(modelPair);
}
bool                               ExtendedBandwidth::GetVbr               ()  const
{
    return this->vbr;
}
void                               ExtendedBandwidth::SetVbr               (bool vbr)
{
    this->vbr = vbr;
}