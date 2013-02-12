/*
 * main.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "QtSamplePlayerGui.h"

#include <QApplication>

#include "libdash.h"
#include "DASHPlayer.h"
#include "Decoder/LibavDecoder.h"
#include "Input/DASHReceiver.h"

using namespace sampleplayer;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtSamplePlayerGui w;
    DASHPlayer p(w);

//    w.addWidgetObserver(&obs);

   /* std::vector<std::string> v_repr;
    v_repr.push_back("asdf");
    v_repr.push_back("bcdaswr");

    std::vector<std::string> v_repr2;
    v_repr2.push_back("lllll");
    v_repr2.push_back("ttttt");


    std::map<std::string, std::vector<std::string> > v_adaption;
    v_adaption["Video 1"] = v_repr;
    v_adaption["Video 2"] = v_repr2;


    w.setGuiFields(v_adaption, v_adaption);

    w.updateKeyValue("Framerate", "25");
    w.updateKeyValue("Bitrate", "120000000");*/

    
    
    w.show();

    return a.exec();
}
