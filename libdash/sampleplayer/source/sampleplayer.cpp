/*
 * sampleplayer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Decoder/LibavDecoder.h"
#include "Input/DASHReceiver.h"
#include "Renderer/SDLRenderer.h"

using namespace sampleplayer::decoder;
using namespace sampleplayer::input;
using namespace sampleplayer::renderer;

int main(int argc, char *argv[])
{
    SDLRenderer     *renderer = new SDLRenderer();
    DASHReceiver    *receiver = new DASHReceiver(30); // Init a DASHReceiver with a buffer size of 30 Segments

    receiver->Init("http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/BigBuckBunny/bunny_2s_480p_only/bunny_Desktop.mpd");

    LibavDecoder *decoder = new LibavDecoder(receiver);

    decoder->attachVideoObserver(renderer);
    decoder->setFrameRate(24);
    decoder->init();
    
    bool eos = false;

    while(!renderer->isQuitKeyPressed() && !eos)
    {
        eos = !decoder->decode();
        renderer->processEvents();
    }

    decoder->stop();

    return 0;
}
