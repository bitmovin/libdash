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

#include <QApplication>
#include "UI/DASHPlayer.h"

using namespace sampleplayer;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtSamplePlayerGui w;

    DASHPlayer p(w);

    w.show();

    return a.exec();
}
