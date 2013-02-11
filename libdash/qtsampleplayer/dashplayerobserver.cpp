/*
 * dashplayerobserver.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "dashplayerobserver.h"
#include <iostream>

using namespace std;

DashPlayerObserver::DashPlayerObserver()
{
}

DashPlayerObserver::~DashPlayerObserver()
{

}

void DashPlayerObserver::OnSettingsChanged (QtSamplePlayer* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation)
{
    cout << "Settings changed" << endl;
    widget->setBufferFillState(80);
}

void DashPlayerObserver::OnURLChanged(QtSamplePlayer* widget, const std::string& url)
{
    widget->setBufferFillState(40);

    cout << "Url changed" << endl;
}

