/**
 *  @class      dash::mpd::IRepresentationBase
 *  @brief      This interface is needed for accessing the common attributes and elements of the certain MPD element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.7
 *  @details    The elements \c <b>AdaptationSet</b>, \c <b>Representation</b> and \c <b>SubRepresentation</b> have assigned common attributes and elements that are specified in 
 *              <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.7.2, table 9
 *  @see        dash::mpd::IDescriptor dash::mpd::IMPDElement
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IREPRESENTATIONBASE_H_
#define IREPRESENTATIONBASE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"

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
                virtual const std::vector<IDescriptor *>&   GetFramePacking                 () const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specifies the audio channel configuration of the audio media component type.\n
                 *  For further details see sections 5.8.1 and 5.8.4.7 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&   GetAudioChannelConfiguration    () const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specifies information about content protection schemes used for the associated Representations.\n
                 *  For further details see sections 5.8.1 and 5.8.4.1 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&   GetContentProtection            () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the profiles which the associated Representation(s) 
                 *  conform to of the list of Media Presentation profiles as described in section 8 of <em>ISO/IEC 23009-1, Part 1, 2012</em>. 
                 *  The value shall be a subset of the respective value in any higher level of the document hierarchy (Representation, Adaptation Set, MPD).\n
                 *  If not present, the value is inferred to be the same as in the next higher level of the document hierarchy. 
                 *  For example, if the value is not present for a Representation, then \c \@profiles at the Adaptation Set level is valid for the Representation.\n
                 *  The same syntax as defined in 5.3.1.2 shall be used.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&     GetProfiles                     () const = 0;

                /**
                 *  Returns an integer that specifies the horizontal visual presentation size of the video 
                 *  media type on a grid determined by the \c \@sar attribute. \n\n
                 *  In the absence of \c \@sar width and height are specified as if the value of \c \@sar were \"1:1\".\n
                 *  \b NOTE:    The visual presentation size of the video is equal to the number of horizontal and vertical samples used for presentation 
                 *  after encoded samples are cropped in response to encoded cropping parameters, “overscan” signaling, or “pan/scan” display parameters, e.g. SEI messages.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                            GetWidth                        () const = 0;

                /**
                 *  Returns an integer that specifies the vertical visual presentation size of the video 
                 *  media type, on a grid determined by the \c \@sar attribute.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                            GetHeight                       () const = 0;

                /**
                 *  Returns a string that specifies the sample aspect ratio of the video media component type, 
                 *  in the form of a string consisting of two integers separated by ':', e.g., \"10:11\". 
                 *  The first number specifies the horizontal size of the encoded video pixels (samples) in arbitrary units. 
                 *  The second number specifies the vertical size of the encoded video pixels (samples) in same units as the horizontal size.
                 *  @return     a string
                 */
                virtual std::string                         GetSar                          () const = 0;

                /**
                 *  Returns a string that specifies the output frame rate (or in the case of interlaced, half the output field rate) 
                 *  of the video media type in the Representation. If the frame or field rate is varying, the value is the average frame 
                 *  or half the average field rate field rate over the entire duration of the Representation.\n
                 *  The value is coded as a string, either containing two integers separated by a \"/\", (\"F/D\"), or a single integer \"F\".
                 *  The frame rate is the division F/D, or F, respectively, per second (i.e. the default value of D is \"1\").
                 *  @return     a string
                 */
                virtual std::string                         GetFrameRate                    () const = 0;

                /**
                 *  Returns a string that represents an audio sampling rate. \n
                 *  Either a single decimal integer value specifying the sampling rate or a whitespace separated pair of decimal integer 
                 *  values specifying the minimum and maximum sampling rate of the audio media component type. The values are in samples per second.
                 *  @return     a string
                 */
                virtual std::string                         GetAudioSamplingRate            () const = 0;

                /**
                 *  Returns a string that specifies the MIME type of the concatenation of the Initialization Segment, if present, 
                 *  and all consecutive Media Segments in the Representation.
                 *  @return     a string
                 */
                virtual std::string                         GetMimeType                     () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the profiles of Segments that are essential to process the Representation. 
                 *  The detailed semantics depend on the value of the \c \@mimeType attribute. The contents of this attribute shall conform to either the 
                 *  \c pro-simple or \c pro-fancy productions of RFC6381, Section 4.5, without the enclosing \c DQUOTE characters, 
                 *  i.e. including only the \c unencodedv or \c encodedv elements respectively. 
                 *  As profile identifier the brand identifier for the Segment as defined in section 6 of <em>ISO/IEC 23009-1, Part 1, 2012</em> shall be used.\n
                 *  If not present on any level, the value may be deducted from the value of the\c \@profiles attribute.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&     GetSegmentProfiles              () const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the codecs present within the Representation. 
                 *  The codec parameters shall also include the profile and level information where applicable. \n
                 *  The contents of this attribute shall conform to either the \c simp-list or \c fancy-list productions of RFC6381, Section 3.2, 
                 *  without the enclosing \c DQUOTE characters. The codec identifier for the Representation's media format, 
                 *  mapped into the name space for codecs as specified in RFC6381, Section 3.3, shall be used.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&     GetCodecs                       () const = 0;

                /**
                 *  Returns a double value specifying the maximum SAP interval in seconds of all contained media streams,
                 *  where the SAP interval is the maximum time interval between the T<sub>SAP</sub> of any two successive SAPs of types 1 to 3 
                 *  inclusive of one media stream in the associated Representations.
                 *  @return     a double
                 */
                virtual double                              GetMaximumSAPPeriod             () const = 0;

                /**
                 *  Returns an unsigned integer that (when greater than 0) specifies that in the associated Representations, 
                 *  each Media Segment starts with a SAP of type less than or equal to the value of this attribute value in each media stream.
                 *  @return     an unsigned integer
                 */
                virtual uint8_t                             GetStartWithSAP                 () const = 0;

                /**
                 *  Returns a double that specifies the maximum playout rate as a multiple of the regular playout rate,
                 *  which is supported with the same decoder profile and level requirements as the normal playout rate.
                 *  @return     a double
                 */
                virtual double                              GetMaxPlayoutRate               () const = 0;

                /**
                 *  Returns a bool value that informs about coding dependency.\n
                 *  If \c 'true', for all contained media streams, specifies that there is at least one access unit that depends on one or more other access units for decoding.
                 *  If \c 'false', for any contained media stream, there is no access unit that depends on any other access unit for decoding (e.g. for video all the pictures are intra coded). \n
                 *  If not specified on any level, there may or may not be coding dependency between access units.
                 *  @return     a bool value
                 */
                virtual bool                                HasCodingDependency             () const = 0;

                /**
                 *  Returns a string that specifies the scan type of the source material of the video media component type. 
                 *  The value may be equal to one of \c \"progressive\", \c \"interlaced\" and \c \"unknown\".
                 *  @return     a string
                 */
                virtual std::string                         GetScanType                     () const = 0;

        };
    }
}

#endif /* IREPRESENTATIONBASE_H_ */