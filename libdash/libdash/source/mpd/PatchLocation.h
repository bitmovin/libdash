/*
 * PatchLocation.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PATCHLOCATION_H_
#define PATCHLOCATION_H_

#include "config.h"

#include "IPatchLocation.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class PatchLocation : public IPatchLocation, public AbstractMPDElement
        {
            public:
                PatchLocation             ();
                virtual ~PatchLocation    ();
                
                const std::string&   GetUrl    ()  const;
                double               GetTtl    ()  const;

                void    SetUrl    (const std::string& url);
                void    SetTtl    (double ttl);
                
            private:
                std::string url;
                double      ttl;
                
        };
    }
}

#endif /* PATCHLOCATION_H_ */