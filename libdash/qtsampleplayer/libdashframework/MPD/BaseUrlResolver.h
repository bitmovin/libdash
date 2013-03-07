/*
 * BaseUrlResolver.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_BASEURLRESOLVER_H_
#define LIBDASH_FRAMEWORK_MPD_BASEURLRESOLVER_H_

#include "IMPD.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            class BaseUrlResolver
            {
                public:
                    static void ResolveBaseUrl  (std::vector<dash::mpd::IBaseUrl *>& urls, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd);
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_MPD_BASEURLRESOLVER_H_ */
