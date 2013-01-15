/*
 * Block.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "config.h"

namespace dash
{
    namespace helpers
    {
        struct block_t
        {
            uint8_t *data;
            size_t  len;
            float   millisec;
            size_t  offset;
        };

        static inline block_t*  AllocBlock      (size_t len)
        {
            block_t *block  = (block_t *)malloc(sizeof(block_t));
            block->data     = new uint8_t[len];
            block->len      = len;
            block->millisec = 0;
            block->offset   = 0;
      
            return block;
        }
        static inline void      DeleteBlock     (block_t *block)
        {
            if(block)
            {
                delete [] block->data;
                free(block);
                block = NULL;
            }
        }
        static inline block_t*  DuplicateBlock  (block_t *block)
        {
            block_t *ret = AllocBlock(block->len);
            ret->offset  = block->offset;

            memcpy(ret->data, block->data, ret->len);

            return block;
        }
    }
}

#endif