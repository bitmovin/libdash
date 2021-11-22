/*
 * Descriptor.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DESCRIPTOR_H_
#define DESCRIPTOR_H_

#include "config.h"

#include "IDescriptor.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Descriptor : public virtual IDescriptor, public AbstractMPDElement
        {
            public:
                Descriptor          ();
                virtual ~Descriptor ();

                const std::string&      GetSchemeIdUri  () const;
                const std::string&      GetValue        () const;
                const std::string&      GetId           () const;

                void    SetValue        (const std::string& value);
                void    SetSchemeIdUri  (const std::string& schemeIdUri);
                void    SetId           (const std::string& id);

            protected:
                std::string  schemeIdUri;
                std::string  value;
                std::string  id;
        };
    }
}

#endif /* DESCRIPTOR_H_ */
