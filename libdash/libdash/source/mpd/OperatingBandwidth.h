/*
 * OperatingBandwidth.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef OPERATINGBANDWIDTH_H_
#define OPERATINGBANDWIDTH_H_

#include "config.h"

#include "IOperatingBandwidth.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class OperatingBandwidth : public IOperatingBandwidth, public AbstractMPDElement
        {
            public:
                OperatingBandwidth             ();
                virtual ~OperatingBandwidth    ();

                const std::string&       GetMediaType                  ()  const;
                uint32_t                 GetMin                        ()  const;
                uint32_t                 GetMax                        ()  const;
                uint32_t                 GetTarget                     ()  const;

                void    SetMediaType     (const std::string& mediaType);
                void    SetMin           (uint32_t min);
                void    SetMax           (uint32_t max);
                void    SetTarget        (uint32_t target);

            private:
                std::string      mediaType;
                uint32_t         min;
                uint32_t         max;
                uint32_t         target;
                
        };
    }
}

#endif /* OPERATINGBANDWIDTH_H_ */
