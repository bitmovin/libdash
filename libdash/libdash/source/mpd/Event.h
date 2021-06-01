/*
 * Event.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
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

                uint64_t             GetPresentationTime    ()  const;
                const std::string&   GetDuration            ()  const;
                uint32_t             GetId                  ()  const;
                const std::string&   GetContentEncoding     ()  const;
                const std::string&   GetMessageData         ()  const;

                void    SetPresentationTime    (uint64_t presentationTime);
                void    SetDuration            (const std::string& duration);
                void    SetId                  (uint32_t  id);
                void    SetContentEncoding     (const std::string&  contentEncoding);
                void    SetMessageData         (const std::string&  messageData);

            private:
                uint64_t    presentationTime;
                std::string duration;
                uint32_t    id;
                std::string contentEncoding;
                std::string messageData;
                
        };
    }
}

#endif /* IEVENT_H_ */
