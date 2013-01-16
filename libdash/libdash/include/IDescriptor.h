/*
 * IDescriptor.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IDESCRIPTOR_H_
#define IDESCRIPTOR_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IDescriptor : public virtual IMPDElement
        {
            public:
                virtual ~IDescriptor(){}

                virtual const std::string&      GetSchemeIdUri  () const = 0;
                virtual const std::string&      GetValue        () const = 0;
        };
    }
}

#endif /* IDESCRIPTOR_H_ */