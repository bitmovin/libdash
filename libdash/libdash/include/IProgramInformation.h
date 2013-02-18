/**
 *  @class      dash::mpd::IProgramInformation
 *  @brief      This interface is needed for accessing the attributes and elements of the Program Information element as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.7.2, table 20
 *  @details    Descriptive information on the program may be provided for a Media Presentation within the <tt><b>ProgramInformation</b></tt> element.
 *              When multiple <tt><b>ProgramInformation</b></tt> elements are present, the \c \@lang attribute shall be present and 
 *              each element shall describe the Media Presentation sufficiently in the language defined by the value of the \c \@lang attribute.
 *              For each language, the program information may specify title, source of the program, copyright information, and a URL to more information.
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

#ifndef IPROGRAMINFORMATION_H_
#define IPROGRAMINFORMATION_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IProgramInformation : public virtual IMPDElement
        {
            public:
                virtual ~IProgramInformation(){}

                /**
                 *  Returns a reference to a string that specifies the title for the Media Presentation.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetTitle                ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies information about the original source (for example content provider) of the Media Presentation.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetSource               ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies a copyright statement for the Media Presentation, usually starting with the copyright symbol, unicode \c U+00A9.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetCopyright            ()  const = 0;

                /**
                 *  Returns a reference to a string that declares the language code(s) for this Program Information. The syntax and semantics according to <em>IETF RFC 5646</em> shall be applied.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetLang                 ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies an absolute URL which provides more information about the Media Presentation.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetMoreInformationURL   ()  const = 0;

        };
    }
}

#endif /* IPROGRAMINFORMATION_H_ */