/*
 * Switching.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Switching.h"

using namespace dash::mpd;

Switching::Switching    ()  :
                 type("media")
{
}
Switching::~Switching   ()
{
}

uint32_t                 Switching::GetInterval           ()  const
{
    return this->interval;
}
void                     Switching::SetInterval           (uint32_t interval)
{
    this->interval = interval;
}
const std::string&       Switching::GetType               ()  const
{
    return this->type;
}
void                     Switching::SetType               (const std::string& type)
{
    this->type = type;
}