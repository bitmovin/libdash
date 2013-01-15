/*
 * ISegmentTemplate.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ISEGMENTTEMPLATE_H_
#define ISEGMENTTEMPLATE_H_

#include "config.h"

#include "IMultipleSegmentBase.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentTemplate : public virtual IMultipleSegmentBase
        {
            public:
                virtual ~ISegmentTemplate(){}

                virtual const std::string&  Getmedia                    ()  const = 0;
                virtual const std::string&  Getindex                    ()  const = 0;
                virtual const std::string&  Getinitialization           ()  const = 0;
                virtual const std::string&  GetbitstreamSwitching       ()  const = 0;
                virtual ISegment*           ToInitializationSegment     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const = 0;
                virtual ISegment*           ToBitstreamSwitchingSegment (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const = 0;
                virtual ISegment*           GetMediaSegmentFromNumber   (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const = 0;
                virtual ISegment*           GetIndexSegmentFromNumber   (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const = 0;
                virtual ISegment*           GetMediaSegmentFromTime     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const = 0;
                virtual ISegment*           GetIndexSegmentFromTime     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const = 0;
        };
    }
}

#endif /* ISEGMENTTEMPLATE_H_ */