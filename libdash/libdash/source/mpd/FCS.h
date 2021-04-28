/*
 * FCS.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 *
 * Email: lorenzidaniele.97@gmail.com
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

                uint32_t    GetPresentationTime    ()  const;
                uint32_t    GetDuration            ()  const;

                void    SetPresentationTime    (uint32_t presentationTime);
                void    SetDuration            (uint32_t duration);

            private:
                uint32_t    presentationTime;
                uint32_t    duration;
        };
    }
}

#endif /* IFCS_H_ */
