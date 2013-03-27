/**
 *  @class      dash::network::IConnection
 *  @brief      The connection interface can be used to enable the download of segments through external connections.
 *  @details    This interface enables the extension of libdash to download segment through, e.g., SPDY, CCN etc.
 *  @see        dash::network::IChunk
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ICONNECTION_H_
#define ICONNECTION_H_

#include "config.h"

#include "IChunk.h"
#include "IDASHMetrics.h"

namespace dash
{
    namespace network
    {
        class IConnection : public virtual dash::metrics::IDASHMetrics
        {
            public:
                virtual ~IConnection(){}

                /**
                 *  This function should read a block of bytes from the specified chunk.
                 *  @param      data    pointer to a block of memory
                 *  @param      len     size of the memory block that can be used by the method
                 *  @param      chunk   the dash::network::IChunk object from which data should be read
                 *  @return     amount of data that has been read
                 */
                virtual int Read (uint8_t *data, size_t len, IChunk *chunk)  = 0;

                /**
                 *  This function should peek a block of bytes from the specified chunk.
                 *  @param      data    pointer to a block of memory
                 *  @param      len     size of the memory block that can be used by the method
                 *  @param      chunk   the dash::network::IChunk object from which data should be peeked
                 *  @return     amount of data that has been peeked
                 */
                virtual int Peek (uint8_t *data, size_t len, IChunk *chunk)  = 0;
        };
    }
}

#endif /* ICONNECTION_H_ */