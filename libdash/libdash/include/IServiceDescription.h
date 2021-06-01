/**
 *  @class      dash::mpd::IServiceDescription
 *  @brief      This interface is needed for accessing the attributes and elements of <tt><b>ServiceDescription</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause K.4.2.1, Table K.5.
 *  @details    The service description may be scoped to a specific client or to an operational mode of the client. This can be expressed by using a Scope descriptor that is defined by the application. \n
 *              It is the service provider's responsibility to ensure that the service description is not contradicting in itself and can be used by clients, for example minimum, target and maximum latency should be in non decreasing order.
 *              Service descriptions with inconsistent or unachievable settings are expected to be ignored by the client. \n
 *              The semantics of the attributes and elements within a \b ServiceDescription element are provided in subclause K.4.2.1, Table K.5. The XML syntax of the \b ServiceDescription element is provided in subclause K.4.3.
 *  @see        dash::mpd::IMPDElement dash::mpd::IDescriptor dash::mpd::ILatency dash::mpd::IPlaybackRate dash::mpd::IOperatingQuality dash::mpd::IOperatingBandwidth
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ISERVICEDESCRIPTION_H_
#define ISERVICEDESCRIPTION_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"
#include "ILatency.h"
#include "IPlaybackRate.h"
#include "IOperatingQuality.h"
#include "IOperatingBandwidth.h"

namespace dash
{
    namespace mpd
    {
        class IServiceDescription : public virtual IMPDElement
        {
            public:
                virtual ~IServiceDescription(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify the scopes of the Service Description.
                 *  If present, this Service Description only targets DASH Clients identified by this Scope descriptor. 
                 *  DASH Clients not in scope, i.e. not recognizing any of the scope descriptor elements, are expected to ignore this service description.
                 *  If no Scope element is present, the Service Description applies to all clients.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&          GetScope                  ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ILatency objects that specify the latency targets for the service. 
                 *  The details are provided in subclause K.4.2.2, Table K.6.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::ILatency objects
                 */
                virtual const std::vector<ILatency *>&             GetLatency                ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IPlaybackRate objects that specify the playback rate targets for the service. 
                 *  The details are provided in subclause K.4.2.3, Table K.7.    
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IPlaybackRate objects
                 */
                virtual const std::vector<IPlaybackRate *>&        GetPlaybackRate           ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IOperatingQuality objects that specify the operating quality targets for the service.
                 *  The details are provided in subclause K.4.2.4, Table K.8.    
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IOperatingQuality objects
                 */
                virtual const std::vector<IOperatingQuality *>&    GetOperatingQuality       ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IOperatingBandwidth objects that specify the operating bandwidth targets for the service.
                 *  The details are provided in subclause K.4.2.5, Table K.9.    
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IOperatingBandwidth objects
                 */
                virtual const std::vector<IOperatingBandwidth *>&  GetOperatingBandwidth     ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies a unique identifier for this Service Description.
                 *  The attribute shall be a unique unsigned integer value amongst \b ServiceDescription elements in the scope of the MPD.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                             GetId                     ()  const = 0;
        };
    }
}

#endif /* ISERVICEDESCRIPTION_H_ */