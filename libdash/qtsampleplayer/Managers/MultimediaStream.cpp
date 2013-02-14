/*
 * MultimediaStream.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultimediaStream.h"

using namespace sampleplayer::managers;
using namespace sampleplayer::renderer;

MultimediaStream::MultimediaStream  ()
{
}
MultimediaStream::~MultimediaStream ()
{
}

void MultimediaStream::OnAudioDataAvailable (const uint8_t **data, audioFrameProperties* props)
{
}
void MultimediaStream::OnVideoDataAvailable (const uint8_t **data, videoFrameProperties* props)
{
}
void MultimediaStream::AttachStreamObserver (IStreamObserver *observer)
{
}
