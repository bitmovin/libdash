/*
 * SegmentList.h
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

#ifndef SEGMENTLIST_H_
#define SEGMENTLIST_H_

#include "config.h"

#include "ISegmentList.h"
#include "MultipleSegmentBase.h"
#include "SegmentURL.h"

namespace dash
{
    namespace mpd
    {
        class SegmentList : public ISegmentList, public MultipleSegmentBase
        {
            public:
                SegmentList             ();
                virtual ~SegmentList    ();

                const std::vector<ISegmentURL *>&   GetSegmentURLs  ()  const;
                const std::string&                  GetXlinkHref    ()  const;
                const std::string&                  GetXlinkActuate ()  const;
                const std::string&                  GetXlinkType    ()  const;
                const std::string&                  GetXlinkShow    ()  const;

                void    AddSegmentURL   (SegmentURL *segmetURL);
                void    SetXlinkHref    (const std::string& xlinkHref);
                void    SetXlinkActuate (const std::string& xlinkActuate);
                void    SetXlinkType    (const std::string& xlinkType);
                void    SetXlinkShow    (const std::string& xlinkShow);

            private:
                std::vector<SegmentURL *> segmentURLs;
                std::string               xlinkHref;
                std::string               xlinkActuate;
                std::string               xlinkType;
                std::string               xlinkShow;
        };
    }
}

#endif /* SEGMENTLIST_H_ */
