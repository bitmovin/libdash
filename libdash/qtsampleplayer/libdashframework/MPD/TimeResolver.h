/*
 * TimeResolver.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_TIMERESOLVER_H_
#define LIBDASH_FRAMEWORK_MPD_TIMERESOLVER_H_

#include <time.h>
#include "config.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            class TimeResolver
            {
                public:
                    static bool         CheckTimeInterval   (std::string availabilityStartTime, std::string availabilityEndTime);
                    static uint32_t     GetCurrentTimeInSec ();
                    static uint32_t     GetUTCDateTimeInSec (const std::string& datetime);
                    static double       GetDurationInSec    (const std::string& duration);

                private:
                    static struct tm*               ResolveUTCDateTime  (const std::string& timeString);
                    static struct tm*               GetCurrentUTCTime   ();
                    static std::vector<int>         SplitToI            (const std::string &s, char delim);
                    static std::vector<std::string> SplitToStr          (const std::string &s, char delim);

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_MPD_TIMERESOLVER_H_ */
