/*
 * ContentPopularityRate.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ContentPopularityRate.h"

using namespace dash::mpd;

ContentPopularityRate::ContentPopularityRate    ()  :
                 source(""),
                 sourceDescription("")
{
}
ContentPopularityRate::~ContentPopularityRate   ()
{
    for(size_t i = 0; i < this->popularityRates.size(); i++)
        delete(this->popularityRates.at(i));
}

const std::vector<IPopularityRate*>&    ContentPopularityRate::GetPopularityRates       () const 
{
    return (std::vector<IPopularityRate*> &) this->popularityRates;
}
void                                    ContentPopularityRate::AddPopularityRate        (PopularityRate *popularityRate) 
{
    this->popularityRates.push_back(popularityRate);
}
const std::string&                      ContentPopularityRate::GetSource                ()  const
{
    return this->source;
}
void                                    ContentPopularityRate::SetSource                (const std::string& source)
{
    this->source = source;
}
const std::string&                      ContentPopularityRate::GetSourceDescription        ()  const
{
    return this->sourceDescription;
}
void                                    ContentPopularityRate::SetSourceDescription     (const std::string& sourceDescription)
{
    this->sourceDescription = sourceDescription;
}