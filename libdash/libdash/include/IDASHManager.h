/*
 * IDASHManager.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IDASHMANAGER_H_
#define IDASHMANAGER_H_

#include "config.h"

#include "IMPD.h"
#include "IConnection.h"

namespace dash
{
    class IDASHManager
    {
        public:
            virtual ~IDASHManager(){}

            virtual mpd::IMPD* Open (char *path) = 0;
    };
}

#endif /* IDASHMANAGER_H_ */
