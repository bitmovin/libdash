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

#include "MediaObject.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class IAdaptationLogic
            {
                public:
                    virtual ~IAdaptationLogic () {}

                    virtual MediaObject* GetSegment (uint32_t number) = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_IADAPTATIONLOGIC_H_ */
