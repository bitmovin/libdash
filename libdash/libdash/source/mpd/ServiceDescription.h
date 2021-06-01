/*
 * ServiceDescription.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SERVICEDESCRIPTION_H_
#define SERVICEDESCRIPTION_H_

#include "config.h"

#include "IServiceDescription.h"
#include "AbstractMPDElement.h"
#include "Descriptor.h"
#include "Latency.h"
#include "PlaybackRate.h"
#include "OperatingQuality.h"
#include "OperatingBandwidth.h"

namespace dash
{
    namespace mpd
    {
        class ServiceDescription : public IServiceDescription, public AbstractMPDElement
        {
            public:
                ServiceDescription             ();
                virtual ~ServiceDescription    ();

                const std::vector<IDescriptor *>&          GetScope                  ()  const;
                const std::vector<ILatency *>&             GetLatency                ()  const;
                const std::vector<IPlaybackRate *>&        GetPlaybackRate           ()  const;
                const std::vector<IOperatingQuality *>&    GetOperatingQuality       ()  const;
                const std::vector<IOperatingBandwidth *>&  GetOperatingBandwidth     ()  const;
                uint32_t                                   GetId                     ()  const;

                void    AddScope                 (Descriptor* scope);
                void    AddLatency               (Latency* latency);
                void    AddPlaybackRate          (PlaybackRate* playbackRate);
                void    AddOperatingQuality      (OperatingQuality* operatingQuality);
                void    AddOperatingBandwidth    (OperatingBandwidth* operatingBandwidth);
                void    SetId                    (uint32_t id);

            private:
                std::vector<IDescriptor *>           scope;
                std::vector<ILatency *>              latency;
                std::vector<IPlaybackRate *>         playbackRate;
                std::vector<IOperatingQuality *>     operatingQuality;
                std::vector<IOperatingBandwidth *>   operatingBandwidth;
                uint32_t                             id;
                
        };
    }
}

#endif /* SERVICEDESCRIPTION_H_ */
