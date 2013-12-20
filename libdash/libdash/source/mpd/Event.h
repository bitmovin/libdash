/*
 * Event.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung GmbH, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef EVENT_H_
#define EVENT_H_

#include "config.h"

#include "IEvent.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Event : public IEvent, public AbstractMPDElement
        {
            public:
                Event             ();
                virtual ~Event    ();

                uint64_t    GetPresentationTime   ()  const;
                uint64_t    GetDuration           ()  const;
                uint32_t    GetId                 ()  const;

                void    SetPresentationTime (uint64_t presentationTime);
                void    SetDuration         (uint64_t duariont);
                void    SetId               (uint32_t id);

            private:
                uint64_t    presentationTime;
                uint64_t    duration;
                uint32_t    id;
        };
    }
}

#endif /* EVENT_H_ */
