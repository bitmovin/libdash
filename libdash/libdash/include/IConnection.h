/*
 * IConnection.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ICONNECTION_H_
#define ICONNECTION_H_

#include "config.h"

#include "IChunk.h"

namespace dash
{
    namespace network
    {
        class IConnection
        {
            public:
                virtual ~IConnection(){}

                virtual int Read (uint8_t *data, size_t len, IChunk *chunk)  = 0;
                virtual int Peek (uint8_t *data, size_t len, IChunk *chunk)  = 0;
        };
    }
}

#endif /* ICONNECTION_H_ */