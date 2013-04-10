/*
 * Segment.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Segment.h"

using namespace dash::mpd;
using namespace dash::helpers;
using namespace dash::metrics;

Segment::Segment    ()  :
            host(""),
            port(0),
            path(""),
            startByte(0),
            endByte(0),
            hasByteRange(false)
{
}
Segment::~Segment   ()
{
}

bool                Segment::Init               (const std::vector<IBaseUrl *>& baseurls, const std::string &uri, const std::string &range, HTTPTransactionType type)
{
    std::string host        = "";
    size_t      port        = 80;
    std::string path        = "";
    size_t      startByte   = 0;
    size_t      endByte     = 0;

    this->absoluteuri = "";

    for(size_t i = 0; i < baseurls.size(); i++)
        this->absoluteuri = Path::CombinePaths(this->absoluteuri, baseurls.at(i)->GetUrl());

    this->absoluteuri = Path::CombinePaths(this->absoluteuri, uri);

    if (uri != "" && dash::helpers::Path::GetHostPortAndPath(this->absoluteuri, host, port, path))
    {
        this->host = host;
        this->port = port;
        this->path = path;

        if (range != "" && dash::helpers::Path::GetStartAndEndBytes(range, startByte, endByte))
        {
            this->range         = range;
            this->hasByteRange  = true;
            this->startByte     = startByte;
            this->endByte       = endByte;
        }

        this->type = type;

        return true;
    }

    return false;
}
std::string&        Segment::AbsoluteURI        ()
{
    return this->absoluteuri;
}
std::string&        Segment::Host               ()
{
    return this->host;
}
size_t              Segment::Port               ()
{
    return this->port;
}
std::string&        Segment::Path               ()
{
    return this->path;
}
std::string&        Segment::Range              ()
{
    return this->range;
}
size_t              Segment::StartByte          ()
{
    return this->startByte;
}
size_t              Segment::EndByte            ()
{
    return this->endByte;
}
bool                Segment::HasByteRange       ()
{
    return this->hasByteRange;
}
void                Segment::AbsoluteURI        (std::string uri)
{
    this->absoluteuri = uri;
}
void                Segment::Host               (std::string host)
{
    this->host = host;
}
void                Segment::Port               (size_t port)
{
    this->port = port;
}
void                Segment::Path               (std::string path)
{
    this->path = path;
}
void                Segment::Range              (std::string range)
{
    this->range = range;
}
void                Segment::StartByte          (size_t startByte)
{
    this->startByte = startByte;
}
void                Segment::EndByte            (size_t endByte)
{
    this->endByte = endByte;
}
void                Segment::HasByteRange       (bool hasByteRange)
{
    this->hasByteRange = hasByteRange;
}
HTTPTransactionType Segment::GetType            ()
{
    return this->type;
}
void                Segment::SetType            (HTTPTransactionType type)
{
    this->type = type;
}
