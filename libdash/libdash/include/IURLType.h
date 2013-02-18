/**
 *  @class      dash::mpd::IURLType
 *  @brief      This interface is needed for accessing the attributes of <tt><b>URLType</b></tt> elements, as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.2.2, table 13
 *  @details    This object defines an HTTP-URL\n
 *  @see        dash::mpd::IBaseUrl dash::mpd::IMPDElement dash::mpd::ISegment
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IURLTYPE_H_
#define IURLTYPE_H_

#include "config.h"

#include "IMPDElement.h"
#include "ISegment.h"
#include "IBaseUrl.h"

namespace dash
{
    namespace mpd
    {
        class IURLType : public virtual IMPDElement
        {
            public:
                virtual ~IURLType(){}

                /**
                 *  Returns a reference to a string that pecifies the source URL part and shall be formated either as an \c <absolute-URI> according to RFC 3986, Clause 4.3, 
                 *  with a fixed scheme of \"http\" or \"https\" or as a \c <relative-ref> according to RFC 3986, Clause 4.2.\n
                 * If not present, then any <tt><b>BaseURL</b></tt> element is mapped to the \c \@sourceURL attribute and the range attribute shall be present. 
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetSourceURL    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the byte range restricting the above HTTP-URL.\n
                 *  The byte range shall be expressed and formatted as a byte-range-spec as defined in RFC 2616, Clause 14.35.1. It is restricted to a single expression identifying a 
                 *  contiguous range of bytes.\n
                 *  If not present, the element refers to the entire resource referenced in the \c \@sourceURL attribute.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetRange        ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object, that can be downloaded
                 *  @param      baseurls    a reference to a vector of pointers to dash::mpd::IBaseUrl objects representing the path to \c \@sourceURL
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           ToSegment       (const std::vector<IBaseUrl *>& baseurls) const = 0;
        };
    }
}

#endif /* IURLTYPE_H_ */