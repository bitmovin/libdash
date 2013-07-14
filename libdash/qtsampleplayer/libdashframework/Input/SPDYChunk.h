/*
 * SPDYChunk.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Created on: 7/13/2013
 * Author: Christopher Mueller <christopher.mueller@bitmovin.net>
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_SPDYCHUNK_H
#define LIBDASH_FRAMEWORK_INPUT_SPDYCHUNK_H

#include "../libdash/source/helpers/SyncedBlockStream.h"
#include "IChunk.h"

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class SPDYChunk
            {
                public:
                    SPDYChunk           (dash::network::IChunk *chunk);
                    virtual ~SPDYChunk  ();

                    dash::network::IChunk               *chunk;
                    uint64_t                            contentLength;
                    uint64_t                            bytesRead;
                    dash::helpers::SyncedBlockStream    blockStream;

            };
        }
    }
}

#endif // LIBDASH_FRAMEWORK_INPUT_SPDYCHUNK_H
