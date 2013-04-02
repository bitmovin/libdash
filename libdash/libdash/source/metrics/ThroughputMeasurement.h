/*
 * ThroughputMeasurement.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef THROUGHPUTMEASUREMENT_H_
#define THROUGHPUTMEASUREMENT_H_

#include "IThroughputMeasurement.h"

namespace dash
{
    namespace metrics
    {
        class ThroughputMeasurement : public IThroughputMeasurement
        {
            public:
                ThroughputMeasurement          ();
                virtual ~ThroughputMeasurement ();

                const std::string&              StartOfPeriod           () const;
                uint64_t                        DurationOfPeriod        () const;
                const std::vector<uint32_t>&    ReceivedBytesPerTrace   () const;

                void    SetStartOfPeriod        (std::string startOfPeriod);
                void    SetDurationOfPeriod     (uint64_t duration);
                void    AddReceivedBytes        (uint32_t numberOfBytes);

            private:
                std::string             startOfPeriod;
                uint64_t                durationOfPeriod;
                std::vector<uint32_t>   receivedBytesPerTrace;
        };
    }
}

#endif /* THROUGHPUTMEASUREMENT_H_ */
