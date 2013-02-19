/**
 *  @class      dash::mpd::IPeriod
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>Period</b></tt> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.2.2, table 4
 *  @details    A Media Presentation consists of one or more Periods. A Period is defined by a <tt><b>Period</b></tt> element in the <tt><b>MPD</b></tt> element. \n
 *              The type of the Period, either a regular Period or an Early Available Period, as well as the \em PeriodStart time of a regular Period is determined as follows:
 *              <ul>
 *                  <li>If the attribute \c \@start is present in the Period, then the Period is a regular <tt><b>Period</b></tt> and the \em PeriodStart is equal to the value of this attribute.
 *                  <li>If the \c \@start attribute is absent, but the previous <tt><b>Period</b></tt> element contains a \c \@duration attribute then then this new Period is also a regular Period.
 *                      The start time of the new Period \em PeriodStart is the sum of the start time of the previous Period \em PeriodStart and 
 *                      the value of the attribute \c \@duration of the previous Period.
 *                  <li>If \em (i) \c \@start attribute is absent, and \em (ii) the <tt><b>Period</b></tt> element is the first in the MPD,
 *                      and \em (iii) the <tt><b>MPD</b>\@type</tt> is \c 'static', then the \em PeriodStart time shall be set to zero.
 *                  <li>If \em (i) \c \@start attribute is absent, and \em (ii) the previous Period element does not contain a \c \@duration attribute or 
 *                      the <tt><b>Period</b></tt> element is the first in the MPD, and (iii) the <tt><b>MPD</b>\@type</tt> is \c 'dynamic', 
 *                      then this Period is an Early Available Period (see below for details).
 *              </ul>
 *              For any regular Period the following holds: \em PeriodStart reflects the actual time that should elapse after playing the media of all prior Periods in this Media Presentation 
 *              relative to the \em PeriodStart time of the first Period in the Media Presentation. The Period extends until the \em PeriodStart of the next Period, or until the end of the 
 *              Media Presentation in the case of the last Period. More specifically, the difference between the \em PeriodStart time of a Period and
 *              either the \em PeriodStart time of the following Period, if this is not the last Period, or the value of the <tt><b>MPD</b>\@mediaPresentationDuration</tt> if this is the last one,
 *              is the presentation duration in Media Presentation time of the media content represented by the Representations in this Period. \n\n
 *              Early Available Periods may be used to advertise initialization of other non-media data before the media data itself is available.
 *              <tt><b>Period</b></tt> elements documenting early available Periods shall not occur before any Period element documenting a regular Period. For Early Available Periods,
 *              any resources that are announced in such a Period element shall be available. Such a <tt><b>Period</b></tt> element shall not contain URLs to Media Segments.
 *              The data contained in such a <tt><b>Period</b></tt> element does not represent a Period in the Media Presentation. Only when the \em PeriodStart time becomes known 
 *              through an update of the MPD, such a <tt><b>Period</b></tt> element represents a regular Period. However, an update of the MPD may even remove a <tt><b>Period</b></tt> element 
 *              representing an Early Available Period in later updates of the MPD as long as no \em PeriodStart time is associated with the Period. \n\n
 *              To avoid dereferencing of a remote element containing a <tt><b>Period</b></tt> element solely to determine the Period timeline, e.g. in case of seeking, 
 *              <tt><b>Period</b>\@start</tt> or previous Period's <tt><b>Period</b>\@duration</tt> should be present in the MPD.
 *  @see        dash::mpd::IMPDElement dash::mpd::BaseUrl dash::mpd::IAdaptationSet dash::mpd::ISegmentBase dash::mpd::ISegmentList dash::mpd::ISegmentTemplate dash::mpd::ISubset
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IPERIOD_H_
#define IPERIOD_H_

#include "config.h"

#include "IMPDElement.h"
#include "IBaseUrl.h"
#include "ISegmentBase.h"
#include "ISegmentList.h"
#include "ISegmentTemplate.h"
#include "IAdaptationSet.h"
#include "ISubset.h"

namespace dash
{
    namespace mpd
    {
        class IPeriod : public virtual IMPDElement
        {
            public:
                virtual ~IPeriod(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IBaseUrl objects that specify base URLs that can be used for reference resolution and alternative URL selection.\n
                 *  For more details refer to the description in section 5.6. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IBaseUrl objects
                 */
                virtual const std::vector<IBaseUrl *>&          GetBaseURLs             ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentBase object that specifies default Segment Base information.\n
                 *  Information in this element is overridden by information in <tt><b>AdapationSet.SegmentBase</b></tt> and <tt><b>Representation.SegmentBase</b></tt>, if present.\n
                 *  For more details see section 5.3.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentBase object
                 */
                virtual ISegmentBase*                           GetSegmentBase          ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentList object that specifies default Segment List information.\n
                 *  Information in this element is overridden by information in <tt><b>AdapationSet.SegmentList</b></tt> and <tt><b>Representation.SegmentList</b></tt>, if present.\n
                 *  For more details see section 5.3.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentList object
                 */
                virtual ISegmentList*                           GetSegmentList          ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentTemplate object that specifies default Segment Template information.\n
                 *  Information in this element is overridden by information in <tt><b>AdapationSet.SegmentTemplate</b></tt> and <tt><b>Representation.SegmentTemplate</b></tt>, if present.
                 *  For more details see section 5.3.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentTemplate object
                 */
                virtual ISegmentTemplate*                       GetSegmentTemplate      ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IAdaptationSet objects that specify Adapatation Sets.\n
                 *  At least one Adaptation Set shall be present in each Period. However, the actual element may be present only in a remote element if xlink is in use.\n
                 *  For more details see section 5.3.3. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IAdaptationSet objects
                 */
                virtual const std::vector<IAdaptationSet *>&    GetAdaptationSets       ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ISubset objects that specify Subsets.\n
                 *  For more details see section 5.3.8. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::ISubset objects
                 */
                virtual const std::vector<ISubset *>&           GetSubsets              ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies a reference to an external <tt><b>Period</b></tt> element.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkHref            ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the processing instructions, which can be either \c \"onLoad\" or \c \"onRequest\".\n
                 *  This attribute shall not be present if the \c \@xlink:href attribute is not present.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkActuate         ()  const = 0;

                /**
                 *  Returns an reference to a string that specifies an identifier for this Period.
                 *  The attribute shall be unique in the scope of the Media Presentation.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetId                   ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the \em PeriodStart time of the Period.The \em PeriodStart time is used as an anchor to determine the MPD start 
                 *  time of each Media Segment as well as to determine the presentation time of each each access unit in the Media Presentation timeline.\n
                 *  If not present, refer to the details in section 5.3.2.1. of <em>ISO/IEC 23009-1, Part 1, 2012</em>
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetStart                ()  const = 0;

                /**
                 *  Returns a reference to a string that  specifies the duration of the Period to determine the \em PeriodStart time of the next Period.\n
                 *  If not present, refer to the details in section 5.3.2.1. of <em>ISO/IEC 23009-1, Part 1, 2012</em>
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetDuration             ()  const = 0;

                /**
                 *  When set to \c 'true', this is equivalent as if the <tt><b>AdaptationSet</b>\@bitstreamSwitching</tt> for each Adaptation Set contained in this Period is set to \c 'true'.
                 *  In this case, the <tt><b>AdaptationSet</b>\@bitstreamSwitching</tt> attribute shall not be set to \c 'false' for any Adaptation Set in this Period.
                 *  @return     a bool value
                 */
                virtual bool                                    GetBitstreamSwitching   ()  const = 0;

        };
    }
}

#endif /* IPERIOD_H_ */