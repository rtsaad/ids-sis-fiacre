#ifndef _DEBUG_H
extern int hippo_debug;
#define _DEBUG_H
    #if defined(_SCN_)
        #include "hippo_app_functions.h"
        #define buffer_size 512
        static int delay_from_previous_delay;
        static char buff[buffer_size];
        int sprint_state (int sz, char *buff);
    #endif
    #ifdef _TRACE_
        #include <stdio.h>
        
	#define log_printf(fmt, ...) do { if (hippo_debug) {printf(fmt, __VA_ARGS__); fflush(stdout);}} while (0)
        #define log_fire(time, transition)  do { if (hippo_debug) {printf("\t\x1B[32m-> fire@%lld: %s\x1B[0m\n", time, transition->name);fflush(stdout);}} while (0)
        #define log_time
        #define log_state  do { if (hippo_debug) {print_state("", 1);fflush(stdout);}} while (0)
    #else
        #if defined(_SCN_)
            #define log_time /*printf("@1\n")*/ delay_from_previous_delay++
            #define log_printf(fmt, ...) do {} while (0)
            #define log_fire(time, transition) printf("%s@%d\n", transition->name, delay_from_previous_delay); delay_from_previous_delay = 0
            #define log_state print_state("#", 0); sprint_state ( buffer_size, buff); printf("#\t%s\n", buff)
        #else
            #define log_time
            #define log_printf(fmt, ...) do {} while (0)
            #define log_fire(time, transition)
            #define log_state
        #endif
    #endif
#endif
