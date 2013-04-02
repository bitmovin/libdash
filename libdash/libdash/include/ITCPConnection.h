/**
 *  @class      dash::metrics::ITCPConnection
 *  @brief      This interface is needed for accessing the attributes and the content of a <tt><b>TCP Connection</b></tt>
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.4.2
 *  @see        
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ITCTPCONNECTION_H_
#define ITCTPCONNECTION_H_

#include "config.h"

namespace dash
{
    namespace metrics
    {
        class ITCPConnection
        {
            public:
                virtual ~ITCPConnection (){}

                virtual uint32_t            TCPId                   () const = 0;
                virtual const std::string&  DestinationAddress      () const = 0;
                virtual const std::string&  ConnectionOpenedTime    () const = 0;
                virtual const std::string&  ConnectionClosedTime    () const = 0;
                virtual uint64_t            ConnectionTime          () const = 0;

        };
    }
}

#endif /* ITCTPCONNECTION_H_ */
