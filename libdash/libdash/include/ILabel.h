/**
 *  @class      dash::mpd::ILabel
 *  @brief      This interface is needed for accessing the attributes of <tt><b>Label</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause 5.3.10.2, Table 23-24.
 *  @details    Labels provide the ability to annotate data structures in a DASH Media Presentation by providing a short textual description of the parent element.
 *              Labels can be used for the purpose of interaction and configuration settings within a DASH Client or associated application.
 *              For example, the Label element can be used to provide a selection menu to the user. GroupLabel may be added on a higher level to provide a summary or title of labels collected in a group.
 *              For example, GroupLabel can be used as the title on a selection menu containing a collection of labels. Labels with the same value for the \c @id attribute belong to a label group.
 *              All labels with the same \c @id shall be on the same level in the MPD. The \c @lang attribute assigned to a label describes the language of that label. 
 *              For example, the \c @lang attribute can be used by the DASH Client to filter labels according to user language preferences. 
 *              The semantics of the label element and the group label element are provided in Table 23 and Table 24, respectively, in subclause 5.3.10.2, the XML syntax is provided in subclause 5.3.10.3.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ILABEL_H_
#define ILABEL_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ILabel : public virtual IMPDElement
        {
            public:
                virtual ~ILabel(){}

                /**
                 *  For Label:
                 *  Returns an integer that specifies an identifier for the label. Labels with the same value for this attribute belong to a label group.    
                 *
                 *  For GroupLabel:
                 *  Returns an integer that specifies an identifier for the group label. The value for this attribute shall be unique for all group labels in the MPD.
                 *  The value of this attribute shall be the same as the id attribute of all Label elements in the label group.
                 *
                 *  @return     an unsigned integer
                 */
                virtual uint32_t             GetId       ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the language of the label.
                 *  If not present, the language of the label is unknown.    
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetLang     ()  const = 0;
                
        };
    }
}

#endif /* ILABEL_H_ */