/*
 * QImageBuffer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_BUFFER_QIMAGEBUFFER_H_
#define LIBDASH_FRAMEWORK_BUFFER_QIMAGEBUFFER_H_

#include "../Portable/MultiThreading.h"
#include <deque>
#include "../../Decoder/IVideoObserver.h"
#include <qimage.h>

namespace libdash
{
    namespace framework
    {
        namespace buffer
        {
            class QImageBuffer
            {
                public:
                    QImageBuffer           (uint32_t maxcapacity);
                    virtual ~QImageBuffer  ();

                    bool        PushBack    (QImage *frame);
                    QImage*     Front       ();
                    QImage*     GetFront    ();
                    void        PopFront    ();
                    void        ClearTail   ();
                    void        Clear       ();
                    void        SetEOS      (bool value);
                    uint32_t    Length      ();
                    uint32_t    Capacity    ();

                private:
                    std::deque<QImage *>        frames;
                    bool                        eos;
                    uint32_t                    maxcapacity;
                    mutable CRITICAL_SECTION    monitorMutex;
                    mutable CONDITION_VARIABLE  full;
                    mutable CONDITION_VARIABLE  empty;
            };
        }
    }
}

#endif /* LIBDASH_FRAMEWORK_BUFFER_QIMAGEBUFFER_H_ */