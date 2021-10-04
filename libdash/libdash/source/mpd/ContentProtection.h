/*
 * ContentProtection.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef CONTENTPROTECTION_H_
#define CONTENTPROTECTION_H_

#include "config.h"

#include "IContentProtection.h"
#include "Descriptor.h"

namespace dash
{
    namespace mpd
    {
        class ContentProtection : public IContentProtection, public Descriptor
        {
            public:
                ContentProtection           ();
                virtual ~ContentProtection  ();

                const std::string&                  GetRobustness          ()  const;
                const std::string&                  GetRefId               ()  const;
                const std::string&                  GetRef                 ()  const;

                void    SetRobustness         (const std::string& robustness);
                void    SetRefId              (const std::string& refId);
                void    SetRef                (const std::string& ref);

            private:
                std::string              robustness;
                std::string              refId;
                std::string              ref;
        };
    }
}

#endif /* CONTENTPROTECTION_H_ */
