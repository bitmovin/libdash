/**
 *  @class      dash::mpd::IOperatingBandwidth
 *  @brief      This interface is needed for accessing the attributes of <tt><b>OperatingBandwidth</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause K.3.5.
 *  @details    Table K.4 defines the service description parameters for operating bandwidth. 
 *              The keys in Table K.4 shall be used to refer to the operating bandwidth as defined in Table K.3.    
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IOPERATINGBANDWIDTH_H_
#define IOPERATINGBANDWIDTH_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IOperatingBandwidth : public virtual IMPDElement
        {
            public:
                virtual ~IOperatingBandwidth(){}

                /**
                 *  Returns a reference to a string that defines the media type for which the bandwidth parameters apply. They type can be:
                 *  <ul>
                 *      <li> \c video: applies to video
                 *      <li> \c audio: applies to audio
                 *      <li> \c any: applies to any media type individually
                 *      <li> \c all: applies to aggregation of all media types
                 *  </ul>                 
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&     GetMediaType           ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the minimum bandwidth value desired through this presentation for the above MediaType.
                 *  This is the smallest desired aggregated value for the \c @bandwidth attribute for all Representations of this media type to be played concurrently by the DASH Client during regular playback.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t         GetMin                 ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the maximum bandwidth value desired through this presentation for the above MediaType.
                 *  This is the largest desired aggregated value for the \c @bandwidth attribute for all Representations of this media type to be played concurrently by the DASH Client during regular playback.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t         GetMax                 ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the target bandwidth value desired through this presentation for the above MediaType.
                 *  This is the largest desired aggregated value for the \c @bandwidth attribute for all Representations of this media type to be played concurrently by the DASH Client during regular playback.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t         GetTarget              ()  const = 0;
        };
    }
}

#endif /* IOPERATINGBANDWIDTH_H_ */