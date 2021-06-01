/**
 *  @class      dash::mpd::IOperatingQuality
 *  @brief      This interface is needed for accessing the attributes of <tt><b>OperatingQuality</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause K.3.4.
 *  @details    Table K.3 defines the service description parameters for operational quality. 
 *              The keys in Table K.3 shall be used to refer to the operating quality as defined in Table K.3.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IOPERATINGQUALITY_H_
#define IOPERATINGQUALITY_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IOperatingQuality : public virtual IMPDElement
        {
            public:
                virtual ~IOperatingQuality(){}

                /**
                 *  Returns a reference to a string that defines the media type for which these quality parameters apply. They type can be
                 *  <ul>
                 *      <li> \c video: applies to video
                 *      <li> \c audio: applies to audio
                 *      <li> \c any: applies to any media type
                 *  </ul>                 
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&     GetMediaType           ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the minimum quality ranking value desired through this presentation for the above MediaType. 
                 *  This is the largest desired value for the \c @qualityRanking attribute for the Representations to be played by the DASH Client during regular playback.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t               GetMin                 ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the maximum quality ranking value desired through this presentation for the above MediaType. 
                 *  This is the largest desired value for the \c @qualityRanking attribute for the Representations to be played by the DASH Client during regular playback.        
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t               GetMax                 ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the quality ranking value desired through this presentation for the above MediaType. 
                 *  This is the target value for the \c @qualityRanking attribute for the Representations to be played by the DASH Client during regular playback.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t               GetTarget              ()  const = 0;
                
                /**
                 *  Returns a reference to a string that defines the interpretation of the value of \c @qualityRanking attribute.
                 *  If not present, the quality is considered in linear scale.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&     GetType                ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the maximum quality difference value recommended by the content author for the presentation for the above MediaType.
                 *  This is the recommended maximum difference between \c @qualityRanking attributes for Representations being played concurrently.
                 *  This is typically applicable for Representations that are picked from Adaptation Sets within one Preselection.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t               GetMaxDifference       ()  const = 0;
        };
    }
}

#endif /* IOPERATINGQUALITY_H_ */