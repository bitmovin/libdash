/*
 * ModelPair.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef MODELPAIR_H_
#define MODELPAIR_H_

#include "config.h"

#include "IModelPair.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ModelPair : public IModelPair, public AbstractMPDElement
        {
            public:
                ModelPair           ();
                virtual ~ModelPair  ();

                const std::string&                  GetBufferTime          ()  const;
                uint64_t                            GetBandwidth           ()  const;

                void    SetBufferTime         (const std::string& bufferTime);
                void    SetBandwidth          (uint64_t bandwidth);

            private:
                std::string              bufferTime;
                uint64_t                 bandwidth;
        };
    }
}

#endif /* MODELPAIR_H_ */
