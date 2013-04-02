/*
 * SegmentTemplate.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SEGMENTTEMPLATE_H_
#define SEGMENTTEMPLATE_H_

#include "config.h"

#include "ISegmentTemplate.h"
#include "MultipleSegmentBase.h"
#include "../helpers/String.h"

namespace dash
{
    namespace mpd
    {
        class SegmentTemplate : public ISegmentTemplate, public MultipleSegmentBase
        {
            public:
                SegmentTemplate             ();
                virtual ~SegmentTemplate    ();

                const std::string&  Getmedia                ()  const;
                const std::string&  Getindex                ()  const;
                const std::string&  Getinitialization       ()  const;
                const std::string&  GetbitstreamSwitching   ()  const;
                ISegment*           ToInitializationSegment     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const;
                ISegment*           ToBitstreamSwitchingSegment (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const;
                ISegment*           GetMediaSegmentFromNumber   (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const;
                ISegment*           GetIndexSegmentFromNumber   (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const;
                ISegment*           GetMediaSegmentFromTime     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const;
                ISegment*           GetIndexSegmentFromTime     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const;

                void    SetMedia                (const std::string& media);
                void    SetIndex                (const std::string& index);
                void    SetInitialization       (const std::string& initialization);
                void    SetBitstreamSwitching   (const std::string& bitstreamSwichting);

            private:
                std::string ReplaceParameters   (const std::string& uri, const std::string& representationID, uint32_t bandwidth, uint32_t number, uint32_t time) const;
                void        FormatChunk         (std::string& uri, uint32_t number) const;
                ISegment*   ToSegment           (const std::string& uri, const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, 
                                                 dash::metrics::HTTPTransactionType type, uint32_t number = 0, uint32_t time = 0) const;

                std::string media;
                std::string index;
                std::string initialization;
                std::string bitstreamSwitching;
        };
    }
}

#endif /* SEGMENTTEMPLATE_H_ */
