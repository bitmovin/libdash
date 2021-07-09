/**
 *  @class      dash::mpd::IUIntVWithID
 *  @brief      This interface is needed for accessing the attributes of <tt><b>InitializationGroup</b></tt> and <tt><b>InitializationPresentation</b></tt>.
 *  @details    Initialization Group and Initialization Presentation signal the capabilities required for playback of the content as intended by the service provider.\n
 *              The \b InitializationGroup element lists the minimum requirements for playback of a media content type in all Periods of the Media Presentation.
 *              Any Period contained in the Media Presentation shall have at least one Adaptation Set that conforms to one of the Initialization Sets included in this Initialization Group.
 *              Therefore, a client supporting all listed Initialization Sets in one \c InitializationGroup element is expected to be able to play that media type during the entire Media Presentation.\n
 *              The \b InitializationPresentation element lists the minimum requirements for playback of a Media Presentation in all Periods. A client supporting all listed Initialization Sets and Groups of one Initialization Presentation is expected to be able to play the entire Media Presentation as intended by the service provider.\n
 *              An Initialization Group or Presentation may get assigned a specific profile using the \b @profiles parameter in order to express conformance to DASH Profiles or Interoperability Points.  
 *  @see        dash::mpd::IDescriptor
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IUINTVWITHID_H_
#define IUINTVWITHID_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IUIntVWithID : public virtual IMPDElement
        {
            public:
                virtual ~IUIntVWithID(){}
                
                
                /**
                 *  Returns a reference to a vector of unsigned integers that specifies the list of ids relative to the Initialization Set, Group or Presentation as specified in 5.3.12.4. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a vector of unsigned integers
                 */
                virtual const std::vector<uint32_t>&        GetList               ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies a unique identifier for this \b InitializationGroup or \b InitializationPresentation element. 
                 *  The attribute shall be a unique unsigned integer value amongst all InitializationSet, InitializationGroup and InitializationPresentation ids in the scope of the MPD.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                            GetId                 ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of strings that specifies the profiles which the associated InitializationGroup(s) or InitializationPresentation(s) 
                 *  conform to of the list of Media Presentation profiles as described in section 8 of <em>ISO/IEC 23009-1</em>. 
                 *  The value shall be a subset of the respective value in any higher level of the document hierarchy and express conformance to DASH Profiles or Interoperability Points.\n
                 *  The same syntax as defined in 5.3.1.2 shall be used.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&     GetProfiles           ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the media content component type for this Initialization Set. 
                 *  A value of the top-level Content-type 'type' value as defined in IETF RFC 6838:2013, Clause 4 shall be taken. \n
                 *  If not present, the media content component type may be defined for each media component or it may be unknown.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                  GetContentType        ()  const = 0;
                            
        };
    }
}

#endif /* IUINTVWITHID_H_ */