/**
 *  @class      dash::metrics::IThroughputMeasurement
 *  @brief      This interface is needed for accessing the attributes and the content of a single <tt><b>Throughput Measurment</b></tt> entry
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.4.3 (part of the HTTP Request/Response Transaction)
 *  @see        dash::metrics::IHTTPTransaction
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ITHROUGHPUTMEASUREMENT_H_
#define ITHROUGHPUTMEASUREMENT_H_

#include "config.h"

namespace dash
{
    namespace metrics
    {
        class IThroughputMeasurement
        {
            public:
                virtual ~IThroughputMeasurement (){}

                virtual const std::string&              StartOfPeriod           () const = 0;
                virtual uint64_t                        DurationOfPeriod        () const = 0;
                virtual const std::vector<uint32_t>&    ReceivedBytesPerTrace   () const = 0;

        };
    }
}

#endif /* ITHROUGHPUTMEASUREMENT_H_ */
