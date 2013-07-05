/**
 *  @class      dash::metrics::IHTTPTransaction
 *  @brief      This interface is needed for accessing the attributes and the content of a <tt><b>HTTP Request/Response Transaction</b></tt>
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.4.3
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IHTTPTRANSACTION_H_
#define IHTTPTRANSACTION_H_

#include "config.h"
#include "IThroughputMeasurement.h"

namespace dash
{
    namespace metrics
    {
        enum HTTPTransactionType
        {
            MPD,
            XLinkEpansion,
            InitializationSegment,
            IndexSegment,
            MediaSegment,
            BitstreamSwitchingSegment,
            Other
        };

        class IHTTPTransaction
        {
            public:
                virtual ~IHTTPTransaction (){}

                virtual uint32_t                                        TCPId                   () const = 0;
                virtual HTTPTransactionType                             Type                    () const = 0;
                virtual const std::string&                              OriginalUrl             () const = 0;
                virtual const std::string&                              ActualUrl               () const = 0;
                virtual const std::string&                              Range                   () const = 0;
                virtual const std::string&                              RequestSentTime         () const = 0;
                virtual const std::string&                              ResponseReceivedTime    () const = 0;
                virtual uint16_t                                        ResponseCode            () const = 0;
                virtual uint64_t                                        Interval                () const = 0;
                virtual const std::vector<IThroughputMeasurement *>&    ThroughputTrace         () const = 0;
                virtual const std::string&                              HTTPHeader              () const = 0;
        };
    }
}

#endif /* IHTTPTRANSACTION_H_ */
