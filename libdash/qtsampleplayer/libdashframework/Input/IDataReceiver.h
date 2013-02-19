/*
 * IDataReceiver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_IDATARECEIVER_H_
#define LIBDASH_FRAMEWORK_INPUT_IDATARECEIVER_H_

#include <stdint.h>

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class IDataReceiver
            {
                public:
                    virtual ~IDataReceiver () {}

                    virtual int Read (uint8_t *buf, int buf_size ) = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_INPUT_IDATARECEIVER_H_ */
