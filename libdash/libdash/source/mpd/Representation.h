/*
 * Representation.h
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

#ifndef REPRESENTATION_H_
#define REPRESENTATION_H_

#include "config.h"

#include "IRepresentation.h"
#include "SegmentTemplate.h"
#include "RepresentationBase.h"
#include "BaseUrl.h"
#include "ExtendedBandwidth.h"
#include "SubRepresentation.h"
#include "SegmentBase.h"
#include "SegmentList.h"
#include "../helpers/String.h"

namespace dash
{
    namespace mpd
    {
        class Representation : public IRepresentation, public RepresentationBase
        {
            public:
                Representation          ();
                virtual ~Representation ();

                const std::vector<IBaseUrl *>&              GetBaseURLs                 ()  const;
                const std::vector<ISubRepresentation *>&    GetSubRepresentations       ()  const;
                const std::vector<IExtendedBandwidth *>&    GetExtendedBandwidths       ()  const;
                ISegmentBase*                               GetSegmentBase              ()  const;
                ISegmentList*                               GetSegmentList              ()  const;
                ISegmentTemplate*                           GetSegmentTemplate          ()  const;
                const std::string&                          GetId                       ()  const;
                uint32_t                                    GetBandwidth                ()  const;
                uint32_t                                    GetQualityRanking           ()  const;
                const std::vector<std::string>&             GetDependencyId             ()  const;
                const std::vector<std::string>&             GetAssociationId            ()  const;
                const std::string&                          GetAssociationType          ()  const;
                const std::vector<std::string>&             GetMediaStreamStructureId   ()  const;

                void    AddBaseURL                  (BaseUrl *baseURL);
                void    AddExtendedBandwidth        (ExtendedBandwidth *extendedBandwidth);
                void    AddSubRepresentation        (SubRepresentation *subRepresentation);
                void    SetSegmentBase              (SegmentBase *segmentBase);
                void    SetSegmentList              (SegmentList *segmentList);
                void    SetSegmentTemplate          (SegmentTemplate *segmentTemplate);
                void    SetId                       (const std::string &id);
                void    SetBandwidth                (uint32_t bandwidth);
                void    SetQualityRanking           (uint32_t qualityRanking);
                void    SetDependencyId             (const std::string &dependencyId);
                void    SetAssociationId            (const std::string &associationId);
                void    SetAssociationType          (const std::string &associationType);
                void    SetMediaStreamStructureId   (const std::string &mediaStreamStructureId);

            private:
                std::vector<BaseUrl *>              baseURLs;
                std::vector<ExtendedBandwidth *>    extendedBandwidths;
                std::vector<SubRepresentation *>    subRepresentations;
                SegmentBase                         *segmentBase;
                SegmentList                         *segmentList;
                SegmentTemplate                     *segmentTemplate;
                std::string                         id;
                uint32_t                            bandwidth;
                uint32_t                            qualityRanking;
                std::vector<std::string>            dependencyId;
                std::vector<std::string>            associationId;
                std::string                         associationType;
                std::vector<std::string>            mediaStreamStructureId;
        };
    }
}

#endif /* REPRESENTATION_H_ */
