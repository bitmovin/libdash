/*
 * SegmentURL.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SEGMENTURL_H_
#define SEGMENTURL_H_

#include "config.h"

#include "ISegmentURL.h"
#include "../helpers/Path.h"
#include "Segment.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class SegmentURL : public ISegmentURL, public AbstractMPDElement
        {
            public:
                SegmentURL         ();
                virtual ~SegmentURL();

                const std::string&  GetMediaURI     ()  const;
                const std::string&  GetMediaRange   ()  const;
                const std::string&  GetIndexURI     ()  const;
                const std::string&  GetIndexRange   ()  const;
                ISegment*           ToMediaSegment  (const std::vector<IBaseUrl *>& baseurls) const;
                ISegment*           ToIndexSegment  (const std::vector<IBaseUrl *>& baseurls) const;

                void    SetMediaURI     (const std::string& mediaURI);
                void    SetMediaRange   (const std::string& mediaRange);
                void    SetIndexURI     (const std::string& indexURI);
                void    SetIndexRange   (const std::string& indexRange);

            private:
                std::string mediaURI;
                std::string mediaRange;
                std::string indexURI;
                std::string indexRange;
        };
    }
}

#endif /* SEGMENTURL_H_ */
