/**
 *  @class      dash::mpd::IInitializationSet
 *  @brief      This interface is needed for accessing the attributes of <tt><b>InitializationSet</b></tt>.
 *  @details    An Initialization Set provides a common set of media properties across Periods in a Media Presentation. 
 *              If an Initialization Set with certain properties is provided in an MPD, there shall be at least one Adaptation Set in at least one Period with these properties.
 *              More importantly, it can also be indicated that all Periods in the Media Presentations include at least one Adaptation Set that follows the properties of the Initialization Set.
 *              Especially in the latter case an Initialization Set can be selected at the start of a Media Presentation in order to establish the relevant decryption, decoding and rendering environment.
 *              This provides expected consistent playback behaviour for the DASH Client if it selects only Adaptation Sets that are included in the selected Initialization Set.\n
 *              The semantical definition of Initialization Sets shares all parameters of Adaptation Sets, but an Initialization Set may only include a subset of those parameters.
 *              An Adaptation Set referring to an Initialization Set that it conforms to may include additional information, for example:\n
 *              <ul>
 *                  <li> There may be an Initialization Set with media type audio and a \c @codecs parameter, but without a \c @lang attribute. 
 *                       Then each Period includes at least one Adaptation Set with the same media type, the same \c @codecs parameter, but each of the Adaptation Sets defines a different language for each Period.
 *                       This ensures that initialization of an audio playback decoder is possible, but over Period boundaries, the language may change, or additional languages may be added.
 *                  <li> There may be an Initialization Set with media type video and \c @maxWidth and \c @maxHeight parameter and a \c @codecs parameter. Then at least one Period includes at least one Adaptation Set with the same media type, 
 *                       but its actual codecs parameters and the \c @maxWidth and \c @maxHeight may be different than the ones in the Initialization Set, but can be decoded and displayed within the Initialization Set constraints. 
 *              </ul> 
 *              An Initialization Set may get assigned a specific profile using the \c @profiles parameter in order to express conformance to DASH profiles or Interoperability Points. \n
 *              If an MPD has multiple Periods, there should be at least one Initialization Set be present for each media type. \n
 *              The semantics of the attributes and elements within an \b InitializationSet element are provided in subclause 5.3.12.2, Table 26. The XML syntax of the \b InitializationSet element is provided in subclause 5.3.12.3.    
 *  @see        dash::mpd::IDescriptor
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IINITIALIZATIONSET_H_
#define IINITIALIZATIONSET_H_

#include "config.h"

#include "IDescriptor.h"
#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class IInitializationSet : public virtual IRepresentationBase
        {
            public:
                virtual ~IInitializationSet(){}
                
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information about accessibility scheme.\n
                 *  For more details refer to sections 5.8.1 and 5.8.4.3. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetAccessibility                ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on role annotation scheme.
                 *  For more details refer to sections 5.8.1 and 5.8.4.2. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetRole                         ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on rating scheme.\n
                 *  For more details refer to sections 5.8.1 and 5.8.4.4. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetRating                       ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on viewpoint annotation scheme.\n
                 *  For more details refer to sections 5.8.1 and 5.8.4.5. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&       GetViewpoint                    ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies a reference to a remote element entity that shall contain exactly one element of type \b InitializationSet.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkHref                    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the processing instructions, which can be either \c \"onLoad\" or \c \"onRequest\".
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkActuate                 ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the the type of link.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetXlinkType                    ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies a unique identifier for this Initialization Set. 
                 *  The attribute shall be a unique unsigned integer value amongst all InitializationSet and InitializationGroup ids in the scope of the MPD.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetId                           ()  const = 0;
                
                /**
                 *  If set to \b true, then there is at least one Adaptation Set in each Period of the Media Presentation that conforms to this Initialization Set.
                 *  
                 *  @return     a bool value
                 */
                virtual bool                                    IsInAllPeriods                  ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the media content component type for this Initialization Set. 
                 *  A value of the top-level Content-type 'type' value as defined in IETF RFC 6838:2013, Clause 4 shall be taken. \n
                 *  If not present, the media content component type may be defined for each media component or it may be unknown.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetContentType                  ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the picture aspect ratio of the video media component type, in the form of a string consisting of two integers separated by ':', e.g.,"16:9". 
                 *  When this attribute is present, and the attributes \c @width and \c @height for the Representations of Adaptation Sets conforming to this Initialization Set are also present, 
                 *  the picture aspect ratio as specified by this attribute shall be the same as indicated by the values of \c @width, \c @height, and \c @sar, i.e. it shall express the same ratio as (\c@width * sarx):(\c@height * sary), with sarx the first number in \c @sar and sary the second number. \n
                 *  If not present, the picture aspect ratio may be defined for each media component or it may be unknown.    
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetPar                          ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the maximum \c @width value in all Representations in all Adaptation Sets associated to this Initialization Set. 
                 *  This value has the same units as the \c @width attribute. \n
                 *  If not present, the value is unknown.
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMaxWidth                     ()  const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies the maximum \c @height value in all Representations in all Adaptation Sets associated to this Initialization Set.
                 *  This value has the same units as the \c @height attribute. \n
                 *  If not present, the value is unknown.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                GetMaxHeight                    ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the maximum \c @framerate value in all Representations in all Adaptation Sets associated to this Initialization Set.
                 *  This value is encoded in the same format as the \c @frameRate attribute. \n
                 *  If not present, the value is unknown.    
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetMaxFrameRate                 ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the URL of an Initialization Segment.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetInitialization               ()  const = 0;
                            
        };
    }
}

#endif /* IINITIALIZATIONSET_H_ */