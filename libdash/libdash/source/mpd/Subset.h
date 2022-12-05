/*
 * Subset.h
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

#ifndef SUBSET_H_
#define SUBSET_H_

#include "config.h"

#include "ISubset.h"
#include "../helpers/String.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Subset : public ISubset, public AbstractMPDElement
        {
            public:
                Subset          ();
                virtual ~Subset ();

                const std::vector<uint32_t>&      Contains   ()  const;
                const std::string&                GetId      ()  const;

                void    SetSubset   (const std::string& subset);
                void    SetId       (const std::string& id);

            private:
                std::vector<uint32_t>      subset;
                std::string                id;
        };
    }
}

#endif /* SUBSET_H_ */
