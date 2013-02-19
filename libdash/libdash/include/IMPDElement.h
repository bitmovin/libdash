/**
 *  @class      dash::mpd::IMPDElement
 *  @brief      This interface is needed for accessing additional nested <em>XML Elements</em> and <em>XML Attributes</em> of some MPD Classes.
 *  @details    Due to the fact that some MPD classes may contain additional <em>XML Elements</em>, which are not specified in <em>ISO/IEC 23009-1, Part 1, 2012</em> 
 *              but are attached to them, this interface is needed for retrieving these <em>XML Elements</em>. \n\n
 *              See example below for clarification (inspired by the example from section G.7 of <em>ISO/IEC 23009-1, Part 1, 2012</em>).\n
 *              \code{.xml}
 *                  <ContentProtection schemeIdUri="http://example.net/052011/drm" additionalAttribute="abc">
 *                      <drm:License>http://MoviesSP.example.com/protect?license=kljklsdfiowek</drm:License>
 *                      <drm:Content>http://MoviesSP.example.com/protect?content=oyfYvpo8yFyvyo8f</drm:Content>
 *                  </ContentProtection>
 *              \endcode
 *              \em ContentProtection is of type <tt><b>DescriptorType</b></tt> which is defined in section 5.8.3 of <em>ISO/IEC 23009-1, Part 1, 2012</em> as follows:
 *              \code{.xml}
 *                  <!-- Descriptor -->
 *                  <xs:complexType name="DescriptorType">
 *                      <xs:sequence>
 *                          <xs:any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
 *                      </xs:sequence>
 *                      <xs:attribute name="schemeIdUri" type="xs:anyURI" use="required"/>
 *                      <xs:attribute name="value" type="xs:string"/>
 *                      <xs:anyAttribute namespace="##other" processContents="lax"/>
 *                  </xs:complexType>
 *              \endcode
 *              So <tt><b>ContentProtection</b></tt> can contain additional <em>XML Elements</em> - here <tt><b>License</b></tt> and <tt><b>Content</b></tt> - 
 *              which are of type dash::xml::INode and can be retrieved by calling GetAdditionalSubNodes(). \n
 *              Similarly additional <em>XML Attributes</em> that are not specified in <em>ISO/IEC 23009-1, Part 1, 2012</em> 
 *              can be retrieved by calling GetRawAttributes(), but please mind that all attributes 
 *              of the Element are returned, not just the additional ones. So in the example above both
 *              attributes \c schemeIDUri (which is specified) and \c additionalAttribute (which is not) are returned.
 *  @see        dash::xml::INode
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IMPDELEMENT_H_
#define IMPDELEMENT_H_

#include "config.h"

#include "INode.h"

namespace dash
{
    namespace mpd
    {
        class IMPDElement
        {
            public:
                virtual ~IMPDElement (){}
                
                /**
                 *  This method returns a vector of pointers to dash::xml::INode objects which correspond to additional <em>XML Elements</em> of certain
                 *  MPD elements. These <em>XML Elements</em> are not specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>. \n
                 *  See the example in the class description for details.
                 *  @return     a vector of pointers to dash::xml::INode objects
                 */
                virtual const std::vector<xml::INode *>             GetAdditionalSubNodes   ()  const = 0;
                
                /**
                 *  This method returns a map with key values and mapped values of type std::string of all <em>XML Attributes</em> of certain MPD elements. \n
                 *  Some of these <em>XML Attributes</em> are not specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>. \n
                 *  See the example in the class description for details.
                 *  @return     a map with key values and mapped values, both of type std::string
                 */
                virtual const std::map<std::string, std::string>    GetRawAttributes        ()  const = 0;
        };
    }
}

#endif /* IMPDELEMENT_H_ */
