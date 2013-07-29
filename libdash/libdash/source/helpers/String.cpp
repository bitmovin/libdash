/*
 * String.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "String.h"

using namespace dash::helpers;

void    String::Split   (const std::string &s, char delim, std::vector<std::string>& vector)
{
    std::stringstream           ss(s);
    std::string                 item;

    while(std::getline(ss, item, delim))
        vector.push_back(item);
}
void    String::Split   (const std::string &s, char delim, std::vector<uint32_t>& vector)
{
    size_t lengthOfString = s.length();
    size_t pos = 0;
    size_t i = 0;
    uint32_t level = 0;

    while (pos != std::string::npos)
    {
        pos = s.find(delim, i);

        if (i < lengthOfString)
        {
            level = strtoul(s.substr(i, pos-i).c_str(), NULL, 10);
            vector.push_back(level);
            i = pos + 1;
        }
    }
}
bool    String::ToBool  (const std::string &s)
{
    if (s == "true" || s == "True" || s == "TRUE")
    {
        return true;
    }
    else
    {
        return false;
    }
}