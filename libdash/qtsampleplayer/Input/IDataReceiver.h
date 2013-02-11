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

#ifndef IDATARECEIVER_H_
#define IDATARECEIVER_H_

#include <stdint.h>

namespace sampleplayer
{
    namespace input
    {
        class IDataReceiver
        {
            public:
                virtual         ~IDataReceiver   (){};

                virtual int     IORead           (uint8_t *buf, int buf_size ) = 0;
        };
    }
}
#endif /* IDATARECEIVER_H_ */
