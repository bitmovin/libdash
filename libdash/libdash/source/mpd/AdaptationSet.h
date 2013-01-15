/*
 * AdaptationSet.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ADAPTATIONSET_H_
#define ADAPTATIONSET_H_

#include "config.h"

#include "IAdaptationSet.h"
#include "RepresentationBase.h"
#include "BaseUrl.h"
#include "SegmentBase.h"
#include "SegmentList.h"
#include "SegmentTemplate.h"
#include "ContentComponent.h"
#include "Representation.h"

namespace dash
{
    namespace mpd
    {
        class AdaptationSet : public IAdaptationSet, public RepresentationBase
        {
            public:
                AdaptationSet           ();
                virtual ~AdaptationSet  ();

                const std::vector<IDescriptor *>&       GetAccessibility                ()  const;
                const std::vector<IDescriptor *>&       GetRole                         ()  const;
                const std::vector<IDescriptor *>&       GetRating                       ()  const;
                const std::vector<IDescriptor *>&       GetViewpoint                    ()  const;
                const std::vector<IContentComponent *>& GetContentComponent             ()  const;
                const std::vector<IBaseUrl *>&          GetBaseURLs                     ()  const;
                ISegmentBase*                           GetSegmentBase                  ()  const;
                ISegmentList*                           GetSegmentList                  ()  const;
                ISegmentTemplate*                       GetSegmentTemplate              ()  const;
                const std::vector<IRepresentation *>&   GetRepresentation               ()  const;
                const std::string&                      GetXlinkHref                    ()  const;
                const std::string&                      GetXlinkActuate                 ()  const;
                uint32_t                                GetId                           ()  const;
                uint32_t                                GetGroup                        ()  const;
                const std::string&                      GetLang                         ()  const;
                const std::string&                      GetContentType                  ()  const;
                const std::string&                      GetPar                          ()  const;
                uint32_t                                GetMinBandwidth                 ()  const;
                uint32_t                                GetMaxBandwidth                 ()  const;
                uint32_t                                GetMinWidth                     ()  const;
                uint32_t                                GetMaxWidth                     ()  const;
                uint32_t                                GetMinHeight                    ()  const;
                uint32_t                                GetMaxHeight                    ()  const;
                const std::string&                      GetMinFramerate                 ()  const;
                const std::string&                      GetMaxFramerate                 ()  const;
                bool                                    SegmentAlignmentIsBoolValue     ()  const;
                bool                                    HasSegmentAlignment             ()  const;
                uint32_t                                GetSegmentAligment              ()  const;
                bool                                    SubsegmentAlignmentIsBoolValue  ()  const;
                bool                                    HasSubsegmentAlignment          ()  const;
                uint32_t                                GetSubsegmentAlignment          ()  const;
                uint8_t                                 GetSubsegmentStartsWithSAP      ()  const;
                bool                                    GetBitstreamSwitching           ()  const;

                void    AddAccessibity              (Descriptor *accessibility);
                void    AddRole                     (Descriptor *role);
                void    AddRating                   (Descriptor *rating);
                void    AddViewpoint                (Descriptor *viewpoint);
                void    AddContentComponent         (ContentComponent *contentComponent);
                void    AddBaseURL                  (BaseUrl *baseURL);
                void    SetSegmentBase              (SegmentBase *segmentBase);
                void    SetSegmentList              (SegmentList *segmentList);
                void    SetSegmentTemplate          (SegmentTemplate *segmentTemplate);
                void    AddRepresentation           (Representation* representation);
                void    SetXlinkHref                (const std::string& xlinkHref);
                void    SetXlinkActuate             (const std::string& xlinkActuate);
                void    SetId                       (uint32_t id);
                void    SetGroup                    (uint32_t group);
                void    SetLang                     (const std::string& lang);
                void    SetContentType              (const std::string& contentType);
                void    SetPar                      (const std::string& par);
                void    SetMinBandwidth             (uint32_t minBandwidth);
                void    SetMaxBandwidth             (uint32_t maxBandwidth);
                void    SetMinWidth                 (uint32_t minWidth);
                void    SetMaxWidth                 (uint32_t maxWidth);
                void    SetMinHeight                (uint32_t minHeight);
                void    SetMaxHeight                (uint32_t maxHeight);
                void    SetMinFramerate             (const std::string& minFramerate);
                void    SetMaxFramerate             (const std::string& maxFramerate);
                void    SetSegmentAlignment         (const std::string& segmentAlignment);
                void    SetSubsegmentAlignment      (const std::string& subsegmentAlignment);
                void    SetSubsegmentStartsWithSAP  (uint8_t subsegmentStartsWithSAP);
                void    SetBitstreamSwitching       (bool value);

            private:
                std::vector<Descriptor *>       accessibility;
                std::vector<Descriptor *>       role;
                std::vector<Descriptor *>       rating;
                std::vector<Descriptor *>       viewpoint;
                std::vector<ContentComponent *> contentComponent;
                std::vector<BaseUrl *>          baseURLs;
                SegmentBase                     *segmentBase;
                SegmentList                     *segmentList;
                SegmentTemplate                 *segmentTemplate;
                std::vector<Representation *>   representation;
                std::string                     xlinkHref;
                std::string                     xlinkActuate;
                uint32_t                        id;
                uint32_t                        group;
                std::string                     lang;
                std::string                     contentType;
                std::string                     par;
                uint32_t                        minBandwidth;
                uint32_t                        maxBandwidth;
                uint32_t                        minWidth;
                uint32_t                        maxWidth;
                uint32_t                        minHeight;
                uint32_t                        maxHeight;
                std::string                     minFramerate;
                std::string                     maxFramerate;
                bool                            segmentAlignmentIsBool;
                bool                            subsegmentAlignmentIsBool;
                bool                            usesSegmentAlignment;
                bool                            usesSubsegmentAlignment;
                uint32_t                        segmentAlignment;
                uint32_t                        subsegmentAlignment;
                uint8_t                         subsegmentStartsWithSAP;
                bool                            isBitstreamSwitching;
        };
    }
}

#endif /* ADAPTATIONSET_H_ */
