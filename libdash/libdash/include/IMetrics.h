/**
 *  @class      dash::mpd::IMetrics
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>Metrics</b></tt> element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.9.2, table 23
 *  @details    This part of <em>ISO/IEC 23009</em> does not define mechanisms for reporting metrics, however it does define a set of metrics and a mechanism 
 *              that may be used by the service provider to trigger metric collection and reporting at the clients, should a reporting mechanism be available.
 *              The trigger mechanism is based on the <tt><b>Metrics</b></tt> element in the MPD. The element contains the list of DASH Metrics for which the measurements are desired, 
 *              the time interval and the granularity for the measurements, as well as the scheme according to which the metric reporting is desired.
 *  @see        dash::mpd::IDescriptor dash::mpd::IRange dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IMETRICS_H_
#define IMETRICS_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"
#include "IRange.h"

namespace dash
{
    namespace mpd
    {
        class IMetrics : public virtual IMPDElement
        {
            public:
                virtual ~IMetrics(){}

                /**
                 *  Returns a refernce to a vector of pointers to dash::mpd::IDescriptor objects that specify information about the requested reporting method and formats.\n
                 *  For more details refer to section 5.9.4. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&   GetReportings   ()  const = 0;

                 /**
                 *  Returns a refernce to a vector of pointers to dash::mpd::IRange objects that specify the time period during which DASH Metrics collection is requested.
                 *  When not present, DASH Metrics reporting is requested for the whole duration of the content.
                 *  @return     a reference to a vector of pointers to dash::mpd::IRange objects
                 */
                virtual const std::vector<IRange *>&        GetRanges       ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies all DASH Metrics (as a list of DASH Metric keys as defined in Annex D of <em>ISO/IEC 23009-1, Part 1, 2012</em>, separated by a comma)
                 *  that the client is desired to report.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                  GetMetrics      ()  const = 0;

        };
    }
}

#endif /* IMETRICS_H_ */