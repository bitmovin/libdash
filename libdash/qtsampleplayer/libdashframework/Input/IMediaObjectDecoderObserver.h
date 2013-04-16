/*
 * IMediaObjectDecoderObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_IMEDIAOBJECTDECODEROBSERVER_H_
#define LIBDASH_FRAMEWORK_INPUT_IMEDIAOBJECTDECODEROBSERVER_H_

#include "../../Decoder/IAudioObserver.h"
#include "../../Decoder/IVideoObserver.h"

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class IMediaObjectDecoderObserver
            {
                public:
                    virtual ~IMediaObjectDecoderObserver    () {}

                    virtual void OnDecodingFinished         ()                                                                          = 0;
                    virtual void OnVideoFrameDecoded        (const uint8_t **data, sampleplayer::decoder::videoFrameProperties* props)  = 0;
                    virtual void OnAudioSampleDecoded       (const uint8_t **data, sampleplayer::decoder::audioFrameProperties* props)  = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_INPUT_IMEDIAOBJECTDECODEROBSERVER_H_ */
