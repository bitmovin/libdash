/**
 *  @class      dash::mpd::IContentProtection
 *  @brief      This interface is needed for accessing the common attributes of <tt><b>ContentProtection</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, section 5.8.4.1
 *  @details    Content protection descriptors are signalled by the <b>ContentProtection</b> element and are used to provide content protection, encryption, and DRM related information in order to access encrypted and/or DRM-protected content. 
 *              The <b>ContentProtection</b> element is an extended descriptor type.\n
 *              For the element <b>ContentProtection</b>, the \c @schemeIdUri attribute is used to identify a content protection descriptor scheme. \n
 *              The <b>ContentProtection</b> descriptors is expected to provide sufficient information, possibly in conjunction with the \c @value and/or extension attributes and elements, such as the DRM system(s), encryption algorithm(s), and key distribution scheme(s) employed, to enable a client to determine whether it can possibly play the protected content. The <b>ContentProtection</b> element can be extended in a separate namespace to provide information specific to a content protection scheme (e.g. particular key management systems or encryption methods). \n
 *              When no <b>ContentProtection</b> element is present, the content shall not be encrypted. \n
 *              Subclause 5.8.5.2 exclusively defines schemes indicating the encryption scheme for different MPEG formats. In subclause 5.8.5.2.2, the MP4 protection scheme identified with \c @schemeIdUri set to \c "urn:mpeg:dash:mp4protection:2011" is defined. In subclause 5.8.5.2.3, the MPEG-2 TS protection scheme identified with \c @schemeIdUri set to \c "urn:mpeg:dash:13818:1:CA_descriptor:2011" is defined. These schemes merely indicate the encryption mode used in conjunction with one or more DRMs. Hence, it is recommended to provide the client with additional content protection information about the available DRMs. \n
 *              Additional <b>ContentProtection</b> elements with the \c @schemeIdURI attribute set to a URN not defined in subclause 5.8.5 must describe a specific key management and protection scheme that is sufficient to access and present the Representation. For such schemes, an optional \c @robustness attribute may be present, for details see subclause 5.8.4.1.2. \n
 *              The content protection information may be provided explicitly in a <b>ContentProtection</b> element or may be referenced from another <b>ContentProtection</b> element. For details refer to subclause 5.8.4.1.3. \n
 *              The semantics of the attributes within the <b>ContentProtection</b> element are provided in subclause 5.8.4.1.4, Table 30. The XML syntax of <b>ContentProtection</b> element is provided in subclause 5.8.4.1.5. \n
 *              Subclause 5.8.4.1.6 provides information on how to define a content protection scheme.
 *  @see        
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ICONTENTPROTECTION_H_
#define ICONTENTPROTECTION_H_

#include "config.h"

#include "IDescriptor.h"

namespace dash
{
    namespace mpd
    {
        class IContentProtection : public virtual IDescriptor
        {
            public:
                virtual ~IContentProtection(){}

                /**
                 *  Returns the reference to a string that specifies the robustness level required for this content protection scheme for accessing content represented by the associated Representation(s). For more details refer to subclause 5.8.4.1.2 and 5.8.4.1.6. \n
                 *  If not present, then the lowest robustness level for the identified content protection scheme applies. 
                 *  @return     a reference to a string
                 */
                virtual const std::string&            GetRobustness      ()  const = 0;
                
                /**
                 *  Returns the reference to a string that specifies an identifier of this descriptor. The identifier shall be unique within an MPD. \n
                 *  The attribute shall not be present if the \c @ref attribute is present.
                 *  @return     a reference to a string
                 */
                virtual const std::string&            GetRefId           ()  const = 0;
                
                /**
                 *  Returns the reference to a string that - if present - makes this a referencing content protection descriptor 
                 *  that inherits from a “source” content protection descriptor which is identified by the equivalent value of \c @refId attribute. For details, refer to subclause 5.8.4.1.3. \n
                 *  The attribute shall not be present if the \c @refId attribute is present.
                 *  @return     a reference to a string
                 */
                virtual const std::string&            GetRef             ()  const = 0;
        };
    }
}

#endif /* ICONTENTPROTECTION_H_ */