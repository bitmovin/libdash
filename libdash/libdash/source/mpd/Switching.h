/*
 * Switching.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef SWITCHING_H_
#define SWITCHING_H_

#include "config.h"

#include "ISwitching.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Switching : public ISwitching, public AbstractMPDElement
        {
            public:
                Switching             ();
                virtual ~Switching    ();

                uint32_t                     GetInterval          ()  const;
                const std::string&           GetType              ()  const;

                void    SetInterval        (uint32_t interval);
                void    SetType            (const std::string& type);

            private:
                uint32_t        interval;
                std::string     type;
        };
    }
}

#endif /* SWITCHING_H_ */
