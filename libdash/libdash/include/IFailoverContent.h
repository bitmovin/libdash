/**
 *  @class      dash::mpd::IFailoverContent
 *  @brief      This interface is needed for accessing the common elements and attributes of <tt><b>FailoverContent</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, section 5.3.9.7.2, table 22
 *  @details    The FailoverContent element enables identification of such sections of Representations that include alternative “failover content” and should be avoided by the DASH Client, 
 *              for example by switching to a Representation that does not include such failover content. \n
 *              The FailoverContent element contains a list of failover content sections, each expressed by one <b>FCS</b> element. 
 *              The FCS element contains an optional \c @d attribute specifying the MPD duration of the alternative content section and a mandatory \c @t time attribute 
 *              whereby the value of the \c @t attribute minus the value of the \c @presentationTimeOffset specifies the MPD start time of the alternative content section. \n
 *              The semantics of the attributes and elements for failover content are provided in 5.3.9.7.2, Table 22. The XML syntax of the Failover Content signalling is provided in 5.3.9.7.3.
 *  @see        dash::mpd::IFCS dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IFAILOVERCONTENT_H_
#define IFAILOVERCONTENT_H_

#include "config.h"

#include "IMPDElement.h"
#include "IFCS.h"

namespace dash
{
    namespace mpd
    {
        class IFailoverContent : public virtual IMPDElement
        {
            public:
                virtual ~IFailoverContent(){}

                /**
                 *  Returns a pointer to a vector of dash::mpd::FCS objects, each of which specifies the property of the Failover Content signalling itself.
                 *  @return     a pointer to a vector of dash::mpd::FCS objects
                 */
                virtual std::vector<IFCS *>&          GetFCS           ()  const = 0;
                
                /**
                 *  Returns a boolean that specifies whether the corresponding data results in a valid HTTP request 
                 *  or if the request is invalid and it is expected that a 404 is received when requesting the associated Media Segment.    
                 *  @return     a bool value
                 */
                virtual bool                          IsValid          ()  const = 0;
        };
    }
}

#endif /* IFAILOVERCONTENT_H_ */