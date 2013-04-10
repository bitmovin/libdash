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

using namespace sampleplayer::helpers;

clock_t Timing::decoderStartTime        = 0;
clock_t Timing::firstFrameDisplayedTime = 0;
std::vector<void *> Timing::timingsInBetween;

clock_t     Timing::GetCurrentUTCTimeInMsec     ()
{
    return clock();
}
void        Timing::SetDecoderStartTime         ()
{
    Timing::decoderStartTime = Timing::GetCurrentUTCTimeInMsec();
}
void        Timing::SetFirstFrameDisplayedTime  ()
{
    Timing::firstFrameDisplayedTime = Timing::GetCurrentUTCTimeInMsec();
}
float       Timing::GetDifference               (clock_t before, clock_t after)
{
    return  (float) (after - before) / CLOCKS_PER_SEC;
}
float       Timing::GetDifference               ()
{
    return  Timing::GetDifference(Timing::decoderStartTime, Timing::firstFrameDisplayedTime);
}
void        Timing::AddTiming                   (void *timing)
{
    Timing::timingsInBetween.push_back(timing);
}
std::string Timing::TimingsInBetweenList        ()
{
    std::stringstream ss;

    ss  << "Interval_1 (Decoder started --- "
        << ((TimingObject *)Timing::timingsInBetween.at(0))->Description() << "): "
        << Timing::GetDifference(Timing::decoderStartTime, ((TimingObject *)Timing::timingsInBetween.at(0))->TimeStamp()) 
        << std::endl;

    for (size_t i = 1; i < Timing::timingsInBetween.size(); i++)
    {
        ss  << "Interval_" << i + 1 << "("
            << ((TimingObject *)Timing::timingsInBetween.at(i-1))->Description() << " --- " << ((TimingObject *)Timing::timingsInBetween.at(i))->Description() << "): "
            << Timing::GetDifference(((TimingObject *)Timing::timingsInBetween.at(i-1))->TimeStamp(), ((TimingObject *)Timing::timingsInBetween.at(i))->TimeStamp())
            << std::endl;
    }

    ss  << "Interval_" << Timing::timingsInBetween.size() + 1 << "("
        << ((TimingObject *)Timing::timingsInBetween.at(Timing::timingsInBetween.size()-1))->Description() << " --- First frame displayed): "
        << Timing::GetDifference(((TimingObject *)Timing::timingsInBetween.at(Timing::timingsInBetween.size()-1))->TimeStamp(), Timing::firstFrameDisplayedTime)
        << std::endl;

    return ss.str();
}
std::string Timing::TimingsList                 ()
{
    std::stringstream ss;

    ss << "Timestamp 1: Decoder started at " << Timing::decoderStartTime << std::endl;

    for (size_t i = 0; i < Timing::timingsInBetween.size(); i++)
    {
        ss  << "Timestamp " << i + 2 << ": " << ((TimingObject *) Timing::timingsInBetween.at(i))->Description()
            << " at " << ((TimingObject *) Timing::timingsInBetween.at(i))->TimeStamp() << std::endl;
    }

    ss << "Timestamp " << Timing::timingsInBetween.size() + 1 << ": First frame displayed at " << Timing::firstFrameDisplayedTime << std::endl;

    return ss.str();
}
void        Timing::WriteToFile                 (std::string filename)
{
    std::ofstream myfile;
    myfile.open (filename);
    myfile << "Time between decoder start and first frame: " << Timing::GetDifference() << " secs." << std::endl;
    myfile << "Intervals:" << std::endl << Timing::TimingsInBetweenList() << std::endl;
    myfile << "Timestamp list: " << std::endl << Timing::TimingsList() << std::endl;
    myfile.close();
}
void        Timing::DisposeTimingObjects        ()
{
    for (size_t i = 0; i < Timing::timingsInBetween.size(); i++)
    {
        TimingObject *timing = (TimingObject *) Timing::timingsInBetween.at(i);
        delete timing;
    }
}
