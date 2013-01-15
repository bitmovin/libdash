/*
 * Subset.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
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

                const std::vector<uint32_t>&    Contains   ()  const;

                void    SetSubset   (const std::string& subset);

            private:
                std::vector<uint32_t>   subset;
        };
    }
}

#endif /* SUBSET_H_ */
