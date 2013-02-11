/*
 * DASHManager.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHManager.h"

using namespace dash;
using namespace dash::xml;
using namespace dash::mpd;
using namespace dash::network;

DASHManager::DASHManager            ()
{
}
DASHManager::~DASHManager           ()
{
}
IMPD*           DASHManager::Open           (char *path)
{
    DOMParser parser(path);

    if(!parser.Parse())
        return NULL;

    IMPD* mpd = parser.GetRootNode()->ToMPD();

    return mpd;
}
