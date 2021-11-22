/**
 *  @class      dash::mpd::IExtendedBandwidth
 *  @brief      This interface is needed for accessing the common attributes and elements of <tt><b>ExtendedBandwidth</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, section 5.3.5.6
 *  @details    Subclause 5.3.5.4 provides a detailed overview on the usage of \c @minBufferTime and \c @bandwidth for determining the bitrate properties of the associated Representation. However, this model does not expose certain extended bandwidth properties of the Representation, for example the nature of the encoding being variable bitrate, or any bitrate properties over different time windows. \n
 *              For this purpose, each Represention have assigned an extended bandwidth signalling providing additional properties of the Representation. This information is provided as part of the <b>ExtendedBandwidth</b> element as defined in Table 12.
 *  @see        dash::mpd::IModelPair
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IEXTENDEDBANDWIDTH_H_
#define IEXTENDEDBANDWIDTH_H_

#include "config.h"

#include "IMPDElement.h"
#include "IModelPair.h"

namespace dash
{
    namespace mpd
    {
        class IExtendedBandwidth : public virtual IMPDElement
        {
            public:
                virtual ~IExtendedBandwidth(){}

                /**
                 *  Returns a pointer to a vector of dash::mpd::IModelPair objects, each of which defines an extended bandwidth model pair that applies for the Representation.
                 *  @return     a pointer to a vector of dash::mpd::IModelPair objects
                 */
                virtual const std::vector<IModelPair *>&       GetModelPairs      ()  const = 0;
                
                /**
                 *  Returns a boolean that - if set to <b>true</b> - assure that the content is encoded to primarily have a constant or consistent quality, while at the same time when the signal restrictions on <b>MPD</b>@minBufferTime and <b>Representation</b>@bandwidth attributes are reached, the quality of the content may drop. 
                 *  In cases where is cap is not reached, the quality of the content is expected to be consistent. \n
                 *  If set to <b>false</b> or not present, no information on the nature of the encoding is present. \n
                 *  \t NOTE: the signalling set to true implies that the actual instantaneous bitrate can frequently be below the maximum. 
                 *  @return     a boolean
                 */
                virtual bool                                   GetVbr             ()  const = 0;
        };
    }
}

#endif /* IEXTENDEDBANDWIDTH_H_ */