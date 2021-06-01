/*
 * UIntPairsWithID.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "UIntPairsWithID.h"

using namespace dash::mpd;

UIntPairsWithID::UIntPairsWithID    ()  :
                 type("")
{
}
UIntPairsWithID::~UIntPairsWithID   ()
{
    for (size_t i=0; i < this->qlpairs.size(); i++)
        delete(this->qlpairs.at(i));
}

const std::vector<IUIntPairs *>&     UIntPairsWithID::GetQualityLatency            ()  const
{
    return (std::vector<IUIntPairs *> &) this->qlpairs;
}
void                                 UIntPairsWithID::AddQualityLatency            (const std::string& ql)
{
    std::vector<std::string> temp;
    dash::helpers::String::Split(ql, ' ', temp);
    UIntPairs* pair = new UIntPairs();
    pair->SetLatency(strtoul(temp[0].c_str(), NULL, 10));
    pair->SetQuality(strtoul(temp[1].c_str(), NULL, 10));
    this->qlpairs.push_back(pair);
}
const std::string&                   UIntPairsWithID::GetType                      ()  const
{
    return this->type;
}
void                                 UIntPairsWithID::SetType                      (const std::string& type)
{
    this->type = type;
}