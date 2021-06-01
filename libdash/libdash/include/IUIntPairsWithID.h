/**
 *  @class      dash::mpd::IUIntPairsWithID
 *  @brief      This interface is needed for accessing the attributes of the utility class <tt><b>UIntPairsWithID</b></tt>
 *  @details    Utility class to define the quality of the latency service, as specified in <em>ISO/IEC 23009-1</em>, subclause K.3.2.
 *  @see        dash::mpd::IMPDElement dash::mpd::IUIntPairs
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IUINTPAIRSWITHID_H_
#define IUINTPAIRSWITHID_H_

#include "config.h"

#include "IMPDElement.h"
#include "IUIntPairs.h"

namespace dash
{
    namespace mpd
    {
        class IUIntPairsWithID : public virtual IMPDElement
        {
            public:
                virtual ~IUIntPairsWithID(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IUIntPairs objects that define a list of latency and quality pairs.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IUIntPairs objects
                 */
                virtual const std::vector<IUIntPairs *>&     GetQualityLatency         ()  const = 0;

                /**
                 *  Returns a reference to a string that defines defines the interpretation of the value of Quality.
                 *  If not present, the quality is considered in linear scale.         
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                   GetType                   ()  const = 0;
                
        };
    }
}

#endif /* IUINTPAIRSWITHID_H_ */