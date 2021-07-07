/**
 *  @class      dash::mpd::IBaseUrl
 *  @brief      This interface is needed for accessing the attributes and the content of <tt><b>BaseURL</b></tt> elements
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.6
 *  @details    The BaseURL element may be used to specify one or more common locations for Segments and other resources.\n
 *              A URL that can be used as Base URL. The content of this element is a URI string as described in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.6.4
 *  @see        dash::mpd::IMPDElement
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

#ifndef IBASEURL_H_
#define IBASEURL_H_

#include "config.h"

#include "IMPDElement.h"
#include "ISegment.h"

namespace dash
{
    namespace mpd
    {
        class IBaseUrl : public virtual IMPDElement
        {
            public:
                virtual ~IBaseUrl(){}

                /**
                 *  Returns the reference to a string representing a BaseURL
                 *  @return     a reference to a string
                 */
                virtual const std::string& GetUrl                      ()  const = 0;

                /**
                 *  Returns the reference to a string that specifies a relationship between Base URLs such that \c <b>BaseURL</b> elements with the same 
                 *  \c \@serviceLocation value are likely to have their URLs resolve to services at a common network location, for example a common Content Delivery Network
                 *  @return     a reference to a string
                 */
                virtual const std::string& GetServiceLocation          ()  const = 0;

                /**
                 *  Returns the reference to a string that represents a byte range. \n
                 *  If present specifies HTTP partial GET requests may alternatively be issued by adding the byte range into a 
                 *  regular HTTP-URL based on the value of this attribute and the construction rules in Annex E.2. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.\n
                 *  If not present, HTTP partial GET requests may not be converted into regular GET requests. \n
                 *  \b NOTE:    Such alternative requests are expected to not be used unless the DASH application requires this. For more details refer to Annex E.
                 *  @return     a reference to a string
                 */
                virtual const std::string& GetByteRange                ()  const = 0;
                
                /**
                 *  Returns a number that specifies an offset to define the adjusted segment availability time.
                 *  If the value is present in \c SegmentBase then this attribute is additive to the one in \c SegmentBase.
                 *  @return     a double
                 */
                virtual double             GetAvailabilityTimeOffset   ()  const = 0;
                
                /**
                 *  Returns a boolean that specifies if all Segments of all associated Representation are complete at the adjusted availability start time.
                 *  If the value is present in \c SegmentBase then this attribute should not be present. If present in \c SegmentBase and \c BaseURL, the value in \c BaseURL shall be ignored.
                 *  @return     a boolean
                 */
                virtual bool                IsAvailabilityTimeComplete  ()  const = 0;
                
                /**
                 *  Returns the reference to a string that specifies the duration of the smallest time shifting buffer for any Representation in the MPD that is guaranteed to be available for a Media Presentation with type 'dynamic'.
                 *  This value overrides \c MPD@timeShiftBufferDepth for the resources that use this \c BaseURL. This value of the attribute is undefined if the \c MPD@type attribute is equal to \c 'static'.
                 *  @return     a reference to a string
                 */
                virtual const std::string& GetTimeShiftBufferDepth     ()  const = 0;
                
                /**
                 *  Returns a boolean that specifies: if set to true, partially available may be accessed with byte range request. If a client is making a byte-range request against a partially available Segment and the first-byte position of that range request is non-zero and the client is expecting an aggregating response, then the client should signal that expectation by following the convention of IETF RFC 8673.  Specifically, it should use a last-byte value of 9007199254740991. This will signal the server to respond with a 206 aggregating response instead of waiting for the end of the segment and responding with a 200 response code and a content-length response header. \n
                 *  If set to false, the client should not expect a response corresponding to the requested byte range. 
                 *  @return     a boolean
                 */
                virtual bool                HasRangeAccess             ()  const = 0;

                 /**
                 *  Returns a pointer to a dash::mpd::ISegment object which represents a media segment that can be downloaded. Should be used for single base urls inside 
                 *  a representation.
                 *  @param      baseurls    a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the media segment
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           ToMediaSegment             (const std::vector<IBaseUrl *>& baseurls) const = 0;
        };
    }
}

#endif /* IBASEURL_H_ */