/*
 * FailoverContent.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "FailoverContent.h"

using namespace dash::mpd;

FailoverContent::FailoverContent    ()  :
                 valid(true)
{
}
FailoverContent::~FailoverContent   ()
{
    for (size_t i=0; i < this->fcs.size(); i++)
        delete(this->fcs.at(i));
}

std::vector<IFCS *>&   FailoverContent::GetFCS         ()  const
{
    return (std::vector<IFCS*> &) this->fcs;
}
void                   FailoverContent::AddFCS         (FCS *fcs_el)
{
    this->fcs.push_back(fcs_el);
}
bool                   FailoverContent::IsValid        ()  const
{
    return this->valid;
}
void                   FailoverContent::SetValid       (bool valid)
{
    this->valid = valid;
}