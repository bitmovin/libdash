/*
 * SyncedBlockStream.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SyncedBlockStream.h"

using namespace dash::helpers;

SyncedBlockStream::SyncedBlockStream    () :
                   eos                  (false)
{
    InitializeConditionVariable (&this->full);
    InitializeCriticalSection   (&this->monitorMutex);
}
SyncedBlockStream::~SyncedBlockStream   ()
{
    DeleteConditionVariable(&this->full);
    DeleteCriticalSection(&this->monitorMutex);
}

void            SyncedBlockStream::PopAndDeleteFront  ()
{
    EnterCriticalSection(&this->monitorMutex);

    BlockStream::PopAndDeleteFront();

    LeaveCriticalSection(&this->monitorMutex);
}
void            SyncedBlockStream::PushBack           (block_t *block)
{
    EnterCriticalSection(&this->monitorMutex);

    BlockStream::PushBack(block);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
void            SyncedBlockStream::PushFront          (block_t *block)
{
    EnterCriticalSection(&this->monitorMutex);

    BlockStream::PushFront(block);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
const block_t*  SyncedBlockStream::GetBytes           (uint32_t len)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    const block_t* block = BlockStream::GetBytes(len);
    LeaveCriticalSection(&this->monitorMutex);

    return block;
}
size_t          SyncedBlockStream::GetBytes           (uint8_t *data, size_t len)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return 0;
    }

    size_t ret = BlockStream::GetBytes(data, len);
    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
size_t          SyncedBlockStream::PeekBytes          (uint8_t *data, size_t len)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return 0;
    }

    size_t ret = BlockStream::PeekBytes(data, len);
    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
size_t          SyncedBlockStream::PeekBytes          (uint8_t *data, size_t len, size_t offset)
{
    EnterCriticalSection(&this->monitorMutex);

    while((this->length == 0 || offset >= this->length) && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0 || offset >= this->length)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return 0;
    }

    size_t ret = BlockStream::PeekBytes(data, len, offset);
    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
uint64_t        SyncedBlockStream::Length             () const
{
    EnterCriticalSection(&this->monitorMutex);

    uint64_t len = BlockStream::Length();

    LeaveCriticalSection(&this->monitorMutex);

    return len;
}
const block_t*  SyncedBlockStream::GetFront           ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    const block_t* block = BlockStream::GetFront();
    LeaveCriticalSection(&this->monitorMutex);

    return block;
}
const block_t*  SyncedBlockStream::Front              () const
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    const block_t* block = BlockStream::Front();
    LeaveCriticalSection(&this->monitorMutex);

    return block;
}
uint8_t         SyncedBlockStream::ByteAt             (uint64_t position) const
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length < position && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length < position)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return 0;
    }

    uint8_t ret = BlockStream::ByteAt(position);
    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
const block_t*  SyncedBlockStream::ToBlock            ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    const block_t* block = BlockStream::ToBlock();
    LeaveCriticalSection(&this->monitorMutex);

    return block;
}
void            SyncedBlockStream::Clear              ()
{
    EnterCriticalSection(&this->monitorMutex);

    BlockStream::Clear();

    LeaveCriticalSection(&this->monitorMutex);
}
void            SyncedBlockStream::EraseFront         (uint64_t len)
{
    EnterCriticalSection(&this->monitorMutex);

    BlockStream::EraseFront(len);

    LeaveCriticalSection(&this->monitorMutex);
}
BlockStream*    SyncedBlockStream::GetBlocks          (uint64_t len)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->length == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->length == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    BlockStream *stream = BlockStream::GetBlocks(len);
    LeaveCriticalSection(&this->monitorMutex);

    return stream;
}
void            SyncedBlockStream::SetEOS             (bool value)
{
    EnterCriticalSection(&this->monitorMutex);

    this->eos = value;

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
