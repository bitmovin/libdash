/**
 *  @class      dash::mpd::IUIntPairs
 *  @brief      This interface is needed for accessing the attributes of the utility class <tt><b>UIntPairs</b></tt>
 *  @details    Utility class to define the quality of the latency service, as specified in <em>ISO/IEC 23009-1</em>, subclause K.3.2.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IUINTPAIRS_H_
#define IUINTPAIRS_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IUIntPairs : public virtual IMPDElement
        {
            public:
                virtual ~IUIntPairs(){}
                
                /**
                 *  Returns an unsigned integer that specifies a latency value for the service in milliseconds.     
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                       GetLatency                ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the quality of the service at the above latency with 0 being the lowest and 100 being the highest.     
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                       GetQuality                ()  const = 0;
                
        };
    }
}

#endif /* IUINTPAIRS_H_ */