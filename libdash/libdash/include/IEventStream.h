/**
 *  @class      dash::mpd::IEventStream
 *  @brief      This interface is needed for accessing the common elements and attributes of <tt><b>EventStream</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause 5.10.2.2, Table 34
 *  @details    The EventStream element is structured in a similar way as the descriptor defined in subclause 5.8, namely it contains a \c @schemeIdUri attribute 
 *              that provides a URI to identify the scheme and an optional attribute \c @value. The semantics of the element are specific to the scheme employed. The URI identifying the scheme may be a URN or a URL. \n
 *              A Period shall contain at most one \b EventStream element with the same value of the \c @schemeIdUri attribute and the value of the \c @value attribute, i.e. all Events of one type shall be clustered in one Event Stream. \n
 *              As Event Streams contain timed events, also a time scale attribute \c @timescale is provided to assign events to a specific media presentation time within the Period. The timed events themselves are described by the \b Event element.
 *              ìThe XML syntax of the Event Stream is provided in subclause 5.10.2.3.
 *  @see        dash::mpd::IEvent dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
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
                 *  Returns a pointer to a vector of dash::mpd::Event objects, each of which specifies the property of the Event itself. \n
                 *  Events in Event Streams shall be ordered such that their presentation time is non-decreasing.
                 *
                 *  @return     a pointer to a vector of dash::mpd::Event objects
                 */
                virtual const std::vector<IEvent *>&       GetEvents                 ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies a reference to an external <tt><b>EventStream</b></tt> element.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&           GetXlinkHref              ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the processing instructions, which can be either \c "onLoad" or \c "onRequest". \n
                 *  This attribute shall not be present if the \c @xlink:href attribute is not present.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&           GetXlinkActuate           ()  const = 0;
                
                /**
                 *  Returns a reference to a string that identifies the message scheme. The string may use URN or URL syntax. 
                 *  When a URL is used, it is recommended to also contain a month-date in the form mmyyyy;
                 *  the assignment of the URL must have been authorized by the owner of the domain name in that URL on or very close to that date. 
                 *  A URL may resolve to an Internet location, and a location that does resolve may store a specification of the message scheme.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&           GetSchemeIdUri            ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the value for the event stream element. The value space and semantics must be defined 
                 *  by the owners of the scheme identified in the \c @schemeIdUriattribute.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&           GetValue                  ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the timescale in units per seconds to be used for the derivation of different real-time duration values in the \b Event elements. \n
                 *  If not present on any level, it shall be set to 1.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                     GetTimescale              ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the presentation time offset of this Event Stream that aligns with the start of the Period.
                 *  Any Event contained in this Event Stream is mapped to the Period timeline by using the Event presentation time adjusted by the value of the presentation time offset. \n
                 *  The value of the presentation time offset in seconds is the division of the value of this attribute and the value of the \c @timescale attribute.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint64_t                     GetPresentationTimeOffset ()  const = 0;
        };
    }
}

#endif /* IEVENTSTREAM */