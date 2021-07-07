/**
 *  @class      dash::mpd::IModelPair
 *  @brief      This interface is needed for accessing the common attributes and elements of <tt><b>ModelPair</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, section 5.3.5.6
 *  @details    A <b>ModelPair</b> element defines an extended bandwidth model pair that applies for the Representation.
 *  @see        
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IMODELPAIR_H_
#define IMODELPAIR_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IModelPair : public virtual IMPDElement
        {
            public:
                virtual ~IModelPair(){}

                /**
                 *  Returns the reference to a string that specifies a duration used in the definition of the Representation data rate together with \c @bandwidth attribute within the same element. \n
                 *  \t NOTE: there are cases for which a real or expected long-term average bitrate may be usefully signaled. Examples include (i) the signaling of the average bitrate of a Representation in On-Demand case. In this case the \c @buffer may be set to the duration of the Period 
                 *     and the \c @bandwidth may be set to the size of the Representation.  (ii) the signaling of the maximum expected long-term bitrate in Live-Edge Periods: In this case the \c @buffer is set to a large value, for example 1 hour, or 24 hours and the bandwidth expresses the maximum amount of bytes over this period.
                 *  @return     a reference to a string
                 */
                virtual const std::string&            GetBufferTime      ()  const = 0;
                
                /**
                 *  Returns an unsigned integer: \n
                 *  Consider a hypothetical constant bitrate channel of bandwidth with the value of this attribute in bits per second (bps). 
                 *  Then, if the Representation is continuously delivered at this bitrate, starting at any signalled SAP of type 1 or 2 included in this Representation element, a client can be assured of having enough data for continuous playout providing playout begins after \c @bufferTime * \c @bandwidth bits have been received (i.e. at time \c @bufferTime after the first bit is received). \n
                 *  For dependent Representations, this value specifies the bandwidth according to the above definition for the aggregation of this Representation and all complementary Representations. \n
                 *  For details, see subclause 5.3.5.4.
                 *  @return     an unsigned integer
                 */
                virtual uint64_t                      GetBandwidth       ()  const = 0;
        };
    }
}

#endif /* IMODELPAIR_H_ */