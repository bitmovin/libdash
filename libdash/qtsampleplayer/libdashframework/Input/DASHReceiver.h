/*
 * DASHReceiver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_
#define LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_

#include "libdash.h"
#include "IMPD.h"

#include "IDASHReceiverObserver.h"
#include "../Buffer/MediaObjectBuffer.h"

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class DASHReceiver
            {
                public:
                    DASHReceiver            (uint32_t maxcapacity);
                    virtual ~DASHReceiver   ();

                private:
                    buffer::MediaObjectBuffer   *buffer;
                    uint32_t                    maxcapacity;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_INPUT_DASHRECEIVER_H_ */