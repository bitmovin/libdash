/*
 * AdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ADAPTATIONLOGIC_H_
#define ADAPTATIONLOGIC_H_

namespace sampleplayer
{
    namespace input
    {
        class AdaptationLogic
        {
            public:
                AdaptationLogic             ();
                virtual ~AdaptationLogic    ();
        };
    }
}

#endif /* ADAPTATIONLOGIC_H_ */