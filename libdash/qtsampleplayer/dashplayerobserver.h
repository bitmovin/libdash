/*
 * dashplayerobserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
#ifndef WIDGETOBSERVER_H
#define WIDGETOBSERVER_H

#include <string>
#include "qtsampleplayer.h"

class DashPlayerObserver
{
public:
    DashPlayerObserver();
    virtual ~DashPlayerObserver();

    virtual void OnSettingsChanged (QtSamplePlayer* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation);
    virtual void OnURLChanged(QtSamplePlayer* widget, const std::string& url);
};

#endif // WIDGETOBSERVER_H
