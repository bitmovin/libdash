/*
 * ISubset.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISUBSET_H_
#define ISUBSET_H_

#include "config.h"

namespace dash
{
    namespace mpd
    {
        class ISubset
        {
            public:
                virtual ~ISubset(){}

                virtual const std::vector<uint32_t>& Contains () const = 0;
        };
    }
}

#endif /* ISUBSET_H_ */