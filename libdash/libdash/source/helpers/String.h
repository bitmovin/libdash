/*
 * String.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef STRING_H_
#define STRING_H_

#include "config.h"

namespace dash
{
    namespace helpers
    {
        class String
        {
            public:
                static void Split   (const std::string &s, char delim, std::vector<std::string>& vector);
                static void Split   (const std::string &s, char delim, std::vector<uint32_t>& vector);
                static bool ToBool  (const std::string &s);
        };
    }
}

#endif /* STRING_H_ */