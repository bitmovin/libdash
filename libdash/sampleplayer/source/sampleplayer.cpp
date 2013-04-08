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
#include "Input/DASHManager.h"
#include "Renderer/SDLRenderer.h"
#include "Buffer/AVFrameBuffer.h"
#include "IMPD.h"
#include "IDASHManager.h"

using namespace sampleplayer::decoder;
using namespace sampleplayer::input;
using namespace sampleplayer::renderer;
using namespace sampleplayer::buffer;

int main(int argc, char *argv[])
{
    dash::IDASHManager  *man = CreateDashManager();

    /* 
     *  Big Buck Bunny 480p only - Segment List 
     *  Do not forget to alter Constructor, GetInitSegment() and GetSegment() in adaptation logic if you switch back
     */
    //dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/big_buck_bunny_480.mpd");

    /* 
     *  Red Bull - Segment Template
     *  Do not forget to alter Constructor, GetInitSegment() and GetSegment() in adaptation logic if you switch back
     */
    dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_segment_template.mpd");

    AVFrameBuffer   *frameBuffer    = new AVFrameBuffer(4);
    DASHManager     *manager        = new DASHManager(frameBuffer, 20, mpd);
    SDLRenderer     *renderer       = new SDLRenderer(frameBuffer);

    manager->Start();
    renderer->Start();

    bool eos = false;

    while(!renderer->isQuitKeyPressed() && !eos)
    {
        renderer->processEvents();
    }

    return 0;
}
