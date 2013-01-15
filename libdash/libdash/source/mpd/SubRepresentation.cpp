/*
 * SubRepresentation.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SubRepresentation.h"

using namespace dash::mpd;

SubRepresentation::SubRepresentation    () :
                    level(0),
                    bandWidth(0)
{
}
SubRepresentation::~SubRepresentation   () 
{
}
uint32_t                        SubRepresentation::GetLevel             ()  const 
{
    return this->level;
}
void                            SubRepresentation::SetLevel             (uint32_t level) 
{
    this->level = level;
}
const std::vector<uint32_t>&    SubRepresentation::GetDependencyLevel   ()  const
{
    return this->dependencyLevel;
}
void                            SubRepresentation::SetDependencyLevel   (const std::string& dependencyLevel)
{
    dash::helpers::String::Split(dependencyLevel, ' ', this->dependencyLevel);
}
uint32_t                        SubRepresentation::GetBandWidth         ()  const
{
    return this->bandWidth;
}
void                            SubRepresentation::SetBandWidth         (uint32_t bandWidth)
{
    this->bandWidth = bandWidth;
}
const std::vector<std::string>& SubRepresentation::GetContentComponent  ()  const
{
    return this->contentComponent;
}
void                            SubRepresentation::SetContentComponent  (const std::string& contentComponent)
{
    dash::helpers::String::Split(contentComponent, ' ', this->contentComponent);
}
