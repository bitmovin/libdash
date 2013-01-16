/*
 * ISegmentBase.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISEGMENTBASE_H_
#define ISEGMENTBASE_H_

#include "config.h"

#include "IMPDElement.h"
#include "IURLType.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentBase : public virtual IMPDElement
        {
            public:
                virtual ~ISegmentBase(){}

                virtual const IURLType*     GetInitialization           ()  const = 0;
                virtual const IURLType*     GetRepresentationIndex      ()  const = 0;
                virtual uint32_t            GetTimescale                ()  const = 0;
                virtual uint32_t            GetPresentationTimeOffset   ()  const = 0;
                virtual const std::string&  GetIndexRange               ()  const = 0;
                virtual bool                HasIndexRangeExact          ()  const = 0;
        };
    }
}

#endif /* ISEGMENTBASE_H_ */