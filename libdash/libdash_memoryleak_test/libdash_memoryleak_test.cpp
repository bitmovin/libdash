/*
 * libdash_memoryleak_test.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "libdash.h"
#include "IMPD.h"

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace dash;
using namespace dash::network;
using namespace std;
using namespace dash::mpd;


int main()
{
    IDASHManager    *manager    = CreateDashManager();
    IMPD            *mpd        = manager->Open("TestMPD.mpd");

    delete(mpd);

    mpd = manager->Open("http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/BigBuckBunny/MPDs/BigBuckBunnyNonSeg_2s_isoffmain_DIS_23009_1_v_2_1c2_2011_08_30.mpd");
    
    std::vector<dash::mpd::IBaseUrl *> baseurls;
    baseurls.push_back(mpd->GetBaseUrls().at(0));
    dash::mpd::ISegment *seg = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRepresentation().at(0)->GetSegmentList()->GetSegmentURLs().at(0)->ToMediaSegment(baseurls);
    seg->StartDownload();

    delete(seg);
    delete(mpd);
    delete(manager);

    _CrtDumpMemoryLeaks();
    return 0;
}
