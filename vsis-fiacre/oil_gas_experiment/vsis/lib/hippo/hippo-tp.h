#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER hippo

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./hippo-tp.h"

#if !defined(_HELLO_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _HELLO_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    hippo,
    clock,
    TP_ARGS(
        unsigned long long int, my_logical_time_arg,
        int, alarm_is_ready_arg,
        int, extern_is_active_arg
    ),
    TP_FIELDS(
        ctf_integer(unsigned long long int, logical_time, my_logical_time_arg)
        ctf_integer(int, alarm, alarm_is_ready_arg)
        ctf_integer(int, ext, extern_is_active_arg)
    )
)

TRACEPOINT_EVENT(
    hippo,
    start_one_turn_engine,
    TP_ARGS(
        unsigned long long int, my_logical_time_arg
    ),
    TP_FIELDS(
        ctf_integer(unsigned long long int, logical_time, my_logical_time_arg)
    )
)

TRACEPOINT_EVENT(
    hippo,
    end_one_turn_engine,
    TP_ARGS(
        unsigned long long int, my_logical_time_arg
    ),
    TP_FIELDS(
        ctf_integer(unsigned long long int, logical_time, my_logical_time_arg)
    )
)

TRACEPOINT_EVENT(
    hippo,
    end_1_loop,
    TP_ARGS(
        unsigned long long int, my_logical_time_arg,
        int, cnter
    ),
    TP_FIELDS(
        ctf_integer(unsigned long long int, logical_time, my_logical_time_arg)
        ctf_integer(int, loop_size, cnter)
    )
)

TRACEPOINT_EVENT(
    hippo,
    end_2_loop,
    TP_ARGS(
        unsigned long long int, my_logical_time_arg,
        int, cnter
    ),
    TP_FIELDS(
        ctf_integer(unsigned long long int, logical_time, my_logical_time_arg)
        ctf_integer(int, loop_size, cnter)
    )
)

TRACEPOINT_EVENT(
    hippo,
    end_3_loop,
    TP_ARGS(
        unsigned long long int, my_logical_time_arg,
        int, cnter
    ),
    TP_FIELDS(
        ctf_integer(unsigned long long int, logical_time, my_logical_time_arg)
        ctf_integer(int, loop_size, cnter)
    )
)

#endif /* _HELLO_TP_H */

#include <lttng/tracepoint-event.h>
