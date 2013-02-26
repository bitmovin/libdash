/*
 * Path.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Path.h"

using namespace dash::helpers;

std::string                 Path::CombinePaths          (const std::string &path1, const std::string &path2)
{
    if(path1 == "")
        return path2;
    if(path2 == "")
        return path1;

    char path1Last  = path1.at(path1.size() - 1);
    char path2First = path2.at(0);

    if(path1Last == '/' && path2First == '/')
        return path1 + path2.substr(1, path2.size());

    if(path1Last != '/' && path2First != '/')
        return path1 + "/" + path2;

    return path1 + path2;
}
std::string                 Path::GetDirectoryPath      (const std::string &path)
{
    int pos = path.find_last_of('/');

    return path.substr(0, pos);
}
std::vector<std::string>    Path::Split                 (const std::string &s, char delim)
{
    std::stringstream           ss(s);
    std::string                 item;
    std::vector<std::string>    ret;

    while(std::getline(ss, item, delim))
        ret.push_back(item);

    return ret;
}
bool                        Path::GetHostPortAndPath    (const std::string &url, std::string &host, size_t &port, std::string& path)
{
    std::string hostPort = "";
    size_t found = 0;
    size_t pathBegin = 0;

    if (url.substr(0,7) == "http://" || url.substr(0,8) == "https://")
    {
        found = url.find("//");
        pathBegin = url.find('/', found+2);
        path = url.substr(pathBegin, std::string::npos);

        hostPort = url.substr(found+2, pathBegin - (found+2));
        found = hostPort.find(':');
        if (found != std::string::npos)
        {
            port = strtoul(hostPort.substr(found+1, std::string::npos).c_str(), NULL, 10);
        }
        host = hostPort.substr(0, found);
        return (host.size() > 0) && (path.size() > 0);
    }

    return false;
}
bool                        Path::GetStartAndEndBytes   (const std::string &byteRange, size_t &startByte, size_t &endByte)
{
    size_t found = 0;

    found = byteRange.find('-');
    if (found != std::string::npos && found < byteRange.size()-1 )
    {
        startByte = strtoul(byteRange.substr(0, found).c_str(), NULL, 10);
        endByte = strtoul(byteRange.substr(found+1, std::string::npos).c_str(), NULL, 10);
        return (startByte <= endByte);
    }

    return false;
}