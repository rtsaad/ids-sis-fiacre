#ifndef _DATA_
#define _DATA_

#if defined XENOMAI
    #include <task.h>
#elif defined POSIX
    #include <pthread.h>
    #include <semaphore.h>
#endif

//typedef int bool;
#include "stdbool.h"

/** 
 * @var typedef struct s_Transition Transition
 * @brief A type definition for a transition
 */
typedef struct s_Transition Transition;

/** 
 * @var typedef struct s_Edge Edge
 * @brief A type definition for a edge from a place to a transition
 */
typedef struct s_Edge Edge;

/**
 * @var typedef struct s_fromPlace_toTransition
 * @brief A type definition for a edge from a place to a transition
 */
typedef struct s_fromPlaceToTransition fromPlaceToTransition;


/**
 * @var typedef struct s_fromTransitionToPlace
 * @brief A type definition for a edge from a place to a transition
 */
typedef struct s_fromTransitionToPlace fromTransitionToPlace;

/** 
 * @var typedef struct s_Place Place
 * @brief A type definition for a place
 */
typedef struct s_Place Place;

/** 
 * @var typedef struct s_Call Call
 * @brief A type definition for an extern call
 */
typedef struct s_Extern Extern;

/** 
 * @var typedef struct s_Call Call
 * @brief A type definition for an extern call
 */
typedef struct s_PriorityRelation PriorityRelation;

/**
 * A structure to represent a transition
 */
struct s_Transition
{
    int idx; /** the index of the transition */
    char *name; /** the name of the transition*/
    int minTime; /** the minimal time of the timed guard */
    int maxTime; /** the maximal time of the timed guard */
    fromPlaceToTransition *preset; /** the index of the first pre-place in the preset table */
    int sizePreset; /** the number of pre-place */
    fromTransitionToPlace *postset; /** the index of the first post-place in the postset table */
    int sizePostset; /** the number of post-place */
    bool (*pre)(); /** the fonction pre associated to the transition */
    bool (*act)(); /** the fonction act associated to the transition */
    Extern *call; /** the idx of the extern call function associated to the transition */
    int alarm; /** The alarm value is 0 if the transition has no alarm and 1 otherwise */
#if defined XENOMAI // TODO : remplacer par void * ?
    RT_TASK *task; /** the task in taskset (if exists) linked to the transition. The task is the same for the process or event */
#elif defined POSIX
    pthread_t *task; /** the task in taskset (if exists) linked to the transition. The task is the same for the process or event */
    sem_t *sem_suspend;
#endif
    int enabled_state; /** The enabled state of the transtion. This is a bit set where a bit indicates if the pre-place is marked or not */
    int state_process; /** A state to describe if the timed guard is in process */
    int isHigherPriority;
    int priority;
};

/**
 * A structure to describe an arc from a place to a transition
 */
struct s_Edge
{
    Place *fromPlace; /** the pointer to the from-place */
    Transition *toTransition; /** the index of the transition in transitionset */
    int posEnableState; /** the index of the place in the set of pre-places of the transition */
};

/**
 * A structure to represent a place
 */
struct s_Place
{
    int idx; /** the index of the place in the placeset */
    char *name; /** The name of the place */
    int mark; /** the mark of the place */
    Edge *edge; /** index of the first edge of the place in the edgeset */
    int nbEdges; /** number of edges used by the place */
};

/**
 * A structure to represent a extern stub
 */
struct s_Extern
{
    int idx; /** the index of the extern stub */
    char *name; /** The name of the extern stub */
    bool isEvent; /** this extern stub is an extern event */
    Transition **startTransition;
    int nbStartTransition;
    Transition **endTransition;
    int nbEndTransition;
    int *ready;
    int *terminate;
    void (*function)(); /** the wrapper */
};

/**
 * A structure to represent an arc from a place to a transition
 */
struct s_fromPlaceToTransition
{
    Place *fromPlace; /** the pointer to the from-place */
    Transition *toTransition; /** the pointer to the from to-transition */
    bool read;
};

/**
 * A structure to represent an arc from a transtion to a place
 */
struct s_fromTransitionToPlace
{
    Transition *fromTransition; /** the pointer to the from-transtion */
    Place *toPlace; /** the pointer to the to-place */
    
};

/**
 * A structure to represent a relation of priority between two transitions
 */
struct s_PriorityRelation
{
    Transition *lower; /** the pointer to the lower priority transition */
    Transition *higher; /** the pointer to the higher priorty transition */
};


#endif
