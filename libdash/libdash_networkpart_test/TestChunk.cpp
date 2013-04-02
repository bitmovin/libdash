/*
 * TestChunk.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "TestChunk.h"

using namespace dash::network;
using namespace libdashtest;

TestChunk::TestChunk        (std::string host, size_t port, std::string path, size_t startbyte, size_t endbyte, bool hasByteRange) :
           host             (host),
           port             (port),
           path             (path),
           startbyte        (startbyte),
           endbyte          (endbyte),
           hasByteRange     (hasByteRange)
{
}
TestChunk::~TestChunk       ()
{
}

std::string&    TestChunk::AbsoluteURI     ()
{
    return this->uri;
}
std::string&    TestChunk::Host            ()
{
    return this->host;
}
size_t          TestChunk::Port            ()
{
    return this->port;
}
std::string&    TestChunk::Path            ()
{
    return this->path;
}
size_t          TestChunk::StartByte       ()
{
    return this->startbyte;
}
size_t          TestChunk::EndByte         ()
{
    return this->endbyte;
}
bool            TestChunk::HasByteRange    ()
{
    return this->hasByteRange;
}
std::string&    TestChunk::Range           ()
{
    return this->range;
}
dash::metrics::HTTPTransactionType  TestChunk::GetType()
{
    return dash::metrics::Other;
}
