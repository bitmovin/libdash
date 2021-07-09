/**
 *  @class      dash::mpd::IEvent
 *  @brief      This interface is needed for accessing the attributes of <tt><b>Event</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause 5.10.2.2, Table 35.
 *  @details    The Event element specifies an Event and contains the message of the event. The content of this element depends on the event scheme. The contents shall be either: \n
 *              <ul>
 *                  <li>A string, optionally encoded as specified by \c @contentEncoding
 *                  <li>XML content using elements external to the MPD namespace
 *              </ul>
 *              For new event schemes, string content should be used, making use of Base 64 encoding if needed. \n
 *              \b NOTE The schema allows “mixed” content within this element however only string data or XML elements are permitted by the above options, not a combination. \n
 *              The XML syntax of the Event is provided in subclause 5.10.2.3.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IEVENT_H_
#define IEVENT_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IEvent : public virtual IMPDElement
        {
            public:
                virtual ~IEvent(){}

                /**
                 *  Returns an integer that specifies the presentation time of the event relative to the start of the Period taking into account the \c @presentationTimeOffset of the Event Stream, if present. \n
                 *  The value of the presentation time in seconds is the division of the value of this attribute and the value of the \c @timescale attribute. \n
                 *  If not present, the value of the presentation time is 0.
                 *
                 *  @return     an unsigned integer
                 */
                virtual uint64_t             GetPresentationTime    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the presentation duration of the Event. \n
                 *  The value of the duration in seconds is the division of the value of this attribute and the value of the \c @timescale attribute. \n
                 *  The interpretation of the value of this attribute is defined by the scheme owner. \n
                 *  If not present, the value of the duration is unknown.    
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetDuration           ()  const = 0;
                
                /**
                 *  Returns an integer that specifies an identifier for this instance of the event. \n
                 *  Events with equivalent content and attribute values in the \b Event element shall have the same value for this attribute. \n
                 *  The scope of the \c @id for each Event is with the same \c @schemeIdURI and \c @value pair.        
                 *
                 *  @return     an unsigned integer
                 */
                virtual uint32_t             GetId                 ()  const = 0;
                
                /**
                 *  Returns the reference to a string that specifies whether the information in the body and the information in the \c @messageData is encoded. \n
                 *  If present, the following value is possible:
                 *  <ul>
                 *      <li> \c base64 the content is encoded as described in IETF RFC 4648 prior to adding it to the field.
                 *  </ul>
                 *  If this attribute is present, the DASH Client is expected to decode the message data and only provide the decoded message to the application.
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetContentEncoding    ()  const = 0;
                
                /**
                 *  Returns the reference to a string that specifies the value for the event stream element. The value space and semantics must be defined by the owners of the scheme identified in the \c @schemeIdUri attribute. \n
                 *  The use of the message data is discouraged by content authors; it is only maintained for the purpose of backward-compatibility. 
                 *  Including the message in the Event element is recommended in preference to using this attribute.    
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetMessageData        ()  const = 0;
        };
    }
}

#endif /* IEVENT_H_ */