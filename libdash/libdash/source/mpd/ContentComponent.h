/*
 * ContentComponent.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef CONTENTCOMPONENT_H_
#define CONTENTCOMPONENT_H_

#include "config.h"

#include "IContentComponent.h"
#include "Descriptor.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ContentComponent : public IContentComponent, public AbstractMPDElement
        {
            public:
                ContentComponent          ();
                virtual ~ContentComponent ();

                const std::vector<IDescriptor *>&   GetAccessibility    ()  const;
                const std::vector<IDescriptor *>&   GetRole             ()  const;
                const std::vector<IDescriptor *>&   GetRating           ()  const;
                const std::vector<IDescriptor *>&   GetViewpoint        ()  const;
                uint32_t                            GetId               ()  const;
                const std::string&                  GetLang             ()  const;
                const std::string&                  GetContentType      ()  const;
                const std::string&                  GetPar              ()  const;

                void    AddAccessibity  (Descriptor *accessibility);
                void    AddRole         (Descriptor *role);
                void    AddRating       (Descriptor *rating);
                void    AddViewpoint    (Descriptor *viewpoint);
                void    SetId           (uint32_t id);
                void    SetLang         (const std::string& lang);
                void    SetContentType  (const std::string& contentType);
                void    SetPar          (const std::string& par);

            private:
                std::vector<Descriptor *>   accessibility;
                std::vector<Descriptor *>   role;
                std::vector<Descriptor *>   rating;
                std::vector<Descriptor *>   viewpoint;
                uint32_t                    id;
                std::string                 lang;
                std::string                 contentType;
                std::string                 par;
        };
    }
}

#endif /* CONTENTCOMPONENT_H_ */
