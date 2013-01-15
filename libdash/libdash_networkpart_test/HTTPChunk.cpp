/*
 * HTTPChunk.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "HTTPChunk.h"

using namespace libdashtest;
using namespace dash::network;

HTTPChunk::HTTPChunk        (IChunk *chunk) :
           chunk            (chunk),
           contentLength    (0),
           isHeaderParsed   (false),
           bytesLeft        (0),
           bytesRead        (0)
{
}
HTTPChunk::~HTTPChunk       ()
{
}

IChunk*     HTTPChunk::Chunk            ()
{
    return this->chunk;
}
uint64_t    HTTPChunk::ContentLength    () const
{
    return this->contentLength;
}
bool        HTTPChunk::HeaderParsed     () const
{
    return this->isHeaderParsed;
}
void        HTTPChunk::HeaderParsed     (bool value)
{
    this->isHeaderParsed = value;
}
void        HTTPChunk::ContentLength    (uint64_t length)
{
    this->contentLength = length;
    this->bytesLeft     = length;
}
void        HTTPChunk::AddBytesRead     (uint64_t bytes)
{
    this->bytesRead += bytes;
    this->bytesLeft -= bytes;
}
void        HTTPChunk::BytesRead        (uint64_t bytes)
{
    this->bytesRead = bytes;
    this->bytesLeft = this->contentLength - bytes;
}
uint64_t    HTTPChunk::BytesRead        () const
{
    return this->bytesRead;
}
uint64_t    HTTPChunk::BytesLeft        () const
{
    return this->bytesLeft;
}
