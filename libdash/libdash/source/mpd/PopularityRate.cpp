/*
 * PopularityRate.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "PopularityRate.h"

using namespace dash::mpd;

PopularityRate::PopularityRate    ()  :
                 r(0)
{
}
PopularityRate::~PopularityRate   ()
{
}

uint8_t                 PopularityRate::GetPopularityRate             ()  const
{
    return this->popularityRate;
}
void                    PopularityRate::SetPopularityRate             (uint8_t popularityRate)
{
    this->popularityRate = popularityRate;
}
uint64_t                PopularityRate::GetStart                      ()  const
{
    return this->start;
}
void                    PopularityRate::SetStart                      (uint64_t start)
{
    this->start = start;
}
int32_t                 PopularityRate::GetR                          ()  const
{
    return this->r;
}
void                    PopularityRate::SetR                          (int32_t r)
{
    this->r = r;
}