/*
 * Label.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LABEL_H_
#define LABEL_H_

#include "config.h"

#include "ILabel.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Label : public ILabel, public AbstractMPDElement
        {
            public:
                Label             ();
                virtual ~Label    ();

                uint32_t             GetId        ()  const;
                const std::string&   GetLang      ()  const;
                

                void    SetId       (uint32_t  id);
                void    SetLang     (const std::string& lang);

            private:
                uint32_t    id;
                std::string lang;
                
        };
    }
}

#endif /* ILABEL_H_ */
