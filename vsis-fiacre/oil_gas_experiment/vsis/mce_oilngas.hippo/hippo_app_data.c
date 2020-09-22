#include "hippo_app_data.h"
extern bool pre_0 ();
extern bool pre_1 ();
extern bool pre_2 ();
extern bool pre_3 ();
extern bool pre_4 ();
extern bool pre_5 ();
extern bool pre_9 ();
extern bool pre_10 ();
extern bool pre_11 ();
extern bool pre_12 ();
extern bool pre_13 ();
extern bool pre_14 ();
extern bool pre_20 ();
extern bool pre_21 ();
extern bool pre_26 ();
extern bool pre_27 ();
extern bool pre_30 ();
extern bool pre_31 ();
extern bool act_4 ();
extern bool act_6 ();
extern bool act_7 ();
extern bool act_8 ();
extern bool act_13 ();
extern bool act_15 ();
extern bool act_16 ();
extern bool act_17 ();
extern bool act_18 ();
extern bool act_19 ();
extern bool act_20 ();
extern bool act_21 ();
extern bool act_22 ();
extern bool act_23 ();
extern bool act_25 ();
extern bool act_26 ();
extern bool act_27 ();
extern bool act_28 ();
extern bool act_29 ();
extern bool act_30 ();
extern bool act_31 ();

/* fiacre task t, cname f_read */
int f_read_start = 1;
int f_read_terminate=0;

/* fiacre task t, cname f_write */
int f_write_start = 1;
int f_write_terminate=0;

extern void wrapper_f_read(void);
extern void wrapper_f_write(void);

Transition *listStartTransitions[NUMBER_OF_START_TRANSITIONS] = {

    &transitionset[20],
    &transitionset[30],
};

Transition *listEndTransitions[NUMBER_OF_END_TRANSITIONS] = {


    &transitionset[21],
    &transitionset[31],
};



Extern externset[NUMBER_OF_EXTERNS] = {
    { .idx = 0,
    .name = "f_read",
    .isEvent = 0,
    .startTransition = &listStartTransitions[0],
    .nbStartTransition = 1,
    .endTransition = &listEndTransitions[0],
    .nbEndTransition = 1,
    .ready = &f_read_start,
    .terminate = &f_read_terminate,
    .function = wrapper_f_read},
    { .idx = 1,
    .name = "f_write",
    .isEvent = 0,
    .startTransition = &listStartTransitions[1],
    .nbStartTransition = 1,
    .endTransition = &listEndTransitions[1],
    .nbEndTransition = 1,
    .ready = &f_write_start,
    .terminate = &f_write_terminate,
    .function = wrapper_f_write},
};

fromPlaceToTransition preset[NUMBER_OF_PRE] = {

    /* Arc from Scan_1_sstart__ust__2oo7 to TON_1_t0_Scan_1_t4 */ 
    {.fromPlace = &placeset[16], .toTransition = &transitionset[0],  .read=0},
    /* Arc from TON_1_sidle to TON_1_t0_Scan_1_t4 */ 
    {.fromPlace = &placeset[5], .toTransition = &transitionset[0],  .read=0},
    
    /* Arc from Scan_1_sstart__ust__2oo7 to TON_1_t1_Scan_1_t4 */ 
    {.fromPlace = &placeset[16], .toTransition = &transitionset[1],  .read=0},
    /* Arc from TON_1_sidle to TON_1_t1_Scan_1_t4 */ 
    {.fromPlace = &placeset[5], .toTransition = &transitionset[1],  .read=1},
    
    /* Arc from Scan_1_sstart__ust__2oo7 to TON_1_t3_Scan_1_t4 */ 
    {.fromPlace = &placeset[16], .toTransition = &transitionset[2],  .read=0},
    /* Arc from TON_1_srunning to TON_1_t3_Scan_1_t4 */ 
    {.fromPlace = &placeset[4], .toTransition = &transitionset[2],  .read=0},
    
    /* Arc from Scan_1_sstart__ust__2oo7 to TON_1_t4_Scan_1_t4 */ 
    {.fromPlace = &placeset[16], .toTransition = &transitionset[3],  .read=0},
    /* Arc from TON_1_srunning to TON_1_t4_Scan_1_t4 */ 
    {.fromPlace = &placeset[4], .toTransition = &transitionset[3],  .read=1},
    
    /* Arc from Scan_1_sstart__ust__2oo7 to TON_1_t7_Scan_1_t4 */ 
    {.fromPlace = &placeset[16], .toTransition = &transitionset[4],  .read=0},
    /* Arc from TON_1_selapsed to TON_1_t7_Scan_1_t4 */ 
    {.fromPlace = &placeset[3], .toTransition = &transitionset[4],  .read=0},
    
    /* Arc from Scan_1_sstart__ust__2oo7 to TON_1_t8_Scan_1_t4 */ 
    {.fromPlace = &placeset[16], .toTransition = &transitionset[5],  .read=0},
    /* Arc from TON_1_selapsed to TON_1_t8_Scan_1_t4 */ 
    {.fromPlace = &placeset[3], .toTransition = &transitionset[5],  .read=1},
    
    /* Arc from Scan_1_send__ust__2oo7 to TON_1_t2_Scan_1_t5 */ 
    {.fromPlace = &placeset[15], .toTransition = &transitionset[6],  .read=0},
    /* Arc from TON_1_sidle to TON_1_t2_Scan_1_t5 */ 
    {.fromPlace = &placeset[5], .toTransition = &transitionset[6],  .read=1},
    
    /* Arc from Scan_1_send__ust__2oo7 to TON_1_t6_Scan_1_t5 */ 
    {.fromPlace = &placeset[15], .toTransition = &transitionset[7],  .read=0},
    /* Arc from TON_1_srunning to TON_1_t6_Scan_1_t5 */ 
    {.fromPlace = &placeset[4], .toTransition = &transitionset[7],  .read=1},
    
    /* Arc from Scan_1_send__ust__2oo7 to TON_1_t9_Scan_1_t5 */ 
    {.fromPlace = &placeset[15], .toTransition = &transitionset[8],  .read=0},
    /* Arc from TON_1_selapsed to TON_1_t9_Scan_1_t5 */ 
    {.fromPlace = &placeset[3], .toTransition = &transitionset[8],  .read=1},
    
    /* Arc from Scan_1_sstart__ust__1oo7 to TON_2_t0_Scan_1_t6 */ 
    {.fromPlace = &placeset[14], .toTransition = &transitionset[9],  .read=0},
    /* Arc from TON_2_sidle to TON_2_t0_Scan_1_t6 */ 
    {.fromPlace = &placeset[2], .toTransition = &transitionset[9],  .read=0},
    
    /* Arc from Scan_1_sstart__ust__1oo7 to TON_2_t1_Scan_1_t6 */ 
    {.fromPlace = &placeset[14], .toTransition = &transitionset[10],  .read=0},
    /* Arc from TON_2_sidle to TON_2_t1_Scan_1_t6 */ 
    {.fromPlace = &placeset[2], .toTransition = &transitionset[10],  .read=1},
    
    /* Arc from Scan_1_sstart__ust__1oo7 to TON_2_t3_Scan_1_t6 */ 
    {.fromPlace = &placeset[14], .toTransition = &transitionset[11],  .read=0},
    /* Arc from TON_2_srunning to TON_2_t3_Scan_1_t6 */ 
    {.fromPlace = &placeset[1], .toTransition = &transitionset[11],  .read=0},
    
    /* Arc from Scan_1_sstart__ust__1oo7 to TON_2_t4_Scan_1_t6 */ 
    {.fromPlace = &placeset[14], .toTransition = &transitionset[12],  .read=0},
    /* Arc from TON_2_srunning to TON_2_t4_Scan_1_t6 */ 
    {.fromPlace = &placeset[1], .toTransition = &transitionset[12],  .read=1},
    
    /* Arc from Scan_1_sstart__ust__1oo7 to TON_2_t7_Scan_1_t6 */ 
    {.fromPlace = &placeset[14], .toTransition = &transitionset[13],  .read=0},
    /* Arc from TON_2_selapsed to TON_2_t7_Scan_1_t6 */ 
    {.fromPlace = &placeset[0], .toTransition = &transitionset[13],  .read=0},
    
    /* Arc from Scan_1_sstart__ust__1oo7 to TON_2_t8_Scan_1_t6 */ 
    {.fromPlace = &placeset[14], .toTransition = &transitionset[14],  .read=0},
    /* Arc from TON_2_selapsed to TON_2_t8_Scan_1_t6 */ 
    {.fromPlace = &placeset[0], .toTransition = &transitionset[14],  .read=1},
    
    /* Arc from Scan_1_send__ust__1oo7 to TON_2_t2_Scan_1_t7 */ 
    {.fromPlace = &placeset[13], .toTransition = &transitionset[15],  .read=0},
    /* Arc from TON_2_sidle to TON_2_t2_Scan_1_t7 */ 
    {.fromPlace = &placeset[2], .toTransition = &transitionset[15],  .read=1},
    
    /* Arc from Scan_1_send__ust__1oo7 to TON_2_t6_Scan_1_t7 */ 
    {.fromPlace = &placeset[13], .toTransition = &transitionset[16],  .read=0},
    /* Arc from TON_2_srunning to TON_2_t6_Scan_1_t7 */ 
    {.fromPlace = &placeset[1], .toTransition = &transitionset[16],  .read=1},
    
    /* Arc from Scan_1_send__ust__1oo7 to TON_2_t9_Scan_1_t7 */ 
    {.fromPlace = &placeset[13], .toTransition = &transitionset[17],  .read=0},
    /* Arc from TON_2_selapsed to TON_2_t9_Scan_1_t7 */ 
    {.fromPlace = &placeset[0], .toTransition = &transitionset[17],  .read=1},
    
    /* Arc from TON_1_srunning to TON_1_t5 */ 
    {.fromPlace = &placeset[4], .toTransition = &transitionset[18],  .read=0},
    
    /* Arc from TON_2_srunning to TON_2_t5 */ 
    {.fromPlace = &placeset[1], .toTransition = &transitionset[19],  .read=0},
    
    /* Arc from Scan_1_sstart__reading to Scan_1_t0 */ 
    {.fromPlace = &placeset[21], .toTransition = &transitionset[20],  .read=0},
    
    /* Arc from Scan_1_send__reading to Scan_1_t1 */ 
    {.fromPlace = &placeset[20], .toTransition = &transitionset[21],  .read=0},
    
    /* Arc from Scan_1_spolarize to Scan_1_t2 */ 
    {.fromPlace = &placeset[19], .toTransition = &transitionset[22],  .read=0},
    
    /* Arc from Scan_1_svotting to Scan_1_t3 */ 
    {.fromPlace = &placeset[17], .toTransition = &transitionset[23],  .read=0},
    
    /* Arc from Scan_1_sinitial to Scan_1_t8 */ 
    {.fromPlace = &placeset[18], .toTransition = &transitionset[24],  .read=0},
    
    /* Arc from Scan_1_srung__1 to Scan_1_t9 */ 
    {.fromPlace = &placeset[12], .toTransition = &transitionset[25],  .read=0},
    
    /* Arc from Scan_1_srung__3 to Scan_1_t10 */ 
    {.fromPlace = &placeset[11], .toTransition = &transitionset[26],  .read=0},
    
    /* Arc from Scan_1_srung__3 to Scan_1_t11 */ 
    {.fromPlace = &placeset[11], .toTransition = &transitionset[27],  .read=0},
    
    /* Arc from Scan_1_srung__4 to Scan_1_t12 */ 
    {.fromPlace = &placeset[10], .toTransition = &transitionset[28],  .read=0},
    
    /* Arc from Scan_1_srung__5 to Scan_1_t13 */ 
    {.fromPlace = &placeset[9], .toTransition = &transitionset[29],  .read=0},
    
    /* Arc from Scan_1_sstart__writing to Scan_1_t14 */ 
    {.fromPlace = &placeset[8], .toTransition = &transitionset[30],  .read=0},
    
    /* Arc from Scan_1_send__writing to Scan_1_t15 */ 
    {.fromPlace = &placeset[7], .toTransition = &transitionset[31],  .read=0},
    
    /* Arc from Scan_1_sfinal to Scan_1_t16 */ 
    {.fromPlace = &placeset[6], .toTransition = &transitionset[32],  .read=0}
    
    };

fromTransitionToPlace postset[NUMBER_OF_POST] = {

    /* Arc from TON_1_t0_Scan_1_t4 to Scan_1_send__ust__2oo7 */ 
    {.fromTransition = &transitionset[0], .toPlace = &placeset[15] },
    /* Arc from TON_1_t0_Scan_1_t4 to TON_1_srunning */ 
    {.fromTransition = &transitionset[0], .toPlace = &placeset[4] },
    
    /* Arc from TON_1_t1_Scan_1_t4 to Scan_1_send__ust__2oo7 */ 
    {.fromTransition = &transitionset[1], .toPlace = &placeset[15] },
    
    /* Arc from TON_1_t3_Scan_1_t4 to Scan_1_send__ust__2oo7 */ 
    {.fromTransition = &transitionset[2], .toPlace = &placeset[15] },
    /* Arc from TON_1_t3_Scan_1_t4 to TON_1_sidle */ 
    {.fromTransition = &transitionset[2], .toPlace = &placeset[5] },
    
    /* Arc from TON_1_t4_Scan_1_t4 to Scan_1_send__ust__2oo7 */ 
    {.fromTransition = &transitionset[3], .toPlace = &placeset[15] },
    
    /* Arc from TON_1_t7_Scan_1_t4 to Scan_1_send__ust__2oo7 */ 
    {.fromTransition = &transitionset[4], .toPlace = &placeset[15] },
    /* Arc from TON_1_t7_Scan_1_t4 to TON_1_sidle */ 
    {.fromTransition = &transitionset[4], .toPlace = &placeset[5] },
    
    /* Arc from TON_1_t8_Scan_1_t4 to Scan_1_send__ust__2oo7 */ 
    {.fromTransition = &transitionset[5], .toPlace = &placeset[15] },
    
    /* Arc from TON_1_t2_Scan_1_t5 to Scan_1_sstart__ust__1oo7 */ 
    {.fromTransition = &transitionset[6], .toPlace = &placeset[14] },
    
    /* Arc from TON_1_t6_Scan_1_t5 to Scan_1_sstart__ust__1oo7 */ 
    {.fromTransition = &transitionset[7], .toPlace = &placeset[14] },
    
    /* Arc from TON_1_t9_Scan_1_t5 to Scan_1_sstart__ust__1oo7 */ 
    {.fromTransition = &transitionset[8], .toPlace = &placeset[14] },
    
    /* Arc from TON_2_t0_Scan_1_t6 to Scan_1_send__ust__1oo7 */ 
    {.fromTransition = &transitionset[9], .toPlace = &placeset[13] },
    /* Arc from TON_2_t0_Scan_1_t6 to TON_2_srunning */ 
    {.fromTransition = &transitionset[9], .toPlace = &placeset[1] },
    
    /* Arc from TON_2_t1_Scan_1_t6 to Scan_1_send__ust__1oo7 */ 
    {.fromTransition = &transitionset[10], .toPlace = &placeset[13] },
    
    /* Arc from TON_2_t3_Scan_1_t6 to Scan_1_send__ust__1oo7 */ 
    {.fromTransition = &transitionset[11], .toPlace = &placeset[13] },
    /* Arc from TON_2_t3_Scan_1_t6 to TON_2_sidle */ 
    {.fromTransition = &transitionset[11], .toPlace = &placeset[2] },
    
    /* Arc from TON_2_t4_Scan_1_t6 to Scan_1_send__ust__1oo7 */ 
    {.fromTransition = &transitionset[12], .toPlace = &placeset[13] },
    
    /* Arc from TON_2_t7_Scan_1_t6 to Scan_1_send__ust__1oo7 */ 
    {.fromTransition = &transitionset[13], .toPlace = &placeset[13] },
    /* Arc from TON_2_t7_Scan_1_t6 to TON_2_sidle */ 
    {.fromTransition = &transitionset[13], .toPlace = &placeset[2] },
    
    /* Arc from TON_2_t8_Scan_1_t6 to Scan_1_send__ust__1oo7 */ 
    {.fromTransition = &transitionset[14], .toPlace = &placeset[13] },
    
    /* Arc from TON_2_t2_Scan_1_t7 to Scan_1_sinitial */ 
    {.fromTransition = &transitionset[15], .toPlace = &placeset[18] },
    
    /* Arc from TON_2_t6_Scan_1_t7 to Scan_1_sinitial */ 
    {.fromTransition = &transitionset[16], .toPlace = &placeset[18] },
    
    /* Arc from TON_2_t9_Scan_1_t7 to Scan_1_sinitial */ 
    {.fromTransition = &transitionset[17], .toPlace = &placeset[18] },
    
    /* Arc from TON_1_t5 to TON_1_selapsed */ 
    {.fromTransition = &transitionset[18], .toPlace = &placeset[3] },
    
    /* Arc from TON_2_t5 to TON_2_selapsed */ 
    {.fromTransition = &transitionset[19], .toPlace = &placeset[0] },
    
    /* Arc from Scan_1_t0 to Scan_1_send__reading */ 
    {.fromTransition = &transitionset[20], .toPlace = &placeset[20] },
    
    /* Arc from Scan_1_t1 to Scan_1_spolarize */ 
    {.fromTransition = &transitionset[21], .toPlace = &placeset[19] },
    
    /* Arc from Scan_1_t2 to Scan_1_svotting */ 
    {.fromTransition = &transitionset[22], .toPlace = &placeset[17] },
    
    /* Arc from Scan_1_t3 to Scan_1_sstart__ust__2oo7 */ 
    {.fromTransition = &transitionset[23], .toPlace = &placeset[16] },
    
    /* Arc from Scan_1_t8 to Scan_1_srung__1 */ 
    {.fromTransition = &transitionset[24], .toPlace = &placeset[12] },
    
    /* Arc from Scan_1_t9 to Scan_1_srung__3 */ 
    {.fromTransition = &transitionset[25], .toPlace = &placeset[11] },
    
    /* Arc from Scan_1_t10 to Scan_1_srung__4 */ 
    {.fromTransition = &transitionset[26], .toPlace = &placeset[10] },
    
    /* Arc from Scan_1_t11 to Scan_1_srung__4 */ 
    {.fromTransition = &transitionset[27], .toPlace = &placeset[10] },
    
    /* Arc from Scan_1_t12 to Scan_1_srung__5 */ 
    {.fromTransition = &transitionset[28], .toPlace = &placeset[9] },
    
    /* Arc from Scan_1_t13 to Scan_1_sstart__writing */ 
    {.fromTransition = &transitionset[29], .toPlace = &placeset[8] },
    
    /* Arc from Scan_1_t14 to Scan_1_send__writing */ 
    {.fromTransition = &transitionset[30], .toPlace = &placeset[7] },
    
    /* Arc from Scan_1_t15 to Scan_1_sfinal */ 
    {.fromTransition = &transitionset[31], .toPlace = &placeset[6] },
    
    /* Arc from Scan_1_t16 to Scan_1_sstart__reading */ 
    {.fromTransition = &transitionset[32], .toPlace = &placeset[21] }
    
    };

Edge edgeset[NUMBER_OF_EDGES] = {

    /* Edge from TON_2_selapsed to TON_2_t7_Scan_1_t6 */
    {.fromPlace = &placeset[0], .toTransition = &transitionset[13], .posEnableState = 1 },
    
    /* Edge from TON_2_selapsed? to TON_2_t8_Scan_1_t6 */
    {.fromPlace = &placeset[0], .toTransition = &transitionset[14], .posEnableState = 1 },
    
    /* Edge from TON_2_selapsed? to TON_2_t9_Scan_1_t7 */
    {.fromPlace = &placeset[0], .toTransition = &transitionset[17], .posEnableState = 1 },
    
    /* Edge from TON_2_srunning to TON_2_t3_Scan_1_t6 */
    {.fromPlace = &placeset[1], .toTransition = &transitionset[11], .posEnableState = 1 },
    
    /* Edge from TON_2_srunning? to TON_2_t4_Scan_1_t6 */
    {.fromPlace = &placeset[1], .toTransition = &transitionset[12], .posEnableState = 1 },
    
    /* Edge from TON_2_srunning? to TON_2_t6_Scan_1_t7 */
    {.fromPlace = &placeset[1], .toTransition = &transitionset[16], .posEnableState = 1 },
    
    /* Edge from TON_2_srunning to TON_2_t5 */
    {.fromPlace = &placeset[1], .toTransition = &transitionset[19], .posEnableState = 0 },
    
    /* Edge from TON_2_sidle to TON_2_t0_Scan_1_t6 */
    {.fromPlace = &placeset[2], .toTransition = &transitionset[9], .posEnableState = 1 },
    
    /* Edge from TON_2_sidle? to TON_2_t1_Scan_1_t6 */
    {.fromPlace = &placeset[2], .toTransition = &transitionset[10], .posEnableState = 1 },
    
    /* Edge from TON_2_sidle? to TON_2_t2_Scan_1_t7 */
    {.fromPlace = &placeset[2], .toTransition = &transitionset[15], .posEnableState = 1 },
    
    /* Edge from TON_1_selapsed to TON_1_t7_Scan_1_t4 */
    {.fromPlace = &placeset[3], .toTransition = &transitionset[4], .posEnableState = 1 },
    
    /* Edge from TON_1_selapsed? to TON_1_t8_Scan_1_t4 */
    {.fromPlace = &placeset[3], .toTransition = &transitionset[5], .posEnableState = 1 },
    
    /* Edge from TON_1_selapsed? to TON_1_t9_Scan_1_t5 */
    {.fromPlace = &placeset[3], .toTransition = &transitionset[8], .posEnableState = 1 },
    
    /* Edge from TON_1_srunning to TON_1_t3_Scan_1_t4 */
    {.fromPlace = &placeset[4], .toTransition = &transitionset[2], .posEnableState = 1 },
    
    /* Edge from TON_1_srunning? to TON_1_t4_Scan_1_t4 */
    {.fromPlace = &placeset[4], .toTransition = &transitionset[3], .posEnableState = 1 },
    
    /* Edge from TON_1_srunning? to TON_1_t6_Scan_1_t5 */
    {.fromPlace = &placeset[4], .toTransition = &transitionset[7], .posEnableState = 1 },
    
    /* Edge from TON_1_srunning to TON_1_t5 */
    {.fromPlace = &placeset[4], .toTransition = &transitionset[18], .posEnableState = 0 },
    
    /* Edge from TON_1_sidle to TON_1_t0_Scan_1_t4 */
    {.fromPlace = &placeset[5], .toTransition = &transitionset[0], .posEnableState = 1 },
    
    /* Edge from TON_1_sidle? to TON_1_t1_Scan_1_t4 */
    {.fromPlace = &placeset[5], .toTransition = &transitionset[1], .posEnableState = 1 },
    
    /* Edge from TON_1_sidle? to TON_1_t2_Scan_1_t5 */
    {.fromPlace = &placeset[5], .toTransition = &transitionset[6], .posEnableState = 1 },
    
    /* Edge from Scan_1_sfinal to Scan_1_t16 */
    {.fromPlace = &placeset[6], .toTransition = &transitionset[32], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__writing to Scan_1_t15 */
    {.fromPlace = &placeset[7], .toTransition = &transitionset[31], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__writing to Scan_1_t14 */
    {.fromPlace = &placeset[8], .toTransition = &transitionset[30], .posEnableState = 0 },
    
    /* Edge from Scan_1_srung__5 to Scan_1_t13 */
    {.fromPlace = &placeset[9], .toTransition = &transitionset[29], .posEnableState = 0 },
    
    /* Edge from Scan_1_srung__4 to Scan_1_t12 */
    {.fromPlace = &placeset[10], .toTransition = &transitionset[28], .posEnableState = 0 },
    
    /* Edge from Scan_1_srung__3 to Scan_1_t10 */
    {.fromPlace = &placeset[11], .toTransition = &transitionset[26], .posEnableState = 0 },
    
    /* Edge from Scan_1_srung__3 to Scan_1_t11 */
    {.fromPlace = &placeset[11], .toTransition = &transitionset[27], .posEnableState = 0 },
    
    /* Edge from Scan_1_srung__1 to Scan_1_t9 */
    {.fromPlace = &placeset[12], .toTransition = &transitionset[25], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__ust__1oo7 to TON_2_t2_Scan_1_t7 */
    {.fromPlace = &placeset[13], .toTransition = &transitionset[15], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__ust__1oo7 to TON_2_t6_Scan_1_t7 */
    {.fromPlace = &placeset[13], .toTransition = &transitionset[16], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__ust__1oo7 to TON_2_t9_Scan_1_t7 */
    {.fromPlace = &placeset[13], .toTransition = &transitionset[17], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__1oo7 to TON_2_t0_Scan_1_t6 */
    {.fromPlace = &placeset[14], .toTransition = &transitionset[9], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__1oo7 to TON_2_t1_Scan_1_t6 */
    {.fromPlace = &placeset[14], .toTransition = &transitionset[10], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__1oo7 to TON_2_t3_Scan_1_t6 */
    {.fromPlace = &placeset[14], .toTransition = &transitionset[11], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__1oo7 to TON_2_t4_Scan_1_t6 */
    {.fromPlace = &placeset[14], .toTransition = &transitionset[12], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__1oo7 to TON_2_t7_Scan_1_t6 */
    {.fromPlace = &placeset[14], .toTransition = &transitionset[13], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__1oo7 to TON_2_t8_Scan_1_t6 */
    {.fromPlace = &placeset[14], .toTransition = &transitionset[14], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__ust__2oo7 to TON_1_t2_Scan_1_t5 */
    {.fromPlace = &placeset[15], .toTransition = &transitionset[6], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__ust__2oo7 to TON_1_t6_Scan_1_t5 */
    {.fromPlace = &placeset[15], .toTransition = &transitionset[7], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__ust__2oo7 to TON_1_t9_Scan_1_t5 */
    {.fromPlace = &placeset[15], .toTransition = &transitionset[8], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__2oo7 to TON_1_t0_Scan_1_t4 */
    {.fromPlace = &placeset[16], .toTransition = &transitionset[0], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__2oo7 to TON_1_t1_Scan_1_t4 */
    {.fromPlace = &placeset[16], .toTransition = &transitionset[1], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__2oo7 to TON_1_t3_Scan_1_t4 */
    {.fromPlace = &placeset[16], .toTransition = &transitionset[2], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__2oo7 to TON_1_t4_Scan_1_t4 */
    {.fromPlace = &placeset[16], .toTransition = &transitionset[3], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__2oo7 to TON_1_t7_Scan_1_t4 */
    {.fromPlace = &placeset[16], .toTransition = &transitionset[4], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__ust__2oo7 to TON_1_t8_Scan_1_t4 */
    {.fromPlace = &placeset[16], .toTransition = &transitionset[5], .posEnableState = 0 },
    
    /* Edge from Scan_1_svotting to Scan_1_t3 */
    {.fromPlace = &placeset[17], .toTransition = &transitionset[23], .posEnableState = 0 },
    
    /* Edge from Scan_1_sinitial to Scan_1_t8 */
    {.fromPlace = &placeset[18], .toTransition = &transitionset[24], .posEnableState = 0 },
    
    /* Edge from Scan_1_spolarize to Scan_1_t2 */
    {.fromPlace = &placeset[19], .toTransition = &transitionset[22], .posEnableState = 0 },
    
    /* Edge from Scan_1_send__reading to Scan_1_t1 */
    {.fromPlace = &placeset[20], .toTransition = &transitionset[21], .posEnableState = 0 },
    
    /* Edge from Scan_1_sstart__reading to Scan_1_t0 */
    {.fromPlace = &placeset[21], .toTransition = &transitionset[20], .posEnableState = 0 },
    
    };

Place placeset[NUMBER_OF_PLACES] = {

    { .idx =0 , .name = "TON_2_selapsed", .mark = 0, .edge = &edgeset[0], .nbEdges = 3 },
    { .idx =1 , .name = "TON_2_srunning", .mark = 0, .edge = &edgeset[3], .nbEdges = 4 },
    { .idx =2 , .name = "TON_2_sidle", .mark = 1, .edge = &edgeset[7], .nbEdges = 3 },
    { .idx =3 , .name = "TON_1_selapsed", .mark = 0, .edge = &edgeset[10], .nbEdges = 3 },
    { .idx =4 , .name = "TON_1_srunning", .mark = 0, .edge = &edgeset[13], .nbEdges = 4 },
    { .idx =5 , .name = "TON_1_sidle", .mark = 1, .edge = &edgeset[17], .nbEdges = 3 },
    { .idx =6 , .name = "Scan_1_sfinal", .mark = 0, .edge = &edgeset[20], .nbEdges = 1 },
    { .idx =7 , .name = "Scan_1_send__writing", .mark = 0, .edge = &edgeset[21], .nbEdges = 1 },
    { .idx =8 , .name = "Scan_1_sstart__writing", .mark = 0, .edge = &edgeset[22], .nbEdges = 1 },
    { .idx =9 , .name = "Scan_1_srung__5", .mark = 0, .edge = &edgeset[23], .nbEdges = 1 },
    { .idx =10 , .name = "Scan_1_srung__4", .mark = 0, .edge = &edgeset[24], .nbEdges = 1 },
    { .idx =11 , .name = "Scan_1_srung__3", .mark = 0, .edge = &edgeset[25], .nbEdges = 2 },
    { .idx =12 , .name = "Scan_1_srung__1", .mark = 0, .edge = &edgeset[27], .nbEdges = 1 },
    { .idx =13 , .name = "Scan_1_send__ust__1oo7", .mark = 0, .edge = &edgeset[28], .nbEdges = 3 },
    { .idx =14 , .name = "Scan_1_sstart__ust__1oo7", .mark = 0, .edge = &edgeset[31], .nbEdges = 6 },
    { .idx =15 , .name = "Scan_1_send__ust__2oo7", .mark = 0, .edge = &edgeset[37], .nbEdges = 3 },
    { .idx =16 , .name = "Scan_1_sstart__ust__2oo7", .mark = 0, .edge = &edgeset[40], .nbEdges = 6 },
    { .idx =17 , .name = "Scan_1_svotting", .mark = 0, .edge = &edgeset[46], .nbEdges = 1 },
    { .idx =18 , .name = "Scan_1_sinitial", .mark = 0, .edge = &edgeset[47], .nbEdges = 1 },
    { .idx =19 , .name = "Scan_1_spolarize", .mark = 0, .edge = &edgeset[48], .nbEdges = 1 },
    { .idx =20 , .name = "Scan_1_send__reading", .mark = 0, .edge = &edgeset[49], .nbEdges = 1 },
    { .idx =21 , .name = "Scan_1_sstart__reading", .mark = 1, .edge = &edgeset[50], .nbEdges = 1 }
    
};

Transition transitionset[NUMBER_OF_TRANSITIONS] = {

    { .idx = 0, .name = "TON_1_t0_Scan_1_t4", .minTime = 0, .maxTime = 0, .preset = &preset[0], .sizePreset = 2, .postset = &postset[0], .sizePostset = 2, .pre = pre_0 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 1, .name = "TON_1_t1_Scan_1_t4", .minTime = 0, .maxTime = 0, .preset = &preset[2], .sizePreset = 2, .postset = &postset[2], .sizePostset = 1, .pre = pre_1 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 2, .name = "TON_1_t3_Scan_1_t4", .minTime = 0, .maxTime = 0, .preset = &preset[4], .sizePreset = 2, .postset = &postset[3], .sizePostset = 2, .pre = pre_2 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 3, .name = "TON_1_t4_Scan_1_t4", .minTime = 0, .maxTime = 0, .preset = &preset[6], .sizePreset = 2, .postset = &postset[5], .sizePostset = 1, .pre = pre_3 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 4, .name = "TON_1_t7_Scan_1_t4", .minTime = 0, .maxTime = 0, .preset = &preset[8], .sizePreset = 2, .postset = &postset[6], .sizePostset = 2, .pre = pre_4 , .act = act_4 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 5, .name = "TON_1_t8_Scan_1_t4", .minTime = 0, .maxTime = 0, .preset = &preset[10], .sizePreset = 2, .postset = &postset[8], .sizePostset = 1, .pre = pre_5 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 6, .name = "TON_1_t2_Scan_1_t5", .minTime = 0, .maxTime = 0, .preset = &preset[12], .sizePreset = 2, .postset = &postset[9], .sizePostset = 1, .pre = 0 , .act = act_6 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 7, .name = "TON_1_t6_Scan_1_t5", .minTime = 0, .maxTime = 0, .preset = &preset[14], .sizePreset = 2, .postset = &postset[10], .sizePostset = 1, .pre = 0 , .act = act_7 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 8, .name = "TON_1_t9_Scan_1_t5", .minTime = 0, .maxTime = 0, .preset = &preset[16], .sizePreset = 2, .postset = &postset[11], .sizePostset = 1, .pre = 0 , .act = act_8 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 9, .name = "TON_2_t0_Scan_1_t6", .minTime = 0, .maxTime = 0, .preset = &preset[18], .sizePreset = 2, .postset = &postset[12], .sizePostset = 2, .pre = pre_9 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 10, .name = "TON_2_t1_Scan_1_t6", .minTime = 0, .maxTime = 0, .preset = &preset[20], .sizePreset = 2, .postset = &postset[14], .sizePostset = 1, .pre = pre_10 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 11, .name = "TON_2_t3_Scan_1_t6", .minTime = 0, .maxTime = 0, .preset = &preset[22], .sizePreset = 2, .postset = &postset[15], .sizePostset = 2, .pre = pre_11 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 12, .name = "TON_2_t4_Scan_1_t6", .minTime = 0, .maxTime = 0, .preset = &preset[24], .sizePreset = 2, .postset = &postset[17], .sizePostset = 1, .pre = pre_12 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 13, .name = "TON_2_t7_Scan_1_t6", .minTime = 0, .maxTime = 0, .preset = &preset[26], .sizePreset = 2, .postset = &postset[18], .sizePostset = 2, .pre = pre_13 , .act = act_13 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 14, .name = "TON_2_t8_Scan_1_t6", .minTime = 0, .maxTime = 0, .preset = &preset[28], .sizePreset = 2, .postset = &postset[20], .sizePostset = 1, .pre = pre_14 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 15, .name = "TON_2_t2_Scan_1_t7", .minTime = 0, .maxTime = 0, .preset = &preset[30], .sizePreset = 2, .postset = &postset[21], .sizePostset = 1, .pre = 0 , .act = act_15 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 16, .name = "TON_2_t6_Scan_1_t7", .minTime = 0, .maxTime = 0, .preset = &preset[32], .sizePreset = 2, .postset = &postset[22], .sizePostset = 1, .pre = 0 , .act = act_16 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 17, .name = "TON_2_t9_Scan_1_t7", .minTime = 0, .maxTime = 0, .preset = &preset[34], .sizePreset = 2, .postset = &postset[23], .sizePostset = 1, .pre = 0 , .act = act_17 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 18, .name = "TON_1_t5", .minTime = 1E3, .maxTime = 1E3, .preset = &preset[36], .sizePreset = 1, .postset = &postset[24], .sizePostset = 1, .pre = 0 , .act = act_18 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 19, .name = "TON_2_t5", .minTime = 1E3, .maxTime = 1E3, .preset = &preset[37], .sizePreset = 1, .postset = &postset[25], .sizePostset = 1, .pre = 0 , .act = act_19 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 20, .name = "Scan_1_t0", .minTime = 0, .maxTime = 0, .preset = &preset[38], .sizePreset = 1, .postset = &postset[26], .sizePostset = 1, .pre = pre_20 , .act = act_20 , .call = &externset[0], .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 21, .name = "Scan_1_t1", .minTime = 0, .maxTime = 0, .preset = &preset[39], .sizePreset = 1, .postset = &postset[27], .sizePostset = 1, .pre = pre_21 , .act = act_21 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 22, .name = "Scan_1_t2", .minTime = 0, .maxTime = 0, .preset = &preset[40], .sizePreset = 1, .postset = &postset[28], .sizePostset = 1, .pre = 0 , .act = act_22 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 23, .name = "Scan_1_t3", .minTime = 0, .maxTime = 0, .preset = &preset[41], .sizePreset = 1, .postset = &postset[29], .sizePostset = 1, .pre = 0 , .act = act_23 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 24, .name = "Scan_1_t8", .minTime = 0, .maxTime = 0, .preset = &preset[42], .sizePreset = 1, .postset = &postset[30], .sizePostset = 1, .pre = 0 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 25, .name = "Scan_1_t9", .minTime = 0, .maxTime = 0, .preset = &preset[43], .sizePreset = 1, .postset = &postset[31], .sizePostset = 1, .pre = 0 , .act = act_25 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 26, .name = "Scan_1_t10", .minTime = 0, .maxTime = 0, .preset = &preset[44], .sizePreset = 1, .postset = &postset[32], .sizePostset = 1, .pre = pre_26 , .act = act_26 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 27, .name = "Scan_1_t11", .minTime = 0, .maxTime = 0, .preset = &preset[45], .sizePreset = 1, .postset = &postset[33], .sizePostset = 1, .pre = pre_27 , .act = act_27 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 28, .name = "Scan_1_t12", .minTime = 0, .maxTime = 0, .preset = &preset[46], .sizePreset = 1, .postset = &postset[34], .sizePostset = 1, .pre = 0 , .act = act_28 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 29, .name = "Scan_1_t13", .minTime = 0, .maxTime = 0, .preset = &preset[47], .sizePreset = 1, .postset = &postset[35], .sizePostset = 1, .pre = 0 , .act = act_29 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 30, .name = "Scan_1_t14", .minTime = 0, .maxTime = 0, .preset = &preset[48], .sizePreset = 1, .postset = &postset[36], .sizePostset = 1, .pre = pre_30 , .act = act_30 , .call = &externset[1], .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 31, .name = "Scan_1_t15", .minTime = 0, .maxTime = 0, .preset = &preset[49], .sizePreset = 1, .postset = &postset[37], .sizePostset = 1, .pre = pre_31 , .act = act_31 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 },
    { .idx = 32, .name = "Scan_1_t16", .minTime = 5, .maxTime = 5, .preset = &preset[50], .sizePreset = 1, .postset = &postset[38], .sizePostset = 1, .pre = 0 , .act = 0 , .call = 0, .alarm = 0, .task = 0, .enabled_state = 1, .priority=0 }

};

PriorityRelation setOfPriorityRelations[NUMBER_OF_PRIORITY_RELATIONS]={
/* Priority relation between TON_1_t2_Scan_1_t5 and TON_1_t5 */ 
    {.lower = &transitionset[6], .higher = &transitionset[18]},
    /* Priority relation between TON_1_t9_Scan_1_t5 and TON_1_t5 */ 
    {.lower = &transitionset[8], .higher = &transitionset[18]},
    /* Priority relation between TON_1_t6_Scan_1_t5 and TON_1_t5 */ 
    {.lower = &transitionset[7], .higher = &transitionset[18]},
    /* Priority relation between TON_2_t2_Scan_1_t7 and TON_2_t5 */ 
    {.lower = &transitionset[15], .higher = &transitionset[19]},
    /* Priority relation between TON_2_t9_Scan_1_t7 and TON_2_t5 */ 
    {.lower = &transitionset[17], .higher = &transitionset[19]},
    /* Priority relation between TON_2_t6_Scan_1_t7 and TON_2_t5 */ 
    {.lower = &transitionset[16], .higher = &transitionset[19]},
    };

