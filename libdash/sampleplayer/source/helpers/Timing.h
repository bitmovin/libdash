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

#ifndef SAMPLEPLAYER_HELPERS_TIMING_H_
#define SAMPLEPLAYER_HELPERS_TIMING_H_

#include <time.h>
#include "config.h"
#include "TimingObject.h"

#include <fstream>

namespace sampleplayer
{
    namespace helpers
    {
        class Timing
        {
            public:
                static void         SetDecoderStartTime         ();
                static void         SetFirstFrameDisplayedTime  ();
                static float        GetDifference               ();
                static void         AddTiming                   (void *timing);
                static clock_t      GetCurrentUTCTimeInMsec     ();
                static void         WriteToFile                 (std::string filename);
                static void         DisposeTimingObjects        ();

            private:
                static float        GetDifference               (clock_t before, clock_t after);
                static std::string  TimingsInBetweenList        ();
                static std::string  TimingsList                 ();

                static clock_t              decoderStartTime;
                static clock_t              firstFrameDisplayedTime;
                static std::vector<void *>  timingsInBetween;

        };

    }
}

#endif /* SAMPLEPLAYER_HELPERS_TIMING_H_ */
