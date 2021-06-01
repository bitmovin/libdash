/**
 *  @class      dash::mpd::IPatchLocation
 *  @brief      This interface is needed for accessing the attributes of <tt><b>PatchLocation</b></tt>.
 *  @details    An MPD may contain one or several <b>PatchLocation</b> elements to provide a location for an MPD patch document that may apply to the MPD including this element in order to generate an updated MPD.\n 
 *              The semantics of the MPD patch location element are provided in Table 48 and the XML syntax is provided in Table 49 of <em>ISO/IEC 23009-1</em>.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IPATCHLOCATION_H_
#define IPATCHLOCATION_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IPatchLocation : public virtual IMPDElement
        {
            public:
                virtual ~IPatchLocation(){}
                
                /**
                 *  Returns a reference to a string that specifies a location at which the MPD patch is available. The referenced document shall conform to an MPD patch document as defined in subclause 5.15.3. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetUrl            ()  const = 0;

                /**
                 *  Returns an double that specifies the time period duration (in seconds) starting from <b>MPD</b><em>@publishTime</em> until the MPD patch document is at least available at the indicated location above. For details refer to the processing model in subclause 5.14.4. of <em>ISO/IEC 23009-1</em>. \n
                 *  If not present, the value is unknown.

                 *
                 *  @return     a double
                 */
                virtual double               GetTtl            ()  const = 0;                
        };
    }
}

#endif /* IPATCHLOCATION_H_ */