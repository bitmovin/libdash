/*
 * Resync.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef RESYNC_H_
#define RESYNC_H_

#include "config.h"

#include "IResync.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Resync : public IResync, public AbstractMPDElement
        {
            public:
                Resync             ();
                virtual ~Resync    ();

                uint32_t                GetType                 () const;
                uint32_t                GetDT                   () const;
                float                   GetDIMax                () const;
                float                   GetDIMin                () const;
                bool                    HasMarker               () const;

                void    SetType              (uint32_t type);
                void    SetDT                (uint32_t dT);
                void    SetDIMax             (float dIMax);
                void    SetDIMin             (float dIMin);
                void    SetMarker            (bool marker);

            private:
                uint32_t        type;
                uint32_t        dT;
                float           dIMax;
                float           dIMin;
                bool            marker;
        };
    }
}

#endif /* RESYNC_H_ */
