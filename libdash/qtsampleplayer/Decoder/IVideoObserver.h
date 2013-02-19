/*
 * IVideoObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef IVIDEOOBSERVER_H_
#define IVIDEOOBSERVER_H_

#include <stdint.h>

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
}

namespace sampleplayer
{
    namespace decoder
    {
        enum   pixelFormat  {
                                yuv420p = 0,
                                yuv422p = 4
                            };

        struct videoFrameProperties
        {
            int*        linesize;
            int         frame;
            int         streamIndex;
            int         framesPerChunk;
            int         width;
            int         height;
            bool        fireError;
            char*       errorMessage;
            pixelFormat pxlFmt;
        };

        class  IVideoObserver
        {
            public:
                virtual ~IVideoObserver () {}

                virtual void OnVideoDataAvailable (const uint8_t **data, videoFrameProperties* props) = 0;
        };
    }
}

#endif /* IVIDEOOBSERVER_H_ */
