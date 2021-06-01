/*
 * Latency.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LATENCY_H_
#define LATENCY_H_

#include "config.h"

#include "ILatency.h"
#include "UIntPairsWithID.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Latency : public ILatency, public AbstractMPDElement
        {
            public:
                Latency             ();
                virtual ~Latency    ();

                const std::vector<IUIntPairsWithID *>&     GetQualityLatencyType         ()  const;
                uint32_t                                   GetReferenceId                ()  const;
                uint32_t                                   GetTarget                     ()  const;
                uint32_t                                   GetMax                        ()  const;
                uint32_t                                   GetMin                        ()  const;

                void    AddQualityLatencyType    (UIntPairsWithID* qlt);
                void    SetReferenceId           (uint32_t referenceId);
                void    SetTarget                (uint32_t target);
                void    SetMax                   (uint32_t max);
                void    SetMin                   (uint32_t min);

            private:
                std::vector<IUIntPairsWithID *>   qltpairs;
                uint32_t                          referenceId;
                uint32_t                          target;
                uint32_t                          max;
                uint32_t                          min;
                
        };
    }
}

#endif /* LATENCY_H_ */
