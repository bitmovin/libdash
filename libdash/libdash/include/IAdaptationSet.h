/**
 *  @class      dash::mpd::IAdaptationSet
 *  @brief      This interface is needed for accessing the attributes and elements of the <b><tt>AdaptationSet</tt></b> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.3.2, table 5
 *  @details    Each Period consists of one or more Adaptation Sets. An Adaptation Set is described by an <b><tt>AdaptationSet</tt></b> element. 
 *              <b><tt>AdaptationSet</tt></b> elements are contained in a <b><tt>Period</tt></b> element.\n\n
 *              An Adaptation Set contains alternate Representations, i.e. only one Representation within an Adaptation Set is expected to be presented at a time.
 *              All Representations contained in one Adaptation Set represent the same media content components and therefore contain media streams that are considered to be perceptually equivalent.\n\n
 *              Representations are arranged into Adaptation Sets according to the media content component properties of the media content components present in the Representations, namely
 *              <ul>
 *                  <li>the language as described by the \c \@lang attribute,
 *                  <li>the media component type described by the \c \@contentType attribute,
 *                  <li>the picture aspect ratio as described by the \c \@par attribute,
 *                  <li>the role property as described by the <b><tt>Role</tt></b> elements,
 *                  <li>the accessibility property as described by the <b><tt>Accessibility</tt></b> elements,
 *                  <li>the viewpoint property as described by the <b><tt>Viewpoint</tt></b> elements,
 *                  <li>the rating property as described by the <b><tt>Rating</tt></b> elements.
 *              </ul>
 *              Representations shall appear in the same Adaptation Set if and only if they have identical values for all of these media content component properties for each media content component.\n\n
 *              The values for the elements <b><tt>Role</tt></b>, <b><tt>Accessibility</tt></b>, <b><tt>Viewpoint</tt></b> and <b><tt>Rating</tt></b> are generally not provided 
 *              within the scope of this part of ISO/IEC 23009. However, a number of simple schemes are defined in section 5.8.5. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.\n\n
 *              If there exist multiple media content components then the properties of each media content component shall be described by a separate ContentComponent element as defined in 5.5.4.
 *              The ContentComponent element shares common elements and attributes with the <b><tt>AdaptationSet</tt></b> element. Default values, or values applicable to all media content components, 
 *              may be provided directly in the <b><tt>AdaptationSet</tt></b> element. Attributes present in the <b><tt>AdaptationSet</tt></b> shall not be repeated in the ContentComponent element.\n\n
 *              The <b><tt>AdaptationSet</tt></b> element may contain default values for elements and attributes associated to the contained Representations. 
 *              The list of possible present elements and attributes that are common to <b><tt>AdaptationSet</tt></b> and <b><tt>Representation</tt></b> (and also <b><tt>SubRepresentation</tt></b>)
 *              are collected in 5.3.7. Any of the common attributes shall only be present either in the <b><tt>AdaptationSet</tt></b> element or in the <b><tt>Representation</tt></b> element, 
 *              but not in both.\n\n
 *              The <b><tt>AdaptationSet</tt></b> element also supports the description of ranges for the \c \@bandwidth, \c \@width, \c \@height and \c \@frameRate attributes 
 *              associated to the contained Representations, which provide a summary of all values for all the Representations within this Adaptation Set. 
 *              The Representations contained within an Adaptation Set shall not contain values outside the ranges documented for that Adaptation Set. \n\n
 *              Adaptation Sets may be further arranged into groups using the \c \@group attribute. The semantics of this grouping is that the media content within one Period is represented by: 
 *              <ol>
 *                  <li>either one Representation from group 0, if present,
 *                  <li>or the combination of at most one Representation from each non-zero group.
 *              </ol>
 *              If the <tt><b>AdaptationSet</b>\@group</tt> attribute is not present then all Representations in this Adaptation Set are assigned to a non-zero group specific to this Adaptation Set.
 *  @see        dash::mpd::IDescriptor dash::mpd::IContentComponent dash::mpd::IBaseUrl dash::mpd::ISegmentBase dash::mpd::ISegmentList dash::mpd::ISegmentTemplate dash::mpd::IRepresentation 
 *              dash::mpd::IRepresentationBase
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IADAPTATIONSET_H_
#define IADAPTATIONSET_H_

#include "config.h"

#include "IDescriptor.h"
#include "IContentComponent.h"
#include "IBaseUrl.h"
#include "ISegmentBase.h"
#include "ISegmentList.h"
#include "ISegmentTemplate.h"
#include "IRepresentation.h"
#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class IAdaptationSet : public virtual IRepresentationBase
        {
            public:
                virtual ~IAdaptationSet(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information about accessibility scheme.\n
                 *  For more details refer to sections 5.8.1 and 5.8.4.3. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetAccessibility                ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on role annotation scheme.
                 *  For more details refer to sections 5.8.1 and 5.8.4.2. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetRole                         ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on rating scheme.\n
                 *  For more details refer to sections 5.8.1 and 5.8.4.4. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetRating                       ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on viewpoint annotation scheme.\n
                 *  For more details refer to sections 5.8.1 and 5.8.4.5. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetViewpoint                    ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IContentComponent objects that specifies the properties
                 *  of one media content component contained in this Adaptation Set.\n
                 *  For more details refer to section 5.3.4. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IContentComponent objects
                 */
                virtual const std::vector<IContentComponent *>& GetContentComponent             ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IBaseUrl objects that specify base URLs that can be used for reference resolution and alternative URL selection.\n
                 *  For more details refer to the description in section 5.6. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IBaseUrl objects
                 */
                virtual const std::vector<IBaseUrl *>&          GetBaseURLs                     ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentBase object that specifies default Segment Base information.\n
                 *  Information in this element is overridden by information in the <tt><b>Representation.SegmentBase</b></tt>, if present.\n
                 *  For more details see section 5.3.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentBase object
                 */
                virtual ISegmentBase*                           GetSegmentBase                  ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentList object that specifies default Segment List information.\n
                 *  Information in this element is overridden by information in the <tt><b>Representation.SegmentList</b></tt>, if present.\n
                 *  For more details see section 5.3.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentList object
                 */
                virtual ISegmentList*                           GetSegmentList                  ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegmentTemplate object that specifies default Segment Template information.\n
                 *  Information in this element is overridden by information in the <tt><b>Representation.SegmentTemplate</b></tt>, if present.\n
                 *  For more details see section 5.3.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a pointer to a dash::mpd::ISegmentTemplate object
                 */
                virtual ISegmentTemplate*                       GetSegmentTemplate              ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IRepresentation objects that specifies a Representation.\n
                 *  At least one Representation element shall be present in each Adaptation Set. The actual element may however be part of a remote element.\n
                 *  For more details refer to section 5.3.5. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IRepresentation objects
                 */
                virtual const std::vector<IRepresentation *>&   GetRepresentation               ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies a reference to external <tt><b>AdaptationSet</b></tt> element.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkHref                    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the processing instructions, which can be either \c \"onLoad\" or \c \"onRequest\".
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkActuate                 ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies an unique identifier for this Adaptation Set in the scope of the Period.
                 *  The attribute shall be unique in the scope of the containing Period. \n\n
                 *  The attribute shall not be present in a remote element.\n\n
                 *  If not present, no identifier for the Adaptation Set is specified.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetId                           ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies an identifier for the group that is unique in the scope of the containing Period.\n
                 *  For details refer to section 5.3.3.1. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetGroup                        ()  const = 0;

                 /**
                 *  Returns a reference to a string that declares the language code for this Adaptation Set. The syntax and semantics according to IETF RFC 5646 shall be used.\n
                 *  If not present, the language code may be defined for each media component or it may be unknown.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetLang                         ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the media content component type for this Adaptation Set. 
                 *  A value of the top-level Content-type 'type' value as defined in RFC1521, Clause 4 shall be taken.\n
                 *  If not present, the media content component type may be defined for each media component or it may be unknown.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetContentType                  ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the picture aspect ratio of the video media component type, 
                 *  in the form of a string consisting of two integers separated by ':', e.g., \c \"16:9\". When this attribute is present, 
                 *  and the attributes \c \@width and \c \@height for the set of Representations are also present, the picture aspect ratio as specified by this attribute shall be the same 
                 *  as indicated by the values of \c \@width, \c \@height, and \c \@sar, i.e. it shall express the same ratio as (\c \@width * \em sarx): (\c \@height * \em sary), 
                 *  with \em sarx the first number in \c \@sar and \em sary the second number.\n
                 *  If not present, the picture aspect ratio may be defined for each media component or it may be unknown.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetPar                          ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies the minimum \c \@bandwidth value in all Representations in this Adaptation Set.
                 *  This value has the same units as the \c \@bandwidth attribute. 
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMinBandwidth                 ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies the maximum \c \@bandwidth value in all Representations in this Adaptation Set.
                 *  This value has the same units as the \c \@bandwidth attribute. 
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMaxBandwidth                 ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies the minimum \c \@width value in all Representations in this Adaptation Set.
                 *  This value has the same units as the \c \@width attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMinWidth                     ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies the maximum \c \@width value in all Representations in this Adaptation Set.
                 *  This value has the same units as the \c \@width attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMaxWidth                     ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies specifies the minimum \c \@height value in all Representations in this Adaptation Set.
                 *  This value has the same units as the \c \@height attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMinHeight                    ()  const = 0;

                /**
                 *  Returns an unsigned integer that specifies specifies the maximum \c \@height value in all Representations in this Adaptation Set.
                 *  This value has the same units as the \c \@height attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMaxHeight                    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the minimum \c \@framerate value in all Representations in this Adaptation Set.
                 *  This value is encoded in the same format as the \c \@frameRate attribute. 
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetMinFramerate                 ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the maximum \c \@framerate value in all Representations in this Adaptation Set.
                 *  This value is encoded in the same format as the \c \@frameRate attribute. 
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetMaxFramerate                 ()  const = 0;

                /**
                 *  Because of the fact that the type of the attribute \em segmentAlignment is a union of \c xs:unsignedInt and \c xs:boolean this method is needed to determine
                 *  whether its value is of type bool or integer.\n
                 *  If and only if \c 'true' is returned, an invocation of HasSegmentAlignment() is neccessary to retrieve the bool value.\n
                 *  If and only if \c 'false' is returned, an invocation of GetSegmentAlignment() is neccessary to retrieve the integer value.
                 *  @return     a bool value
                 */
                virtual bool                                    SegmentAlignmentIsBoolValue     ()  const = 0;

                /**
                 *  If the return value of SegmentAlignmentIsBoolValue() equals \c 'true' the bool value returned by this method 
                 *  specifies whether Segment Alignment is used or not. This is only valid for Adaptation Sets containing Representations with multiple media content components.
                 *  If \c 'true' is returned, this specifies that for any two Representations, 
                 *  X and Y, within the same Adaptation Set, the <em>m</em>-th Segment of X and the <em>n</em>-th Segment of Y 
                 *  are non-overlapping (as defined in section 4.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>) whenever \em m is not equal to \em n.
                 *  @return     a bool value
                 */
                virtual bool                                    HasSegmentAlignment             ()  const = 0;

                /**
                 *  If the return value of SegmentAlignmentIsBoolValue() equals \c 'false' this specifies that for any two Representations, 
                 *  X and Y, within the same Adaptation Set, the <em>m</em>-th Segment of X and the <em>n</em>-th Segment of Y 
                 *  are non-overlapping (as defined in section 4.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>) whenever \em m is not equal to \em n.\n\n
                 *  For Adaptation Sets containing Representations with a single media content component, when two <b><tt>AdaptationSet</tt></b> elements within a Period share the same 
                 *  integer value for this attribute - <b>which is the return value of this method</b>, then for any two Representations, X and Y, within the union of the two Adaptation Sets, 
                 *  the <em>m</em>-th Segment of X and the <em>n</em>-th Segment of Y are non-overlapping (as defined in section 4.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>)
                 *  whenever \em m is not equal to \em n.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetSegmentAligment              ()  const = 0;

                /**
                 *  Because of the fact that the type of the attribute \em subsegmentAlignment is a union of \c xs:unsignedInt and \c xs:boolean this method is needed to determine
                 *  whether its value is of type bool or integer.\n
                 *  If and only if \c 'true' is returned, an invocation of HasSubsegmentAlignment() is neccessary to retrieve the bool value.\n
                 *  If and only if \c 'false' is returned, an invocation of GetSubsegmentAlignment() is neccessary to retrieve the integer value.
                 *  @return     a bool value
                 */
                virtual bool                                    SubsegmentAlignmentIsBoolValue  ()  const = 0;

                /**
                 *  If and only if the return value of SubsegmentAlignmentIsBoolValue() equals \c 'true' the bool value returned by this method 
                 *  specifies whether Subsegment Alignment is used or not.
                 *  If \c 'true' is returned, the following conditions shall be satisfied:
                 *  <ul>
                 *      <li>Each Media Segment shall be indexed (i.e. either it contains a Segment index or there is an Index Segment providing an index for the Media Segment)
                 *      <li>For any two Representations, X and Y, within the same Adaptation Set, the <em>m</em>-th Subsegment of X and the <em>n</em>-th Subsegment of Y are
                 *          non-overlapping (as defined in section 4.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>) whenever \em m is not equal to \em n.
                 *  </ul>
                 *  @return     a bool value
                 */
                virtual bool                                    HasSubsegmentAlignment          ()  const = 0;

                /**
                 *  If the return value of SubsegmentAlignmentIsBoolValue() equals \c 'false' the following conditions shall be satisfied:
                 *  <ul>
                 *      <li>Each Media Segment shall be indexed (i.e. either it contains a Segment index or there is an Index Segment providing an index for the Media Segment)
                 *      <li>For any two Representations, X and Y, within the same Adaptation Set, the <em>m</em>-th Subsegment of X and the <em>n</em>-th Subsegment of Y are
                 *          non-overlapping (as defined in section 4.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>) whenever \em m is not equal to \em n.
                 *      <li>For Adaptation Sets containing Representations with a single media content component, when two <tt><b>AdaptationSet</b></tt> elements within a Period share 
                 *          the same integer value for this attribute - <b>which is the return value of this method</b>, then for any two Representations, X and Y, 
                 *          within the union of the two Adaptation Sets, the <em>m</em>-th Subsegment of X and the <em>n</em>-th Subsegment of Y are non-overlapping 
                 *          (as defined in section 4.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>) whenever m is not equal to n.
                 *  </ul>
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetSubsegmentAlignment          ()  const = 0;

                /**
                 *  Returns a unsigned integer that when greater than 0, specifies that each Subsegment with \c SAP_type greater than 0 starts with a SAP of type 
                 *  less than or equal to the value of \c \@subsegmentStartsWithSAP. A Subsegment starts with SAP when the Subsegment contains a SAP, 
                 *  and for the first SAP, I<sub>SAU</sub> is the index of the first access unit that follows I<sub>SAP</sub> , and I<sub>SAP</sub> is contained in the Subsegment.\n
                 *  The semantics of \c \@subsegmentStartsWithSAP equal to 0 are unspecified. 
                 *  @return     an unsigned integer
                 */
                virtual uint8_t                                 GetSubsegmentStartsWithSAP      ()  const = 0;

                /**
                 *  Returns a bool value that when true, the following applies:
                 *  <ul>
                 *      <li>All Representations in the Adaptation Set shall have the same number \em M of Media Segments; 
                 *      <li>Let \em R<sub>1</sub> , \em R<sub>2</sub> , ..., \em R<sub>N</sub>  be all the Representations within the Adaptation Set.
                 *      <li>Let
                 *          <ul>
                 *              <li><em>S<sub>i,j</sub></em> , for \em j > 0, be the \em j<sup>th</sup> Media Segment in the \em i<sup>th</sup> Representation (i.e., \em R<sub>i</sub> )
                 *              <li>if present, let <em>S<sub>i,0</sub></em> be the Initialization Segment in the \em i<sup>th</sup> Representation, and 
                 *              <li>if present, let \em B<sub>i</sub>  be the Bitstream Switching Segment in the \em i<sup>th</sup> Representation.
                 *          </ul>
                 *      <li>The sequence of
                 *          <ul>
                 *              <li>any Initialization Segment, if present, in the Adaptation Set, with,
                 *              <li> if Bitstream Switching Segments are present, \n
                 *                  <em> B<sub>i(1)</sub>, S<sub>i(1),1</sub>, B<sub>i(2)</sub>,   S<sub>i(2),2</sub>, ..., 
                 *                  B<sub>i(k)</sub>, S<sub>i(k),k</sub>, ..., B<sub>i(M)</sub>, S<sub>i(M),M</sub> </em>
                 *              <li>else \n
                 *                  S<sub>i(1),1</sub>, S<sub>i(2),2</sub>, ..., S<sub>i(k),k</sub>, ..., S<sub>i(M),M</sub>,
                 *          </ul>
                 *          wherein any \em i(k) for all \em k values in the range of 1 to \em M, respectively, is an integer value in the range of 1 to \em N,
                 *          results  in  a  \"conforming  Segment  sequence\"  as defined in section 4.5.3 of <em>ISO/IEC 23009-1, Part 1, 2012</em> 
                 *          with the media format as specified in the \c \@mimeType attribute.
                 *  </ul>
                 *  More detailed rules may be defined for specific media formats.
                 *  @return     a bool value
                 */
                virtual bool                                    GetBitstreamSwitching           ()  const = 0;
        };
    }
}

#endif /* IADAPTATIONSET_H_ */