/*
 * UIntPairs.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef UINTPAIRS_H_
#define UINTPAIRS_H_

#include "config.h"

#include "IUIntPairs.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class UIntPairs : public IUIntPairs, public AbstractMPDElement
        {
            public:
                UIntPairs             ();
                virtual ~UIntPairs    ();

                uint32_t    GetLatency    ()  const;
                uint32_t    GetQuality    ()  const;

                void    SetLatency    (uint32_t latency);
                void    SetQuality    (uint32_t quality);

            private:
                uint32_t    latency;
                uint32_t    quality;
                
        };
    }
}

#endif /* UINTPAIRS_H_ */
