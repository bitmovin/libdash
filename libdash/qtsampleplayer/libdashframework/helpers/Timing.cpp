/*
 * Timing.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Timing.h"

using namespace libdash::framework::helpers;

std::vector<void *> Timing::timingsInBetween;

clock_t     Timing::GetCurrentUTCTimeInMsec     ()
{
    return clock();
}
float       Timing::GetDifference               (clock_t before, clock_t after)
{
    return  (float) (after - before) / CLOCKS_PER_SEC;
}
void        Timing::AddTiming                   (void *timing)
{
    Timing::timingsInBetween.push_back(timing);
}
std::string Timing::TimingsInBetweenList        ()
{
    std::stringstream ss;

    for (size_t i = 1; i < Timing::timingsInBetween.size(); i++)
    {
        ss  << "Interval_" << i << " ("
            << ((TimingObject *)Timing::timingsInBetween.at(i-1))->Description() << " --- " << ((TimingObject *)Timing::timingsInBetween.at(i))->Description() << "): "
            << Timing::GetDifference(((TimingObject *)Timing::timingsInBetween.at(i-1))->TimeStamp(), ((TimingObject *)Timing::timingsInBetween.at(i))->TimeStamp())
            << std::endl;
    }

    return ss.str();
}
std::string Timing::TimingsList                 ()
{
    std::stringstream ss;

    for (size_t i = 0; i < Timing::timingsInBetween.size(); i++)
    {
        ss  << "Timestamp " << i + 1 << ": " << ((TimingObject *) Timing::timingsInBetween.at(i))->Description()
            << " at " << ((TimingObject *) Timing::timingsInBetween.at(i))->TimeStamp() << std::endl;
    }

    return ss.str();
}
void        Timing::WriteToFile                 (std::string filename)
{
    std::ofstream myfile;
    myfile.open (filename);
    myfile << "Intervals:" << std::endl << Timing::TimingsInBetweenList() << std::endl;
    myfile << "Timestamp list: " << std::endl << Timing::TimingsList() << std::endl;
    myfile.close();
}
void        Timing::DisposeTimingObjects        ()
{
    size_t numObj = Timing::timingsInBetween.size();

    for (size_t i = 0; i < numObj; i++)
    {
        TimingObject *timing = (TimingObject *) Timing::timingsInBetween.at(i);
        delete timing;
    }
}
