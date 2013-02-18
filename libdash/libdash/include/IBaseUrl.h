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
 */

#ifndef IBASEURL_H_
#define IBASEURL_H_

#include "config.h"

#include "IMPDElement.h"

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
                virtual const std::string& GetUrl               ()  const = 0;

                /**
                 *  Returns the reference to a string that specifies a relationship between Base URLs such that \c <b>BaseURL</b> elements with the same 
                 *  \c \@serviceLocation value are likely to have their URLs resolve to services at a common network location, for example a common Content Delivery Network
                 *  @return     a reference to a string
                 */
                virtual const std::string& GetServiceLocation   ()  const = 0;

                /**
                 *  Returns the reference to a string that represents a byte range. \n
                 *  If present specifies HTTP partial GET requests may alternatively be issued by adding the byte range into a 
                 *  regular HTTP-URL based on the value of this attribute and the construction rules in Annex E.2. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.\n
                 *  If not present, HTTP partial GET requests may not be converted into regular GET requests. \n
                 *  \b NOTE:    Such alternative requests are expected to not be used unless the DASH application requires this. For more details refer to Annex E.
                 *  @return     a reference to a string
                 */
                virtual const std::string& GetByteRange         ()  const = 0;
        };
    }
}

#endif /* IBASEURL_H_ */