/**
 *  @class      dash::mpd::IRepresentation
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>Representation</b></tt> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.5.2, table 7
 *  @details    Representations are described by the <tt><b>Representation</b></tt> element. <tt><b>Representation</b></tt> elements are contained in an <tt><b>AdaptationSet</b></tt> element.\n
 *              A Representation is one of the alternative choices of the complete set or subset of media content components comprising the media content during the defined Period.\n
 *              A Representation starts at the start of the Period \em PeriodStart and continues to the end of the Period, i.e. the start of the next Period or the end of the Media Presentation.\n
 *              Each Representation includes one or more media streams, where each media stream is an encoded version of one media content component.\n
 *              A Representation consists of one or more Segments.\n
 *              Each Representation either shall contain an Initialization Segment or each Media Segment in the Representation shall be self-initializing, 
 *              i.e. the Media Segment itself conforms to the media type as specified in the \c \@mimeType attribute for this Representation. \n
 *              When a Representation is not a dependent Representation, i.e. the \c \@dependencyId attribute is absent, then concatenation of the Initialization Segment, 
 *              if present, and all consecutive Media Segments in one Representation shall represent a conforming Segment sequence as defined in section 4.5.3 of <em>ISO/IEC 23009-1, Part 1, 2012</em>
 *              conforming to the media type as specified in the \c \@mimeType attribute for this Representation.\n
 *              Dependent Representations are described by a <tt><b>Representation</b></tt> element that contains a \c \@dependencyId attribute.
 *              Dependent Representations are regular Representations except that they depend on a set of complementary Representations for decoding and/or presentation. 
 *              The \c \@dependencyId contains the values of the \c \@id attribute of all the complementary Representations, i.e. Representations that are necessary to 
 *              present and/or decode the media content components contained in this dependent Representation.\n
 *              For any dependent Representation X that depends on complementary Representation Y, the <em>m</em>-th Subsegment of X and the <em>n</em>-th Subsegment of Y 
 *              shall be non-overlapping (as defined in 4.5.3) whenever \em m is not equal to \em n. For dependent Representations the concatenation of the Initialization Segment with the 
 *              sequence of Subsegments of the dependent Representations, each being preceded by the corresponding Subsegment of each of the complementary Representations 
 *              in order as provided in the \c \@dependencyId attribute shall represent a conforming Subsegment sequence as defined in 4.5.3 conforming to the media 
 *              format as specified in the \c \@mimeType attribute for this dependent Representation.\n\n
 *              \b NOTE:    When decoding of a dependent Representation is started from a SAP in the (Sub)Segment with number \em i, the decoding process does not need to access 
 *                          data from the complementary Representation(s) from any earlier (sub)segments than (sub)Segment with number i of the complementary Representation(s).
 *  @see        dash::mpd::IRepresentationBase dash::mpd::ISegmentBase dash::mpd::ISegmentList dash::mpd::ISegmentTemplate dash::mpd::IBaseUrl dash::mpd::ISubRepresentation
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IREPRESENTATION_H_
#define IREPRESENTATION_H_

#include "config.h"

#include "IBaseUrl.h"
#include "ISubRepresentation.h"
#include "ISegmentBase.h"
#include "ISegmentList.h"
#include "ISegmentTemplate.h"
#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class IRepresentation : public virtual IRepresentationBase
        {
            public:
                virtual ~IRepresentation(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IBaseUrl objects that specifies Base URLs that can be used for reference resolution and alternative URL selection.\n
                 *   For more details refer to the description in section 5.6. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IBaseUrl objects
                 */
                virtual const std::vector<IBaseUrl *>&              GetBaseURLs                 ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ISubRepresentation objects that specifies information about Sub-Representations 
                 *  that are embedded in the containing Representation.
                 *  For more detail see section 5.3.6 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::ISubRepresentation objects
                 */
                virtual const std::vector<ISubRepresentation *>&    GetSubRepresentations       ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentBase object that specifies default Segment Base information.
                 *  For more detail see section 5.3.9 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentBase object
                 */
                virtual ISegmentBase*                               GetSegmentBase              ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentList object that specifies the Segment List information.
                 *  For more detail see section 5.3.9 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentList object
                 */
                virtual ISegmentList*                               GetSegmentList              ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentTemplate object that specifies the Segment Template information.
                 *  For more detail see section 5.3.9 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentTemplate object
                 */
                virtual ISegmentTemplate*                           GetSegmentTemplate          ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies an identifier for this Representation. The identifier shall be unique within a Period 
                 *  unless the Representation is functionally identically to another Representation in the same Period. \n
                 *  The identifier shall not contain whitespace characters. \n
                 *  If used in the template-based URL construction as defined in 5.3.9.4.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em>, 
                 *  the string shall only contain characters that are permitted within an HTTP-URL according to RFC 1738.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetId                       ()  const = 0;

                /**
                 *  Returns an integer that specifies a bandwidth in bits per seconds (bps).\n
                 *  If the Representation is continuously delivered at this bitrate, starting at any SAP that is indicated either by \c \@startWithSAP 
                 *  or by any Segment Index box, a client can be assured of having enough data for continuous playout providing playout begins after 
                 *  \c \@minBufferTime * \c \@bandwidth bits have been received (i.e. at time \c \@minBufferTime after the first bit is received).\n\n
                 *  For dependent Representations this value shall specify the minimum bandwidth as defined above of this Representation and all complementary Representations.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                    GetBandwidth                ()  const = 0;

                /**
                 *  Returns an integer that specifies a quality ranking of the Representation relative to other Representations in the same Adaptation Set. 
                 *  Lower values represent higher quality content.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                    GetQualityRanking           ()  const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies all complementary Representations the Representation depends on in the decoding and/or 
                 *  presentation process as values of \c \@id attributes.\n
                 *  If not present, the Representation can be decoded and presented independently of any other Representation. \n
                 *  This attribute shall not be present where there are no dependencies.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&             GetDependencyId             ()  const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies media stream structure identifier values.\n
                 *  The attribute may be present for Representations containing video and its semantics are unspecified for any other type of Representations.\n
                 *  If present, the attribute \c \@mediaStreamStructureId specifies a whitespace-separated list of media stream structure identifier values.
                 *  If media streams share the same media stream structure identifier value, the media streams shall have the following characteristics:
                 *  <ul>
                 *  <li>    The media streams have the same number of Stream Access Points of type 1 to 3.
                 *  <li>    The values of T<sub>SAP</sub>, T<sub>DEC</sub>, T<sub>EPT</sub>, and T<sub>PTF</sub> of the <em>i</em>-th SAP of type 1 to 3 in one media stream are identical 
                 *          to the values of T<sub>SAP</sub>, T<sub>DEC</sub>, T<sub>EPT</sub>, and T<sub>PTF</sub>, respectively, of the <em>i</em>-th SAP of type 1 to 3 
                 *          in the other media streams for any value of \em i from 1 to the number of SAPs of type 1 to 3 in any of the media streams.
                 *  <li>    A media stream formed by concatenating the media stream of a first Representation until I<sub>SAU</sub> (exclusive) of the <em>i</em>-th SAP of type 1 to 3 and the 
                 *          media stream of a second Representation (having the same media stream structure identifier value as for the first Representation) starting from the I<sub>SAU</sub> 
                 *          (inclusive) of the <em>i</em>-th SAP of type 1 to 3 conforms to the specification in which the media stream format is specified for any value of \em i from 1 to the number 
                 *          of SAPs of type 1 to 3 in either media stream. Furthermore, the decoded pictures have an acceptable quality regardless of type of the Stream Access Point access unit used.
                 *  </ul>
                 *  All media stream structure identifier values for one Adaptation Set shall differ from those of another Adaptation Set.\n
                 *  If not present, then for this Representation no similarities to other Representations are known.
                 *  \b NOTE     Indicating multiple media stream structure identifier values for a Representation can be useful in cases where switching between Representations A and B
                 *              as well as between Representations B and C is allowed at non-IDR intra pictures, but switching between Representations A and C would cause too 
                 *              severe a degradation in the quality of the leading pictures and is hence not allowed. To indicate these permissions and restrictions, 
                 *              Representation A would contain \c \@mediaStreamStructureId equal to \"1"\", Representation B would contain \c \@mediaStreamStructureId equal to \"1 2\",
                 *              and Representation C would contain \c \@mediaStreamStructureId equal to \"2\".
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&             GetMediaStreamStructureId   ()  const = 0;
        };
    }
}

#endif /* IREPRESENTATION_H_ */