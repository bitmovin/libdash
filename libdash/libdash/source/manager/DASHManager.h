/*
 * DASHManager.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DASHMANAGER_H_
#define DASHMANAGER_H_

#include "config.h"

#include "../xml/Node.h"
#include "../xml/DOMParser.h"
#include "IDASHManager.h"
#include "../helpers/Time.h"

namespace dash
{
    class DASHManager : public IDASHManager
    {
        public:
            DASHManager             ();
            virtual ~DASHManager    ();

            mpd::IMPD*  Open    (const char *path);
            void        Delete  ();
    };
}

#endif /* DASHMANAGER_H_ */
