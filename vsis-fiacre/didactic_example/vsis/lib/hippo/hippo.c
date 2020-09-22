#include "hippo.h"
#include "debug.h"

#include <sys/time.h>
#include <string.h>
#include <assert.h>

#if !defined(_LTTNG_)
    #define tracepoint(...)
#else
    #include "hippo-tp.h"
#endif

#if defined(_DEBUG_ON_)
    int hippo_debug = 1;
#else
    int hippo_debug = 0;
#endif

#define REPORT_NULL_SYSCALL(call, string)	\
  do {int res_ = call; 				\
    if (res_ != 0) {				\
      fprintf(stderr,"%s: %s\n",string,strerror(res_));	\
      assert(res_ == 0);			\
    } 						\
  } while (0)

#define REPORT_MINUS_ONE_SYSCALL(call, string)	\
  do {int res_ = call; 				\
    if (res_ == -1) {				\
      fprintf(stderr,"%s: %s\n",string,strerror(res_));	\
      assert(res_ == -1);			\
    } 						\
  } while (0)



/*******************************************************************************
 * constants
 ******************************************************************************/
#ifndef _TICK_UNIT_
    #define _TICK_UNIT_ 1000000000
#endif
#define NOT_FIREABLE -1
#define FIREABLE 1
#define EVENT_PRIORITY 98
#define ENGINE_PRIORITY 97
#define PROCESS_PRIORITY 1
#define ALARM_IS_ACTIVE 1
#define ALARM_IS_NOT_ACTIVE 0
#define NO_PREVIOUS -1
#define NONE -1
#define ENABLE 1
#define NOT_ENABLE 0

/*******************************************************************************
 * macros
 ******************************************************************************/
#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                            } while (0)

#define is_transition_delayed_by_time(transition) !((transition->minTime == 0)&&(transition->maxTime ==0 || transition->maxTime ==-1))
#define is_transition_immediate(transition) ((transition->minTime == 0)&&(transition->maxTime ==0))
#define is_bound_to_an_extern_task(transition) (transition->call != NULL)
#define is_transition_has_an_event(transition) (transition->event != NULL)
#define is_transition_fireable(transition) (setOfFireableTransitions[transition->idx].state == FIREABLE)
#define is_transition_enable(transition) (! transition->enabled_state)

#if defined XENOMAI
    #define unblock_engine rt_sem_v(&semaphoreToCallTheEngine)
#elif defined POSIX
    #define unblock_engine REPORT_MINUS_ONE_SYSCALL(sem_post(&semaphoreToCallTheEngine),"unblock_engine sem_post")
#endif

#if defined XENOMAI
    #define block_engine rt_sem_p(&semaphoreToCallTheEngine, 0)
#elif defined POSIX
  #define block_engine  while (sem_wait(&semaphoreToCallTheEngine) == -1){ if (errno == EINTR) errno = 0; else {fprintf(stderr,"block_engine: %s\n",strerror(errno)); assert(errno == EINTR); break;}}
    // TODO : find a more elegant solution with posix and avoid the test on EINTR
#endif

#if defined XENOMAI
    #define acquire_mutex_data_engine rt_mutex_acquire_timed(&mutexDataEngine, NULL)
#elif defined POSIX
    #define acquire_mutex_data_engine REPORT_NULL_SYSCALL(pthread_mutex_lock(&mutexDataEngine),"acquire_mutex_data_engine")
#endif

#if defined XENOMAI
    #define release_mutex_data_engine rt_mutex_release(&mutexDataEngine)
#elif defined POSIX
    #define release_mutex_data_engine  REPORT_NULL_SYSCALL(pthread_mutex_unlock(&mutexDataEngine),"release_mutex_data_engine")
#endif

#if defined XENOMAI
    #define suspend_extern_task(extern) rt_task_suspend(NULL)
#elif defined POSIX
    #define suspend_extern_task(extern) while (sem_wait((*((extern)->startTransition))->sem_suspend) == -1){ if (errno == EINTR) errno = 0; else {fprintf(stderr,"suspend_extern_task: %s\n",strerror(errno)); assert(errno == EINTR); break;}}
#endif

#if defined XENOMAI
    #define resume_extern_task_bound_to_transition(transition) rt_task_resume(transition->task)
#elif defined POSIX
    #define resume_extern_task_bound_to_transition(transition) REPORT_MINUS_ONE_SYSCALL(sem_post((transition)->sem_suspend),"resume_extern_task_bound_to_transition")
#endif

/*******************************************************************************
 * private functions
 ******************************************************************************/

#if defined (XENOMAI)
    void * handle_global_clock(void *arg);
#elif defined (POSIX)
    static void  handle_global_clock(int sig, siginfo_t *si, void *uc);
#endif

void *handle_engine_execution(void *);
void *handle_execution_of_an_extern_function(void *arg);
void *handle_execution_of_an_extern_event(void *arg);
void start_engine();
void start_gloabl_clock();
void compute_priority();
void initialize_structures_for_the_engine();
void spawn_task_engine();
void initialize_structures_for_global_clock();
void initialize_set_of_active_alarm();
void initialize_structures_for_extern_events_and_tasks();
void initialize_values_of_the_model();
void initialize_transitionWithPreSet();
void spawn_task_for_extern(Extern *ext);
void update_transition_initial_states();
void declare_extern_as_active(Extern *ext);
void activate_alarm_of_a_transition(Transition *tr);
void fire_transition(Transition *transition);
void add_token_to_place(Place *place);
void remove_transition_from_the_fireable_set(Transition *transition);
void add_transition_to_the_fireable_set(Transition *transition);
void remove_transition_from_the_enable_set(Transition *transition);
void add_transition_to_the_enable_set(Transition *transition);
void update_state_transition_with_pre_condition_isTrWithPre_isTrEnabled(Transition *tr);
void update_state_transition_with_pre_condition(Transition *transition);
void update_state_of_all_transitions_with_pre_conditions(void);
void update_state_of_transition_after_empty_a_previous_place(Transition *transition, int idx);
void update_state_of_transition_after_add_a_token_in_a_previous_place(Transition *transition, int idx);
void print_state(char * comment_char, bool is_text_color);

void print_marked_places();
void print_enabled_transitions();
void print_fireable_transitions();
void print_state_of_alarms();

/*******************************************************************************
 * local variables
 ******************************************************************************/

#if defined (POSIX)
    int signum = SIGALRM;
#endif

unsigned long long int global_logical_time = 0;
int idxOfTheCurrentFireableTransition = NONE;
int idxOfTheLastFireableTransition = NONE;
int idxOfTheEarliestAlarm;
ActiveAlarm setOfActiveAlarms[NUMBER_OF_TRANSITIONS]  = {
    {-1, ALARM_IS_NOT_ACTIVE, NONE, NONE}
};
Extern *setOfFinishedExternEventsAndTasks[NUMBER_OF_EXTERNS] = { NULL };
int nbOfFinishedExterns = -1;
Fireable setOfFireableTransitions[NUMBER_OF_TRANSITIONS] = {
    {NOT_FIREABLE, NONE, NONE}
};
int idxOfTheCurrentEnableTransition = NONE;
Enable setOfEnableTransitions[NUMBER_OF_TRANSITIONS] = {
    {NOT_ENABLE, NONE, NONE}
};

int priorityRelations[NUMBER_OF_TRANSITIONS][NUMBER_OF_TRANSITIONS];

/*******************************************************************************
 * function implementations
 ******************************************************************************/
void (*thread_starting_hook) () = NULL;

void call_thread_starting_hook(char *thread_name)
{
  if (thread_starting_hook) {
    thread_starting_hook(NULL);	/* let portlib pick up a unique name */
  }
}


void engine_run() {
    printf("#             .''\n#   ._.-.___.' (`\\  >> Initialize engine structures <<\n"); // Art by Veronica Karlsson
    initialize_structures_for_the_engine();
    spawn_task_engine();
    initialize_structures_for_global_clock();
    printf("#  //(        ( `'  >> Engine is initialized and ready to start <<\n");
    printf("# '/ )\\ ).__. )     >> Compute initial state << \n");
    compute_priority();
    initialize_structures_for_extern_events_and_tasks();
    initialize_values_of_the_model();
    update_transition_initial_states();
    printf("# ' <' `\\ ._/'\\     >> GO hippo GO << \n#    `   \\     \\  vk\n");
    printf("# _TICK_UNIT_ = %d ns\n", _TICK_UNIT_);
    start_engine();
    pause();
    printf("# >> This is the end <<");
}

void initialize_structures_for_the_engine(){
    #if defined XENOMAI
        rt_sem_create(&semaphoreToCallTheEngine, "sync", 0, S_FIFO);
    #elif defined POSIX
        sem_init(&semaphoreToCallTheEngine, 0,0);
    #endif
    #if defined XENOMAI
        rt_mutex_create(&mutexDataEngine, "mutex_engine");
    #elif defined POSIX
        pthread_mutexattr_t mattr;
        pthread_mutexattr_init(&mattr);
        pthread_mutexattr_setprotocol(&mattr, PTHREAD_PRIO_INHERIT);
        pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
        pthread_mutexattr_settype(&mattr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutexattr_setrobust(&mattr, PTHREAD_MUTEX_ROBUST);
        pthread_mutex_init(&mutexDataEngine, &mattr);
    #endif
}

void initialize_values_of_the_model(){
    initial();
}

void spawn_task_engine(){
    #if defined XENOMAI
        rt_task_spawn(&taskEngine, "Task Engine", 0, ENGINE_PRIORITY, 0, handle_engine_execution, NULL);
    #elif defined POSIX
        struct sched_param params;
        pthread_attr_t attributs;
        pthread_attr_init(& attributs);
        params.sched_priority = sched_get_priority_max(SCHED_FIFO)-1;
        pthread_attr_setschedpolicy(& attributs, SCHED_FIFO);
        pthread_attr_setschedparam(& attributs, & params);
        pthread_create (&taskEngine, & attributs, handle_engine_execution, NULL);
    #endif
}

void initialize_structures_for_global_clock(){
    #if defined XENOMAI
        rt_alarm_create(&clock_alarm,"alarm_global_clock", handle_global_clock,NULL);
    #elif defined POSIX
        sigset_t   sigset;
        sigemptyset (&sigset);
        sigaddset (&sigset, signum);
        sigprocmask (SIG_BLOCK, &sigset, NULL);
        /* Establish handler for timer signal */
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction =  handle_global_clock;
        sigemptyset(&sa.sa_mask);
        if (sigaction(signum, &sa, NULL) == -1){
            errExit("sigaction");
        }
        sigemptyset(&mask);
        sigaddset(&mask, signum);
        if (sigprocmask(SIG_SETMASK, &mask, NULL) == -1){
            errExit("sigprocmask");
        }
        /* Create the timer */
        sev.sigev_notify = SIGEV_SIGNAL;
        sev.sigev_signo = signum;
        sev.sigev_value.sival_ptr = &clock_alarm;
        if (timer_create(CLOCK_REALTIME, &sev, &clock_alarm) == -1)
            errExit("timer_create");
    #endif
    initialize_set_of_active_alarm();
}

void initialize_set_of_active_alarm(){
    idxOfTheEarliestAlarm = NONE;
}

void update_transition_initial_states(){
    idxOfTheCurrentFireableTransition = NONE;
    for (Place *pl = &placeset[0]; pl < &placeset[NUMBER_OF_PLACES]; pl++) {
        if (pl->mark > 0) {
            for (Edge *e = pl->edge; e < pl->edge + pl->nbEdges; e++) { update_state_of_transition_after_add_a_token_in_a_previous_place(e->toTransition, e->posEnableState);
                log_printf("\x1B[31m%s %s %d\x1B[0m\n", pl->name, e->toTransition->name, e->toTransition->enabled_state);
            }
        }
    }
}

void start_engine() {
    unblock_engine;
    start_gloabl_clock();
}

void start_gloabl_clock(){
    #if defined (XENOMAI)
        rt_alarm_start(&clock_alarm, 1, _TICK_UNIT_);
    #elif defined (POSIX)
        its.it_value.tv_sec = _TICK_UNIT_ / 1000000000;
        its.it_value.tv_nsec = _TICK_UNIT_ % 1000000000;
        its.it_interval.tv_sec = its.it_value.tv_sec;
        its.it_interval.tv_nsec = its.it_value.tv_nsec;
        if (timer_settime(clock_alarm, 0, &its, NULL) == -1)
            errExit("timer_settime");
    #endif
}

void compute_priority(){
    for (int i=0; i < NUMBER_OF_TRANSITIONS; i++){
        transitionset[i].priority = 0;
        transitionset[i].isHigherPriority = 0;
        for (int j=0; j < NUMBER_OF_TRANSITIONS; j++){
            priorityRelations[i][j] = 0;
        }
    }

    for (int i = 0; i < NUMBER_OF_PRIORITY_RELATIONS; i ++){
        int l = (setOfPriorityRelations[i].lower)->idx;
        int h = (setOfPriorityRelations[i].higher)->idx;
        priorityRelations[l][h] = 1;
        transitionset[l].priority = 1;
    }
    int test = 1;

    while(test){
        test = 0;
        for (int i=0; i < NUMBER_OF_TRANSITIONS; i++){
            for (int j=0; j < NUMBER_OF_TRANSITIONS; j++){
                if (priorityRelations[i][j] == 1){
                    for (int k = 0; k < NUMBER_OF_TRANSITIONS; k++){
                        if ((priorityRelations[j][k] == 1)&&(priorityRelations[i][k] != 1)){
                            priorityRelations[i][k]= 1;
                            test = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i < NUMBER_OF_TRANSITIONS; i++){
        for (int j=0; j < NUMBER_OF_TRANSITIONS; j++){
            if (priorityRelations[i][j] == 1){
                transitionset[j].isHigherPriority = 1;
            }
        }
    }
}

void initialize_structures_for_extern_events_and_tasks() {
    for (Transition *tr = &transitionset[0]; tr < &transitionset[NUMBER_OF_TRANSITIONS]; tr++) {
        if (tr->minTime != 0) {
            tr->alarm = 1;
            log_printf("\x1B[31mAlarm handler %s is created\x1B[0m\n", tr->name);
        }
        for (int i = 0; i < tr->sizePreset; i++) {
            tr->enabled_state |= (1 << i);
        }
        if(is_transition_enable(tr)){
          add_transition_to_the_enable_set(tr);
        }
    }
    for (Extern *ext = &externset[0]; ext < &externset[NUMBER_OF_EXTERNS]; ext++) {
        spawn_task_for_extern(ext);
    }
}

void spawn_task_for_extern(Extern *ext){
        if (ext->isEvent) {
            #if defined XENOMAI
                rt_task_spawn(&taskset[ext->idx], ext->name, 0, EVENT_PRIORITY, 0, handle_execution_of_an_extern_event, ext);
            #elif defined POSIX
                sem_t * sem_id= malloc(sizeof(sem_t));
                sem_init(sem_id, 0, 0);
                for (int i =0; i < ext->nbStartTransition; i++){
                    Transition *tr = *(ext->startTransition + i);
                    tr->sem_suspend = sem_id;
                }
                struct sched_param params;
                pthread_attr_t attributs;
                pthread_attr_init(& attributs);
                params.sched_priority = sched_get_priority_max(SCHED_FIFO)-10;
                pthread_attr_setschedpolicy(& attributs, SCHED_FIFO);
                pthread_attr_setschedparam(& attributs, & params);
                pthread_create (&taskset[ext->idx], & attributs, handle_execution_of_an_extern_event, ext);
            #endif
            log_printf("\x1B[Task for extern event [%s] is spawned\x1B[0m\n", ext->name);
        } else {
            #if defined XENOMAI
                rt_task_spawn(&taskset[ext->idx], ext->name, 0, PROCESS_PRIORITY, 0, handle_execution_of_an_extern_function, ext);
            #elif defined POSIX
                sem_t * sem_id= malloc(sizeof(sem_t));
                sem_init(sem_id, 0, 0);
                for (int i =0; i < ext->nbStartTransition; i++){
                    Transition *tr = *(ext->startTransition + i);
                    tr->sem_suspend = sem_id;
                }
                struct sched_param params;
                pthread_attr_t attributs;
                pthread_attr_init(& attributs);
                params.sched_priority = sched_get_priority_max(SCHED_FIFO)-9;
                pthread_attr_setschedpolicy(& attributs, SCHED_FIFO);
                pthread_attr_setschedparam(& attributs, & params);
                pthread_create (&taskset[ext->idx], & attributs, handle_execution_of_an_extern_function, ext);
            #endif
            (*(ext->startTransition))->task = &taskset[ext->idx];
            log_printf("\x1B[31mTask for externe function [%s] is spawned\x1B[0m\n", ext->name);
        }
}

#if defined (XENOMAI)
void * handle_global_clock(void *arg)
#elif defined (POSIX)
static void  handle_global_clock(int sig, siginfo_t *si, void *uc)
#endif
{
    // TODO : vérifier que la priorité du handler et de la tâche
    // de l'engine est plus élévée que les
    // tâches de externs (event et task) => risque d'incohérence entre appel
    // engine et execution de l'engine

    unblock_engine; // Async-Signal Safety
}

int engine_one_turn(int idxOfExternsToDealWith, Extern * (*t)[]){
  tracepoint(hippo, start_one_turn_engine, global_logical_time);
  int idx = idxOfTheEarliestAlarm;
  while ((idx != NONE) && (setOfActiveAlarms[idx].date == global_logical_time)){
      Transition *tr = &transitionset[idx];
      if (is_transition_enable(tr)) {
          add_transition_to_the_fireable_set(tr);
      }
      idx = setOfActiveAlarms[idx].next;
  }
  while (idxOfExternsToDealWith >= 0){
      Extern *ext = (*t)[idxOfExternsToDealWith];
      if (ext->endTransition != 0) {
          *(ext->terminate) = 1;
          for (Transition **tr_idx = ext->endTransition ; tr_idx < (ext->endTransition + ext->nbEndTransition) ; tr_idx++) {
              update_state_transition_with_pre_condition((*(tr_idx)));
          }
      }
      *(ext->ready) = 1;
      for (Transition **tr_idx = ext->startTransition ; tr_idx < (ext->startTransition + ext->nbStartTransition) ; tr_idx++) {
          update_state_transition_with_pre_condition((*(tr_idx)));
      }
      idxOfExternsToDealWith --;
  }
  while (idxOfTheCurrentFireableTransition != NONE) {
      log_state;
      fire_transition(&transitionset[idxOfTheCurrentFireableTransition]);
  }
  tracepoint(hippo, end_one_turn_engine, global_logical_time);
  return idxOfExternsToDealWith;
}

void *handle_engine_execution(void *arg) {
    call_thread_starting_hook("task_engine");
    Extern *localCpyOfActiveExterns[NUMBER_OF_EXTERNS] = { NULL };
    int idxOfExternsToDealWith = -1;
    /* first iteation, t=0 */
    block_engine;
    acquire_mutex_data_engine;
    idxOfExternsToDealWith = engine_one_turn(idxOfExternsToDealWith, &setOfFinishedExternEventsAndTasks);
    release_mutex_data_engine;
    while (1) {
        block_engine;
        bool is_an_alarm_ready = 0;
        bool is_an_extern_ready = 0;

        global_logical_time ++;
        is_an_alarm_ready = (setOfActiveAlarms[idxOfTheEarliestAlarm].date == global_logical_time);
        acquire_mutex_data_engine;
        if (nbOfFinishedExterns >= 0){
            is_an_extern_ready = 1;
            memcpy(&localCpyOfActiveExterns, &setOfFinishedExternEventsAndTasks, (nbOfFinishedExterns+1)*sizeof(Extern *));
            idxOfExternsToDealWith = nbOfFinishedExterns;
            nbOfFinishedExterns = -1;
        }
        release_mutex_data_engine;

        tracepoint(hippo, clock, global_logical_time, is_an_alarm_ready, is_an_extern_ready );
        log_time;

        if (is_an_alarm_ready || is_an_extern_ready){
            idxOfExternsToDealWith = engine_one_turn(idxOfExternsToDealWith, &localCpyOfActiveExterns);
        }
    }
}

void *handle_execution_of_an_extern_function(void *arg) {
    Transition **tr;
    Extern *ext = ((Extern *) arg);
    call_thread_starting_hook("call_handler");
    while (1) {
        suspend_extern_task(ext);
        log_printf("\x1B[34m@%lld: The external function [%s] is called\x1B[0m\n", global_logical_time, ext->name);
        (ext->function)();
        log_printf("\x1B[34m@%lld: The external function [%s] is finished\x1B[0m\n", global_logical_time, ext->name);
        declare_extern_as_active(ext);
    }
}

void *handle_execution_of_an_extern_event(void *arg) {
    Extern *ext = ((Extern *) arg);
    call_thread_starting_hook("event_handler");
    while (1) {
        log_printf("\x1B[34m@%lld: The external event [%s] listens\x1B[0m\n", global_logical_time, ext->name);
        (ext->function)();
        log_printf("\x1B[34m@%lld: The external event [%s] is occurred\x1B[0m\n", global_logical_time, ext->name);
        declare_extern_as_active(ext);
    }
}

void declare_extern_as_active(Extern *ext){
    acquire_mutex_data_engine;
    nbOfFinishedExterns++;
    setOfFinishedExternEventsAndTasks[nbOfFinishedExterns] = ext;
    release_mutex_data_engine;
}

void activate_alarm_of_a_transition(Transition *tr){
    setOfActiveAlarms[tr->idx].date = global_logical_time + tr->minTime;
    setOfActiveAlarms[tr->idx].active = ALARM_IS_ACTIVE;
    if (idxOfTheEarliestAlarm == NONE){
        idxOfTheEarliestAlarm = tr->idx;
        setOfActiveAlarms[tr->idx].next = NONE;
        setOfActiveAlarms[tr->idx].prev = NONE;
    } else {
        int next_idx = idxOfTheEarliestAlarm;
        int prev_idx = setOfActiveAlarms[next_idx].prev;
        while (setOfActiveAlarms[next_idx].date < setOfActiveAlarms[tr->idx].date){
            prev_idx = next_idx;
            next_idx = setOfActiveAlarms[next_idx].next;
            if (next_idx == NONE)
                break;
        }
        setOfActiveAlarms[tr->idx].next = next_idx;
        setOfActiveAlarms[tr->idx].prev = prev_idx;
        if (prev_idx == NONE){
            idxOfTheEarliestAlarm = tr->idx;
        } else{
            setOfActiveAlarms[prev_idx].next = tr->idx;
        }
        if (next_idx != NONE){
            setOfActiveAlarms[next_idx].prev = tr->idx;
        }
    }
}

void remove_alarm(Transition *tr){
    int idx_next = setOfActiveAlarms[tr->idx].next;
    int idx_prev = setOfActiveAlarms[tr->idx].prev;
    setOfActiveAlarms[tr->idx].active = ALARM_IS_NOT_ACTIVE;
    setOfActiveAlarms[tr->idx].prev = NONE;
    setOfActiveAlarms[tr->idx].next = NONE;
    setOfActiveAlarms[tr->idx].date = -1;
    if (idxOfTheEarliestAlarm == tr->idx) /* May be we are not removing the earliest one... */
      idxOfTheEarliestAlarm = idx_next;	  /* Just set it if we removed the earliest alarm. */
    if (idx_prev == NONE){
        setOfActiveAlarms[idx_next].prev = NONE;
    } else {
        setOfActiveAlarms[idx_prev].next = idx_next;
    }
    if (idx_next == NONE){
        setOfActiveAlarms[idx_prev].next = NONE;
    } else {
      setOfActiveAlarms[idx_next].prev = idx_prev;
    }
}

void remove_transition_from_the_fireable_set(Transition *tr) {
    int idx = tr->idx;
    if (idxOfTheLastFireableTransition == idx)
      idxOfTheLastFireableTransition = setOfFireableTransitions[idx].prev;
    if (setOfFireableTransitions[idx].prev != NONE) {
        setOfFireableTransitions[setOfFireableTransitions[idx].prev].next = setOfFireableTransitions[idx].next;
    } else {
        idxOfTheCurrentFireableTransition = setOfFireableTransitions[idx].next;
    }
    if (setOfFireableTransitions[idx].next != NONE)
      setOfFireableTransitions[setOfFireableTransitions[idx].next].prev = setOfFireableTransitions[idx].prev;

    setOfFireableTransitions[idx].state = NOT_FIREABLE;
    setOfFireableTransitions[idx].prev = NONE;
    setOfFireableTransitions[idx].next = NONE;
}

void add_transition_to_the_fireable_set(Transition *transition) {
    int transitionIdx = transition->idx;
    if (transition->priority){
        for (int i = 0; i < NUMBER_OF_TRANSITIONS ; i++){
            if ((priorityRelations[transition->idx][i]) && (setOfFireableTransitions[i].state == FIREABLE)){
                return;
            }
        }
    }

    setOfFireableTransitions[transitionIdx].state = FIREABLE;
    setOfFireableTransitions[transitionIdx].next = NONE;
    if (idxOfTheCurrentFireableTransition == NONE) { //empty set
        idxOfTheCurrentFireableTransition = transitionIdx;
        setOfFireableTransitions[transitionIdx].prev = NONE;
    }
    else {
        setOfFireableTransitions[transitionIdx].prev = idxOfTheLastFireableTransition;
        setOfFireableTransitions[idxOfTheLastFireableTransition].next = transitionIdx;
    }
    idxOfTheLastFireableTransition = transitionIdx;

    if (transition->isHigherPriority){
        for (int i = 0; i < NUMBER_OF_TRANSITIONS ; i++){
            if ((priorityRelations[i][transition->idx]) && (setOfFireableTransitions[i].state == FIREABLE)){
                remove_transition_from_the_fireable_set(&transitionset[i]);
            }
        }
    }
}

void remove_transition_from_the_enable_set(Transition *tr){
  int idx = tr->idx;
  if (setOfEnableTransitions[idx].prev == NONE){//list head
    idxOfTheCurrentEnableTransition = setOfEnableTransitions[idx].next;
  }
  else{
    setOfEnableTransitions[setOfEnableTransitions[idx].prev].next = setOfEnableTransitions[idx].next;
  }
  if (setOfEnableTransitions[idx].next != NONE)
    setOfEnableTransitions[setOfEnableTransitions[idx].next].prev = setOfEnableTransitions[idx].prev;

  setOfEnableTransitions[idx].state = NOT_ENABLE;
  setOfEnableTransitions[idx].prev = NONE;
  setOfEnableTransitions[idx].next = NONE;
}

void add_transition_to_the_enable_set(Transition *tr){
  int idx = tr->idx;
  setOfEnableTransitions[idx].state = ENABLE;
  setOfEnableTransitions[idx].prev = NONE;
  setOfEnableTransitions[idx].next = idxOfTheCurrentEnableTransition;
  if (idxOfTheCurrentEnableTransition != NONE)
    setOfEnableTransitions[idxOfTheCurrentEnableTransition].prev = idx;
  idxOfTheCurrentEnableTransition = idx;
}

void update_state_of_transition_after_remove_a_token(Transition *tr, int idxOfTheArcFromPreviousPlace) {
    if (is_transition_enable(tr)) {
        if (is_transition_delayed_by_time(tr)) {
            log_printf("\x1B[34m@%lld: The alarm [%s] is stoped\x1B[0m\n", global_logical_time, tr->name);
            remove_alarm(tr);
        }
        if (is_transition_fireable(tr)) {
            remove_transition_from_the_fireable_set(tr);
        }
    }
    tr->enabled_state = tr->enabled_state | (1 << idxOfTheArcFromPreviousPlace);
    if(!is_transition_enable(tr)){
      remove_transition_from_the_enable_set(tr);
    }
}

void update_state_transition_with_pre_condition_isTrWithPre_isTrEnabled(Transition *tr) {
  //reorder condition evaluation as bellow :
  // A : tr->alarm, F : is_transition_fireable, P : tr->pre()
  //                    -  F  --- not P
  //        -  not A  -
  //      -            -  not F - P
  // ---
  //      -            -  P
  //        -  A  ----
  //                   -  not P
    if(tr->alarm == 0){//not A
      bool p = tr->pre();
      if(is_transition_fireable(tr)){//F
        if(!p){//not P
          remove_transition_from_the_fireable_set(tr);
        }
      }
      else{//not F
        if(p){//P
          add_transition_to_the_fireable_set(tr);
        }
      }
    }
    else{//A
      bool p = tr->pre();
      if(p){//P
        if (setOfActiveAlarms[tr->idx].active == ALARM_IS_NOT_ACTIVE){
            activate_alarm_of_a_transition(tr);
            log_printf("\x1B[34m@%lld: The alarm [%s] is started (expired in %d)\x1B[0m\n", global_logical_time, tr->name, tr->minTime);
        }
      }
      else{//not P
        if (setOfActiveAlarms[tr->idx].active == ALARM_IS_ACTIVE){
            remove_alarm(tr);
            log_printf("\x1B[34m@%lld: The alarm [%s] is stopped\x1B[0m\n", global_logical_time, tr->name);
        }
      }
    }
}

void update_state_transition_with_pre_condition(Transition *tr) {
    if (is_transition_enable(tr) &&  tr->pre != NULL){
      return update_state_transition_with_pre_condition_isTrWithPre_isTrEnabled(tr);
    }
}

void update_state_of_all_transitions_with_pre_conditions() {
    Transition *tr;
    int idx = idxOfTheCurrentEnableTransition;
    while (idx != NONE) {
        tr = &transitionset[idx];
        if(tr->pre != NULL)
          update_state_transition_with_pre_condition_isTrWithPre_isTrEnabled(tr);
        idx = setOfEnableTransitions[idx].next;
    }
}

void update_state_of_transition_after_add_a_token_in_a_previous_place(Transition *tr, int idxOfTheArcFromPreviousPlace) {
    int previously = is_transition_enable(tr);
    tr->enabled_state = tr->enabled_state & ~(1 << idxOfTheArcFromPreviousPlace);
    if(is_transition_enable(tr)){
      add_transition_to_the_enable_set(tr);
    }
    if (is_transition_enable(tr) && !previously) {
        if (is_transition_immediate(tr)) {
            if ((tr->pre == 0) || (tr->pre())) {
                add_transition_to_the_fireable_set(tr);
            }
        } else {
            if (tr->alarm) {
                if (tr->pre != NULL) {
                    if (tr->pre() == 1) {
                        activate_alarm_of_a_transition(tr);
                        log_printf("\x1B[34m@%lld: The alarm [%s] is started (expired in %d)\x1B[0m\n", global_logical_time, tr->name, tr->minTime);
                    }
                } else {
                    activate_alarm_of_a_transition(tr);
                    log_printf("\x1B[34m@%lld: The alarm [%s] is started (expired in %d)\x1B[0m\n", global_logical_time, tr->name, tr->minTime);
                }
            }
        }
    }
}

void fire_transition(Transition *tr) {
    log_fire(global_logical_time, tr);
    remove_transition_from_the_fireable_set(tr);
    for (fromPlaceToTransition *arc = tr->preset; arc < tr->preset + tr->sizePreset; arc++) {
        if (!arc->read){ // The arc is not a read arc
            arc->fromPlace->mark--;
            if (arc->fromPlace->mark == 0){
                for (Edge *e = arc->fromPlace->edge ; e < (arc->fromPlace->edge + arc->fromPlace->nbEdges) ; e++) {
                    update_state_of_transition_after_remove_a_token(e->toTransition, e->posEnableState);
                }
            }
        }
    }
    /* Execute the action of the transition */
    if (tr->act) {
        tr->act();
        update_state_of_all_transitions_with_pre_conditions();
        //TODO : update only transitions with pre condition changed by the act
    }
    for (fromTransitionToPlace *post = tr->postset ; post < (tr->postset + tr->sizePostset) ; post++) {
        add_token_to_place(post->toPlace);
    }
    if (is_bound_to_an_extern_task(tr)) {
        resume_extern_task_bound_to_transition(tr);
    }
    log_state;
}

void add_token_to_place(Place * pl) {
    pl->mark++;
    if (pl->mark == 1) {
        for (Edge *e = pl->edge ; e < (pl->edge + pl->nbEdges) ; e++) {
          update_state_of_transition_after_add_a_token_in_a_previous_place(e->toTransition, e->posEnableState);
        }
    }
}

void print_marked_places(){
    char *separateur = ", ";
    printf("| Marked@%lld: [", global_logical_time);
    for (Place *pl = &placeset[0]; pl < &placeset[NUMBER_OF_PLACES]; pl++) {
        if (pl == &placeset[NUMBER_OF_PLACES - 1])
            separateur = "";
        if (pl->mark)
            printf("%s: %d%s", pl->name, pl->mark, separateur);
    }
    printf("]");
}

void print_enabled_transitions(){
    char *separateur = ", ";
    printf("| Enabled@%lld: [", global_logical_time);
    for (Transition *tr = &transitionset[0]; tr < &transitionset[NUMBER_OF_TRANSITIONS]; tr++) {
        if (tr == &transitionset[NUMBER_OF_TRANSITIONS - 1])
            separateur = "";
        if (is_transition_enable(tr))
            if ((tr->pre) && (tr->pre())) {
                printf("%s [%lld] %s ", tr->name, is_transition_immediate(tr) ? 0 : setOfActiveAlarms[tr->idx].date - global_logical_time, separateur);
            } else if (! tr->pre) {
                printf("%s [%lld] %s ", tr->name, is_transition_immediate(tr) ? 0 : setOfActiveAlarms[tr->idx].date - global_logical_time, separateur);
            }
    }
    printf("]");
}

void print_fireable_transitions(){
    char *separateur = ", ";
    printf("| Fireable@%lld: [", global_logical_time);
    int b = idxOfTheCurrentFireableTransition;
    while (b != NONE) {
        if (setOfFireableTransitions[b].next == NONE)
            separateur = "";
        printf("%s%s", transitionset[b].name, separateur);
        b = setOfFireableTransitions[b].next;
    }
    printf("]");
}

void print_state(char * comment_char, bool is_text_color) {
    char *separateur = ", ";
    char *color_begin = "";
    char *color_end = "";

    if (is_text_color){
        color_begin = "\x1B[35m";
        color_end = "\x1B[0m";
    }
    printf("%s%s\t", color_begin, comment_char);
    print_marked_places();
    printf("\n");
    printf("%s\t", comment_char);
    print_enabled_transitions();
    printf("\n");
    printf("%s\t", comment_char);
    print_fireable_transitions();
    printf("%s\n", color_end);
}

void print_state_of_alarms(){
    for (int i = 0; i < NUMBER_OF_TRANSITIONS; i++)
        printf("{%d: nxt:%d, prv:%d, dt:%lld, ctv:%d}\n", i, setOfActiveAlarms[i].next, setOfActiveAlarms[i].prev, setOfActiveAlarms[i].date, setOfActiveAlarms[i].active);
    printf("\n");
}
