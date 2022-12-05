/*
 * InitializationSet.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef INITIALIZATIONSET_H_
#define INITIALIZATIONSET_H_

#include "config.h"

#include "IInitializationSet.h"
#include "Descriptor.h"
#include "RepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class InitializationSet : public IInitializationSet, public RepresentationBase
        {
            public:
                InitializationSet             ();
                virtual ~InitializationSet    ();
                
                const std::vector<IDescriptor *>&       GetAccessibility                ()  const;
                const std::vector<IDescriptor *>&       GetRole                         ()  const;
                const std::vector<IDescriptor *>&       GetRating                       ()  const;
                const std::vector<IDescriptor *>&       GetViewpoint                    ()  const;
                const std::string&                      GetXlinkHref                    ()  const;
                const std::string&                      GetXlinkActuate                 ()  const;
                const std::string&                      GetXlinkType                    ()  const;
                uint32_t                                GetId                           ()  const;
                bool                                    IsInAllPeriods                  ()  const;
                const std::string&                      GetContentType                  ()  const;
                const std::string&                      GetPar                          ()  const;
                uint32_t                                GetMaxWidth                     ()  const;
                uint32_t                                GetMaxHeight                    ()  const;
                const std::string&                      GetMaxFrameRate                 ()  const;
                const std::string&                      GetInitialization               ()  const;
                
                void    AddAccessibity       (Descriptor *accessibility);
                void    AddRole              (Descriptor *role);
                void    AddRating            (Descriptor *rating);
                void    AddViewpoint         (Descriptor *viewpoint);
                void    SetXlinkHref         (const std::string& xlinkHref);
                void    SetXlinkActuate      (const std::string& xlinkActuate);
                void    SetXlinkType         (const std::string& xlinkType);
                void    SetId                (uint32_t id);
                void    SetInAllPeriods      (bool inAllPeriods);
                void    SetContentType       (const std::string& contentType);
                void    SetPar               (const std::string& par);
                void    SetMaxWidth          (uint32_t maxWidth);
                void    SetMaxHeight         (uint32_t maxHeight);
                void    SetMaxFrameRate      (const std::string& maxFrameRate);
                void    SetInitialization    (const std::string& initialization);
                
            private:
                std::vector<Descriptor *>       accessibility;
                std::vector<Descriptor *>       role;
                std::vector<Descriptor *>       rating;
                std::vector<Descriptor *>       viewpoint;
                std::string                     xlinkHref;
                std::string                     xlinkActuate;
                std::string                     xlinkType;
                uint32_t                        id;
                bool                            inAllPeriods;
                std::string                     contentType;
                std::string                     par;
                uint32_t                        maxWidth;
                uint32_t                        maxHeight;
                std::string                     maxFrameRate;
                std::string                     initialization;
        };
    }
}

#endif /* INITIALIZATIONSET_H_ */