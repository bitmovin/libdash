/**
 *  @class      dash::mpd::ISegmentList
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>SegmentList</b></tt> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.3.2, table 14
 *  @details    The Segment list is defined by one or more <tt><b>SegmentList</b></tt> elements. Each <tt><b>SegmentList</b></tt> element itself contains a list of <tt><b>SegmentURL</b></tt> elements 
 *              for a consecutive list of Segment URLs. Each Segment URL may contain the Media Segment URL and possibly a byte range. 
 *              The Segment URL element may also contain an Index Segment.
 *  @see        dash::mpd::ISegmentURL dash::mpd::IMultipleSegmentBase
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 */

#ifndef ISEGMENTLIST_H_
#define ISEGMENTLIST_H_

#include "config.h"

#include "ISegmentURL.h"
#include "IMultipleSegmentBase.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentList : public virtual IMultipleSegmentBase
        {
            public:
                virtual ~ISegmentList(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ISegmentURL objects that are contained in this SegmentList.
                 *  @return     a reference to a vector of pointers to dash::mpd::ISegmentURL objects
                 */
                virtual const std::vector<ISegmentURL *>&   GetSegmentURLs  ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies a reference to an external <tt><b>SegmentList</b></tt> element.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                  GetXlinkHref    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the processing set - can be either \c \"onLoad\" or \c \"onRequest\".
                 *  @return     a reference to a string
                 */
                virtual const std::string&                  GetXlinkActuate ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the type of W3C XLINK being used. \n
                 *  In the context of this document, all references shall be W3C XLINK simple links. The attribute \c @xlink:type is optional with fixed setting \c @xlink:type="simple".    .
                 *  @return     a reference to a string
                 */
                virtual const std::string&                     GetXlinkType    ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the desired behaviour of the remote element entity once dereferenced from within an MPD as defined in W3C XLINK. \n
                 *  In the context of this document, the attribute \c @xlink:show is optional with fixed setting \c @xlink:show="embed". \n    
                 *  \b NOTE In W3C XLINK, the behaviour of conforming XLink applications when embedding as a remote element entity is not defined. Thus, the actual behaviour for this document is defined in subclause 5.5.3. of <em>ISO/IEC 23009-1</em>.    
                 *  @return     a reference to a string
                 */
                virtual const std::string&                    GetXlinkShow    ()  const = 0;

        };
    }
}

#endif /* ISEGMENTLIST_H_ */