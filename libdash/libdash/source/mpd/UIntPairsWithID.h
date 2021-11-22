/*
 * UIntPairsWithID.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef UINTPAIRSWITHID_H_
#define UINTPAIRSWITHID_H_

#include "config.h"

#include "IUIntPairsWithID.h"
#include "UIntPairs.h"
#include "AbstractMPDElement.h"
#include "../helpers/String.h"

namespace dash
{
    namespace mpd
    {
        class UIntPairsWithID : public IUIntPairsWithID, public AbstractMPDElement
        {
            public:
                UIntPairsWithID             ();
                virtual ~UIntPairsWithID    ();

                const std::vector<IUIntPairs *>&     GetQualityLatency         ()  const;
                const std::string&                   GetType                   ()  const;

                void    AddQualityLatency    (const std::string& ql);
                void    SetType              (const std::string& type);

            private:
                std::vector<IUIntPairs *>   qlpairs;
                std::string                 type;
                
        };
    }
}

#endif /* UINTPAIRSWITHID_H_ */
