/**
 *  @class      dash::mpd::ITimeline
 *  @brief      This interface is needed for accessing the attributes of <b><tt>S</tt></b> elements, as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.6.1
 *  @details    dash::mpd::ITimeline objects correspond to <b><tt>S</tt></b> elements of the <tt><b>SegmentTimeline</b></tt> \n \n
 *              The <b><tt>S</tt></b> element contains a mandatory \c \@d attribute specifying the MPD duration, 
 *              an optional \c \@r repeat count attribute specifying the number of contiguous Segments with identical MPD duration minus one 
 *              and an optional \c \@t time attribute specifying the MPD start time of the first Segment in the series.
 *  @see        dash::mpd::ISegmentTimeline dash::mpd::IMultipleSegmentBase dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ITIMELINE_H_
#define ITIMELINE_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ITimeline : public virtual IMPDElement
        {
            public:
                virtual ~ITimeline(){}

                /**
                 *  Returns an integer that specifies the MPD start time, in \c \@timescale units, the first Segment in the series starts relative to the beginning of the Period.\n
                 *  The value of this attribute must be equal to or greater than the sum of the previous <tt><b>S</b></tt> element earliest presentation time and 
                 *  the sum of the contiguous Segment durations. \n
                 *  If the value of the attribute is greater than what is expressed by the previous <tt><b>S</b></tt> element, it expresses discontinuities in the timeline.\n
                 *  If not present then the value shall be assumed to be zero for the first S element and for the subsequent <tt><b>S</b></tt> elements, 
                 *  the value shall be assumed to be the sum of the previous <tt><b>S</b></tt> element's earliest presentation time and contiguous duration 
                 *  (i.e. previous <tt><b>S</b>\@t</tt> + \c \@d * (\c \@r + 1)).\n\n
                 *  \em StartTime corresponds to the \c \@t attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t    GetStartTime    ()  const = 0;

                /**
                 *  Returns the integer that specifies the Segment duration, in units of the value of the \c \@timescale. \n\n
                 *  \em Duration corresponds to the \c \@d attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t    GetDuration     ()  const = 0;

                /**
                 *  Returns an integer that specifies the repeat count of the number of following contiguous Segments with the same duration expressed by the value of \c \@d.
                 *  This value is zero-based (e.g. a value of three means four Segments in the contiguous series). \n\n
                 *  \em RepeatCount corresponds to the \c \@r attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t    GetRepeatCount  ()  const = 0;
        };
    }
}

#endif /* ITIMELINE_H_ */