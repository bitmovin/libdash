/*
 * TimingObject.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "TimingObject.h"

using namespace libdash::framework::helpers;

TimingObject::TimingObject  (std::string desc) :
              description   (desc)
{
    this->timeStamp = Timing::GetCurrentUTCTimeInMsec();
}
TimingObject::~TimingObject ()
{
}

clock_t     TimingObject::TimeStamp     ()
{
    return this->timeStamp;
}
std::string TimingObject::Description   ()
{
    return this->description;
}
