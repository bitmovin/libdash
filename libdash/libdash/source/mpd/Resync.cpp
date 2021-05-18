/*
 * Resync.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 *
 * Email: lorenzidaniele.97@gmail.com
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Resync.h"

using namespace dash::mpd;

Resync::Resync    ()  :
                 type(0),
				 dIMin(0),
				 marker(false),
				 rangeAccess(false)
{
}
Resync::~Resync   ()
{
}

uint32_t                                Resync::GetType	                ()  const
{
    return this->type;
}
void                                    Resync::SetType                 (uint32_t type)
{
    this->type = type;
}
uint32_t                                Resync::GetDT	                ()  const
{
    return this->dT;
}
void                                    Resync::SetDT                   (uint32_t dT)
{
    this->dT = dT;
}
float                                   Resync::GetDIMax	            ()  const
{
    return this->dIMax;
}
void                                    Resync::SetDIMax                (float dIMax)
{
    this->dIMax = dIMax;
}
float                                   Resync::GetDIMin	            ()  const
{
    return this->dIMin;
}
void                                    Resync::SetDIMin                (float dIMin)
{
    this->dIMin = dIMin;
}
bool                                    Resync::HasMarker	            ()  const
{
    return this->marker;
}
void                                    Resync::SetMarker               (bool marker)
{
    this->marker = marker;
}
bool                                    Resync::HasRangeAccess	        ()  const
{
    return this->rangeAccess;
}
void                                    Resync::SetRangeAccess          (bool rangeAccess)
{
    this->rangeAccess = rangeAccess;
}
const std::string&                      Resync::GetIndex	            ()  const
{
    return this->index;
}
void                                    Resync::SetIndex                (const std::string& index)
{
    this->index = index;
}