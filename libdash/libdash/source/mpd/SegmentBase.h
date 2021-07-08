/*
 * SegmentBase.h
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

#ifndef SEGMENTBASE_H_
#define SEGMENTBASE_H_

#include "config.h"

#include "ISegmentBase.h"
#include "URLType.h"
#include "FailoverContent.h"
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

                const IURLType*         GetInitialization           ()  const;
                const IURLType*         GetRepresentationIndex      ()  const;
                const IFailoverContent* GetFailoverContent          ()  const;
                uint32_t                GetTimescale                ()  const;
                int                     GetEptDelta                 ()  const;
                int                     GetPdDelta                  ()  const;
                uint64_t                GetPresentationTimeOffset   ()  const;
                uint64_t                GetPresentationDuration     ()  const;
                const std::string&      GetTimeShiftBufferDepth     ()  const;
                const std::string&      GetIndexRange               ()  const;
                bool                    HasIndexRangeExact          ()  const;
                double                  GetAvailabilityTimeOffset   ()  const;
                bool                    IsAvailabilityTimeComplete  ()  const;

                void    SetInitialization           (URLType *initialization);
                void    SetRepresentationIndex      (URLType *representationIndex);
                void    SetFailoverContent          (FailoverContent *failoverContent);
                void    SetTimescale                (uint32_t timescale);
                void    SetEptDelta                 (int eptDelta);
                void    SetPdDelta                  (int eptDelta);
                void    SetPresentationTimeOffset   (uint64_t presentationTimeOffset);
                void    SetPresentationDuration     (uint64_t presentationDuration);
                void    SetTimeShiftBufferDepth     (const std::string& timeShiftBufferDepth);
                void    SetIndexRange               (const std::string& indexRange);
                void    SetIndexRangeExact          (bool indexRangeExact);
                void    SetAvailabilityTimeOffset   (double availabilityTimeOffset);
                void    SetAvailabilityTimeComplete (bool availabilityTimeComplete);

            protected:
                URLType         *initialization;
                URLType         *representationIndex;
                FailoverContent *failoverContent;
                uint32_t        timescale;
                int             eptDelta;
                int             pdDelta;
                uint64_t        presentationTimeOffset;
                uint64_t        presentationDuration;
                std::string     timeShiftBufferDepth;
                std::string     indexRange;
                bool            indexRangeExact;
                double          availabilityTimeOffset;
                bool            availabilityTimeComplete;
        };
    }
}

#endif /* SEGMENTBASE_H_ */
