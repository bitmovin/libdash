/**
 *  @class      dash::mpd::ISegmentTimeline
 *  @brief      This interface is needed for accessing the subelements of the <tt><b>SegmentTimeline</b></tt> element, as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.6
 *  @details    The <tt><b>SegmentTimeline</b></tt> element expresses the earliest presentation time and presentation duration (in units based on the \c \@timescale attribute)
 *              for each Segment in the Representation. The use is an alternative to providing the \c \@duration attribute and provides three additional features:
 *              <ul>
 *                  <li> the specification of arbitrary Segment durations,
 *                  <li> the specification of accurate Segment durations for one media stream where the duration expresses presentation duration of the Segment, and
 *                  <li> the signalling of discontinuities of the Media Presentation timeline for which no Segment data are present in a specific Representation.
 *              </ul>
 *              For compactness the syntax of this element includes run-length compression to express a sequence of Segments having constant duration.\n\n
 *              The <tt><b>SegmentTimeline</b></tt> element shall contain a list of <tt><b>S</b></tt> elements each of which describes a sequence of contiguous segments of identical MPD duration.
 *  @see        dash::mpd::ITimeline dash::mpd::IMultipleSegmentBase dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ISEGMENTTIMELINE_H_
#define ISEGMENTTIMELINE_H_

#include "config.h"

#include "ITimeline.h"
#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentTimeline : public virtual IMPDElement
        {
            public:
                virtual ~ISegmentTimeline(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ITimeline objects, that correspond to the to <b><tt>S</tt></b> elements.
                 *  @return     a reference to vector of pointers to dash::mpd::ITimeline objects
                 */
                virtual std::vector<ITimeline *>&   GetTimelines ()  const = 0;
        };
    }
}

#endif /* ISEGMENTTIMELINE_H_ */