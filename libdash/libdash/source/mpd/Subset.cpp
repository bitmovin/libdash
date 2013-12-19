/*
 * Subset.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Subset.h"

using namespace dash::mpd;

Subset::Subset () :
        id("")
{
}
Subset::~Subset ()
{
}

const std::vector<uint32_t>&    Subset::Contains    ()  const
{
    return this->subset;
}
const std::string&              Subset::GetId       ()  const
{
    return this->id;
}
void                            Subset::SetId       (const std::string& id)
{
    this->id = id;
}
void                            Subset::SetSubset   (const std::string& subset)
{
    dash::helpers::String::Split(subset, ' ', this->subset);
}
