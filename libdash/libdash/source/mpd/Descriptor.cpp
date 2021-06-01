/* 
 * Descriptor.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Descriptor.h"

using namespace dash::mpd;

Descriptor::Descriptor  () :
            schemeIdUri (""),
            value       (""),
            id            ("")
{
}
Descriptor::~Descriptor ()
{
}
const std::string&  Descriptor::GetSchemeIdUri  ()  const
{
    return this->schemeIdUri;
}
void                Descriptor::SetSchemeIdUri  (const std::string& schemeIdUri) 
{
    this->schemeIdUri = schemeIdUri;
}
const std::string&  Descriptor::GetValue        ()  const
{
    return this->value;
}
void                Descriptor::SetValue        (const std::string& value) 
{
    this->value = value;
}
const std::string&  Descriptor::GetId           ()  const
{
    return this->id;
}
void                Descriptor::SetId           (const std::string& id)
{
    this->id = id;
}