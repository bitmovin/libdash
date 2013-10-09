/*
 * Buffer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_BUFFER_BUFFER_H_
#define LIBDASH_FRAMEWORK_BUFFER_BUFFER_H_

#include "../Portable/MultiThreading.h"
#include "IBufferObserver.h"
#include <deque>
#include <vector>

namespace libdash
{
    namespace framework
    {
        namespace buffer
        {
            template <class T>
            class Buffer
            {
                public:
                    Buffer          (uint32_t maxcapacity, BufferType type);
                    virtual ~Buffer ();

                    bool        PushBack        (T *element);
                    T*          Front           ();
                    T*          GetFront        ();
                    void        PopFront        ();
                    void        ClearTail       ();
                    void        Clear           ();
                    void        SetEOS          (bool value);
                    uint32_t    Length          ();
                    uint32_t    Capacity        ();
                    void        AttachObserver  (IBufferObserver *observer);
                    void        Notify          ();

                private:
                    std::deque<T*>                  objects;
                    std::vector<IBufferObserver *>  observer;
                    bool                            eos;
                    uint32_t                        maxcapacity;
                    mutable CRITICAL_SECTION        monitorMutex;
                    mutable CONDITION_VARIABLE      full;
                    mutable CONDITION_VARIABLE      empty;
                    BufferType                      type;
            };
        }
    }
}

using namespace libdash::framework::buffer;

template <class T>
Buffer<T>::Buffer   (uint32_t maxcapacity, BufferType type) :
            type         (type),
            eos          (false),
            maxcapacity  (maxcapacity)
{
    InitializeConditionVariable (&this->full);
    InitializeConditionVariable (&this->empty);
    InitializeCriticalSection   (&this->monitorMutex);
}
template <class T>
Buffer<T>::~Buffer  ()
{
    this->Clear();

    DeleteConditionVariable (&this->full);
    DeleteConditionVariable (&this->empty);
    DeleteCriticalSection   (&this->monitorMutex);
}

template <class T>
bool        Buffer<T>::PushBack         (T *object)
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->objects.size() >= this->maxcapacity && !this->eos)
        SleepConditionVariableCS(&this->empty, &this->monitorMutex, INFINITE);

    if(this->objects.size() >= this->maxcapacity)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return false;
    }

    this->objects.push_back(object);

    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
    return true;
}
template <class T>
T*          Buffer<T>::Front            ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->objects.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->objects.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    T *object = this->objects.front();

    LeaveCriticalSection(&this->monitorMutex);

    return object;
}
template <class T>
T*          Buffer<T>::GetFront         ()
{
    EnterCriticalSection(&this->monitorMutex);

    while(this->objects.size() == 0 && !this->eos)
        SleepConditionVariableCS(&this->full, &this->monitorMutex, INFINITE);

    if(this->objects.size() == 0)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return NULL;
    }

    T *object = this->objects.front();
    this->objects.pop_front();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();

    return object;
}
template <class T>
uint32_t    Buffer<T>::Length           ()
{
    EnterCriticalSection(&this->monitorMutex);

    uint32_t ret = this->objects.size();

    LeaveCriticalSection(&this->monitorMutex);

    return ret;
}
template <class T>
void        Buffer<T>::PopFront         ()
{
    EnterCriticalSection(&this->monitorMutex);

    this->objects.pop_front();

    WakeAllConditionVariable(&this->empty);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
template <class T>
void        Buffer<T>::SetEOS           (bool value)
{
    EnterCriticalSection(&this->monitorMutex);

    this->eos = value;

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
}
template <class T>
void        Buffer<T>::AttachObserver   (IBufferObserver *observer)
{
    this->observer.push_back(observer);
}
template <class T>
void        Buffer<T>::Notify           ()
{
    for(size_t i = 0; i < this->observer.size(); i++)
        this->observer.at(i)->OnBufferStateChanged(this->type, (uint32_t)((double)this->objects.size()/(double)this->maxcapacity*100.0));
}
template <class T>
void        Buffer<T>::ClearTail        ()
{
    EnterCriticalSection(&this->monitorMutex);

    int size = this->objects.size() - 1;

    if (size < 1)
    {
        LeaveCriticalSection(&this->monitorMutex);
        return;
    }

    T* object = this->objects.front();
    this->objects.pop_front();
    for(int i=0; i < size; i++)
    {
        delete this->objects.front();
        this->objects.pop_front();
    }

    this->objects.push_back(object);
    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
template <class T>
void        Buffer<T>::Clear            ()
{
    EnterCriticalSection(&this->monitorMutex);

    for(int i = 0; i < this->objects.size(); i++)
        delete this->objects[i];

    this->objects.clear();

    WakeAllConditionVariable(&this->empty);
    WakeAllConditionVariable(&this->full);
    LeaveCriticalSection(&this->monitorMutex);
    this->Notify();
}
template <class T>
uint32_t    Buffer<T>::Capacity         ()
{
    return this->maxcapacity;
}

#endif /* LIBDASH_FRAMEWORK_BUFFER_BUFFER_H_ */
