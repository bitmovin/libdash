/*
 * ProducerReferenceTime.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef PRODUCERREFERENCETIME_H_
#define PRODUCERREFERENCETIME_H_

#include "config.h"

#include "IProducerReferenceTime.h"
#include "Descriptor.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ProducerReferenceTime : public IProducerReferenceTime, public AbstractMPDElement
        {
            public:
                ProducerReferenceTime             ();
                virtual ~ProducerReferenceTime    ();

                const IDescriptor*      GetUTCTiming            () const;
                uint32_t                GetId                   () const;
                bool                    IsInband                () const;
                const std::string&      GetType                 () const;
                const std::string&      GetApplicationScheme    () const;
                const std::string&      GetWallClockTime        () const;
                uint64_t                GetPresentationTime     () const;

                void    SetUTCTiming             (Descriptor *utcTiming);
                void    SetId                    (uint32_t id);
                void    SetInband                (bool inband);
                void    SetType                  (const std::string& type);
                void    SetApplicationScheme     (const std::string& applicationScheme);
                void    SetWallClockTime         (const std::string& wallClockTime);
                void    SetPresentationTime      (uint64_t presentationTime);

            private:
                Descriptor      *utcTiming;
                uint32_t        id;
                bool            inband;
                std::string     type;
                std::string     applicationScheme;
                std::string     wallClockTime;
                uint64_t        presentationTime;
        };
    }
}

#endif /* PRODUCERREFERENCETIME_H_ */
