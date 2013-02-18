/**
 *  @class      dash::xml::INode
 *  @brief      This interface defines the access to class members of <em>XML Elements</em>.
 *  @details    Due to the fact that some MPD elements may contain additional <em>XML Elements</em>, which are not specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>
 *              but are attached to them, this interface is needed to access such an <em>XML Element</em>. \n\n
 *              For clarification see the example in dash::mpd::IMPDElement
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

#ifndef INODE_H_
#define INODE_H_

#include "config.h"

namespace dash
{
    namespace xml
    {
        class INode
        {
            public:
                virtual ~INode (){}

                /**
                 *  Returns a reference to a vector of pointers to nested dash::xml::INode objects.
                 *  @return     a reference to a vector containing pointers to dash::xml::INode objects.
                 */
                virtual const std::vector<INode *>&                 GetNodes            ()  const = 0;

                /**
                 *  Returns a vector of attribute names belonging to this <em>XML Element</em>
                 *  @return     a vector of strings
                 */
                virtual std::vector<std::string>                    GetAttributeKeys    ()  const = 0;

                /**
                 *  Returns the name of this <em>XML Element</em>
                 *  @return     a reference to string
                 */
                virtual const std::string&                          GetName             ()  const = 0;

                /**
                 *  Returns the text contained in this <em>XML Element</em>
                 *  @return     a string
                 */
                virtual std::string                                 GetText             ()  const = 0;

                /**
                 *  Returns a std::map of key value / mapped value pairs corresponding to the <em>XML Attributes</em> and their values of this <em>XML Element</em>
                 *  @return     a reference to a map with key values and mapped values, both of type std::string
                 */
                virtual const std::map<std::string, std::string>&   GetAttributes       ()  const = 0;

                /**
                 *  Returns the type of this <em>XML Element</em> represented by an integer
                 *  \code
                 *      Start       = 1
                 *      End         = 15
                 *      WhiteSpace  = 14
                 *      Text        = 3
                 *  \endcode
                 *  @return     an integer
                 */
                virtual int                                         GetType             ()  const = 0;

                /**
                 *  Returns the value belonging to the <em>XML Attribute</em> specified by key
                 *  @param      key     the name of the desired <em>XML Attribute</em>
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetAttributeValue   (std::string key) const = 0;

                /**
                 *  Returns a bool value determininig whether the <em>XML Attribute</em> name is contained in this <em>XML Element</em> or not.
                 *  @param      name    the name of the desired <em>XML Attribute</em>
                 *  @return     a bool value
                 */
                virtual bool                                        HasAttribute        (const std::string& name) const = 0;

                /**
                 *  Returns a bool value determining whether the <em>XML Element</em> has text or not.
                 *  @return     a bool value
                 */
                virtual bool                                        HasText             ()  const = 0;
        };
    }
}

#endif /* INODE_H_ */
