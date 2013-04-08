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

#ifndef SAMPLEPLAYER_INPUT_IMEDIAOBJECTDECODEROBSERVER_H_
#define SAMPLEPLAYER_INPUT_IMEDIAOBJECTDECODEROBSERVER_H_

namespace sampleplayer
{
    namespace input
    {
        class IMediaObjectDecoderObserver
        {
            public:
                virtual ~IMediaObjectDecoderObserver    () {}

                virtual void OnDecodingFinished         () = 0;
        };
    }
}
#endif /* SAMPLEPLAYER_INPUT_IMEDIAOBJECTDECODEROBSERVER_H_ */
