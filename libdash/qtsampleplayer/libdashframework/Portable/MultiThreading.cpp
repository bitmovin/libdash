#include "MultiThreading.h"

THREAD_HANDLE   CreateThreadPortable    (void *(*start_routine) (void *), void *arg)
{
    #if defined _WIN32 || defined _WIN64
        return CreateThread (0, 0, (LPTHREAD_START_ROUTINE)start_routine, (LPVOID)arg, 0, 0);
    #else
        THREAD_HANDLE th = (THREAD_HANDLE)malloc(sizeof(pthread_t));
    
        if (!th)
        {
            std::cerr << "Error allocating thread." << std::endl;
            return NULL;
        }

        if(int err = pthread_create(th, NULL, start_routine, arg))
        {
            std::cerr << strerror(err) << std::endl;
            return NULL;
        }
        return th;
    #endif
}
void            DestroyThreadPortable   (THREAD_HANDLE th)
{
    #if !defined _WIN32 && !defined _WIN64
        if(th)
            free(th);
    #endif
}

/****************************************************************************
* Condition variables for Windows XP and older windows sytems
*****************************************************************************/
#if defined WINXPOROLDER
    void InitCondition       (condition_variable_t *cv)
    {
        InitializeCriticalSection(&cv->waitersCountLock);

        cv->waitersCount        = 0;
        cv->waitGenerationCount = 0;
        cv->releaseCount        = 0;

        cv->waitingEvent = CreateEvent (NULL,  // no security
                                        TRUE,  // manual-reset
                                        FALSE, // non-signaled initially
                                        NULL); // unnamed
    }
    void WaitCondition       (condition_variable_t *cv, CRITICAL_SECTION *externalMutex)
    {
        EnterCriticalSection(&cv->waitersCountLock);

        cv->waitersCount++;

        int currentGenerationCount = cv->waitGenerationCount;

        LeaveCriticalSection(&cv->waitersCountLock);
        LeaveCriticalSection(externalMutex);

        bool isWaitDone = false;
        while(!isWaitDone)
        {
            WaitForSingleObject (cv->waitingEvent, INFINITE);
            EnterCriticalSection (&cv->waitersCountLock);

            isWaitDone = (cv->releaseCount > 0 && cv->waitGenerationCount != currentGenerationCount);
            LeaveCriticalSection (&cv->waitersCountLock);
        }

        EnterCriticalSection(externalMutex);
        EnterCriticalSection(&cv->waitersCountLock);

        cv->waitersCount--;
        cv->releaseCount--;
        bool isLastWaiter = (cv->releaseCount == 0);

        LeaveCriticalSection(&cv->waitersCountLock);

        if(isLastWaiter)
            ResetEvent(cv->waitingEvent);
    }
    void SignalCondition     (condition_variable_t *cv)
    {
        EnterCriticalSection(&cv->waitersCountLock);

        if(cv->waitersCount > cv->releaseCount) 
        {
            SetEvent(cv->waitingEvent);
            cv->releaseCount++;
            cv->waitGenerationCount++;
        }

        LeaveCriticalSection(&cv->waitersCountLock);
    }
    void BroadcastCondition  (condition_variable_t *cv)
    {
        EnterCriticalSection(&cv->waitersCountLock);

        if(cv->waitersCount > 0) 
        {
            SetEvent(cv->waitingEvent);
            cv->releaseCount = cv->waitersCount;
            cv->waitGenerationCount++;
        }

        LeaveCriticalSection(&cv->waitersCountLock);
}
#endif