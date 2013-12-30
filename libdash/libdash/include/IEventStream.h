/**
 *  @class      dash::mpd::IEventStream
 *  @brief      This interface is needed for accessing the attributes of the <tt><b>Event Stream</b></tt> type
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2013</em>, section 5.10.2
 *  @details    The EventStream element is structured in a similar way as the descriptor
 *              defined in 5.8, namely it contains a @schemeIdUri attribute that provides
 *              a URI to identify the scheme and an optional attribute @value. The semantics
 *              of the element are specific to the scheme employed. The URI identifying the
 *              scheme may be a URN or a URL.
 *  @see        dash::mpd::IEvent
 *
 *  @author     bitmovin Softwareentwicklung GmbH \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung GmbH, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IEVENTSTREAM_H_
#define IEVENTSTREAM_H_

#include "config.h"

#include "IMPDElement.h"
#include "IEvent.h"

namespace dash
{
    namespace mpd
    {
        class IEventStream : public virtual IMPDElement
        {
            public:
                virtual ~IEventStream(){}

                /**
                 *  Returns a reference to a string that specifies a URI to identify the message scheme. \n
                 *  The semantics of this element are specific to the scheme specified by this attribute.
                 *  The \c \@schemeIdUri may be a URN or URL. When a URL is used, it should also contain a month-date in the form 
                 *  mmyyyy; the assignment of the URL must have been authorized by the owner of the domain name in that URL on 
                 *  or very close to that date, to avoid problems when domain names change ownership.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetSchemeIdUri  () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the value for the event stream element. \n
                 *  The value space and semantics must be defined by the owners of the scheme identified in the \c \@schemeIdUri attribute.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetValue        () const = 0;

                /**
                 *  Returns a reference to an int that specifies the timescale in units per seconds to be used for the derivation of different\n
                 *  real-time duration values in the Event elements.
                 *  @return     a reference to an int
                 */
                virtual uint32_t                                GetTimescale    () const = 0;


                /**
                 *  Returns a reference to a string that specifies a reference to an external <tt><b>EventStream</b></tt> element.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkHref    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the processing instructions, which can be either \c \"onLoad\" or \c \"onRequest\".\n
                 *  This attribute shall not be present if the \c \@xlink:href attribute is not present.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkActuate ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IEvent objects that specify Events.\n
                 *  For more details see section 5.10. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IEvent objects
                 */
                virtual const std::vector<IEvent *>&            GetEvents       ()  const = 0;
        };
    }
}

#endif /* IEVENTSTREAM_H_ */