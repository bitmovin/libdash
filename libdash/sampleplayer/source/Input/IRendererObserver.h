/*
 * IRendererObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IRENDEREROBSERVER_H_
#define IRENDEREROBSERVER_H_

#include "config.h"

namespace sampleplayer
{
    namespace input
    {
        class IRendererObserver
        {
            public:
                virtual         ~IRendererObserver      (){};

                virtual void    ChangeRepresentation    ()  = 0;
                virtual void    ChangeAdaptationSet     ()  = 0;
                virtual void    ChangePeriod            ()  = 0;
        };
    }
}
#endif /* IRENDEREROBSERVER_H_ */
