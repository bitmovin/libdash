/**
 *  @class      dash::mpd::IRepresentationBase
 *  @brief      This interface is needed for accessing the common attributes and elements of the certain MPD element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.7
 *  @details    The elements \c <b>AdaptationSet</b>, \c <b>Representation</b> and \c <b>SubRepresentation</b> have assigned common attributes and elements that are specified in 
 *              <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.7.2, table 9
 *  @see        dash::mpd::IDescriptor dash::mpd::IContentProtection dash::mpd::IEventStream dash::mpd::ILabel dash::mpd::ISwitching dash::mpd::IContentPopularityRate 
 *              dash::mpd::IProducerReferenceTime dash::mpd::IRandomAccess dash::mpd::IResync dash::mpd::IMPDElement
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

#ifndef IREPRESENTATIONBASE_H_
#define IREPRESENTATIONBASE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IContentProtection.h"
#include "IDescriptor.h"
#include "IEventStream.h"
#include "ILabel.h"
#include "ISwitching.h"
#include "IContentPopularityRate.h"
#include "IProducerReferenceTime.h"
#include "IRandomAccess.h"
#include "IResync.h"

namespace dash
{
    namespace mpd
    {
        class IRepresentationBase : public virtual IMPDElement
        {
            public:
                virtual ~IRepresentationBase(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specifies frame-packing arrangement information of the video media component type.\n
                 *  When no <tt><b>FramePacking</b></tt> element is provided for a video component, frame-packing shall not used for the video media component.\n
                 *  For further details see sections 5.8.1 and 5.8.4.6 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&              GetFramePacking                  () const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specifies the audio channel configuration of the audio media component type.\n
                 *  For further details see sections 5.8.1 and 5.8.4.7 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&              GetAudioChannelConfiguration     () const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IContentProtection objects that specifies information about content protection schemes used for the associated Representations.\n
                 *  For further details see sections 5.8.1 and 5.8.4.1 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IContentProtection objects
                 */
                virtual const std::vector<IContentProtection *>&       GetContentProtections            () const = 0;
                
                /**
                 *  Returns a pointer to a dash::mpd::IDescriptor object that specifies information about the output protection schemes used for the associated Representations.\n
                 *  For further details see sections 5.8.1 and 5.8.4.1 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *
                 *  @return     a pointer to a dash::mpd::IDescriptor object
                 */
                virtual const IDescriptor *                            GetOutputProtection              () const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information about the containing element that is considered 
                 *  essential by the Media Presentation author for processing the containing element. \n    
                 *  For details, see subclause 5.8.4.8. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&              GetEssentialProperties           ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify supplemental information about the containing element 
                 *  that may be used by the DASH Client optimizing the processing. \n
                 *  For details, see subclause 5.8.4.9. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&              GetSupplementalProperties        ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IEventStream objects, each of which specifies Event Stream information.\n
                 *  For more details see section 5.10.2. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IEventStream objects
                 */
                virtual const std::vector<IEventStream *>&             GetEventStreams                  ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ISwitching objects, each of which specifies a switch-to times and types for the associated Representations.\n
                 *  For more details, refer to subclause 5.3.3.4. of <em>ISO/IEC 23009-1</em>.\n
                 *  These elements shall only be present if the \c @timescale value is the same for all Representations in one Adaptation Set and if the Segment Timeline is used for segment duration signalling.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::ISwitching objects
                 */
                virtual const std::vector<ISwitching *>&               GetSwitchings                    ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IRandomAccess objects, each of which specifies a random access times and types for the associated Representations.
                 *  For more details, refer to subclause 5.3.5.5. of <em>ISO/IEC 23009-1</em>.\n
                 *  These elements shall only be present if the \c @timescale value is the same for all Representations in one Adaptation Set and if the Segment Timeline is used for segment duration signalling.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IRandomAccess objects
                 */
                virtual const std::vector<IRandomAccess *>&            GetRandomAccesses                ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ILabel objects that specify summary labels for a group of Labels.
                 *  For more details, refer to subclause 5.3.10. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::ILabel objects
                 */
                virtual const std::vector<ILabel *>&                   GetGroupLabels                   ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::ILabel objects that specify textual descriptions of the elements that may be used for annotation and selection purposes.
                 *  For more details, refer to subclause 5.3.10. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::ILabel objects
                 */
                virtual const std::vector<ILabel *>&                   GetLabels                        ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IContentPopularityRate objects that indicates a level of popularity of the containing entity (i.e., the Adaptation Set, Representation or Preselection) within the Media Presentation.
                 *  For details, see subclause 5.14. of <em>ISO/IEC 23009-1</em>.\n
                 *  \b NOTE This element is primarily introduced for the usage of Pre-Selections and Adaptation Sets but use for Representation and Sub-Representations is not precluded.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IContentPopularityRate objects
                 */
                virtual const std::vector<IContentPopularityRate *>&   GetContentPopularityRates        () const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IProducerReferenceTime objects that specifies the presence and possibly values of producer reference time in the associated Representations.
                 *  For details, refer to subclause 5.12. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IProducerReferenceTime objects
                 */
                virtual const std::vector<IProducerReferenceTime *>&   GetProducerReferenceTimes        () const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IResync objects that specifies information on Segments’ resynchronization points. \n
                 *  For details refer to subclause 5.3.12. of <em>ISO/IEC 23009-1</em>.

                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IResync objects
                 */
                virtual const std::vector<IResync *>&                  GetResyncs                       () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the profiles which the associated Representation(s) 
                 *  conform to of the list of Media Presentation profiles as described in section 8 of <em>ISO/IEC 23009-1, Part 1, 2012</em>. 
                 *  The value shall be a subset of the respective value in any higher level of the document hierarchy (Representation, Adaptation Set, MPD).\n
                 *  If not present, the value is inferred to be the same as in the next higher level of the document hierarchy. 
                 *  For example, if the value is not present for a Representation, then \c \@profiles at the Adaptation Set level is valid for the Representation.\n
                 *  The same syntax as defined in 5.3.1.2 shall be used.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&                GetProfiles                      () const = 0;

                /**
                 *  Returns an integer that specifies the horizontal visual presentation size of the video 
                 *  media type on a grid determined by the \c \@sar attribute. \n\n
                 *  In the absence of \c \@sar width and height are specified as if the value of \c \@sar were \"1:1\".\n
                 *  \b NOTE:    The visual presentation size of the video is equal to the number of horizontal and vertical samples used for presentation 
                 *  after encoded samples are cropped in response to encoded cropping parameters, “overscan” signaling, or “pan/scan” display parameters, e.g. SEI messages.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                       GetWidth                         () const = 0;

                /**
                 *  Returns an integer that specifies the vertical visual presentation size of the video 
                 *  media type, on a grid determined by the \c \@sar attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                       GetHeight                        () const = 0;

                /**
                 *  Returns a string that specifies the sample aspect ratio of the video media component type, 
                 *  in the form of a string consisting of two integers separated by ':', e.g., \"10:11\". 
                 *  The first number specifies the horizontal size of the encoded video pixels (samples) in arbitrary units. 
                 *  The second number specifies the vertical size of the encoded video pixels (samples) in same units as the horizontal size.
                 *  @return     a string
                 */
                virtual std::string                                    GetSar                           () const = 0;

                /**
                 *  Returns a string that specifies the output frame rate (or in the case of interlaced, half the output field rate) 
                 *  of the video media type in the Representation. If the frame or field rate is varying, the value is the average frame 
                 *  or half the average field rate field rate over the entire duration of the Representation.\n
                 *  The value is coded as a string, either containing two integers separated by a \"/\", (\"F/D\"), or a single integer \"F\".
                 *  The frame rate is the division F/D, or F, respectively, per second (i.e. the default value of D is \"1\").
                 *  @return     a string
                 */
                virtual std::string                                    GetFrameRate                     () const = 0;

                /**
                 *  Returns a string that represents an audio sampling rate. \n
                 *  Either a single decimal integer value specifying the sampling rate or a whitespace separated pair of decimal integer 
                 *  values specifying the minimum and maximum sampling rate of the audio media component type. The values are in samples per second.
                 *  @return     a string
                 */
                virtual std::string                                    GetAudioSamplingRate             () const = 0;

                /**
                 *  Returns a string that specifies the MIME type of the concatenation of the Initialization Segment, if present, 
                 *  and all consecutive Media Segments in the Representation.
                 *  @return     a string
                 */
                virtual std::string                                    GetMimeType                      () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the profiles of Segments that are essential to process the Representation. 
                 *  The detailed semantics depend on the value of the \c \@mimeType attribute. The contents of this attribute shall conform to either the 
                 *  \c pro-simple or \c pro-fancy productions of RFC6381, Section 4.5, without the enclosing \c DQUOTE characters, 
                 *  i.e. including only the \c unencodedv or \c encodedv elements respectively. 
                 *  As profile identifier the brand identifier for the Segment as defined in section 6 of <em>ISO/IEC 23009-1, Part 1, 2012</em> shall be used.\n
                 *  If not present on any level, the value may be deducted from the value of the\c \@profiles attribute.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&                GetSegmentProfiles               () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the codecs present within the Representation. 
                 *  The codec parameters shall also include the profile and level information where applicable. \n
                 *  The contents of this attribute shall conform to either the \c simp-list or \c fancy-list productions of RFC6381, Section 3.2, 
                 *  without the enclosing \c DQUOTE characters. The codec identifier for the Representation's media format, 
                 *  mapped into the name space for codecs as specified in RFC6381, Section 3.3, shall be used.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&                GetCodecs                        () const = 0;
                
                /**
                 *  Returns a reference to a vector of strings that specifies the container profiles of Representations that are essential to process it. The detailed semantics depend on the value of the \c @mimeType attribute. \n
                 *  The contents of this attribute shall conform to either the pro-simple or pro-fancy productions of IETF RFC 6381:2011, subclause 4.5, without the enclosing DQUOTE characters, i.e. including only the unencodedv or encodedv elements respectively. \n 
                 *  4CC may contain characters that must be escaped in XML. 4CC strings shall be escaped according to W3C XML:2008, Section 2.4.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&                GetContainerProfiles             () const = 0;

                /**
                 *  Returns a double value specifying the maximum SAP interval in seconds of all contained media streams,
                 *  where the SAP interval is the maximum time interval between the T<sub>SAP</sub> of any two successive SAPs of types 1 to 3 
                 *  inclusive of one media stream in the associated Representations.
                 *  @return     a double
                 */
                virtual double                                         GetMaximumSAPPeriod              () const = 0;

                /**
                 *  Returns an unsigned integer that (when greater than 0) specifies that in the associated Representations, 
                 *  each Media Segment starts with a SAP of type less than or equal to the value of this attribute value in each media stream.
                 *  @return     an unsigned integer
                 */
                virtual uint8_t                                        GetStartWithSAP                  () const = 0;

                /**
                 *  Returns a double that specifies the maximum playout rate as a multiple of the regular playout rate,
                 *  which is supported with the same decoder profile and level requirements as the normal playout rate.
                 *  @return     a double
                 */
                virtual double                                         GetMaxPlayoutRate                () const = 0;

                /**
                 *  Returns a bool value that informs about coding dependency.\n
                 *  If \c 'true', for all contained media streams, specifies that there is at least one access unit that depends on one or more other access units for decoding.
                 *  If \c 'false', for any contained media stream, there is no access unit that depends on any other access unit for decoding (e.g. for video all the pictures are intra coded). \n
                 *  If not specified on any level, there may or may not be coding dependency between access units.
                 *  @return     a bool value
                 */
                virtual bool                                           HasCodingDependency              () const = 0;

                /**
                 *  Returns a string that specifies the scan type of the source material of the video media component type. 
                 *  The value may be equal to one of \c \"progressive\", \c \"interlaced\" and \c \"unknown\".
                 *  @return     a string
                 */
                virtual std::string                                    GetScanType                      () const = 0;
                
                /**
                 *  Returns a string that specifies the selection priority for the described data structures, i.e. the one described by the containing element.    
                 *  In the absence of other information, higher numbers are the preferred selection over lower numbers.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                        GetSelectionPriority            () const = 0;
                
                /**
                 *  Returns a string that specifies the tag of the Representation, Adaptation Set or Preselection which may be used for selection purposes towards the decoder. \n
                 *  NOTE This attribute is primarily introduced for the usage of Pre-Selections and Adaptation Sets, but future use for Representation and Sub-Representations is not precluded.    
                 *  @return     a string
                 */
                virtual std::string                                    GetTag                           () const = 0;

        };
    }
}

#endif /* IREPRESENTATIONBASE_H_ */