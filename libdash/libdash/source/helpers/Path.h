/*
 * Path.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PATH_H_
#define PATH_H_

#include "config.h"

namespace dash
{
    namespace helpers
    {
        class Path
        {
            public:
                static std::string              CombinePaths        (const std::string &path1, const std::string &path2);
                static std::string              GetDirectoryPath    (const std::string &path);
                static std::vector<std::string> Split               (const std::string &s, char delim);
                static bool                     GetHostPortAndPath  (const std::string &url, std::string &host, size_t &port, std::string& path);
                static bool                     GetStartAndEndBytes (const std::string &byteRange, size_t &startByte, size_t &endByte);
        };
    }
}

#endif /* PATH_H_ */