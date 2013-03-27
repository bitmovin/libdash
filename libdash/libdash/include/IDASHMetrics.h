/**
 *  @class      dash::metrics::IDASHMetrics
 *  @brief      The connection interface can be used to retrieve DASH Metrics.
 *  @details    The <em>TCP Connection</em> list and <em>HTTP Request/Response Transactions</em> can be retrieved. \n
 *              This basically corresponds to the information neeed for <tt>Observation point 1</tt> as defined in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.3.2.
 *  @see        dash::metrics::ITCPConnection dash::metrics::IHTTPConnection
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IDASHMETRICS_H_
#define IDASHMETRICS_H_

#include "config.h"
#include "IHTTPTransaction.h"
#include "ITCPConnection.h"

namespace dash
{
    namespace metrics
    {
        class IDASHMetrics
        {
            public:
                virtual ~IDASHMetrics(){}

                /**
                 *  This function returns a list of DASH Metrics as defined in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.4.2.
                 *  @return     a list of dash::metrics::ITCPConnection Metrics Objects
                 */
                virtual const std::vector<ITCPConnection *>&   GetTCPConnectionList    () const = 0;

                /**
                 *  This function returns a list of DASH Metrics as defined in <em>ISO/IEC 23009-1, Part 1, 2012</em>, annex D.4.3.
                 *  @return     a list of dash::metrics::IHTTPConnection Metrics Objets
                 */
                virtual const std::vector<IHTTPTransaction *>& GetHTTPTransactionList  () const = 0;
        };
    }
}

#endif /* IDASHMETRICS_H_ */
