/*
 * Range.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef RANGE_H_
#define RANGE_H_

#include "config.h"

#include "IRange.h"

namespace dash
{
    namespace mpd
    {
        class Range : public IRange
        {
            public:
                Range           ();
                virtual ~Range  ();

                const std::string&  GetStarttime    ()  const;
                const std::string&  GetDuration     ()  const;

                void    SetStarttime    (const std::string& start);
                void    SetDuration     (const std::string& duration);

            private:
                std::string starttime;
                std::string duration;
        };
    }
}

#endif /* RANGE_H_ */
