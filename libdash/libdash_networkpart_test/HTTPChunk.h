/*
 * HTTPChunk.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef HTTPCHUNK_H_
#define HTTPCHUNK_H_

#include "IChunk.h"

namespace libdashtest
{
    class HTTPChunk
    {
        public:
            HTTPChunk          (dash::network::IChunk *chunk);
            virtual ~HTTPChunk ();

            dash::network::IChunk*  Chunk           ();
            uint64_t                ContentLength   () const;
            uint64_t                BytesLeft       () const;
            uint64_t                BytesRead       () const;
            bool                    HeaderParsed    () const;

            void        HeaderParsed    (bool value);
            void        ContentLength   (uint64_t length);
            void        BytesRead       (uint64_t bytes);
            void        AddBytesRead    (uint64_t bytes);

        private:
            dash::network::IChunk   *chunk;
            uint64_t                contentLength;
            uint64_t                bytesLeft;
            uint64_t                bytesRead;
            bool                    isHeaderParsed;
    };
}

#endif /* HTTPCHUNK_H_ */
