/*
 * IAdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_IADAPTATIONLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_IADAPTATIONLOGIC_H_

#include "../Input/MediaObject.h"
#include "IRepresentation.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            enum LogicType
            {
                Manual,
                AlwaysLowest
            };

            class IAdaptationLogic
            {
                public:
                    virtual ~IAdaptationLogic () {}

                    virtual uint32_t                    GetPosition         ()                                              = 0;
                    virtual void                        SetPosition         (uint32_t segmentNumber)                        = 0;
                    virtual dash::mpd::IRepresentation* GetRepresentation   ()                                              = 0;
                    virtual void                        SetRepresentation   (dash::mpd::IPeriod *period,
                                                                             dash::mpd::IAdaptationSet *adaptationSet,
                                                                             dash::mpd::IRepresentation *representation)    = 0;
                    virtual LogicType                   GetType             ()                                              = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_IADAPTATIONLOGIC_H_ */
