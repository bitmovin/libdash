/*
 * Preselection.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PRESELECTION_H_
#define PRESELECTION_H_

#include "config.h"

#include "IPreselection.h"
#include "Descriptor.h"
#include "RepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class Preselection : public IPreselection, public RepresentationBase
        {
            public:
                Preselection             ();
                virtual ~Preselection    ();
                
                const std::vector<IDescriptor *>&       GetAccessibility                ()  const;
                const std::vector<IDescriptor *>&       GetRole                         ()  const;
                const std::vector<IDescriptor *>&       GetRating                       ()  const;
                const std::vector<IDescriptor *>&       GetViewpoint                    ()  const;
                const std::string&                      GetId                           ()  const;
                const std::vector<std::string>&         GetPreselectionComponents       ()  const;
                const std::string&                      GetLang                         ()  const;
                const std::string&                      GetOrder                        ()  const;
                
                void    AddAccessibity                 (Descriptor *accessibility);
                void    AddRole                        (Descriptor *role);
                void    AddRating                      (Descriptor *rating);
                void    AddViewpoint                   (Descriptor *viewpoint);
                void    SetId                          (const std::string& id);
                void    SetPreselectionComponents      (const std::string& preselectionComponents);
                void    SetLang                        (const std::string& lang);
                void    SetOrder                       (const std::string& order);
                
            private:
                std::vector<Descriptor *>       accessibility;
                std::vector<Descriptor *>       role;
                std::vector<Descriptor *>       rating;
                std::vector<Descriptor *>       viewpoint;
                std::string                     id;
                std::vector<std::string>        preselectionComponents;
                std::string                     lang;
                std::string                     order;
        };
    }
}

#endif /* PRESELECTION_H_ */