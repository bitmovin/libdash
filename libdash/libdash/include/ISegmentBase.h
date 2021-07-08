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
 *  @see        dash::mpd::IURLType dash::mpd::FailoverContent dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 */

#ifndef ISEGMENTBASE_H_
#define ISEGMENTBASE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IURLType.h"
#include "IFailoverContent.h"

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
                virtual const IURLType*             GetInitialization           ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::IURLType object that specifies the URL including a possible byte range for the Representation Index Segment.
                 *  @return     a pointer to dash::mpd::IURLType object
                 */
                virtual const IURLType*             GetRepresentationIndex      ()  const = 0;
                
                /**
                 *  Returns a pointer to a dash::mpd::IFailoverContent object that specifies the sections that contain failover content.
                 *  @return     a pointer to dash::mpd::IFailoverContent object
                 */
                virtual const IFailoverContent*     GetFailoverContent          ()  const = 0;

                /**
                 *  Returns an integer representing a timescale that specifies the timescale in units per seconds 
                 *  to be used for the derivation of different real-time duration values in the Segment Information.\n
                 *  \b NOTE: This may be any frequency but typically is the media clock frequency of one of the media streams (or a positive integer multiple thereof).
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                    GetTimescale                ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the difference between the earliest presentation time in the Representation and the value of the @presentationTimeOffset. \n
                 *  The value of the earliest presentation time of the first Media Segment in this Representation in seconds is computed as the sum of the value of this attribute and 
                 *  the value of the @presentationTimeOffset in units of the @timescale attribute. \n
                 *  If not present on any level, but the \c SegmentTimeline element is present, then the value is the value of the @t attribute of the first \c S element in the Segment minus the value of the @presentationTimeOffset. \n
                 *  Otherwise, it assumed to be 0.    
                 *  @return     an integer
                 */
                virtual int                          GetEptDelta                ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the difference between the presentation duration of this Representation in units of \c @timescale and the Period duration. \n
                 *  If the media is contained in a Self-Initializing Media Segment, the sum of the value of \c @presentationTimeOffset and the Period duration is used to identify the Subsegment, that is the last one of the Representation. In this case, \c @pdDelta shall be set according to the presentation duration of this last Subsegment. \n
                 *  If not present, the value is unknown. \n
                 *  \t Note: if the value if \c @pdDelta is smaller than zero then this results in a gap at the end of the Period. If the value is positive, it results in an overlap.
                 *  @return     an integer
                 */
                virtual int                          GetPdDelta                 ()  const = 0;

                /**
                 *  Returns an integer that specifies the presentation time offset of the Representation relative to the start of the Period.\n
                 *  The value of the presentation time offset in seconds is the division of the value of this attribute and the value of the \c \@timescale attribute.\n
                 *  If not present on any level, the value of the presentation time offset is 0. 
                 *  @return     an unsigned integer
                 */
                virtual uint64_t                    GetPresentationTimeOffset   ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the presentation duration of the Representation in the Period. \n
                 *  The value of the presentation duration in seconds is the division of the value of this attribute and the value of the \c @timescale attribute.
                 *  Specifically, the sum of the value of the \c @presentationTimeOffset, if present, or 0 otherwise and the value of this attribute is the last presentation time to be presented for this Representation. \n
                 *  If not present on any level, the value of this attribute is unknown and the Representation should be presented until the end of the Period, i.e. until the presentation is terminated or until the next Period starts.
                 *  @return     an unsigned integer
                 */
                virtual uint64_t                    GetPresentationDuration     ()  const = 0;
                
                /**
                 *  Returns a string that specifies the duration of the time shifting buffer for this Representation that is guaranteed to be available for a Media Presentation with type 'dynamic'. When not present, the value is of the \c @timeShiftBufferDepth
                 *  on MPD level applies. If present, this value shall be not smaller than the value on MPD level. This value of the attribute is undefined if the \c @type attribute is equal to 'static'.    \n
                 *  \n NOTE When operating in a time-shift buffer on a Representation with value larger than the time-shift buffer signalled on MPD level, not all Representations are necessarily available for switching.
                 *  @return     a reference to a string
                 */
                virtual const std::string&          GetTimeShiftBufferDepth     ()  const = 0;

                /**
                 *  Returns a string that specifies the byte range that contains the Segment Index in all Media Segments of the Representation.\n
                 *  The byte range shall be expressed and formatted as a \c byte-range-spec as defined in RFC 2616, Clause 14.35.1. 
                 *  It is restricted to a single expression identifying a contiguous range of bytes.
                 *  @return     a reference to a string
                 */
                virtual const std::string&          GetIndexRange               ()  const = 0;

                /**
                 *  When set to \c 'true' specifies that for all Segments in the Representation, the data outside the prefix defined by \c \@indexRange contains the data 
                 *  needed to access all access units of all media streams syntactically and semantically.
                 *  @return     a bool value
                 */
                virtual bool                        HasIndexRangeExact          ()  const = 0;
                
                /**
                 *  Returns a double that specifies an offset to define the adjusted segment availability time. The value is specified in seconds, possibly with arbitrary precision. \n
                 *  The offset provides the time how much earlier these segments are available compared to their computed availability start time for all Segments of all associated Representation. \n
                 *  The segment availability start time defined by this value is referred to as adjusted segment availability start time. For details on computing the adjusted segment availability start time, refer to subclause 5.3.9.5. of <em>ISO/IEC 23009-1</em>. \n
                 *  If not present, no adjusted segment availability start time is defined. \n
                 *  \b NOTE The value of \c "INF" implies availability of all segments starts at \c MPD@availabilityStartTime.
                 *  @return     a double
                 */
                virtual double                      GetAvailabilityTimeOffset   ()  const = 0;
                
                /**
                 *  Returns a boolean that specifies if all Segments of all associated Representation are complete at the adjusted availability start time. The attribute shall be ignored if \c @availabilityTimeOffset is not present on any level. \n
                 *  If not present on any level, the value is inferred to true. \n
                 *  \b NOTE If the value is set to false, then it can be inferred by the client that the segment is available at its announced location prior being complete.
                 *  @return     a bool value
                 */
                virtual bool                        IsAvailabilityTimeComplete  ()  const = 0;
        };
    }
}

#endif /* ISEGMENTBASE_H_ */