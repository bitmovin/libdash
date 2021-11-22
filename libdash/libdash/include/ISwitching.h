/**
 *  @class      dash::mpd::ISwitching
 *  @brief      This interface is needed for accessing the common attributes of <tt><b>Switching</b></tt>
 *  @details    Switching refers to the presentation of decoded data from one Representation up to a certain time t, and presentation of decoded data of another Representation from time t onwards;
 *              for details, refer to subclause 4.3.\n
 *              The \b Switching element as defined in Table 6 provides instructions of switch points within an Adaptation Set and the permitted switching options as defined in Table 7.
 *              When this element is present, it signals opportunities for simple switching across Representations in one Adaptation Set. This element may be used instead of the attributes \c @segmentAlignment or \c @bitstreamSwitching.\n
 *              Table 7 defines different switching strategies that provide instructions to the client on the procedures to switch appropriately within an Adaptation Set.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ISWITCHING_H_
#define ISWITCHING_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ISwitching : public virtual IMPDElement
        {
            public:
                virtual ~ISwitching(){}
                
                /**
                 *  Returns an unsigned integer that specifies the interval between two switching points in the scale of the \c @timescale on Representation level.\n
                 *  Any Segment for which the earliest presentation time minus the \c @t value of the \b S element describing the segment is an integer multiple of the product of \c @timescale and \c @interval is a switch-to opportunity,
                 *  i.e. it enables to switch to this Representation with the switching strategy as defined by the \c @type value.\n
                 *  The value should be chosen such that the resulting time matches MPD start time of segments, otherwise no switching will be described.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                     GetInterval          ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the switching strategy for the switch points identified in by the \c @interval attribute.\n
                 *  Switching strategies are defined in Table 7 of <em>ISO/IEC 23009-1</em>.    
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&           GetType              ()  const = 0;
                
        };
    }
}

#endif /* ISWITCHING_H_ */