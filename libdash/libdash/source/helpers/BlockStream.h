/*
 * BlockStream.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef __BLOCKSTREAM_H__
#define __BLOCKSTREAM_H__

#include "config.h"

#include "Block.h"

namespace dash
{
    namespace helpers
    {
        class BlockStream
        {
            public:
                BlockStream          ();
                virtual ~BlockStream ();

                virtual void            PushBack            (block_t *block);
                virtual void            PushFront           (block_t *block);
                virtual const block_t*  GetBytes            (uint32_t len);
                virtual size_t          GetBytes            (uint8_t *data, size_t len);
                virtual size_t          PeekBytes           (uint8_t *data, size_t len);
                virtual size_t          PeekBytes           (uint8_t *data, size_t len, size_t offset);
                virtual const block_t*  GetFront            ();
                virtual const block_t*  Front               ()                  const;
                virtual uint64_t        Length              ()                  const;
                virtual uint8_t         ByteAt              (uint64_t position) const;
                virtual const block_t*  ToBlock             ();
                virtual void            Clear               ();
                virtual void            EraseFront          (uint64_t len);
                virtual BlockStream*    GetBlocks           (uint64_t len);
                virtual void            PopAndDeleteFront   ();

            protected:
                uint64_t                length;
                std::deque<block_t *>   blockqueue;

                virtual bool BlockQueueGetBytes     (uint8_t *data, uint32_t len);
                virtual bool BlockQueuePeekBytes    (uint8_t *data, uint32_t len, size_t offset);
        };
    }
}

#endif // __BLOCKSTREAM_H__