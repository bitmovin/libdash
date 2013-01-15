/*
 * IMPDElement.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IMPDELEMENT_H_
#define IMPDELEMENT_H_

#include "config.h"

#include "INode.h"

namespace dash
{
    namespace mpd
    {
        class IMPDElement
        {
            public:
                virtual ~IMPDElement (){}

                virtual const std::vector<xml::INode *>             GetAdditionalSubNodes   ()  const = 0;
                virtual const std::map<std::string, std::string>    GetRawAttributes        ()  const = 0;
        };
    }
}

#endif /* IMPDELEMENT_H_ */