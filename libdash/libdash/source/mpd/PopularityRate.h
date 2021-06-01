/*
 * PopularityRate.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef POPULARITYRATE_H_
#define POPULARITYRATE_H_

#include "config.h"

#include "IPopularityRate.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class PopularityRate : public IPopularityRate, public AbstractMPDElement
        {
            public:
                PopularityRate             ();
                virtual ~PopularityRate    ();

                uint8_t                     GetPopularityRate    ()  const;
                uint64_t                    GetStart             ()  const;
                int32_t                     GetR                 ()  const;

                void    SetPopularityRate   (uint8_t popularityRate);
                void    SetStart            (uint64_t start);
                void    SetR                (int32_t r);

            private:
                uint8_t   popularityRate;
                uint64_t  start;
                int32_t   r;
        };
    }
}

#endif /* POPULARITYRATE_H_ */
