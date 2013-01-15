/*
 * Range.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Range.h"

using namespace dash::mpd;

Range::Range    () :
        starttime(""),
        duration("")
{
}
Range::~Range   ()
{
}

const std::string&  Range::GetStarttime ()  const
{
    return this->starttime;
}
void                Range::SetStarttime (const std::string& starttime)
{
    this->starttime = starttime;
}
const std::string&  Range::GetDuration  ()  const
{
    return this->duration;
}
void                Range::SetDuration  (const std::string& duration)
{
    this->duration = duration;
}
