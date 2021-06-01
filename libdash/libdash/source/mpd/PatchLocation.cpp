/*
 * PatchLocation.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "PatchLocation.h"

using namespace dash::mpd;

PatchLocation::PatchLocation    ()  :
    url(""),
    ttl(0.0)
    
{
}
PatchLocation::~PatchLocation   ()
{
}

const std::string&  PatchLocation::GetUrl    ()  const
{
    return this->url;
}
void                PatchLocation::SetUrl    (const std::string& url) 
{
    this->url = url;
}
double              PatchLocation::GetTtl    ()  const
{
    return this->ttl;
}
void                PatchLocation::SetTtl    (double ttl) 
{
    this->ttl = ttl;
}