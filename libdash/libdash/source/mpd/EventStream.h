/*
 * EventStream.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung GmbH, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef EVENTSTREAM_H_
#define EVENTSTREAM_H_

#include "config.h"

#include "IEventStream.h"
#include "AbstractMPDElement.h"
#include "Event.h"

namespace dash
{
    namespace mpd
    {
        class EventStream : public IEventStream, public AbstractMPDElement
        {
            public:
                EventStream             ();
                virtual ~EventStream    ();

                const std::string&              GetXlinkHref    ()  const;
                const std::string&              GetXlinkActuate ()  const;
                const std::string&              GetSchemeIdUri  ()  const;
                const std::string&              GetValue        ()  const;
                uint32_t                        GetTimescale    ()  const;
                const std::vector<IEvent *>&    GetEvents       ()  const;

                void    SetXlinkHref    (const std::string& xlinkHref);
                void    SetXlinkActuate (const std::string& xlinkActuate);
                void    SetSchemeIdUri  (const std::string& schemeIdUri);
                void    SetValue        (const std::string& value);
                void    SetTimescale    (const uint32_t timescale);
                void    AddEvent        (Event *newEvent);

            private:
                std::string             xlinkHref;
                std::string             xlinkActuate;
                std::string             schemeIdUri;
                std::string             value;
                uint32_t                timescale;
                std::vector<Event *>    events;
        };
    }
}

#endif /* EVENTSTREAM_H_ */
