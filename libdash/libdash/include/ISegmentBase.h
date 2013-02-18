/**
 *  @class      dash::mpd::ISegmentBase
 *  @brief      This interface is needed for accessing the common elements and attributes of <tt><b>SegmentBase</b></tt>
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.2.2, table 11
 *  @details    It specifies Semgent base elements as well as the type for the Segment base information. \n
 *              The <tt><b>SegmentBase</b></tt> is sufficient if only a single Media Segment is provided per Representation and the Media Segment URL is included in the BaseURL element.\n
 *              In case multiple Media Segments are present, either a <tt><b>SegmentList</b></tt> or a <tt><b>SegmentTemplate</b></tt> is used 
 *              that share the multiple Segment base information as provided in 5.3.9.2.3, Table 12. \n
 *              If the Representation contains more than one Media Segment, then either the attribute \c \@duration or the element <tt><b>SegmentTimeline</b></tt> shall be present.
 *              The attribute \c \@duration and the element <tt><b>SegmentTimeline</b></tt> shall not be present at the same time.
 *              Segments described by the Segment base information are referenced by an HTTP-URL conforming to the type URLType as defined in Table 13.
 *  @see        dash::mpd::IURLType dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ISEGMENTBASE_H_
#define ISEGMENTBASE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IURLType.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentBase : public virtual IMPDElement
        {
            public:
                virtual ~ISegmentBase(){}

                /**
                 *  Returns a pointer to a dash::mpd::IURLType object that specifies the URL including a possible byte range for the Initialization Segment.
                 *  @return     a pointer to dash::mpd::IURLType object
                 */
                virtual const IURLType*     GetInitialization           ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::IURLType object that specifies the URL including a possible byte range for the Representation Index Segment.
                 *  @return     a pointer to dash::mpd::IURLType object
                 */
                virtual const IURLType*     GetRepresentationIndex      ()  const = 0;

                /**
                 *  Returns an integer representing a timescale that specifies the timescale in units per seconds 
                 *  to be used for the derivation of different real-time duration values in the Segment Information.\n
                 *  \b NOTE:  This may be any frequency but typically is the media clock frequency of one of the media streams (or a positive integer multiple thereof).
                 *  @return     an unsigned integer
                 */
                virtual uint32_t            GetTimescale                ()  const = 0;

                /**
                 *  Returns an integer that specifies the presentation time offset of the Representation relative to the start of the Period.\n
                 *  The value of the presentation time offset in seconds is the division of the value of this attribute and the value of the \c \@timescale attribute.\n
                 *  If not present on any level, the value of the presentation time offset is 0. 
                 *  @return     an unsigned integer
                 */
                virtual uint32_t            GetPresentationTimeOffset   ()  const = 0;

                /**
                 *  Returns a string that specifies the byte range that contains the Segment Index in all Media Segments of the Representation.\n
                 *  The byte range shall be expressed and formatted as a \c byte-range-spec as defined in RFC 2616, Clause 14.35.1. 
                 *  It is restricted to a single expression identifying a contiguous range of bytes.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetIndexRange               ()  const = 0;

                /**
                 *  When set to \c 'true' specifies that for all Segments in the Representation, the data outside the prefix defined by \c \@indexRange contains the data 
                 *  needed to access all access units of all media streams syntactically and semantically.
                 *  @return     a bool value
                 */
                virtual bool                HasIndexRangeExact          ()  const = 0;
        };
    }
}

#endif /* ISEGMENTBASE_H_ */