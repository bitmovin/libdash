/*
 * SPDYChunk.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Created on: 7/13/2013
 * Author: Christopher Mueller <christopher.mueller@bitmovin.net>
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SPDYChunk.h"

using namespace libdash::framework::input;

SPDYChunk::SPDYChunk    (dash::network::IChunk *chunk) :
    chunk           (chunk),
    contentLength   (0),
    bytesRead       (0)
{
}
SPDYChunk::~SPDYChunk   ()
{
}
