/*
 * ExtendedBandwidth.h
 ******************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef EXTENDEDBANDWIDTH_H_
#define EXTENDEDBANDWIDTH_H_

#include "config.h"

#include "IExtendedBandwidth.h"
#include "AbstractMPDElement.h"
#include "ModelPair.h"

namespace dash
{
    namespace mpd
    {
        class ExtendedBandwidth : public IExtendedBandwidth, public AbstractMPDElement
        {
            public:
                ExtendedBandwidth             ();
                virtual ~ExtendedBandwidth    ();

                const std::vector<IModelPair *>&   GetModelPairs           ()  const;
                bool                               GetVbr                  ()  const;

                void    AddModelPair                (ModelPair *modelPair);
                void    SetVbr                      (bool vbr);

            private:
                std::vector<ModelPair *> modelPairs;
                bool                     vbr;
        };
    }
}

#endif /* EXTENDEDBANDWIDTH_H_ */
