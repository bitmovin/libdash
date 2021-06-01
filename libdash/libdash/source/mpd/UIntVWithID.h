/*
 * UIntVWithID.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef UINTVWITHID_H_
#define UINTVWITHID_H_

#include "config.h"

#include "IUIntVWithID.h"
#include "AbstractMPDElement.h"
#include "../helpers/String.h"

namespace dash
{
    namespace mpd
    {
        class UIntVWithID : public IUIntVWithID, public AbstractMPDElement
        {
            public:
                UIntVWithID          ();
                virtual ~UIntVWithID ();

                const std::vector<uint32_t>&        GetList               ()  const;
                uint32_t                            GetId                 ()  const;
                const std::vector<std::string>&     GetProfiles           ()  const;
                const std::string&                  GetContentType        ()  const;

                void    SetList          (const std::string& list);
                void    SetId            (uint32_t id);
                void    SetProfiles      (const std::string& profiles);
                void    SetContentType   (const std::string& contentType);

            private:
                std::vector<uint32_t>       list;
                uint32_t                    id;
                std::vector<std::string>    profiles;
                std::string                 contentType;
        };
    }
}
#endif /* UINTVWITHID_H_ */
