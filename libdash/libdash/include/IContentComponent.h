/*
 * IContentComponent.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ICONTENTCOMPONENT_H_
#define ICONTENTCOMPONENT_H_

#include "config.h"

#include "IDescriptor.h"

namespace dash
{
    namespace mpd
    {
        class IContentComponent
        {
            public:
                virtual ~IContentComponent(){}

                virtual const std::vector<IDescriptor *>&   GetAccessibility    ()  const = 0;
                virtual const std::vector<IDescriptor *>&   GetRole             ()  const = 0;
                virtual const std::vector<IDescriptor *>&   GetRating           ()  const = 0;
                virtual const std::vector<IDescriptor *>&   GetViewpoint        ()  const = 0;
                virtual uint32_t                            GetId               ()  const = 0;
                virtual const std::string&                  GetLang             ()  const = 0;
                virtual const std::string&                  GetContentType      ()  const = 0;
                virtual const std::string&                  GetPar              ()  const = 0;

        };
    }
}

#endif /* ICONTENTCOMPONENT_H_ */