/**
 *  @class      dash::mpd::IRange
 *  @brief      This interface is needed for accessing the attributes and elements of the Metrics <tt><b>Range</b></tt> element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.9.2, table 23
 *  @details    It specifies the time period during which DASH Metrics collection is requested.
 *  @see        dash::mpd::IMetrics
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IRANGE_H_
#define IRANGE_H_

#include "config.h"

namespace dash
{
    namespace mpd
    {
        class IRange
        {
            public:
                virtual ~IRange(){}

                /**
                 *  Returns a reference to a string that specifies the start time of the DASH Metrics collection operation. 
                 *  When not present, DASH Metrics collection is requested from the beginning of content consumption.
                 *  For services with <tt><b>MPD</b>\@type='dynamic'</tt>, the start time is indicated in wallclock time by adding the value of this 
                 *  attribute to the value of the <tt><b>MPD</b>\@availabilityStartTime</tt> attribute.
                 *  For services with <tt><b>MPD</b>\@type='static'</tt>, the start time is indicated in Media Presentation time and is relative to the 
                 *  PeriodStart time of the first Period in this MPD. 
                 *  \b NOTE:    For example, if <tt><b>MPD</b>\@availabilityStartTime</tt> is 14:30 and the metrics collection is intended to start at 14:45, then \c \@starttime is 0:15.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetStarttime    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the duration of the DASH metrics collection interval. The value of the attribute expresses in Media Presentation time.
                 *  If not present, the value is identical to the Media Presentation duration.
                 *  @return     a reference to string
                 */
                virtual const std::string&  GetDuration     ()  const = 0;

        };
    }
}

#endif /* IRANGE_H_ */