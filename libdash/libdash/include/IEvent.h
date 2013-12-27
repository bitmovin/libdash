/**
 *  @class      dash::mpd::IEvent
 *  @brief      This interface is needed for accessing the attributes of the <tt><b>Event</b></tt> type
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2013</em>, section 5.10.2
 *  @details    Events may be provided in the MPD or within a Representation in order to signal aperiodic
 *              information to the DASH client or to an application. Events are timed, i.e. each event starts
 *              at a specific media presentation time and typically has a duration. Events include DASH
 *              specific signalling or application-specific events. In the latter case, a proper scheme
 *              identifier identifies the application such that the DASH client can forward the event to the
 *              proper application.
 *
 *  @author     bitmovin Softwareentwicklung GmbH \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung GmbH, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IEVENT_H_
#define IEVENT_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IEvent : public virtual IMPDElement
        {
            public:
                virtual ~IEvent(){}

                /**
                 *  Returns a long that specifies the presentation time of the event relative to the start of the Period.\n
                 *  The value of the presentation time in seconds is the division of the value of this attribute and the \n
                 *  value of the @timescale attribute.
                 *  @return     an unsigned long
                 */
                virtual uint64_t    GetPresentationTime ()  const = 0;

                /**
                 *  Returns a long that specifies the presentation duration of the event. \n
                 *  The value of the duration in seconds is the division of the value of this attribute and the value of the \n
                 *  @timescale attribute.
                 *  @return     an unsigned long
                 */
                virtual uint64_t    GetDuration         ()  const = 0;

                /**
                 *  Returns an integer that specifies an identifier for this instance of the event. Events with equivalent content \n
                 *  and attribute values in the Event element shall have the same value for this attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t    GetId               ()  const = 0;
        };
    }
}

#endif /* IEVENT_H_ */