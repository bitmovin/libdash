/*
 * IMediaObjectBufferObserver.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_BUFFER_IMEDIAOBJECTBUFFEROBSERVER_H_
#define LIBDASH_FRAMEWORK_BUFFER_IMEDIAOBJECTBUFFEROBSERVER_H_

#include <stdint.h>

namespace libdash
{
    namespace framework
    {
        namespace buffer
        {
            class IMediaObjectBufferObserver
            {
                public:
                    virtual ~IMediaObjectBufferObserver () {}

                    virtual void OnBufferStateChanged(uint32_t fillstateInPercent) = 0;

            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_BUFFER_IMEDIAOBJECTBUFFEROBSERVER_H_ */
