/*
 * IBaseUrl.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IBASEURL_H_
#define IBASEURL_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IBaseUrl : public virtual IMPDElement
        {
            public:
                virtual ~IBaseUrl(){}

                virtual const std::string& GetUrl               ()  const = 0;
                virtual const std::string& GetServiceLocation   ()  const = 0;
                virtual const std::string& GetByteRange         ()  const = 0;
        };
    }
}

#endif /* IBASEURL_H_ */