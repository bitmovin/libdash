/*
 * RepresentationHelper.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_MPD_REPRESENTATIONHELPER_H_
#define LIBDASH_FRAMEWORK_MPD_REPRESENTATIONHELPER_H_

#include "IMPD.h"

namespace libdash
{
    namespace framework
    {
        namespace mpd
        {
            class RepresentationHelper
            {
                public:
                    static dash::mpd::ISegment* GetInitSegment      (dash::mpd::IRepresentation *representation, const std::vector<dash::mpd::IBaseUrl *>& baseurls);
                    static dash::mpd::ISegment* GetSegment          (dash::mpd::IRepresentation *representation, const std::vector<dash::mpd::IBaseUrl *>& baseurls, uint32_t number);
                    static uint32_t             GetSize             (dash::mpd::IRepresentation *representation);
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_MPD_REPRESENTATIONHELPER_H_ */