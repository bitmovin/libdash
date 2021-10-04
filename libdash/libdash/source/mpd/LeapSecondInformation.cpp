/*
 * LeapSecondInformation.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "LeapSecondInformation.h"

using namespace dash::mpd;

LeapSecondInformation::LeapSecondInformation    ()  :
    availabilityStartLeapOffset(0)
    
{
}
LeapSecondInformation::~LeapSecondInformation   ()
{
}

int32_t              LeapSecondInformation::GetAvailabilityStartLeapOffset        ()  const
{
    return this->availabilityStartLeapOffset;
}
void                 LeapSecondInformation::SetAvailabilityStartLeapOffset        (int32_t availabilityStartLeapOffset) 
{
    this->availabilityStartLeapOffset = availabilityStartLeapOffset;
}
int32_t              LeapSecondInformation::GetNextAvailabilityStartLeapOffset    ()  const
{
    return this->nextAvailabilityStartLeapOffset;
}
void                 LeapSecondInformation::SetNextAvailabilityStartLeapOffset    (int32_t nextAvailabilityStartLeapOffset) 
{
    this->nextAvailabilityStartLeapOffset = nextAvailabilityStartLeapOffset;
}
const std::string&   LeapSecondInformation::GetNextLeapChangeTime                 ()  const
{
    return this->nextLeapChangeTime;
}
void                 LeapSecondInformation::SetNextLeapChangeTime                 (const std::string& nextLeapChangeTime) 
{
    this->nextLeapChangeTime = nextLeapChangeTime;
}