#ifndef _APP_DATA_
#define _APP_DATA_

#include "data.h"

/* Static allocation */
#define NUMBER_OF_PLACES 18
#define NUMBER_OF_TRANSITIONS 28
#define NUMBER_OF_EDGES 46
#define NUMBER_OF_PRE 46
#define NUMBER_OF_POST 34
#define NUMBER_OF_TASKS 2
#define NUMBER_OF_ALARMS 28
#define NUMBER_OF_START_TRANSITIONS 2
#define NUMBER_OF_END_TRANSITIONS 2
#define NUMBER_OF_EXTERNS 2
#define NUMBER_OF_PRIORITY_RELATIONS 6


Transition *listStartTransitions[NUMBER_OF_START_TRANSITIONS];
Transition *listEndTransitions[NUMBER_OF_END_TRANSITIONS];
Extern externset[NUMBER_OF_EXTERNS];
Place placeset[NUMBER_OF_PLACES];
Transition transitionset[NUMBER_OF_TRANSITIONS];
Edge edgeset[NUMBER_OF_EDGES];
fromPlaceToTransition preset[NUMBER_OF_PRE];
fromTransitionToPlace postset[NUMBER_OF_POST];
PriorityRelation setOfPriorityRelations[NUMBER_OF_PRIORITY_RELATIONS];

#endif
