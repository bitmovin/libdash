#ifndef PORTABLE_MULTITHREADING_H_
#define PORTABLE_MULTITHREADING_H_

#if defined _WIN32 || defined _WIN64

    #define _WINSOCKAPI_
    #include <Windows.h>
    #define DeleteConditionVariable(cond_p) {}

    typedef HANDLE THREAD_HANDLE;

    #if defined WINXPOROLDER
        /****************************************************************************
        * Variables
        *****************************************************************************/
        struct condition_variable_t
        {
            int                 waitersCount;           // Count of the number of waiters.
            CRITICAL_SECTION    waitersCountLock;       // Serialize access to <waitersCount>.
            int                 releaseCount;           // Number of threads to release via a <BroadcastCondition> or a <SignalCondition>. 
            int                 waitGenerationCount;    // Keeps track of the current "generation" so that we don't allow one thread to steal all the "releases" from the broadcast.
            HANDLE              waitingEvent;           // A manual-reset event that's used to block and release waiting threads. 
        };
        /****************************************************************************
        * Prototypes
        *****************************************************************************/
        void InitCondition       (condition_variable_t *cv);
        void WaitCondition       (condition_variable_t *cv, CRITICAL_SECTION *externalMutex);
        void SignalCondition     (condition_variable_t *cv);
        void BroadcastCondition  (condition_variable_t *cv);
        /****************************************************************************
        * Defines
        *****************************************************************************/
        #define CONDITION_VARIABLE  condition_variable_t

        #define InitializeConditionVariable(cond_p)                 InitCondition(cond_p)
        #define SleepConditionVariableCS(cond_p, mutex_p, infinite) WaitCondition(cond_p, mutex_p) // INFINITE should be handled mor properly
        #define WakeConditionVariable(cond_p)                       SignalCondition(cond_p)
        #define WakeAllConditionVariable(cond_p)                    BroadcastCondition(cond_p)
    #endif

#else

    #include <string.h>
    #include <pthread.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <iostream>

    #define CRITICAL_SECTION    pthread_mutex_t
    #define CONDITION_VARIABLE  pthread_cond_t

    #define InitializeCriticalSection(mutex_p)                  pthread_mutex_init(mutex_p, NULL)
    #define DeleteCriticalSection(mutex_p)                      pthread_mutex_destroy(mutex_p)
    #define EnterCriticalSection(mutex_p)                       pthread_mutex_lock(mutex_p)
    #define LeaveCriticalSection(mutex_p)                       pthread_mutex_unlock(mutex_p)
    #define InitializeConditionVariable(cond_p)                 pthread_cond_init(cond_p, NULL)
    #define DeleteConditionVariable(cond_p)                     pthread_cond_destroy(cond_p)
    #define SleepConditionVariableCS(cond_p, mutex_p, infinite) pthread_cond_wait(cond_p, mutex_p) // INFINITE should be handled mor properly
    #define WakeConditionVariable(cond_p)                       pthread_cond_signal(cond_p)
    #define WakeAllConditionVariable(cond_p)                    pthread_cond_broadcast(cond_p)

    typedef pthread_t* THREAD_HANDLE;

#endif

THREAD_HANDLE   CreateThreadPortable    (void *(*start_routine) (void *), void *arg);
void            DestroyThreadPortable   (THREAD_HANDLE th);

#endif  // PORTABLE_MULTITHREADING_H_