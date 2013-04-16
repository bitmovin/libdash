/*
 * IStreamObserver.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_MANAGERS_STREAMOBSERVER_H_
#define QTSAMPLEPLAYER_MANAGERS_STREAMOBSERVER_H_

#include <IMPD.h>
#include <QImage.h>
#include <QtMultimedia/qaudioformat.h>

namespace sampleplayer
{
    namespace managers
    {
        class IStreamObserver
        {
            public:
                virtual ~IStreamObserver () {}

                virtual void OnSegmentDownloaded    ()  = 0;
        };
    }
}

#endif /* QTSAMPLEPLAYER_MANAGERS_STREAMOBSERVER_H_ */
