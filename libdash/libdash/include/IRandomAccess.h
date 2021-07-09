/**
 *  @class      dash::mpd::IRandomAccess
 *  @brief      This interface is needed for accessing the common attributes of <tt><b>RandomAccess</b></tt>
 *  @details    Random Access refers to start processing, decoding and presenting the Representation from the random access point at time t onwards by initializing the Representation with the Initialization Segment, if present and decoding and presenting the Representation from the signalled Segment onwards.
 *              Random Access point may be signalled with the \b RandomAccess element as defined in Table 10 of <em>ISO/IEC 23009-1</em>. Table 11 of <em>ISO/IEC 23009-1</em> provides different random access point types.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IRANDOMACCESS_H_
#define IRANDOMACCESS_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IRandomAccess : public virtual IMPDElement
        {
            public:
                virtual ~IRandomAccess(){}
                
                /**
                 *  Returns an unsigned integer that specifies the position of the random access points in the Representations. The information is specified in the scale of the \c @timescale on Representation level.    
                 *  Any Segment for which the MPD start time minus the \c @t value of the \b S element describing the segment is an integer multiple of the product of \c @timescale and \c @interval is a random access opportunity, i.e. it enables randomly access to this Representation with the random access strategy as defined by the \c @type value.\n
                 *  The value should be chosen such that the resulting time matches MPD start time of segments, otherwise no random access will be described.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                GetInterval                   () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the random access strategy for the random access points in by the \c @interval attribute.\n
                 *  The value shall use a type present in Table 11 of <em>ISO/IEC 23009-1</em>.\n
                 *  If the value of the type is unknown, the DASH Client is expected to ignore the containing Random Access element.    
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetType                       () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies a common duration used in the definition of the Representation data rate (see \c @bandwidth attribute in subclauses 5.3.5.2 and 5.3.5.4 of <em>ISO/IEC 23009-1</em>).\n
                 *  If not present, then the value of the MPD level is inherited.        
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetMinBufferTime              () const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies a hypothetical constant bitrate channel of bandwidth with the value of this attribute in bits per second (bps).
                 *  If the Representation is continuously delivered at this bitrate, starting at any RAP indicated in this element a client can be assured of having enough data for continuous playout providing playout begins after \c @minBufferTime * \c @bandwidth bits have been received 
                 *  (i.e. at time \c @minBufferTime after the first bit is received). \n
                 *  For dependent Representations, this value specifies the bandwidth according to the above definition for the aggregation of this Representation and all complementary Representations.\n
                 *  For details, see subclause 5.3.5.4. of <em>ISO/IEC 23009-1</em>.\n
                 *  If not present, the value of the Representation is inherited.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                GetBandwidth                  () const = 0;
                
        };
    }
}

#endif /* IRANDOMACCESS_H_ */