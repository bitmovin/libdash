/*
 * TimingObject.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_HELPERS_TIMINGOBJECT_H_
#define LIBDASH_FRAMEWORK_HELPERS_TIMINGOBJECT_H_

#include "config.h"

#include <time.h>
#include "Timing.h"

namespace libdash
{
    namespace framework
    {
        namespace helpers
        {
            class TimingObject
            {
                public:
                    TimingObject            (std::string desc);
                    virtual ~TimingObject   ();

                    clock_t     TimeStamp   ();
                    std::string Description ();

                private:
                    clock_t     timeStamp;
                    std::string description;

            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_HELPERS_TIMINGOBJECT_H_ */
