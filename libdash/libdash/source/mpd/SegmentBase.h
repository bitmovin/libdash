/*
 * SegmentBase.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SEGMENTBASE_H_
#define SEGMENTBASE_H_

#include "config.h"

#include "ISegmentBase.h"
#include "URLType.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class SegmentBase : public virtual ISegmentBase, public AbstractMPDElement
        {
            public:
                SegmentBase             ();
                virtual ~SegmentBase    ();

                const IURLType*     GetInitialization           ()  const;
                const IURLType*     GetRepresentationIndex      ()  const;
                uint32_t            GetTimescale                ()  const;
                uint32_t            GetPresentationTimeOffset   ()  const;
                const std::string&  GetIndexRange               ()  const;
                bool                HasIndexRangeExact          ()  const;

                void    SetInitialization           (URLType *initialization);
                void    SetRepresentationIndex      (URLType *representationIndex);
                void    SetTimescale                (uint32_t timescale);
                void    SetPresentationTimeOffset   (uint32_t presentationTimeOffset);
                void    SetIndexRange               (const std::string& indexRange);
                void    SetIndexRangeExact          (bool indexRangeExact);

            protected:
                URLType     *initialization;
                URLType     *representationIndex;
                uint32_t    timescale;
                uint32_t    presentationTimeOffset;
                std::string indexRange;
                bool        indexRangeExact;
        };
    }
}

#endif /* SEGMENTBASE_H_ */
