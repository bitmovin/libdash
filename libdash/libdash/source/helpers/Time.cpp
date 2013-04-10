/*
 * Time.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Time.h"

using namespace dash::helpers;

uint32_t    Time::GetCurrentUTCTimeInSec   ()
{
    return mktime(Time::GetCurrentUTCTime());
}
std::string Time::GetCurrentUTCTimeStr   ()
{
    char timeString[30];
    strftime(timeString, 30, "%Y-%m-%dT%H:%M:%SZ", Time::GetCurrentUTCTime());

    return std::string(timeString);
}
struct tm*  Time::GetCurrentUTCTime     ()
{
    time_t      rawTime;

    time(&rawTime);
    return gmtime(&rawTime);
}
