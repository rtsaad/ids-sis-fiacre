/* Created Mon Sep 21 19:11:31 2020 by frac version 2.6.0 */

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <fiacre.h>

/* provider */
char *source_info[3] = {"frac","2.6.0","Mon Sep 21 19:11:31 2020"};
char **sourceinfo () {return source_info;}

/* fiacre and private headers */
#include "hippo_app_functions.h"

static int avail;    /* for sprint_* */
static char tmpbuff[16]; /* for sprint_* */

/* utilities for structure a0 */

static int compare_a0 (struct a0 e1, struct a0 e2) {
  size_t i = 0;
  for (i=0; i<8; i++) {
    if (!(e1.at[i]) && (e2.at[i])) return -1;
    if ((e1.at[i]) && !(e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a0 (char *buff, struct a0 *e, const struct pmap *pmap) {
  int j0;
  PUTS(pmap->a.l);
  for (j0=0; j0<8; j0++) {
    if (j0) {PUTS(pmap->a.s);}
    if (e->at[j0]) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a1 */

static int compare_a1 (struct a1 e1, struct a1 e2) {
  size_t i = 0;
  for (i=0; i<4; i++) {
    if (!(e1.at[i]) && (e2.at[i])) return -1;
    if ((e1.at[i]) && !(e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a1 (char *buff, struct a1 *e, const struct pmap *pmap) {
  int j1;
  PUTS(pmap->a.l);
  for (j1=0; j1<4; j1++) {
    if (j1) {PUTS(pmap->a.s);}
    if (e->at[j1]) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  }
  PUTS(pmap->a.r);
  return buff;
}

/* fiacre task f_read, cname f_read */
struct a0 f_read_output;
extern int f_read_start;
extern int f_read_terminate;
void wrapper_f_read() {
    f_read_output = f_read();
}

/* fiacre task f_write, cname f_write */
struct a1 f_write_input_1;
int f_write_output;
extern int f_write_start;
extern int f_write_terminate;
void wrapper_f_write() {
    f_write_output = f_write( f_write_input_1);
}

/* Fiacre function v2oo3 */
bool fcr_v2oo3 (bool A, bool B, bool C) {
    bool Q; 
    Q=0; 
    Q=(((A && B) || (B && C)) || (A && C)); 
    return Q;
}

/* Process TON_2_TON_1_Scan_1 */

/* state type */

struct value {
  bool Scan_1_vIN__01;
  bool Scan_1_vIN__02;
  bool Scan_1_vIN__03;
  bool Scan_1_vIN__04;
  bool Scan_1_vIN__05;
  bool Scan_1_vIN__06A;
  bool Scan_1_vIN__06B;
  bool Scan_1_vIN__06C;
  bool Scan_1_vQ__01;
  bool Scan_1_vQ__02;
  bool Scan_1_vQ__03;
  bool Scan_1_vQ__04;
  bool TON_1_vQ;
  bool TON_2_vQ;
};
struct value state;


/* utilities for structure value */

int compare_value (struct value *e1, struct value *e2) {
  if (!(e1->Scan_1_vIN__01) && (e2->Scan_1_vIN__01)) return -1;
  if ((e1->Scan_1_vIN__01) && !(e2->Scan_1_vIN__01)) return 1;
  if (!(e1->Scan_1_vIN__02) && (e2->Scan_1_vIN__02)) return -1;
  if ((e1->Scan_1_vIN__02) && !(e2->Scan_1_vIN__02)) return 1;
  if (!(e1->Scan_1_vIN__03) && (e2->Scan_1_vIN__03)) return -1;
  if ((e1->Scan_1_vIN__03) && !(e2->Scan_1_vIN__03)) return 1;
  if (!(e1->Scan_1_vIN__04) && (e2->Scan_1_vIN__04)) return -1;
  if ((e1->Scan_1_vIN__04) && !(e2->Scan_1_vIN__04)) return 1;
  if (!(e1->Scan_1_vIN__05) && (e2->Scan_1_vIN__05)) return -1;
  if ((e1->Scan_1_vIN__05) && !(e2->Scan_1_vIN__05)) return 1;
  if (!(e1->Scan_1_vIN__06A) && (e2->Scan_1_vIN__06A)) return -1;
  if ((e1->Scan_1_vIN__06A) && !(e2->Scan_1_vIN__06A)) return 1;
  if (!(e1->Scan_1_vIN__06B) && (e2->Scan_1_vIN__06B)) return -1;
  if ((e1->Scan_1_vIN__06B) && !(e2->Scan_1_vIN__06B)) return 1;
  if (!(e1->Scan_1_vIN__06C) && (e2->Scan_1_vIN__06C)) return -1;
  if ((e1->Scan_1_vIN__06C) && !(e2->Scan_1_vIN__06C)) return 1;
  if (!(e1->Scan_1_vQ__01) && (e2->Scan_1_vQ__01)) return -1;
  if ((e1->Scan_1_vQ__01) && !(e2->Scan_1_vQ__01)) return 1;
  if (!(e1->Scan_1_vQ__02) && (e2->Scan_1_vQ__02)) return -1;
  if ((e1->Scan_1_vQ__02) && !(e2->Scan_1_vQ__02)) return 1;
  if (!(e1->Scan_1_vQ__03) && (e2->Scan_1_vQ__03)) return -1;
  if ((e1->Scan_1_vQ__03) && !(e2->Scan_1_vQ__03)) return 1;
  if (!(e1->Scan_1_vQ__04) && (e2->Scan_1_vQ__04)) return -1;
  if ((e1->Scan_1_vQ__04) && !(e2->Scan_1_vQ__04)) return 1;
  if (!(e1->TON_1_vQ) && (e2->TON_1_vQ)) return -1;
  if ((e1->TON_1_vQ) && !(e2->TON_1_vQ)) return 1;
  if (!(e1->TON_2_vQ) && (e2->TON_2_vQ)) return -1;
  if ((e1->TON_2_vQ) && !(e2->TON_2_vQ)) return 1;
  return 0;
}

static int sprint_value (int sz, char *buff, const struct pmap *pmap) {
  struct value *v = &state;
  avail = sz - 1;
  /* prints state into buff: */
  PUTS(pmap->r.l);
  PUTN(14,pmap->n,"Scan_1_vIN__01"); PUTS(pmap->r.b); if (v->Scan_1_vIN__01) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(14,pmap->n,"Scan_1_vIN__02"); PUTS(pmap->r.b); if (v->Scan_1_vIN__02) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(14,pmap->n,"Scan_1_vIN__03"); PUTS(pmap->r.b); if (v->Scan_1_vIN__03) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(14,pmap->n,"Scan_1_vIN__04"); PUTS(pmap->r.b); if (v->Scan_1_vIN__04) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(14,pmap->n,"Scan_1_vIN__05"); PUTS(pmap->r.b); if (v->Scan_1_vIN__05) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(15,pmap->n,"Scan_1_vIN__06A"); PUTS(pmap->r.b); if (v->Scan_1_vIN__06A) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(15,pmap->n,"Scan_1_vIN__06B"); PUTS(pmap->r.b); if (v->Scan_1_vIN__06B) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(15,pmap->n,"Scan_1_vIN__06C"); PUTS(pmap->r.b); if (v->Scan_1_vIN__06C) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(13,pmap->n,"Scan_1_vQ__01"); PUTS(pmap->r.b); if (v->Scan_1_vQ__01) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(13,pmap->n,"Scan_1_vQ__02"); PUTS(pmap->r.b); if (v->Scan_1_vQ__02) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(13,pmap->n,"Scan_1_vQ__03"); PUTS(pmap->r.b); if (v->Scan_1_vQ__03) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(13,pmap->n,"Scan_1_vQ__04"); PUTS(pmap->r.b); if (v->Scan_1_vQ__04) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(8,pmap->n,"TON_1_vQ"); PUTS(pmap->r.b); if (v->TON_1_vQ) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(8,pmap->n,"TON_2_vQ"); PUTS(pmap->r.b); if (v->TON_2_vQ) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.r);
  return (avail<0) ? -1 : (sz - avail - 1);
}

int sprint_state (int sz, char *buff) {
  return sprint_value (sz, buff, &fcrPmap);
}

int sprint_json_state (int sz, char *buff) {
  return sprint_value (sz, buff, &jsonPmap);
}

/* initializes temporaries and creates initial state */
void initial() {
  /* state variables: */
  state.Scan_1_vIN__01=0;
  state.Scan_1_vIN__02=0;
  state.Scan_1_vIN__03=0;
  state.Scan_1_vIN__04=0;
  state.Scan_1_vIN__05=0;
  state.Scan_1_vIN__06A=0;
  state.Scan_1_vIN__06B=0;
  state.Scan_1_vIN__06C=0;
  state.Scan_1_vQ__01=0;
  state.Scan_1_vQ__02=0;
  state.Scan_1_vQ__03=0;
  state.Scan_1_vQ__04=0;
  state.TON_1_vQ=0;
  state.TON_2_vQ=0;
}


/* -- predicates and actions */
/* by default, pre_t* returns true and act_t* is the identity function */

/* translation table for transition names */
char *transtable[28] = {"TON_1_t0_Scan_1_t3","TON_1_t1_Scan_1_t3","TON_1_t3_Scan_1_t3","TON_1_t4_Scan_1_t3","TON_1_t7_Scan_1_t3","TON_1_t8_Scan_1_t3","TON_1_t2_Scan_1_t4","TON_1_t6_Scan_1_t4","TON_1_t9_Scan_1_t4","TON_2_t0_Scan_1_t5","TON_2_t1_Scan_1_t5","TON_2_t3_Scan_1_t5","TON_2_t4_Scan_1_t5","TON_2_t7_Scan_1_t5","TON_2_t8_Scan_1_t5","TON_2_t2_Scan_1_t6","TON_2_t6_Scan_1_t6","TON_2_t9_Scan_1_t6","TON_1_t5","TON_2_t5","Scan_1_t0","Scan_1_t1","Scan_1_t2","Scan_1_t7","Scan_1_t8","Scan_1_t9","Scan_1_t10","Scan_1_t11"};

char **transitions (int *sz) {
*sz =28;
return transtable;
}

bool pre_0 () {
  /* TON_1_t0_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!(v->Scan_1_vIN__02)) return 0;
  return 1;
 error: return 0;
}

bool pre_1 () {
  /* TON_1_t1_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (v->Scan_1_vIN__02) return 0;
  return 1;
 error: return 0;
}

bool pre_2 () {
  /* TON_1_t3_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (v->Scan_1_vIN__02) return 0;
  return 1;
 error: return 0;
}

bool pre_3 () {
  /* TON_1_t4_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!(v->Scan_1_vIN__02)) return 0;
  return 1;
 error: return 0;
}

bool pre_4 () {
  /* TON_1_t7_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (v->Scan_1_vIN__02) return 0;
  return 1;
 error: return 0;
}

bool pre_5 () {
  /* TON_1_t8_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!(v->Scan_1_vIN__02)) return 0;
  return 1;
 error: return 0;
}

bool pre_9 () {
  /* TON_2_t0_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!(v->Scan_1_vIN__04)) return 0;
  return 1;
 error: return 0;
}

bool pre_10 () {
  /* TON_2_t1_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (v->Scan_1_vIN__04) return 0;
  return 1;
 error: return 0;
}

bool pre_11 () {
  /* TON_2_t3_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (v->Scan_1_vIN__04) return 0;
  return 1;
 error: return 0;
}

bool pre_12 () {
  /* TON_2_t4_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!(v->Scan_1_vIN__04)) return 0;
  return 1;
 error: return 0;
}

bool pre_13 () {
  /* TON_2_t7_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (v->Scan_1_vIN__04) return 0;
  return 1;
 error: return 0;
}

bool pre_14 () {
  /* TON_2_t8_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!(v->Scan_1_vIN__04)) return 0;
  return 1;
 error: return 0;
}

bool pre_20 () {
  /* Scan_1_t0 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!((f_read_start > 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_21 () {
  /* Scan_1_t1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!((f_read_terminate > 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_25 () {
  /* Scan_1_t9 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!((f_write_start > 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_26 () {
  /* Scan_1_t10 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  struct value *v = &state;
  if (!((f_write_terminate > 0))) return 0;
  return 1;
 error: return 0;
}

bool act_4 () {
  /* TON_1_t7_Scan_1_t3:portTON_IN_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  state.TON_1_vQ=0; 
  return 1;
 error: return 0;
}

bool act_6 () {
  /* TON_1_t2_Scan_1_t4:portTON_Q_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vTON__Q__1=state.TON_1_vQ; 
  state.Scan_1_vQ__01=(state.Scan_1_vIN__01 || Scan_1_vTON__Q__1); 
  return 1;
 error: return 0;
}

bool act_7 () {
  /* TON_1_t6_Scan_1_t4:portTON_Q_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vTON__Q__1=state.TON_1_vQ; 
  state.Scan_1_vQ__01=(state.Scan_1_vIN__01 || Scan_1_vTON__Q__1); 
  return 1;
 error: return 0;
}

bool act_8 () {
  /* TON_1_t9_Scan_1_t4:portTON_Q_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vTON__Q__1=state.TON_1_vQ; 
  state.Scan_1_vQ__01=(state.Scan_1_vIN__01 || Scan_1_vTON__Q__1); 
  return 1;
 error: return 0;
}

bool act_13 () {
  /* TON_2_t7_Scan_1_t5:portTON_IN_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  state.TON_2_vQ=0; 
  return 1;
 error: return 0;
}

bool act_15 () {
  /* TON_2_t2_Scan_1_t6:portTON_Q_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vTON__Q__2=state.TON_2_vQ; 
  state.Scan_1_vQ__02=(((state.Scan_1_vIN__01 && state.Scan_1_vIN__03) || state.Scan_1_vIN__05) || Scan_1_vTON__Q__2); 
  return 1;
 error: return 0;
}

bool act_16 () {
  /* TON_2_t6_Scan_1_t6:portTON_Q_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vTON__Q__2=state.TON_2_vQ; 
  state.Scan_1_vQ__02=(((state.Scan_1_vIN__01 && state.Scan_1_vIN__03) || state.Scan_1_vIN__05) || Scan_1_vTON__Q__2); 
  return 1;
 error: return 0;
}

bool act_17 () {
  /* TON_2_t9_Scan_1_t6:portTON_Q_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vTON__Q__2=state.TON_2_vQ; 
  state.Scan_1_vQ__02=(((state.Scan_1_vIN__01 && state.Scan_1_vIN__03) || state.Scan_1_vIN__05) || Scan_1_vTON__Q__2); 
  return 1;
 error: return 0;
}

bool act_18 () {
  /* TON_1_t5:portTON_Timer_1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  state.TON_1_vQ=1; 
  return 1;
 error: return 0;
}

bool act_19 () {
  /* TON_2_t5:portTON_Timer_2 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  state.TON_2_vQ=1; 
  return 1;
 error: return 0;
}

bool act_20 () {
  /* Scan_1_t0 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  f_read_start=0; 
  return 1;
 error: return 0;
}

bool act_21 () {
  /* Scan_1_t1 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  f_read_terminate=0; 
  Scan_1_vtmp=f_read_output; 
  state.Scan_1_vIN__01=Scan_1_vtmp.at[0]; 
  state.Scan_1_vIN__02=Scan_1_vtmp.at[1]; 
  state.Scan_1_vIN__03=Scan_1_vtmp.at[2]; 
  state.Scan_1_vIN__04=Scan_1_vtmp.at[3]; 
  state.Scan_1_vIN__05=Scan_1_vtmp.at[4]; 
  state.Scan_1_vIN__06A=Scan_1_vtmp.at[5]; 
  state.Scan_1_vIN__06B=Scan_1_vtmp.at[6]; 
  state.Scan_1_vIN__06C=Scan_1_vtmp.at[7]; 
  return 1;
 error: return 0;
}

bool act_23 () {
  /* Scan_1_t7 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  state.Scan_1_vQ__03=((state.Scan_1_vIN__06A || state.Scan_1_vIN__06B) || state.Scan_1_vIN__06C); 
  return 1;
 error: return 0;
}

bool act_24 () {
  /* Scan_1_t8 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  Scan_1_vstate__vote=fcr_v2oo3(state.Scan_1_vIN__06A,state.Scan_1_vIN__06B,state.Scan_1_vIN__06C); 
  state.Scan_1_vQ__04=(Scan_1_vstate__vote || state.Scan_1_vIN__05); 
  return 1;
 error: return 0;
}

bool act_25 () {
  /* Scan_1_t9 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  f_write_start=0; 
  f_write_input_1.at[0]=state.Scan_1_vQ__01; 
  f_write_input_1.at[1]=state.Scan_1_vQ__02; 
  f_write_input_1.at[2]=state.Scan_1_vQ__03; 
  f_write_input_1.at[3]=state.Scan_1_vQ__04; 
  return 1;
 error: return 0;
}

bool act_26 () {
  /* Scan_1_t10 */
  bool Scan_1_vstate__vote;
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp;
  f_write_terminate=0; 
  return 1;
 error: return 0;
}

