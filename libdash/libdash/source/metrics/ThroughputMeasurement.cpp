/*
 * ThroughputMeasurement.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ThroughputMeasurement.h"

using namespace dash::metrics;

ThroughputMeasurement::ThroughputMeasurement ()
{
}
ThroughputMeasurement::~ThroughputMeasurement()
{
}

const std::string&              ThroughputMeasurement::StartOfPeriod           () const
{
    return this->startOfPeriod;
}
void                            ThroughputMeasurement::SetStartOfPeriod        (std::string start)
{
    this->startOfPeriod = start;
}
uint64_t                        ThroughputMeasurement::DurationOfPeriod        () const
{
    return this->durationOfPeriod;
}
void                            ThroughputMeasurement::SetDurationOfPeriod     (uint64_t duration)
{
    this->durationOfPeriod = duration;
}
const std::vector<uint32_t>&    ThroughputMeasurement::ReceivedBytesPerTrace   () const
{
    return this->receivedBytesPerTrace;
}
void                            ThroughputMeasurement::AddReceivedBytes        (uint32_t numberOfBytes)
{
    this->receivedBytesPerTrace.push_back(numberOfBytes);
}
