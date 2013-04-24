/*
 * AudioChunk.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AudioChunk.h"

using namespace libdash::framework::buffer;

AudioChunk::AudioChunk  (QAudioFormat *format, char* data, qint64 dataLength) :
            chunkLength (dataLength),
            format      (format)
{
    this->data = (char*) malloc(this->chunkLength);
    memcpy(this->data, data, this->chunkLength);
}
AudioChunk::~AudioChunk ()
{
    delete this->format;
    free(this->data);
}

char*           AudioChunk::Data    ()
{
    return this->data;
}
qint64          AudioChunk::Length  ()
{
    return this->chunkLength;
}
QAudioFormat*   AudioChunk::Format  ()
{
    return this->format;
}
