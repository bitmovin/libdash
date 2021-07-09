/*
 * ContentProtection.cpp
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ContentProtection.h"

using namespace dash::mpd;

ContentProtection::ContentProtection    () :
                robustness(""),
                refId(""),
                ref("")
{
}
ContentProtection::~ContentProtection   ()
{
}

const std::string&                      ContentProtection::GetRobustness                     ()  const
{
    return this->robustness;
}
void                                    ContentProtection::SetRobustness                     (const std::string& robustness)
{
    this->robustness = robustness;
}
const std::string&                      ContentProtection::GetRefId                          ()  const
{
    return this->refId;
}
void                                    ContentProtection::SetRefId                          (const std::string& refId)
{
    this->refId = refId;
}
const std::string&                      ContentProtection::GetRef                            ()  const
{
    return this->ref;
}
void                                    ContentProtection::SetRef                            (const std::string& ref)
{
    this->ref = ref;
}