/**
 *  @class      dash::mpd::IMultipleSegmentBase
 *  @brief      This interface is needed for accessing the common elements and attributes for the <tt><b>MultipleBaseInformation</b></tt> type
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.2.2, table 12
 *  @details    It specifies multiple Segment base information
 *  @see        dash::mpd::ISegmentTimeline dash::mpd::ISegmentBase dash::mpd::IURLType
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IMULTIPLESEGMENTBASE_H_
#define IMULTIPLESEGMENTBASE_H_

#include "config.h"

#include "ISegmentTimeline.h"
#include "ISegmentBase.h"
#include "IURLType.h"

namespace dash
{
    namespace mpd
    {
        class IMultipleSegmentBase : public virtual ISegmentBase
        {
            public:
                virtual ~IMultipleSegmentBase(){}

                /**
                 *  Return a pointer to a dash::mpd::ISegmentTimeline object
                 *  @return     a pointer to a dash::mpd::ISegmentTimeline object
                 */
                virtual const ISegmentTimeline*     GetSegmentTimeline      ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::IURLType object that specifies the URL including a possible byte range for the Bitstream Switching Segment.
                 *  @return     a pointer to a dash::mpd::IURLType object
                 */
                virtual const IURLType*             GetBitstreamSwitching   ()  const = 0;

                /**
                 *  Returns a integer specifying the constant approximate Segment duration. \n
                 *  All Segments within this Representation element have the same duration unless it is the last Segment within the Period, which could be significantly shorter.\n
                 *  The value of the duration in seconds is the division of the value of this attribute and the value of the \c \@timescale attribute associated to the containing Representation.\n
                 *  For more details refer to section 5.3.9.5.3. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                    GetDuration             ()  const = 0;

                /**
                 *  Returns a integer specifying the number of the first Media Segment in this Representation in the Period.\n
                 *  For more details refer to 5.3.9.5.3. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                    GetStartNumber          ()  const = 0;
        };
    }
}

#endif /* IMULTIPLESEGMENTBASE_H_ */