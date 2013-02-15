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

                    virtual MediaObject* GetSegment                 () = 0;
                    virtual uint32_t     GetSegmentNumber           () = 0;
                    virtual void         SetSegmentNumber           (uint32_t segmentNumber) = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_IADAPTATIONLOGIC_H_ */
