/**
 *  @class      dash::mpd::ISubset
 *  @brief      This interface is needed for accessing the attributes of the <tt><b>Subset</b></tt> element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.8.2, table 10
 *  @details    Subsets are described by the <tt><b>Subset</b></tt> element contained in the <tt><b>Period</b></tt> element. \n
 *              Subsets provide a mechanism to restrict the combination of active Adaptation Sets where an active Adaptation Set is one 
 *              for which the DASH client is presenting at least one of the contained Representations.\n
 *              A Subset defines a set of one or more Adaptation Sets. The presence of a <tt><b>Subset</b></tt> element within a <tt><b>Period</b></tt> element expresses 
 *              the intention of the creator of the Media Presentation that a client should act as follows: 
 *              At any time, the set of active Adaptation Sets shall be a subset of the Adaptation Sets of one of the specified Subsets.
 *              Any Adaptation Set not explicitly contained in any Subset element is implicitly contained in all specified Subsets.\n
 *              This implies that
 *              <ul>
 *                  <li>Empty Subsets are not allowed.
 *                  <li>No Subset should contain all the Adaptation Sets.
 *              </ul>
 *              Each Adaptation Set for which the value of the \c \@id is provided in the \c \@contains attribute is contained in this Subset.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ISUBSET_H_
#define ISUBSET_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ISubset : public virtual IMPDElement
        {
            public:
                virtual ~ISubset(){}

                /**
                 *  Returns a reference to a vector of unsigned integers specifying the Adaptation Sets contained in a Subset by providing 
                 *  the \c \@id values of the contained Adaptation Sets.
                 *  @return     a reference to a vector of unsigned integers
                 */
                virtual const std::vector<uint32_t>& Contains () const = 0;
        };
    }
}

#endif /* ISUBSET_H_ */