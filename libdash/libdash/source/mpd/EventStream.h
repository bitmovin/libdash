/*
 * EventStream.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
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

                const std::vector<IEvent *>& GetEvents                 ()  const;
                const std::string&           GetXlinkHref              ()  const;
                const std::string&           GetXlinkActuate           ()  const;
                const std::string&           GetSchemeIdUri            ()  const;
                const std::string&           GetValue                  ()  const;
                uint32_t                     GetTimescale              ()  const;
                uint64_t                     GetPresentationTimeOffset ()  const;

                void    AddEvent                    (Event *event);
                void    SetXlinkHref                (const std::string& xlinkHref);
                void    SetXlinkActuate             (const std::string& xlinkActuate);
                void    SetSchemeIdUri              (const std::string& schemeIdUri);
                void    SetValue                    (const std::string& value);
                void    SetTimescale                (uint32_t timescale);
                void    SetPresentationTimeOffset   (uint64_t presentationTimeOffset);

            protected:
                std::vector<Event *>  events;
                std::string           xlinkHref;
                std::string           xlinkActuate;
                std::string           schemeIdUri;
                std::string           value;
                uint32_t              timescale;
                uint64_t              presentationTimeOffset;
        };
    }
}

#endif /* EVENTSTREAM_H_ */
