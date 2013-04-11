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
#include "helpers/Timing.h"

using namespace sampleplayer::decoder;
using namespace sampleplayer::input;
using namespace sampleplayer::renderer;
using namespace sampleplayer::buffer;
using namespace sampleplayer::helpers;

int main(int argc, char *argv[])
{
    dash::IDASHManager  *man = CreateDashManager();

    /* 
     *  Big Buck Bunny 480p only - Segment List 
     *  Do not forget to alter GetInitSegment() and GetSegment() in adaptation logic if you switch back
     */
    dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/big_buck_bunny_480.mpd");

    /* 
     *  Red Bull - Segment Template (only AdaptationSet switches possible)
     *  Do not forget to alter GetInitSegment() and GetSegment() in adaptation logic if you switch back
     */
    //dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_segment_template.mpd");

    AVFrameBuffer   *frameBuffer    = new AVFrameBuffer(2);
    DASHManager     *manager        = new DASHManager(frameBuffer, 1, mpd);
    SDLRenderer     *renderer       = new SDLRenderer(frameBuffer, manager);

    manager->Start();
    renderer->Start();

    while(!renderer->isQuitKeyPressed());

    renderer->Stop();
    manager->Stop();

    Timing::DisposeTimingObjects();

    return 0;
}
