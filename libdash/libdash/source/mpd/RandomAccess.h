/*
 * RandomAccess.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef RANDOMACCESS_H_
#define RANDOMACCESS_H_

#include "config.h"

#include "IRandomAccess.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class RandomAccess : public IRandomAccess, public AbstractMPDElement
        {
            public:
                RandomAccess             ();
                virtual ~RandomAccess    ();

                uint32_t                GetInterval                   () const;
                const std::string&      GetType                       () const;
                const std::string&      GetMinBufferTime              () const;
                uint32_t                GetBandwidth                  () const;

                void    SetInterval          (uint32_t interval);
                void    SetType              (const std::string& type);
                void    SetMinBufferTime     (const std::string& minBufferTime);
                void    SetBandwidth         (uint32_t bandwidth);

            private:
                uint32_t        interval;
                std::string     type;
                std::string     minBufferTime;
                uint32_t        bandwidth;
        };
    }
}

#endif /* RANDOMACCESS_H_ */
