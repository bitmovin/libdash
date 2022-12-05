/*
 * BaseUrl.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef BASEURL_H_
#define BASEURL_H_

#include "config.h"

#include "Segment.h"
#include "IBaseUrl.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class BaseUrl : public IBaseUrl, public AbstractMPDElement
        {
            public:
                BaseUrl         ();
                virtual ~BaseUrl();

                const std::string& GetUrl                      ()  const;
                const std::string& GetServiceLocation          ()  const;
                const std::string& GetByteRange                ()  const;
                double             GetAvailabilityTimeOffset   ()  const;
                bool               IsAvailabilityTimeComplete  ()  const;
                const std::string& GetTimeShiftBufferDepth     ()  const;
                bool               HasRangeAccess              ()  const;

                void    SetUrl                          (const std::string& url);
                void    SetServiceLocation              (const std::string& serviceLocation);
                void    SetByteRange                    (const std::string& byteRange);
                void    SetAvailabilityTimeOffset       (double availabilityTimeOffset);
                void    SetAvailabilityTimeComplete     (bool availabilityTimeComplete);
                void    SetTimeShiftBufferDepth         (const std::string& timeShiftBufferDepth);
                void    SetRangeAccess                  (bool rangeAccess);

                virtual ISegment* ToMediaSegment (const std::vector<IBaseUrl *>& baseurls) const;

            private:
                std::string url;
                std::string serviceLocation;
                std::string byteRange;
                double availabilityTimeOffset;
                bool availabilityTimeComplete;
                std::string timeShiftBufferDepth;
                bool rangeAccess;
        };
    }
}

#endif /* BASEURL_H_ */
