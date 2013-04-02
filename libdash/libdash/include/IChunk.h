/**
 *  @class      dash::network::IChunk
 *  @brief      This interface is needed for accessing the information belonging to a dash::network::IChunk object
 *  @details    Provides specific information of a chunk, e.g., URI, Hostname, Port, Path and optional Range that
 *              that are needed to download this chunk.
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ICHUNK_H_
#define ICHUNK_H_

#include "config.h"
#include "IHTTPTransaction.h"

namespace dash
{
    namespace network
    {
        class IChunk
        {
            public:
                virtual ~IChunk(){}

                /**
                 *  Returns a reference to a string that specifies the absolute URI to this chunk
                 *  @return     a reference to a string
                 */
                virtual std::string&    AbsoluteURI     ()  = 0;

                /**
                 *  Returns a reference to a string that specifies the host of this chunk
                 *  @return     a reference to a string
                 */
                virtual std::string&    Host            ()  = 0;

                /**
                 *  Returns an unsigned integer representing the port belonging to this chunk
                 *  @return     an unsigned integer
                 */
                virtual size_t          Port            ()  = 0;

                /**
                 *  Returns a reference to a string that specifies the path to this chunk
                 *  @return     a reference to a string
                 */
                virtual std::string&    Path            ()  = 0;

                /**
                 *  Returns a reference to a string that specifies the byte range belonging to this chunk
                 *  @return     a reference to a string
                 */
                virtual std::string&    Range           ()  = 0;

                /**
                 *  Returns an unsigned integer representing the start byte of the byte range that belongs to this chunk
                 *  @return     an unsigned integer
                 */
                virtual size_t          StartByte       ()  = 0;

                /**
                 *  Returns an unsigned integer representing the end byte of the byte range that belongs to this chunk
                 *  @return     an unsigned integer
                 */
                virtual size_t          EndByte         ()  = 0;

                /**
                 *  Returns a bool value that represents whether this chunk has a byte range or not
                 *  @return     a bool value
                 */
                virtual bool            HasByteRange    ()  = 0;

                /**
                 *  Returns the type of a <b>HTTP Request/Response Transaction</b> in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.4.3, Table D.2
                 *  @return     a dash::metrics::HTTPTransactionType
                 */
                virtual dash::metrics::HTTPTransactionType GetType  ()  = 0;
        };
    }
}

#endif /* ICHUNK_H_ */