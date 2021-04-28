/*
 * FCS.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 *
 * Email: lorenzidaniele.97@gmail.com
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "FCS.h"

using namespace dash::mpd;

FCS::FCS    ()  :
    presentationTime(0),
    duration(0)
{
}
FCS::~FCS   ()
{
}

uint32_t    FCS::GetPresentationTime     ()  const
{
    return this->presentationTime;
}
void        FCS::SetPresentationTime     (uint32_t presentationTime) 
{
    this->presentationTime = presentationTime;
}
uint32_t    FCS::GetDuration             ()  const
{
    return this->duration;
}
void        FCS::SetDuration             (uint32_t duration) 
{
    this->duration = duration;
}