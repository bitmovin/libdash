/*
 * ISubRepresentation.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISUBREPRESENTATION_H_
#define ISUBREPRESENTATION_H_

#include "config.h"

#include "IRepresentationBase.h"

namespace dash
{
    namespace mpd
    {
        class ISubRepresentation : public virtual IRepresentationBase
        {
            public:
                virtual ~ISubRepresentation(){}

                virtual uint32_t                            GetLevel            () const = 0;
                virtual const std::vector<uint32_t>&        GetDependencyLevel  () const = 0;
                virtual uint32_t                            GetBandWidth        () const = 0;
                virtual const std::vector<std::string>&     GetContentComponent () const = 0;

        };
    }
}

#endif /* ISUBREPRESENTATION_H_ */