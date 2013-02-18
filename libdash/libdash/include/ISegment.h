/**
 *  @class      dash::mpd::ISegment
 *  @brief      This interface is needed for setting values of a Segment
 *  @details    Several methods for setting the values of member variables are provided. \n\n
 *              These are only needed in case you do not want to use the values provided by the MPD.
 *  @see        dash::network::IDownloadableChunk dash::network::IChunk
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ISEGMENT_H_
#define ISEGMENT_H_

#include "config.h"

#include "IDownloadableChunk.h"

namespace dash
{
    namespace mpd
    {
        class ISegment : public virtual network::IDownloadableChunk
        {
            public:
                virtual ~ISegment(){}

                /**
                 *  This method allows you to specify an absolute URI for this Segment
                 *  @param      uri     a string representing an URI 
                 */
                virtual void    AbsoluteURI  (std::string uri)   = 0;

                /**
                 *  This method allows you to specify a host for this Segment
                 *  @param      host    a string representing an host
                 */
                virtual void    Host         (std::string host)  = 0;

                /**
                 *  This method allows you to specify a port for this Segment
                 *  @param      port    an integer representing a portnumber
                 */
                virtual void    Port         (size_t port)       = 0;

                /**
                 *  This method allows you to specify a path for this Segment
                 *  @param      path    a string representing a path
                 */
                virtual void    Path         (std::string path)  = 0;

                /**
                 *  This method allows you to specify a byte range for this Segment
                 *  @param      range   a string representing a byte range as definend in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.2.2, table 13:\n
                                        <em>The byte range shall be expressed and formatted as a \c byte-range-spec as defined in RFC 2616, Clause 14.35.1.
                                        It is restricted to a single expression identifying a contiguous range of bytes.</em>
                 */
                virtual void    Range        (std::string range) = 0;

                /**
                 *  This method allows you to specify the start byte for this Segment
                 *  @param      startByte   an integer representing the start byte
                 */
                virtual void    StartByte    (size_t startByte)  = 0;

                /**
                 *  This method allows you to specify the end byte for this Segment
                 *  @param      endByte     an integer representing the end byte
                 */
                virtual void    EndByte      (size_t endByte)    = 0;

                /**
                 *  This method allows you to specify whether this Segment has a byte range or not
                 *  @param      hasByteRange    a bool value, \c true to specify that this Segment has a byte range, \c false otherwise
                 */
                virtual void    HasByteRange (bool hasByteRange) = 0;
        };
    }
}

#endif /* ISEGMENT_H_ */