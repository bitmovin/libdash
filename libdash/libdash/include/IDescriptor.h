/**
 *  @class      dash::mpd::IDescriptor
 *  @brief      This interface is needed for accessing the attributes of the <tt><b>Descriptor</b></tt> type as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.8.2, table 21
 *  @details    The MPD may contain descriptors that make use of a common syntax as defined in this subclause.
 *              The elements of type \c DescriptorType provide a flexible mechanism for DASH content authors to annotate 
 *              and extend the \c <b>MPD</b>, \c <b>Period</b>, \c <b>AdaptationSet</b> and \c <b>Representation</b> elements.\n
 *              The descriptor elements are all structured in the same way, namely they contain a \c \@schemeIdUri attribute that provides a URI to identify the scheme and 
 *              an optional attribute \c \@value. The semantics of the element are specific to the scheme employed. The URI identifying the scheme may be a URN or a URL.\n
 *              In <em>ISO/IEC 23009-1, Part 1, 2012</em>, specific elements for descriptors are defined in section 5.8.4.\n
 *              The MPD does not provide any specific information on how to use these elements. It is up to the application that employs DASH formats 
 *              to instantiate the description elements with appropriate scheme information. However, this part of ISO/IEC 23009 defines some specific schemes in 5.8.5.\n
 *              DASH applications that use one of these elements must first define a Scheme Identifier in the form of a URI and must then define the value space 
 *              for the element when that Scheme Identifier is used. The Scheme Identifier appears in the \c \@schemeIdUri attribute.
 *              In the case that a simple set of enumerated values are required, a text string may be defined for each value and this string must be included 
 *              in the \c \@value attribute. If structured data is required then any extension element or attribute may be defined in a separate namespace.\n
 *              Two elements of type DescriptorType are equivalent, if the element name, the value of the \c \@schemeIdUri and the value of the \c \@value attribute are equivalent.
 *              If the \c \@schemeIdUri is a URN, then equivalence shall refer to lexical equivalence as defined in clause 5 of RFC 2141. If the \c \@schemeIdUri is a URL, 
 *              then equivalence shall refer to equality on a character-for-character basis as defined in clause 6.2.1 of RFC3986. 
 *              If the \c \@value attribute is not present, equivalence is determined by the equivalence for \c \@schemeIdUri only. 
 *              Attributes and element in extension namespaces are not used for determining equivalence.
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

#ifndef IDESCRIPTOR_H_
#define IDESCRIPTOR_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IDescriptor : public virtual IMPDElement
        {
            public:
                virtual ~IDescriptor(){}

                /**
                 *  Returns a reference to a string that specifies a URI to identify the scheme. \n
                 *  The semantics of this element are specific to the scheme specified by this attribute.
                 *  The \c \@schemeIdUri may be a URN or URL. When a URL is used, it should also contain a month-date in the form 
                 *  mmyyyy; the assignment of the URL must have been authorized by the owner of the domain name in that URL on 
                 *  or very close to that date, to avoid problems when domain names change ownership.
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetSchemeIdUri  () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the value for the descriptor element. \n
                 *  The value space and semantics must be defined by the owners of the scheme identified in the \c \@schemeIdUri attribute.
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetValue        () const = 0;
        };
    }
}

#endif /* IDESCRIPTOR_H_ */