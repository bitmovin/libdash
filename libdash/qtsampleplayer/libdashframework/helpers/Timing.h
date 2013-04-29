/*
 * Timing.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_HELPERS_TIMING_H_
#define LIBDASH_FRAMEWORK_HELPERS_TIMING_H_

#include <time.h>
#include "config.h"
#include "TimingObject.h"
#include <iomanip>

#include <fstream>

namespace libdash
{
    namespace framework
    {
        namespace helpers
        {
            class Timing
            {
                public:
                    static void         AddTiming                   (void *timing);
                    static clock_t      GetCurrentUTCTimeInMsec     ();
                    static void         WriteToFile                 (std::string filename);
                    static void         DisposeTimingObjects        ();

                private:
                    static float        GetDifference               (clock_t before, clock_t after);
                    static std::string  TimingsInBetweenList        ();
                    static std::string  TimingsList                 ();

                    static std::vector<void *>  timingsInBetween;

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_HELPERS_TIMING_H_ */
