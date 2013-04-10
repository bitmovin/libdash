/*
 * BlockStream.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "BlockStream.h"
#include <limits>

using namespace dash::helpers;

BlockStream::BlockStream    () :
             length         (0)
{
}
BlockStream::~BlockStream   ()
{
    this->Clear();
}

void            BlockStream::PopAndDeleteFront      ()
{
    if(this->blockqueue.empty())
        return;

    this->length -= this->blockqueue.front()->len;
    DeleteBlock(this->blockqueue.front());
    this->blockqueue.pop_front();
}
void            BlockStream::PushBack               (block_t *block)
{
    this->length += block->len;
    this->blockqueue.push_back(block);
}
void            BlockStream::PushFront              (block_t *block)
{
    this->length += block->len;
    this->blockqueue.push_front(block);
}
const block_t*  BlockStream::GetBytes               (uint32_t len)
{
    /* Performance Intensive */
    if(this->length < len)
        return NULL;

    block_t *block = AllocBlock(len);
    this->BlockQueueGetBytes(block->data, block->len);

    this->length -= len;

    return block;
}
size_t          BlockStream::GetBytes               (uint8_t *data, size_t len)
{
    /* Performance Intensive */
    if(len > this->length)
        len = (size_t) this->length;

    this->BlockQueueGetBytes(data, len);

    this->length -= len;

    return len;
}
size_t          BlockStream::PeekBytes              (uint8_t *data, size_t len)
{
    /* Performance Intensive */
    if(len > this->length)
        len = (size_t) this->length;

    this->BlockQueuePeekBytes(data, len, 0);

    return len;
}
size_t          BlockStream::PeekBytes              (uint8_t *data, size_t len, size_t offset)
{
    /* Performance Intensive */
    if(len > this->length)
        len = (size_t) this->length;

    if (offset + len > this->length)
        len = (size_t) (this->length - offset);

    this->BlockQueuePeekBytes(data, len, offset);

    return len;
}
uint64_t        BlockStream::Length                 () const
{
    return this->length;
}
const block_t*  BlockStream::GetFront               ()
{
    if(this->blockqueue.empty())
        return NULL;

    const block_t* ret = this->blockqueue.front();
    this->length -= ret->len;
    this->blockqueue.pop_front();

    return ret;
}
const block_t*  BlockStream::Front                  () const
{
    if(this->blockqueue.empty())
        return NULL;

    return this->blockqueue.front();
}
bool            BlockStream::BlockQueueGetBytes     (uint8_t *data, uint32_t len)
{
    uint32_t pos = 0;

    block_t *block = NULL;

    while(pos < len)
    {
        block = this->blockqueue.front();
        if((len - pos) < (block->len))
        {
            memcpy(data + pos, block->data, len - pos);

            this->blockqueue.pop_front();

            block_t* newfront = AllocBlock(block->len - (len - pos));
            memcpy(newfront->data, block->data + (len - pos), newfront->len);

            DeleteBlock(block);
            this->blockqueue.push_front(newfront);

            return true;
        }
        else
        {
            memcpy(data + pos, block->data, block->len);
            pos += block->len;

            DeleteBlock(block);
            this->blockqueue.pop_front();
        }
    }

    return false;
}
bool            BlockStream::BlockQueuePeekBytes    (uint8_t *data, uint32_t len, size_t offset)
{
    uint32_t pos = 0;
    int      cnt = 0;

    const block_t *block = NULL;

    while(pos < len)
    {
        block = this->blockqueue.at(cnt);
        if((offset + len - pos) < (block->len))
        {
            memcpy(data + pos, block->data + offset, len - pos - offset);
            return true;
        }
        else
        {
            memcpy(data + pos, block->data + offset, block->len - offset);
            pos += block->len;
        }

        cnt++;
    }

    return false;
}
uint8_t         BlockStream::ByteAt                 (uint64_t position) const
{
    if(position > this->length)
        return -1;

    uint64_t pos = 0;

    for(size_t i = 0; i < this->blockqueue.size(); i++)
    {
        const block_t *block = this->blockqueue.at(i);

        if(pos + block->len > position)
            return block->data[position - pos];
        else
            pos += block->len;
    }

    return -1;
}
const block_t*  BlockStream::ToBlock                ()
{
    if(this->length > std::numeric_limits<size_t>::max())
        return NULL;

    return BlockStream::GetBytes((size_t)this->length);
}
void            BlockStream::Clear                  ()
{
    while(!this->blockqueue.empty())
    {
        DeleteBlock(this->blockqueue.front());
        this->blockqueue.pop_front();
    }

    this->length = 0;
}
void            BlockStream::EraseFront             (uint64_t len)
{
    if(len > this->length)
        len = this->length;

    uint64_t actLen = 0;

    while(actLen < len)
    {
        if(this->blockqueue.size() == 0)
            return;

        block_t *front = this->blockqueue.front();

        if((actLen + front->len) <= len)
        {
            this->length    -= front->len;
            actLen          += front->len;

            DeleteBlock(front);
            this->blockqueue.pop_front();
        }
        else
        {
            uint32_t diff       = (uint32_t) (len - actLen);
            this->length       -= diff;
            actLen             += diff;
            block_t* newfront   = AllocBlock(front->len - diff);

            memcpy(newfront->data, front->data + diff, newfront->len);

            DeleteBlock(front);
            this->blockqueue.pop_front();
            this->blockqueue.push_front(newfront);
        }
    }
}
BlockStream*    BlockStream::GetBlocks              (uint64_t len)
{
    if(len > this->length)
        return NULL;

    BlockStream *blocks = new BlockStream();

    uint64_t actLen = 0;

    while(actLen < len)
    {
        block_t *front = this->blockqueue.front();

        if((actLen + front->len) <= len)
        {
            this->length    -= front->len;
            actLen          += front->len;

            blocks->PushBack(front);
            this->blockqueue.pop_front();
        }
        else
        {
            uint32_t diff       = (uint32_t) (len - actLen);
            this->length       -= diff;
            actLen             += diff;
            block_t *block      = AllocBlock(diff);
            block_t* newfront   = AllocBlock(front->len - diff);

            memcpy(block->data, front->data, diff);
            blocks->PushBack(block);

            memcpy(newfront->data, front->data+ diff, newfront->len);

            DeleteBlock(front);
            this->blockqueue.pop_front();
            this->blockqueue.push_front(newfront);
        }
    }

    return blocks;
}