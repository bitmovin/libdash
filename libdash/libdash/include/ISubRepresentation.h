/**
 *  @class      dash::mpd::ISubRepresentation
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>SubRepresentation</b></tt> element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.6.2, table 8
 *  @details    Sub-Representations are embedded in regular Representations and are described by the <tt><b>SubRepresentation</b></tt> element. 
 *              <tt><b>SubRepresentation</b></tt> elements are contained in a <tt><b>Representation</b></tt> element.\n
 *              The SubRepresentation element describes properties of one or several media content components that are embedded in the Representation.
 *              It may for example describe the exact properties of an embedded audio component (e.g., codec, sampling rate, etc.),
 *              an embedded sub-title (e.g., codec) or it may describe some embedded lower quality video layer (e.g. some lower frame rate, etc.).
 *  @see        dash::mpd::IRepresentationBase
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef ISUBREPRESENTATION_H_
#define ISUBREPRESENTATION_H_

#include "config.h"

#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class ISubRepresentation : public virtual IRepresentationBase
        {
            public:
                virtual ~ISubRepresentation(){}

                /**
                 *  Returns an integer that specifies the Sub-Representation level. If \c \@level attribute is present and for media formats used in this Part of ISO/IEC 23009,
                 *  a Subsegment Index as defined in section 6.3.2.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em> shall be available for each Media Segment in the containing Representation.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                            GetLevel            () const = 0;

                /**
                 *  Returns a reference to a vector of unsigned integers that specifies the set of Sub-Representations within this Representation that this Sub-Representation depends on
                 *  in the decoding and/or presentation process as a list of \c \@level values.\n
                 *  If not present, the Sub-Representation can be decoded and presented independently of any other Representation.
                 *  @return     a reference to a vector of unsigned integers
                 */
                virtual const std::vector<uint32_t>&        GetDependencyLevel  () const = 0;

                /**
                 *  Returns an integer that is identical to the \c \@bandwidth definition in Representation, but applied to this Sub-Representation.
                 *  This attribute shall be present if the \c \@level attribute is present.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                            GetBandWidth        () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the set of all media content components 
                 *  that are contained in this Sub-Representation as <tt><b>ContentComponent</b>\@id</tt> values. \n
                 *  If not present, the Sub-Representation is not assigned to a media content component. 
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&     GetContentComponent () const = 0;

        };
    }
}

#endif /* ISUBREPRESENTATION_H_ */