/*
 * SyncedBlockStream.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef __SYNCEDBLOCKSTREAM_H__
#define __SYNCEDBLOCKSTREAM_H__

#include "config.h"

#include "BlockStream.h"
#include "../portable/MultiThreading.h"

namespace dash
{
    namespace helpers
    {
        class SyncedBlockStream : public BlockStream
        {
            public:
                SyncedBlockStream          ();
                virtual ~SyncedBlockStream ();

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
                virtual void            SetEOS              (bool value);

            private:
                bool eos;

                mutable CRITICAL_SECTION    monitorMutex;
                mutable CONDITION_VARIABLE  full;

        };
    }
}

#endif // __SYNCEDBLOCKSTREAM_H__