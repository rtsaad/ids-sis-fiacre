#ifndef _HIPPO_
#define _HIPPO_

#if !defined(XENOMAI) && !defined(POSIX)
    #define POSIX
#endif

#if defined XENOMAI
    #include <stdio.h>
    #include <stdlib.h>
    #include <alarm.h>
    #include <task.h>
    #include <sem.h>
    #include <mutex.h>
#elif defined POSIX
    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <unistd.h>
    #include <time.h>
    #include <sys/signal.h>
    #include <sys/time.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <fcntl.h>
#endif

#include "data.h"
#include "hippo_app_data.h"
#include "hippo_app_functions.h"

/** \def typedef struct s_fireable Fireable
 *  \brief A structure to represent a element of the ordered list of fireable
 *  transitions
 */
typedef struct s_fireable Fireable;

/** a fireable element
 */
struct s_fireable {
    int state; /** is the transition is fireable */
    int prev; /** previous fireable transition */
    int next; /** next fireable transition */
};

/** \def typedef struct s_enable Enable
 *  \brief A structure to represent a element of the ordered list of enable
 *  transitions
 */
typedef struct s_enable Enable;

/** an enable element
 */
struct s_enable {
    int state; /** is the transition is enable */
    int prev; /** previous enable transition */
    int next; /** next enable transition */
};

/**
 * @def typdeef struct s_setOfActiveAlarms setOfActiveAlarms
 * @brieg A structure to manage the alarms of hippo
 * */
typedef struct s_ActiveAlarm ActiveAlarm;

/**
 * A hippo alarm
 * */
struct s_ActiveAlarm{
    unsigned long long int date;
    int active;
    int prev;
    int next;
};

#if defined XENOMAI
    /** The synchronous global clock alarm
     * */
    RT_ALARM clock_alarm;

    /** The set of tasks used by the engine
     */
    RT_TASK taskset[NUMBER_OF_TASKS];

    /** This semaphore is used to synchronized the engine, alarms ans tasks
     */
    RT_SEM semaphoreToCallTheEngine;

    /** This mutex is used to protect shared variables in engine
     */
    RT_MUTEX mutexDataEngine;

    /** This is the main task to execute the engine
     */
    RT_TASK taskEngine;
#elif defined POSIX
    /** The synchronous global clock alarm
     * */
    timer_t clock_alarm;
    sigset_t mask;
    struct sigaction sa;
    struct sigevent sev;
    struct itimerspec its;

    /** The set of tasks used by the engine
     */
    pthread_t taskset[NUMBER_OF_TASKS];

    /** This semaphore is used to synchronized the engine, alarms ans tasks
     */
    sem_t semaphoreToCallTheEngine;

    /** This mutex is used to protect shared variables in engine
     */
    static pthread_mutex_t mutexDataEngine;

    /** This is the main task to execute the engine
     */
    pthread_t taskEngine;
#endif

/**
 * Run the engine
 */
void engine_run();

#endif
