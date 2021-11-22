/**
 *  @class      dash::mpd::IContentPopularityRate
 *  @brief      This interface is needed for accessing the common elements and attributes of <tt><b>ContentPopularityRate</b></tt>
 *  @details    Content Popularity Rate is a method for signalling information on which content items amongst the different Preselections and Adaptation Sets are expected to be more popular than others.
 *              Example use cases for different content streams in a Media Presentation include:
 *              <ul>
 *                  <li> content streams from different viewpoints: in this case, an Adaptation Set containing recommended viewpoint is expected to be more popular than other Adaptation Sets;
 *                  <li> sub-picture streams in a 360 video: in this case, a set of Adaptation Sets containing the sub-picture streams that compose "recommended viewport" can be signalled as more popular than others.
 *              </ul>
 *              Content Popularity Rate information is expected to be provided by the content provider based on the author’s intent, expected consumption rate by users, 
 *              or actual viewing statistics that could have been measured by using DASH metrics, such as Play list as defined in Annex D.4.6. of <em>ISO/IEC 23009-1</em>.\n
 *              If provided, the information can be used for data prefetching by clients or network elements, e.g. CDN servers. 
 *              It can also be used for example to deliver the data that is considered most relevant on a preferred data link, for example on multicast or broadcast, whereas less popular data is only provided in unicast.
 *              Expected-to-be-popular data can also be prefetched in higher quality in order to ensure that such data is available in good quality.\n
 *              To indicate the popularity of a Pre-selection or Adaptation Set, the \b ContentPopularityRate element may be present within that element. 
 *              The \b ContentPopularityRate element contains one or more \b PR elements giving the rating for different parts of the content. 
 *              The semantics of the \b ContentPopularityRate element are provided in 5.14.2, Table 43, the syntax is provided in 5.14.3 (of <em>ISO/IEC 23009-1</em>).    
 *  @see        dash::mpd::IPopularityRate dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ICONTENTPOPULARITYRATE_H_
#define ICONTENTPOPULARITYRATE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IPopularityRate.h"

namespace dash
{
    namespace mpd
    {
        class IContentPopularityRate : public virtual IMPDElement
        {
            public:
                virtual ~IContentPopularityRate(){}
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IPopularityRate objects that specifies 
                 *  start time and number of segments for a contiguous sequence of segments assigned identical Popularity Rate value.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IPopularityRate objects
                 */
                virtual const std::vector<IPopularityRate *>&   GetPopularityRates                 () const = 0;
                
                /**
                 *  Returns a reference to a string that indicates the source of rating by this element.
                 *  The value can be one of the following:
                 *  <ul>
                 *      <li> \c content (when the value is specified by the content author or content provider);
                 *      <li> \c statistics (when the value is specified based on viewing statistics);
                 *      <li> \c other.
                 *  </ul>
                 *  When \c "other" is used, \c @source_description should be provided.            
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetSource                          () const = 0;
                
                /**
                 *  Returns a reference to a UTF-8 string that provides a textual description of the source of rating.        
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetSourceDescription               () const = 0;
                
        };
    }
}

#endif /* ICONTENTPOPULARITYRATE_H_ */