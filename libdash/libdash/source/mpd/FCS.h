/*
 * FCS.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef FCS_H_
#define FCS_H_

#include "config.h"

#include "IFCS.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class FCS : public IFCS, public AbstractMPDElement
        {
            public:
                FCS             ();
                virtual ~FCS    ();

                uint64_t    GetPresentationTime    ()  const;
                uint64_t    GetDuration            ()  const;

                void    SetPresentationTime    (uint64_t presentationTime);
                void    SetDuration            (uint64_t duration);

            private:
                uint64_t    presentationTime;
                uint64_t    duration;
        };
    }
}

#endif /* IFCS_H_ */
