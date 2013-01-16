/*
 * IProgramInformation.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IPROGRAMINFORMATION_H_
#define IPROGRAMINFORMATION_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IProgramInformation : public virtual IMPDElement
        {
            public:
                virtual ~IProgramInformation(){}

                virtual const std::string&  GetTitle                ()  const = 0;
                virtual const std::string&  GetSource               ()  const = 0;
                virtual const std::string&  GetCopyright            ()  const = 0;
                virtual const std::string&  GetLang                 ()  const = 0;
                virtual const std::string&  GetMoreInformationURL   ()  const = 0;

        };
    }
}

#endif /* IPROGRAMINFORMATION_H_ */