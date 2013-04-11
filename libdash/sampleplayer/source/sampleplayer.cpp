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

    //dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/big_buck_bunny_480.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_2_resolutions.mpd");
    dash::mpd::IMPD     *mpd = man->Open("http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_segment_template.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/1a/netflix/exMPD_BIP_TC1.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/1a/sony/SNE_DASH_SD_CASE1A_REVISED.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/1b/envivio/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/1b/thomson-networks/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/1c/envivio/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/2a/envivio/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/2a/sony/SNE_DASH_CASE_2A_SD_REVISED.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/3a/fraunhofer/ed.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/3b/fraunhofer/elephants_dream_heaac2_0.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/3b/sony/SNE_DASH_CASE3B_SD_REVISED.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/4b/sony/SNE_DASH_CASE4B_SD_REVISED.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/5a/1/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/5b/1/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/6c/envivio/manifest.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://dash.edgesuite.net/dash264/TestCases/6c/envivio/manifest2.mpd");
    //dash::mpd::IMPD     *mpd = man->Open("http://tvnlive.dashdemo.edgesuite.net/live/manifest.mpd");

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
