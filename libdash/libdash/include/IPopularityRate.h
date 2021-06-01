/**
 *  @class      dash::mpd::IPopularityRate
 *  @brief      This interface is needed for accessing the common attributes of <tt><b>PR</b></tt> of 5.14.2., table 43 of <em>ISO/IEC 23009-1</em>
 *  @details    In the context of the \b ContentPopularityRate element, one or more PopularityRate elements are used to specify start time and number of segments for a contiguous sequence of segments assigned identical Popularity Rate value.
 *              For more details, see 5.14.2., table 43 of <em>ISO/IEC 23009-1</em>.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IPOPULARITYRATE_H_
#define IPOPULARITYRATE_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IPopularityRate : public virtual IMPDElement
        {
            public:
                virtual ~IPopularityRate(){}
                
                /**
                 *  Returns an unsigned integer that indicates the relative Popularity Rate of the segments of containing entity (i.e. the Preselection or Adaptation Set containing this \b ContentPopularityRate element),
                 *  within the same Media Presentation. No unit. The value shall be in the range of 1 to 100.
                 *  A greater value means higher likelihood of the series of (Sub)Segments being consumed/requested.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint8_t                     GetPopularityRate    ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the first Segment from which \c @popularityRate value of this \b PR element is relevant.
                 *  If the addressing scheme for the containing entity is using Segment template with \c $Number$, then \c @popularityRate applies from the earliest presentation time of the Segment with the segment number specified by this attribute.
                 *  For other addressing schemes, the value of \c @popularityRate applies from the Segment which contains the media sample whose presentation time specified by this attribute in unit of \c @timescale on Representation level.
                 *  If not present, then it shall be assumed that \c @popularityRate applies from:
                 *  <ul>
                 *      <li> the first Segment of the containing Period, for the first \b PR element,
                 *      <li> the Segment after the last Segment of the previous \b PR element, for other PR elements.    
                 *  </ul>
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint64_t                    GetStart             ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the number of segments after the segment indicated by \c @start which are included in this \b PR entry (i.e. the repeat count).
                 *  A negative value indicates that the series continues until the segment before the first segment of the next \b PR element, or if there are no further \b PR elements until the end of the Period or the next MPD update.
                 *  
                 *  @return     an integer
                 */
                virtual int32_t                     GetR                 ()  const = 0;
                
        };
    }
}

#endif /* IPOPULARITYRATE_H_ */