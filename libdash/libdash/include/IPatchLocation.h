/**
 *  @class      dash::mpd::IPatchLocation
 *  @brief      This interface is needed for accessing the attributes of <tt><b>PatchLocation</b></tt>.
 *  @details    
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
                 *  Returns a reference to a string that specifies...	
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetUrl            ()  const = 0;

                /**
                 *  Returns an integer that specifies...
				 *
                 *  @return     an unsigned integer
                 */
                virtual uint32_t             GetTtl            ()  const = 0;				
        };
    }
}

#endif /* IPATCHLOCATION_H_ */