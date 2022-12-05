/**
 *  @class      dash::mpd::IPreselection
 *  @brief      This interface is needed for accessing the attributes of <tt><b>Preselection</b></tt>.
 *  @details    Preselections define user experiences that can be selected by the DASH Client. Each Preselection is uniquely identifiable and distinguishable, e.g. by language.
 *              A Preselection encompasses a subset of media components such that the media components can be selected and combined into a complete experience.\n
 *              Preselections can be used to reference a set of Representations from multiple Adaptation Sets in order to produce a complete experience.
 *              Preselections can also be used to indicate a pre-defined experience at the elementary-stream level, i.e. the DASH Client can select a pre-defined experience and provides the selection to the media engine.\n
 *              Preselections may be uniquely identified by a Preselection Tag. Users/Codecs using this Tag functionality are encouraged to provide more information on how tags defined in the MPD map to functionality in the specific codec.\n
 *              Preselections have equivalent annotation parameters to Adaptation Sets and are always assigned exactly one media type.\n 
 *              Media components can be mapped to Adaptation Sets in multiple ways:    
 *              <ol>
 *                  <li> by a one-to-one mapping between media components and Adaptation Sets;
 *                  <li> by the inclusion of multiple media components in a single Adaptation Set where all encoded versions of the media components are multiplexed on the file-container level;
 *                  <li> by the inclusion of multiple media components in a single Adaptation Set where all encoded versions of the media components are multiplexed on the elementary-stream level.
 *              </ol>
 *              If the Adaptation Set contains a single media component, then the media component can be referenced by the \c @id of the Adaptation Set.\n
 *              If the Adaptation Set contains multiple media components multiplexed on the file-container level, then each media component is mapped to a Content Component as defined in 5.3.4.
 *              For example, in the ISO BMFF case, a Representation contains multiple tracks and each track is mapped to a Content Component. Therefore, media components can be referenced by the \b @id of an Adaptation Set or the \b @id of a Content Component.
 *              When Preselections reference Content Components, the \c @id of Adaptation Sets and Content Components shall be unique within the scope of a Period.\n
 *              If the Adaptation Set contains multiple media components multiplexed at the elementary-stream level, then a pre-defined experience is referenced by the Preselection.
 *              For example, in the ISO BMFF case, a Representation contains a single track of multiple media components that is referenced by the \b @id of the Adaptation Set. 
 *              Multiple Preselections can reference the Adaptation Set and select a pre-defined experience by passing the Presentation Tag to the media engine along with the media stream.\n
 *              The Main Adaptation Set is the Adaptation Set that contains the Initialisation Segment for the complete experience. Each Preselection shall reference a Main Adaptation Set and may reference zero, one or more other Adaptation Sets.\n
 *              \b NOTE In the context of Preselection, the term "Main Adaptation Set" is used. This term is not to be confused with an Adaptation Set that has assigned the main Role.\n
 *              Within a Preselection, two types of Adaptation Sets are differentiated:
 *              <ul>
 *                  <li> Main Adaptation Set: A Representation of this Adaptation Set is needed for playback of the Preselection. In particular for ISO BMFF, the Initialization Segment of such a Representation is needed for playback of the Preselection.
 *                  <li> Partial Adaptation Set: A Representation of this Adaptation Set is only consumable together with the Main Adaptation Sets within this Preselection. Again, in particular for ISO BMFF, the Initialization Segment of a Representation of the Main Adaptation Set is needed for playback.
 *              </ul>
 *              Preselections, main Adaptation Set and partial Adaptation Sets may be defined by one of the two means:
 *              <ul>
 *                  <li> A preselection descriptor as specified in subclause 5.3.11.2. Such a descriptor enables simple configurations and preserves backward compatibility but may not be suitable for advanced use cases.
 *                  <li> A preselection element as specified in 5.3.11.3 and 5.3.11.4. The semantics of the Preselection element is provided in subclause 5.3.11.3 and the XML syntax is provided in 5.3.11.4. 
 *              </ul>
 *
 *  @see        dash::mpd::IDescriptor
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IPRESELECTION_H_
#define IPRESELECTION_H_

#include "config.h"

#include "IDescriptor.h"
#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class IPreselection : public virtual IRepresentationBase
        {
            public:
                virtual ~IPreselection(){}
                
                
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
                 *  Returns a reference to a string that specifies the id of the Preselection. This shall be unique within one Period.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetId                           ()  const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies the ids of the contained Adaptation Sets or Content Components that belong to this Preselection 
                 *  as white space separated list in processing order. The first id defines the Main Adaptation Set.    
                 *  
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&         GetPreselectionComponents       ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the language of the preselection as specified in in Table 5 for \c @lang attribute.
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetLang                         ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the conformance rules for Representations in Adaptation Sets within the Preselection.\n
                 *  When set to '<b>undefined</b>', the Preselection follows the conformance rules for Multi-Segment Tracks in subclause 5.3.11.5.1.\n
                 *  When set to 'time-ordered', the Preselection follows the conformance rules for Time-Ordered Segment Tracks in subclause 5.3.11.5.2.\n
                 *  When set to 'fully-ordered', the Preselection follows the conformance rules for Fully-Ordered Segment Tracks in subclause 5.3.11.5.3. 
                 *  In this case, order in the \c @preselectionComponents attribute specifies the component order.    
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&                      GetOrder                        ()  const = 0;
                            
        };
    }
}

#endif /* IPRESELECTION_H_ */