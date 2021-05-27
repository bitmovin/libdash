/*
 * UIntVWithID.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "UIntVWithID.h"

using namespace dash::mpd;

UIntVWithID::UIntVWithID    () :
                    id(0),
                    contentType("")
{
}
UIntVWithID::~UIntVWithID   () 
{
}
const std::vector<uint32_t>&    UIntVWithID::GetList               ()  const
{
    return this->list;
}
void                            UIntVWithID::SetList               (const std::string& list)
{
    dash::helpers::String::Split(list, ' ', this->list);
}
uint32_t                        UIntVWithID::GetId                 ()  const
{
    return this->id;
}
void                            UIntVWithID::SetId                 (uint32_t id)
{
    this->id = id;
}
const std::vector<std::string>& UIntVWithID::GetProfiles           ()  const
{
    return this->profiles;
}
void                            UIntVWithID::SetProfiles           (const std::string& profiles)
{
    dash::helpers::String::Split(profiles, ' ', this->profiles);
}
const std::string&              UIntVWithID::GetContentType        ()  const
{
    return this->contentType;
}
void                            UIntVWithID::SetContentType        (const std::string& contentType)
{
    this->contentType = contentType;
}