/*
 * ISegmentList.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISEGMENTLIST_H_
#define ISEGMENTLIST_H_

#include "config.h"

#include "ISegmentURL.h"
#include "IMultipleSegmentBase.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentList : public virtual IMultipleSegmentBase
        {
            public:
                virtual ~ISegmentList(){}

                virtual const std::vector<ISegmentURL *>&   GetSegmentURLs  ()  const = 0;
                virtual const std::string&                  GetXlinkHref    ()  const = 0;
                virtual const std::string&                  GetXlinkActuate ()  const = 0;

        };
    }
}

#endif /* ISEGMENTLIST_H_ */