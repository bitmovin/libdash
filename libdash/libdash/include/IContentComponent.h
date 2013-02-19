/**
 *  @class      dash::mpd::IContentComponent
 *  @brief      This interface is needed for accessing the attributes and elements of the <b><tt>ContentComponent</tt></b> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.4.2, table 6
 *  @details    Each Adaptation Set contains one or more media content components. The properties of each media content 
 *              component are described by a <b><tt>ContentComponent</tt></b> element or may be described directly on the <b><tt>AdaptationSet</tt></b> element 
 *              if only one media content component is present in the Adaptation Set. <b><tt>ContentComponent</tt></b> elements are contained in an <b><tt>AdaptationSet</tt></b> element.
 *  @see        dash::mpd::IMPDElement dash::mpd::IDescriptor dash::mpd::IAdaptationSet
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ICONTENTCOMPONENT_H_
#define ICONTENTCOMPONENT_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"

namespace dash
{
    namespace mpd
    {
        class IContentComponent : public virtual IMPDElement
        {
            public:
                virtual ~IContentComponent(){}


                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetAccessibility()
                 */
                virtual const std::vector<IDescriptor *>&   GetAccessibility    ()  const = 0;

                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetRole()
                 */
                virtual const std::vector<IDescriptor *>&   GetRole             ()  const = 0;

                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetRating()
                 */
                virtual const std::vector<IDescriptor *>&   GetRating           ()  const = 0;

                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetViewpoint()
                 */
                virtual const std::vector<IDescriptor *>&   GetViewpoint        ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies an identifier for this media component.
                 *  The attribute shall be unique in the scope of the containing Adaptation Set.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                            GetId               ()  const = 0;

                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetLang()
                 */
                virtual const std::string&                  GetLang             ()  const = 0;

                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetContentType()
                 */
                virtual const std::string&                  GetContentType      ()  const = 0;

                /**
                 *  @copydoc    dash::mpd::IAdaptationSet::GetPar()
                 */
                virtual const std::string&                  GetPar              ()  const = 0;

        };
    }
}

#endif /* ICONTENTCOMPONENT_H_ */