/*
 * OperatingQuality.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef OPERATINGQUALITY_H_
#define OPERATINGQUALITY_H_

#include "config.h"

#include "IOperatingQuality.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class OperatingQuality : public IOperatingQuality, public AbstractMPDElement
        {
            public:
                OperatingQuality             ();
                virtual ~OperatingQuality    ();

                const std::string&       GetMediaType                  ()  const;
                uint32_t                 GetMin                        ()  const;
                uint32_t                 GetMax                        ()  const;
                uint32_t                 GetTarget                     ()  const;
                const std::string&       GetType                       ()  const;
                uint32_t                 GetMaxDifference              ()  const;

                void    SetMediaType     (const std::string& mediaType);
                void    SetMin           (uint32_t min);
                void    SetMax           (uint32_t max);
                void    SetTarget        (uint32_t target);
                void    SetType          (const std::string& type);
                void    SetMaxDifference (uint32_t maxDifference);

            private:
                std::string      mediaType;
                uint32_t         min;
                uint32_t         max;
                uint32_t         target;
                std::string      type;
                uint32_t         maxDifference;
                
        };
    }
}

#endif /* OPERATINGQUALITY_H_ */
