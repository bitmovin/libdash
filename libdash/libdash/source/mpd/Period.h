/*
 * Period.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PERIOD_H_
#define PERIOD_H_

#include "config.h"

#include "IPeriod.h"
#include "BaseUrl.h"
#include "AdaptationSet.h"
#include "Subset.h"
#include "SegmentBase.h"
#include "SegmentList.h"
#include "SegmentTemplate.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class Period : public IPeriod, public AbstractMPDElement
        {
            public:
                Period          ();
                virtual ~Period ();

                const std::vector<IBaseUrl *>&          GetBaseURLs             ()  const;
                ISegmentBase*                           GetSegmentBase          ()  const;
                ISegmentList*                           GetSegmentList          ()  const;
                ISegmentTemplate*                       GetSegmentTemplate      ()  const;
                const std::vector<IAdaptationSet *>&    GetAdaptationSets       ()  const;
                const std::vector<ISubset *>&           GetSubsets              ()  const;
                const std::string&                      GetXlinkHref            ()  const;
                const std::string&                      GetXlinkActuate         ()  const;
                const std::string&                      GetId                   ()  const;
                const std::string&                      GetStart                ()  const;
                const std::string&                      GetDuration             ()  const;
                bool                                    GetBitstreamSwitching   ()  const;

                void    AddBaseURL                  (BaseUrl *baseURL);
                void    SetSegmentBase              (SegmentBase *segmentBase);
                void    SetSegmentList              (SegmentList *segmentList);
                void    SetSegmentTemplate          (SegmentTemplate *segmentTemplate);
                void    AddAdaptationSet            (AdaptationSet *AdaptationSet);
                void    AddSubset                   (Subset *subset);
                void    SetXlinkHref                (const std::string& xlinkHref);
                void    SetXlinkActuate             (const std::string& xlinkActuate);
                void    SetId                       (const std::string& id);
                void    SetStart                    (const std::string& start);
                void    SetDuration                 (const std::string& duration);
                void    SetBitstreamSwitching       (bool value);

            private:
                std::vector<BaseUrl *>          baseURLs;
                SegmentBase                     *segmentBase;
                SegmentList                     *segmentList;
                SegmentTemplate                 *segmentTemplate;
                std::vector<AdaptationSet *>    adaptationSets;
                std::vector<Subset *>           subsets;
                std::string                     xlinkHref;
                std::string                     xlinkActuate;
                std::string                     id;
                std::string                     start;
                std::string                     duration;
                bool                            isBitstreamSwitching;
        };
    }
}

#endif /* PERIOD_H_ */
