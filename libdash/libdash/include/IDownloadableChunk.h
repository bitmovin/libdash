/*
 * IDownloadableChunk.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IDOWNLOADABLECHUNK_H_
#define IDOWNLOADABLECHUNK_H_

#include "config.h"

#include "IDownloadObserver.h"
#include "IConnection.h"
#include "IChunk.h"

namespace dash
{
    namespace network
    {
        class IDownloadableChunk : public IChunk
        {
            public:
                virtual ~IDownloadableChunk(){}

                virtual bool    StartDownload           ()                              = 0;
                virtual bool    StartDownload           (IConnection *connection)       = 0;
                virtual void    AbortDownload           ()                              = 0;
                virtual int     Read                    (uint8_t *data, size_t len)     = 0;
                virtual int     Peek                    (uint8_t *data, size_t len)     = 0;
                virtual void    AttachDownloadObserver  (IDownloadObserver *observer)   = 0;
        };
    }
}

#endif /* IDOWNLOADABLECHUNK_H_ */