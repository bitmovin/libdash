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
#include "INode.h"

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace dash;
using namespace dash::network;
using namespace std;
using namespace dash::mpd;

void testleaks()
{
    IDASHManager    *manager    = CreateDashManager();
    IMPD            *mpd        = manager->Open("TestMPD.mpd");

    if (mpd)
    {
        dash::xml::INode* inode = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetSegmentTemplate()->GetSegmentTimeline()->GetAdditionalSubNodes().at(0);
        std::map<std::string, std::string> rawAttr = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetSegmentTemplate()->GetSegmentTimeline()->GetRawAttributes();

        std::string nodeText = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetAdditionalSubNodes().at(0)->GetName();
        nodeText = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetAdditionalSubNodes().at(0)->GetText();

        nodeText = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetContentProtection().at(0)->GetAdditionalSubNodes().at(1)->GetName();
        nodeText = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetContentProtection().at(0)->GetAdditionalSubNodes().at(1)->GetText();

        rawAttr = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRawAttributes();

        delete(mpd);
    }

    mpd = manager->Open("http://www-itec.uni-klu.ac.at/ftp/datasets/mmsys12/BigBuckBunny/MPDs/BigBuckBunnyNonSeg_2s_isoffmain_DIS_23009_1_v_2_1c2_2011_08_30.mpd");
    std::string mediauri = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRepresentation().at(0)->GetSegmentList()->GetSegmentURLs().at(0)->GetMediaURI();
    std::string mediarng = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRepresentation().at(0)->GetSegmentList()->GetSegmentURLs().at(0)->GetMediaRange();

    std::vector<dash::mpd::IBaseUrl *> baseurls;
    baseurls.push_back(mpd->GetBaseUrls().at(0));
    dash::mpd::ISegment *seg = mpd->GetPeriods().at(0)->GetAdaptationSets().at(0)->GetRepresentation().at(0)->GetSegmentList()->GetSegmentURLs().at(0)->ToMediaSegment(baseurls);
    seg->StartDownload();

    delete(seg);
    delete(mpd);
    delete(manager);
}
int main()
{
    testleaks();
    _CrtDumpMemoryLeaks();
    return 0;
}
