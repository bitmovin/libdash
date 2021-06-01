/**
 *  @class      dash::mpd::ILatency
 *  @brief      This interface is needed for accessing the attributes and elements of <tt><b>Latency</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause K.3.2.
 *  @details    Table K.1 defines the service description parameters for the service latency
 *  @see        dash::mpd::IMPDElement dash::mpd::IUIntPairsWithID
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ILATENCY_H_
#define ILATENCY_H_

#include "config.h"

#include "IMPDElement.h"
#include "IUIntPairsWithID.h"

namespace dash
{
    namespace mpd
    {
        class ILatency : public virtual IMPDElement
        {
            public:
                virtual ~ILatency(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IUIntPairsWithID objects that define a list of latency and quality pairs together with the quality type.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IUIntPairsWithID objects
                 */
                virtual const std::vector<IUIntPairsWithID *>&     GetQualityLatencyType     ()  const = 0;

                /**
                 *  Returns an unsigned integer that defines the ID of the Producer Reference Time element in the MPD against which the latency is measured, if more than one is present.                 
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                   GetReferenceId            ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the service provider’s preferred presentation latency in milliseconds compared to the producer reference time.
                 *  Indicates a content provider’s desire for the content to be presented as close to the indicated latency as is possible given the player’s capabilities and observations. \n
                 *  This attribute may express a latency that is only achievable by low-latency players under favourable network conditions.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                   GetTarget                 ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the service provider’s indication about the maximum presentation latency in milliseconds. 
                 *  Indicates a content provider’s desire for the content not to be presented if the latency exceeds the maximum latency.        
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                   GetMax                    ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the service provider’s indication about minimum presentation latency in milliseconds for example to avoid inconsistencies with second screen applications, overlays, etc.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                   GetMin                    ()  const = 0;
        };
    }
}

#endif /* ILATENCY_H_ */