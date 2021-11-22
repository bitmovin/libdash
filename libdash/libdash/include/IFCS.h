/**
 *  @class      dash::mpd::IFCS
 *  @brief      This interface is needed for accessing the attributes of <tt><b>FCS</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, section 5.3.9.7.2, table 22
 *  @details    The FCS element contains an optional \c @d attribute specifying the MPD duration of the alternative content section and a mandatory \c @t time attribute 
 *              whereby the value of the \c @t attribute minus the value of the \c @presentationTimeOffset specifies the MPD start time of the alternative content section. \n
 *              The semantics of the attributes for FCS are provided in 5.3.9.7.2, Table 22. The XML syntax of the Failover Content signalling is provided in 5.3.9.7.3.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IFCS_H_
#define IFCS_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IFCS : public virtual IMPDElement
        {
            public:
                virtual ~IFCS(){}

                /**
                 *  Returns an integer that specifies the value of the \c PresentationTime which corresponds to the \c @t attribute. 
                 *  This attribute minus the value of the \c @presentationTimeOffset specifies the MPD start time, in \c @timescale units, of the first sample in the alternative content section. \n
                 *  The value of this attribute must be equal to or greater than the sum of the previous FCS element earliest presentation time and the sum of the contiguous section duration.
                 *
                 *  @return     an unsigned integer
                 */
                virtual uint64_t    GetPresentationTime    ()  const = 0;

                /**
                 *  Returns an integer that specifies the alternative content section duration in units of the value of the \c @timescale. \n
                 *  If not present, the alternative content section lasts until the start of the next FCS element, or until the end of the Period or until the end of MPD duration, whichever occurs first in the timeline. \n\n
                 *  \em Duration corresponds to the \c \@d attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint64_t    GetDuration            ()  const = 0;
        };
    }
}

#endif /* IFCS_H_ */