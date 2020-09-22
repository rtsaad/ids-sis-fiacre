/* Created Wed Sep 16 18:00:45 2020 by frac version 2.6.0 */

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <fiacre.h>

/* provider */
char *source_info[3] = {"frac","2.6.0","Wed Sep 16 18:00:45 2020"};
char **sourceinfo () {return source_info;}

/* fiacre and private headers */
#include "hippo_app_functions.h"

static int avail;    /* for sprint_* */
static char tmpbuff[16]; /* for sprint_* */

/* utilities for structure a0 */

static int compare_a0 (struct a0 e1, struct a0 e2) {
  size_t i = 0;
  for (i=0; i<29; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a0 (char *buff, struct a0 *e, const struct pmap *pmap) {
  int j0;
  PUTS(pmap->a.l);
  for (j0=0; j0<29; j0++) {
    if (j0) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j0]);
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

/* utilities for structure a2 */

static int compare_a2 (struct a2 e1, struct a2 e2) {
  size_t i = 0;
  for (i=0; i<7; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a2 (char *buff, struct a2 *e, const struct pmap *pmap) {
  int j2;
  PUTS(pmap->a.l);
  for (j2=0; j2<7; j2++) {
    if (j2) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j2]);
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a3 */

static int compare_a3 (struct a3 e1, struct a3 e2) {
  size_t i = 0;
  for (i=0; i<7; i++) {
    if (!(e1.at[i]) && (e2.at[i])) return -1;
    if ((e1.at[i]) && !(e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a3 (char *buff, struct a3 *e, const struct pmap *pmap) {
  int j3;
  PUTS(pmap->a.l);
  for (j3=0; j3<7; j3++) {
    if (j3) {PUTS(pmap->a.s);}
    if (e->at[j3]) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a4 */

static int compare_a4 (struct a4 e1, struct a4 e2) {
  size_t i = 0;
  for (i=0; i<5; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a4 (char *buff, struct a4 *e, const struct pmap *pmap) {
  int j4;
  PUTS(pmap->a.l);
  for (j4=0; j4<5; j4++) {
    if (j4) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j4]);
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a5 */

static int compare_a5 (struct a5 e1, struct a5 e2) {
  size_t i = 0;
  for (i=0; i<5; i++) {
    if (!(e1.at[i]) && (e2.at[i])) return -1;
    if ((e1.at[i]) && !(e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a5 (char *buff, struct a5 *e, const struct pmap *pmap) {
  int j5;
  PUTS(pmap->a.l);
  for (j5=0; j5<5; j5++) {
    if (j5) {PUTS(pmap->a.s);}
    if (e->at[j5]) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a6 */

static int compare_a6 (struct a6 e1, struct a6 e2) {
  size_t i = 0;
  for (i=0; i<10; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a6 (char *buff, struct a6 *e, const struct pmap *pmap) {
  int j6;
  PUTS(pmap->a.l);
  for (j6=0; j6<10; j6++) {
    if (j6) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j6]);
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a7 */

static int compare_a7 (struct a7 e1, struct a7 e2) {
  size_t i = 0;
  for (i=0; i<10; i++) {
    if (!(e1.at[i]) && (e2.at[i])) return -1;
    if ((e1.at[i]) && !(e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a7 (char *buff, struct a7 *e, const struct pmap *pmap) {
  int j7;
  PUTS(pmap->a.l);
  for (j7=0; j7<10; j7++) {
    if (j7) {PUTS(pmap->a.s);}
    if (e->at[j7]) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  }
  PUTS(pmap->a.r);
  return buff;
}

/* utilities for structure a8 */

static int compare_a8 (struct a8 e1, struct a8 e2) {
  size_t i = 0;
  for (i=0; i<4; i++) {
    if ((e1.at[i]) < (e2.at[i])) return -1;
    if ((e1.at[i]) > (e2.at[i])) return 1;
  }
  return 0;
}

static char *sprint_a8 (char *buff, struct a8 *e, const struct pmap *pmap) {
  int j8;
  PUTS(pmap->a.l);
  for (j8=0; j8<4; j8++) {
    if (j8) {PUTS(pmap->a.s);}
    PUTV("%d",e->at[j8]);
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

/* fiacre task f_print_b, cname f_print_b */
bool f_print_b_input_1;
int f_print_b_output;
extern int f_print_b_start;
extern int f_print_b_terminate;
void wrapper_f_print_b() {
    f_print_b_output = f_print_b( f_print_b_input_1);
}

/* fiacre task f_print_n, cname f_print_n */
int f_print_n_input_1;
int f_print_n_output;
extern int f_print_n_start;
extern int f_print_n_terminate;
void wrapper_f_print_n() {
    f_print_n_output = f_print_n( f_print_n_input_1);
}

/* Fiacre function v1oo4 */
bool fcr_v1oo4 (bool A, bool B, bool C, bool D) {
    bool Q; 
    Q=0; 
    Q=(((A || B) || C) || D); 
    return Q;
}

/* Fiacre function v1oo7 */
bool fcr_v1oo7 (bool A, bool B, bool C, bool D, bool E, bool F, bool G) {
    bool Q; 
    Q=0; 
    Q=((((((A || B) || C) || D) || E) || F) || G); 
    return Q;
}

/* Fiacre function v1oo10 */
bool fcr_v1oo10 (bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool H, bool I, bool J) {
    bool Q; 
    Q=0; 
    Q=(((((((((A || B) || C) || D) || E) || F) || G) || H) || I) || J); 
    return Q;
}

/* Fiacre function v2oo3 */
bool fcr_v2oo3 (bool A, bool B, bool C) {
    bool Q; 
    Q=0; 
    Q=(((A && B) || (B && C)) || (A && C)); 
    return Q;
}

/* Fiacre function v2oo4 */
bool fcr_v2oo4 (bool I1, bool I2, bool I3, bool I4) {
    bool Q; 
    Q=0; 
    Q=((((((I1 && I2) || (I1 && I3)) || (I1 && I4)) || (I2 && I3)) || (I2 && I4)) || (I3 && I4)); 
    return Q;
}

/* Fiacre function v2oo5 */
bool fcr_v2oo5 (bool I1, bool I2, bool I3, bool I4, bool I5) {
    bool Q; 
    Q=0; 
    Q=((((((((((I1 && I2) || (I1 && I3)) || (I1 && I4)) || (I1 && I5)) || (I2 && I3)) || (I2 && I4)) || (I2 && I5)) || (I3 && I4)) || (I3 && I5)) || (I4 && I5)); 
    return Q;
}

/* Fiacre function v2oo7 */
bool fcr_v2oo7 (bool I1, bool I2, bool I3, bool I4, bool I5, bool I6, bool I7) {
    bool Q; 
    Q=0; 
    Q=(((((((((((((((((((((I1 && I2) || (I1 && I3)) || (I1 && I4)) || (I1 && I5)) || (I1 && I6)) || (I1 && I7)) || (I2 && I3)) || (I2 && I4)) || (I2 && I5)) || (I2 && I6)) || (I2 && I7)) || (I3 && I4)) || (I3 && I5)) || (I3 && I6)) || (I3 && I7)) || (I4 && I5)) || (I4 && I6)) || (I4 && I7)) || (I5 && I6)) || (I5 && I7)) || (I6 && I7)); 
    return Q;
}

/* Fiacre function v2oo10 */
bool fcr_v2oo10 (bool I1, bool I2, bool I3, bool I4, bool I5, bool I6, bool I7, bool I8, bool I9, bool I10) {
    bool Q; 
    Q=0; 
    Q=(((((((((((((((((((((((((((((((((((((((((((((I1 && I2) || (I1 && I3)) || (I1 && I4)) || (I1 && I5)) || (I1 && I6)) || (I1 && I7)) || (I1 && I8)) || (I1 && I9)) || (I1 && I10)) || (I2 && I3)) || (I2 && I4)) || (I2 && I5)) || (I2 && I6)) || (I2 && I7)) || (I2 && I8)) || (I2 && I9)) || (I2 && I10)) || (I3 && I4)) || (I3 && I5)) || (I3 && I6)) || (I3 && I7)) || (I3 && I8)) || (I3 && I9)) || (I3 && I10)) || (I4 && I5)) || (I4 && I6)) || (I4 && I7)) || (I4 && I8)) || (I4 && I9)) || (I4 && I10)) || (I5 && I6)) || (I5 && I7)) || (I5 && I8)) || (I5 && I9)) || (I5 && I10)) || (I6 && I7)) || (I6 && I8)) || (I6 && I9)) || (I6 && I10)) || (I7 && I8)) || (I7 && I9)) || (I7 && I10)) || (I8 && I9)) || (I8 && I10)) || (I9 && I10)); 
    return Q;
}

/* Fiacre function analog_to_bool */
bool fcr_analog_to_bool (int value, bool level_h, int threshould) {
    bool Q; 
    Q=0; 
    if (level_h) {
      if ((value >= threshould)) {
        return 1;
      } else {
        return 0;
      }
    } else {
      if ((value <= threshould)) {
        return 1;
      } else {
        return 0;
      }
    }
}

/* Process TON_2_TON_1_Scan_1 */

/* state type */

struct value {
  struct a2 Scan_1_vINPUT__001__007;
  struct a3 Scan_1_vINPUT__001__007__HH;
  int Scan_1_vINPUT__008;
  bool Scan_1_vINPUT__008__L;
  struct a4 Scan_1_vINPUT__009__013;
  struct a5 Scan_1_vINPUT__009__013__HH;
  struct a6 Scan_1_vINPUT__014__023;
  struct a7 Scan_1_vINPUT__014__023__HH;
  struct a8 Scan_1_vINPUT__024__027;
  struct a1 Scan_1_vINPUT__024__027__HH;
  bool Scan_1_vOUTPUT__1;
  bool Scan_1_vOUTPUT__2;
  int Scan_1_vINPUT__28__CMZ;
  bool Scan_1_vOUTPUT__3;
  bool Scan_1_vOUTPUT__4;
  bool Scan_1_vstate__vote__2oo7__INPUT__001__007;
  bool Scan_1_vstate__vote__2oo7__INPUT__001__007__ON;
  bool Scan_1_vstate__vote__1oo7__INPUT__001__007;
  bool Scan_1_vstate__vote__1oo7__INPUT__001__007__ON;
  bool Scan_1_vstate__vote__2oo5__INPUT__009__013;
  bool Scan_1_vstate__vote__2oo10__INPUT__014__023;
  bool Scan_1_vstate__vote__2oo4__INPUT__024__027;
  bool TON_1_vQ;
  bool TON_2_vQ;
};
struct value state;


/* utilities for structure value */

int compare_value (struct value *e1, struct value *e2) {
  {int r = compare_a2(e1->Scan_1_vINPUT__001__007,e2->Scan_1_vINPUT__001__007); if (r) return r;}
  {int r = compare_a3(e1->Scan_1_vINPUT__001__007__HH,e2->Scan_1_vINPUT__001__007__HH); if (r) return r;}
  if ((e1->Scan_1_vINPUT__008) < (e2->Scan_1_vINPUT__008)) return -1;
  if ((e1->Scan_1_vINPUT__008) > (e2->Scan_1_vINPUT__008)) return 1;
  if (!(e1->Scan_1_vINPUT__008__L) && (e2->Scan_1_vINPUT__008__L)) return -1;
  if ((e1->Scan_1_vINPUT__008__L) && !(e2->Scan_1_vINPUT__008__L)) return 1;
  {int r = compare_a4(e1->Scan_1_vINPUT__009__013,e2->Scan_1_vINPUT__009__013); if (r) return r;}
  {int r = compare_a5(e1->Scan_1_vINPUT__009__013__HH,e2->Scan_1_vINPUT__009__013__HH); if (r) return r;}
  {int r = compare_a6(e1->Scan_1_vINPUT__014__023,e2->Scan_1_vINPUT__014__023); if (r) return r;}
  {int r = compare_a7(e1->Scan_1_vINPUT__014__023__HH,e2->Scan_1_vINPUT__014__023__HH); if (r) return r;}
  {int r = compare_a8(e1->Scan_1_vINPUT__024__027,e2->Scan_1_vINPUT__024__027); if (r) return r;}
  {int r = compare_a1(e1->Scan_1_vINPUT__024__027__HH,e2->Scan_1_vINPUT__024__027__HH); if (r) return r;}
  if (!(e1->Scan_1_vOUTPUT__1) && (e2->Scan_1_vOUTPUT__1)) return -1;
  if ((e1->Scan_1_vOUTPUT__1) && !(e2->Scan_1_vOUTPUT__1)) return 1;
  if (!(e1->Scan_1_vOUTPUT__2) && (e2->Scan_1_vOUTPUT__2)) return -1;
  if ((e1->Scan_1_vOUTPUT__2) && !(e2->Scan_1_vOUTPUT__2)) return 1;
  if ((e1->Scan_1_vINPUT__28__CMZ) < (e2->Scan_1_vINPUT__28__CMZ)) return -1;
  if ((e1->Scan_1_vINPUT__28__CMZ) > (e2->Scan_1_vINPUT__28__CMZ)) return 1;
  if (!(e1->Scan_1_vOUTPUT__3) && (e2->Scan_1_vOUTPUT__3)) return -1;
  if ((e1->Scan_1_vOUTPUT__3) && !(e2->Scan_1_vOUTPUT__3)) return 1;
  if (!(e1->Scan_1_vOUTPUT__4) && (e2->Scan_1_vOUTPUT__4)) return -1;
  if ((e1->Scan_1_vOUTPUT__4) && !(e2->Scan_1_vOUTPUT__4)) return 1;
  if (!(e1->Scan_1_vstate__vote__2oo7__INPUT__001__007) && (e2->Scan_1_vstate__vote__2oo7__INPUT__001__007)) return -1;
  if ((e1->Scan_1_vstate__vote__2oo7__INPUT__001__007) && !(e2->Scan_1_vstate__vote__2oo7__INPUT__001__007)) return 1;
  if (!(e1->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON) && (e2->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON)) return -1;
  if ((e1->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON) && !(e2->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON)) return 1;
  if (!(e1->Scan_1_vstate__vote__1oo7__INPUT__001__007) && (e2->Scan_1_vstate__vote__1oo7__INPUT__001__007)) return -1;
  if ((e1->Scan_1_vstate__vote__1oo7__INPUT__001__007) && !(e2->Scan_1_vstate__vote__1oo7__INPUT__001__007)) return 1;
  if (!(e1->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON) && (e2->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON)) return -1;
  if ((e1->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON) && !(e2->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON)) return 1;
  if (!(e1->Scan_1_vstate__vote__2oo5__INPUT__009__013) && (e2->Scan_1_vstate__vote__2oo5__INPUT__009__013)) return -1;
  if ((e1->Scan_1_vstate__vote__2oo5__INPUT__009__013) && !(e2->Scan_1_vstate__vote__2oo5__INPUT__009__013)) return 1;
  if (!(e1->Scan_1_vstate__vote__2oo10__INPUT__014__023) && (e2->Scan_1_vstate__vote__2oo10__INPUT__014__023)) return -1;
  if ((e1->Scan_1_vstate__vote__2oo10__INPUT__014__023) && !(e2->Scan_1_vstate__vote__2oo10__INPUT__014__023)) return 1;
  if (!(e1->Scan_1_vstate__vote__2oo4__INPUT__024__027) && (e2->Scan_1_vstate__vote__2oo4__INPUT__024__027)) return -1;
  if ((e1->Scan_1_vstate__vote__2oo4__INPUT__024__027) && !(e2->Scan_1_vstate__vote__2oo4__INPUT__024__027)) return 1;
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
  PUTN(23,pmap->n,"Scan_1_vINPUT__001__007"); PUTS(pmap->r.b); buff = sprint_a2 (buff,&v->Scan_1_vINPUT__001__007,pmap);
  PUTS(pmap->r.s);
  PUTN(27,pmap->n,"Scan_1_vINPUT__001__007__HH"); PUTS(pmap->r.b); buff = sprint_a3 (buff,&v->Scan_1_vINPUT__001__007__HH,pmap);
  PUTS(pmap->r.s);
  PUTN(18,pmap->n,"Scan_1_vINPUT__008"); PUTS(pmap->r.b); PUTV("%d",v->Scan_1_vINPUT__008);
  PUTS(pmap->r.s);
  PUTN(21,pmap->n,"Scan_1_vINPUT__008__L"); PUTS(pmap->r.b); if (v->Scan_1_vINPUT__008__L) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(23,pmap->n,"Scan_1_vINPUT__009__013"); PUTS(pmap->r.b); buff = sprint_a4 (buff,&v->Scan_1_vINPUT__009__013,pmap);
  PUTS(pmap->r.s);
  PUTN(27,pmap->n,"Scan_1_vINPUT__009__013__HH"); PUTS(pmap->r.b); buff = sprint_a5 (buff,&v->Scan_1_vINPUT__009__013__HH,pmap);
  PUTS(pmap->r.s);
  PUTN(23,pmap->n,"Scan_1_vINPUT__014__023"); PUTS(pmap->r.b); buff = sprint_a6 (buff,&v->Scan_1_vINPUT__014__023,pmap);
  PUTS(pmap->r.s);
  PUTN(27,pmap->n,"Scan_1_vINPUT__014__023__HH"); PUTS(pmap->r.b); buff = sprint_a7 (buff,&v->Scan_1_vINPUT__014__023__HH,pmap);
  PUTS(pmap->r.s);
  PUTN(23,pmap->n,"Scan_1_vINPUT__024__027"); PUTS(pmap->r.b); buff = sprint_a8 (buff,&v->Scan_1_vINPUT__024__027,pmap);
  PUTS(pmap->r.s);
  PUTN(27,pmap->n,"Scan_1_vINPUT__024__027__HH"); PUTS(pmap->r.b); buff = sprint_a1 (buff,&v->Scan_1_vINPUT__024__027__HH,pmap);
  PUTS(pmap->r.s);
  PUTN(17,pmap->n,"Scan_1_vOUTPUT__1"); PUTS(pmap->r.b); if (v->Scan_1_vOUTPUT__1) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(17,pmap->n,"Scan_1_vOUTPUT__2"); PUTS(pmap->r.b); if (v->Scan_1_vOUTPUT__2) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(22,pmap->n,"Scan_1_vINPUT__28__CMZ"); PUTS(pmap->r.b); PUTV("%d",v->Scan_1_vINPUT__28__CMZ);
  PUTS(pmap->r.s);
  PUTN(17,pmap->n,"Scan_1_vOUTPUT__3"); PUTS(pmap->r.b); if (v->Scan_1_vOUTPUT__3) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(17,pmap->n,"Scan_1_vOUTPUT__4"); PUTS(pmap->r.b); if (v->Scan_1_vOUTPUT__4) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(42,pmap->n,"Scan_1_vstate__vote__2oo7__INPUT__001__007"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__2oo7__INPUT__001__007) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(46,pmap->n,"Scan_1_vstate__vote__2oo7__INPUT__001__007__ON"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(42,pmap->n,"Scan_1_vstate__vote__1oo7__INPUT__001__007"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__1oo7__INPUT__001__007) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(46,pmap->n,"Scan_1_vstate__vote__1oo7__INPUT__001__007__ON"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(42,pmap->n,"Scan_1_vstate__vote__2oo5__INPUT__009__013"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__2oo5__INPUT__009__013) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(43,pmap->n,"Scan_1_vstate__vote__2oo10__INPUT__014__023"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__2oo10__INPUT__014__023) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
  PUTS(pmap->r.s);
  PUTN(42,pmap->n,"Scan_1_vstate__vote__2oo4__INPUT__024__027"); PUTS(pmap->r.b); if (v->Scan_1_vstate__vote__2oo4__INPUT__024__027) {PUTN(4,pmap->n,"true");} else {PUTN(5,pmap->n,"false");}
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
  state.Scan_1_vINPUT__001__007.at[0]=0;
  state.Scan_1_vINPUT__001__007.at[1]=0;
  state.Scan_1_vINPUT__001__007.at[2]=0;
  state.Scan_1_vINPUT__001__007.at[3]=0;
  state.Scan_1_vINPUT__001__007.at[4]=0;
  state.Scan_1_vINPUT__001__007.at[5]=0;
  state.Scan_1_vINPUT__001__007.at[6]=0;
  state.Scan_1_vINPUT__001__007__HH.at[0]=0;
  state.Scan_1_vINPUT__001__007__HH.at[1]=0;
  state.Scan_1_vINPUT__001__007__HH.at[2]=0;
  state.Scan_1_vINPUT__001__007__HH.at[3]=0;
  state.Scan_1_vINPUT__001__007__HH.at[4]=0;
  state.Scan_1_vINPUT__001__007__HH.at[5]=0;
  state.Scan_1_vINPUT__001__007__HH.at[6]=0;
  state.Scan_1_vINPUT__008=0;
  state.Scan_1_vINPUT__008__L=0;
  state.Scan_1_vINPUT__009__013.at[0]=0;
  state.Scan_1_vINPUT__009__013.at[1]=0;
  state.Scan_1_vINPUT__009__013.at[2]=0;
  state.Scan_1_vINPUT__009__013.at[3]=0;
  state.Scan_1_vINPUT__009__013.at[4]=0;
  state.Scan_1_vINPUT__009__013__HH.at[0]=0;
  state.Scan_1_vINPUT__009__013__HH.at[1]=0;
  state.Scan_1_vINPUT__009__013__HH.at[2]=0;
  state.Scan_1_vINPUT__009__013__HH.at[3]=0;
  state.Scan_1_vINPUT__009__013__HH.at[4]=0;
  state.Scan_1_vINPUT__014__023.at[0]=0;
  state.Scan_1_vINPUT__014__023.at[1]=0;
  state.Scan_1_vINPUT__014__023.at[2]=0;
  state.Scan_1_vINPUT__014__023.at[3]=0;
  state.Scan_1_vINPUT__014__023.at[4]=0;
  state.Scan_1_vINPUT__014__023.at[5]=0;
  state.Scan_1_vINPUT__014__023.at[6]=0;
  state.Scan_1_vINPUT__014__023.at[7]=0;
  state.Scan_1_vINPUT__014__023.at[8]=0;
  state.Scan_1_vINPUT__014__023.at[9]=0;
  state.Scan_1_vINPUT__014__023__HH.at[0]=0;
  state.Scan_1_vINPUT__014__023__HH.at[1]=0;
  state.Scan_1_vINPUT__014__023__HH.at[2]=0;
  state.Scan_1_vINPUT__014__023__HH.at[3]=0;
  state.Scan_1_vINPUT__014__023__HH.at[4]=0;
  state.Scan_1_vINPUT__014__023__HH.at[5]=0;
  state.Scan_1_vINPUT__014__023__HH.at[6]=0;
  state.Scan_1_vINPUT__014__023__HH.at[7]=0;
  state.Scan_1_vINPUT__014__023__HH.at[8]=0;
  state.Scan_1_vINPUT__014__023__HH.at[9]=0;
  state.Scan_1_vINPUT__024__027.at[0]=0;
  state.Scan_1_vINPUT__024__027.at[1]=0;
  state.Scan_1_vINPUT__024__027.at[2]=0;
  state.Scan_1_vINPUT__024__027.at[3]=0;
  state.Scan_1_vINPUT__024__027__HH.at[0]=0;
  state.Scan_1_vINPUT__024__027__HH.at[1]=0;
  state.Scan_1_vINPUT__024__027__HH.at[2]=0;
  state.Scan_1_vINPUT__024__027__HH.at[3]=0;
  state.Scan_1_vOUTPUT__1=0;
  state.Scan_1_vOUTPUT__2=0;
  state.Scan_1_vINPUT__28__CMZ=0;
  state.Scan_1_vOUTPUT__3=0;
  state.Scan_1_vOUTPUT__4=0;
  state.Scan_1_vstate__vote__2oo7__INPUT__001__007=0;
  state.Scan_1_vstate__vote__2oo7__INPUT__001__007__ON=0;
  state.Scan_1_vstate__vote__1oo7__INPUT__001__007=0;
  state.Scan_1_vstate__vote__1oo7__INPUT__001__007__ON=0;
  state.Scan_1_vstate__vote__2oo5__INPUT__009__013=0;
  state.Scan_1_vstate__vote__2oo10__INPUT__014__023=0;
  state.Scan_1_vstate__vote__2oo4__INPUT__024__027=0;
  state.TON_1_vQ=0;
  state.TON_2_vQ=0;
}


/* -- predicates and actions */
/* by default, pre_t* returns true and act_t* is the identity function */

/* translation table for transition names */
char *transtable[33] = {"TON_1_t0_Scan_1_t4","TON_1_t1_Scan_1_t4","TON_1_t3_Scan_1_t4","TON_1_t4_Scan_1_t4","TON_1_t7_Scan_1_t4","TON_1_t8_Scan_1_t4","TON_1_t2_Scan_1_t5","TON_1_t6_Scan_1_t5","TON_1_t9_Scan_1_t5","TON_2_t0_Scan_1_t6","TON_2_t1_Scan_1_t6","TON_2_t3_Scan_1_t6","TON_2_t4_Scan_1_t6","TON_2_t7_Scan_1_t6","TON_2_t8_Scan_1_t6","TON_2_t2_Scan_1_t7","TON_2_t6_Scan_1_t7","TON_2_t9_Scan_1_t7","TON_1_t5","TON_2_t5","Scan_1_t0","Scan_1_t1","Scan_1_t2","Scan_1_t3","Scan_1_t8","Scan_1_t9","Scan_1_t10","Scan_1_t11","Scan_1_t12","Scan_1_t13","Scan_1_t14","Scan_1_t15","Scan_1_t16"};

char **transitions (int *sz) {
*sz =33;
return transtable;
}

bool pre_0 () {
  /* TON_1_t0_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!(v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON)) return 0;
  return 1;
 error: return 0;
}

bool pre_1 () {
  /* TON_1_t1_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON) return 0;
  return 1;
 error: return 0;
}

bool pre_2 () {
  /* TON_1_t3_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON) return 0;
  return 1;
 error: return 0;
}

bool pre_3 () {
  /* TON_1_t4_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!(v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON)) return 0;
  return 1;
 error: return 0;
}

bool pre_4 () {
  /* TON_1_t7_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON) return 0;
  return 1;
 error: return 0;
}

bool pre_5 () {
  /* TON_1_t8_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!(v->Scan_1_vstate__vote__2oo7__INPUT__001__007__ON)) return 0;
  return 1;
 error: return 0;
}

bool pre_9 () {
  /* TON_2_t0_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!(v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON)) return 0;
  return 1;
 error: return 0;
}

bool pre_10 () {
  /* TON_2_t1_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON) return 0;
  return 1;
 error: return 0;
}

bool pre_11 () {
  /* TON_2_t3_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON) return 0;
  return 1;
 error: return 0;
}

bool pre_12 () {
  /* TON_2_t4_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!(v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON)) return 0;
  return 1;
 error: return 0;
}

bool pre_13 () {
  /* TON_2_t7_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON) return 0;
  return 1;
 error: return 0;
}

bool pre_14 () {
  /* TON_2_t8_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!(v->Scan_1_vstate__vote__1oo7__INPUT__001__007__ON)) return 0;
  return 1;
 error: return 0;
}

bool pre_20 () {
  /* Scan_1_t0 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!((f_read_start > 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_21 () {
  /* Scan_1_t1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!((f_read_terminate > 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_26 () {
  /* Scan_1_t10 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!((v->Scan_1_vINPUT__28__CMZ == 1))) return 0;
  return 1;
 error: return 0;
}

bool pre_27 () {
  /* Scan_1_t11 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!((!(v->Scan_1_vINPUT__28__CMZ == 1)))) return 0;
  return 1;
 error: return 0;
}

bool pre_30 () {
  /* Scan_1_t14 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!((f_write_start > 0))) return 0;
  return 1;
 error: return 0;
}

bool pre_31 () {
  /* Scan_1_t15 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  struct value *v = &state;
  if (!((f_write_terminate > 0))) return 0;
  return 1;
 error: return 0;
}

bool act_4 () {
  /* TON_1_t7_Scan_1_t4:portTON_IN_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.TON_1_vQ=0; 
  return 1;
 error: return 0;
}

bool act_6 () {
  /* TON_1_t2_Scan_1_t5:portTON_Q_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  Scan_1_vTON__Q__1=state.TON_1_vQ; 
  state.Scan_1_vstate__vote__2oo7__INPUT__001__007=(Scan_1_vTON__Q__1 && state.Scan_1_vstate__vote__2oo7__INPUT__001__007__ON); 
  return 1;
 error: return 0;
}

bool act_7 () {
  /* TON_1_t6_Scan_1_t5:portTON_Q_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  Scan_1_vTON__Q__1=state.TON_1_vQ; 
  state.Scan_1_vstate__vote__2oo7__INPUT__001__007=(Scan_1_vTON__Q__1 && state.Scan_1_vstate__vote__2oo7__INPUT__001__007__ON); 
  return 1;
 error: return 0;
}

bool act_8 () {
  /* TON_1_t9_Scan_1_t5:portTON_Q_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  Scan_1_vTON__Q__1=state.TON_1_vQ; 
  state.Scan_1_vstate__vote__2oo7__INPUT__001__007=(Scan_1_vTON__Q__1 && state.Scan_1_vstate__vote__2oo7__INPUT__001__007__ON); 
  return 1;
 error: return 0;
}

bool act_13 () {
  /* TON_2_t7_Scan_1_t6:portTON_IN_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.TON_2_vQ=0; 
  return 1;
 error: return 0;
}

bool act_15 () {
  /* TON_2_t2_Scan_1_t7:portTON_Q_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  Scan_1_vTON__Q__2=state.TON_2_vQ; 
  state.Scan_1_vstate__vote__1oo7__INPUT__001__007=(Scan_1_vTON__Q__2 && state.Scan_1_vstate__vote__1oo7__INPUT__001__007__ON); 
  return 1;
 error: return 0;
}

bool act_16 () {
  /* TON_2_t6_Scan_1_t7:portTON_Q_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  Scan_1_vTON__Q__2=state.TON_2_vQ; 
  state.Scan_1_vstate__vote__1oo7__INPUT__001__007=(Scan_1_vTON__Q__2 && state.Scan_1_vstate__vote__1oo7__INPUT__001__007__ON); 
  return 1;
 error: return 0;
}

bool act_17 () {
  /* TON_2_t9_Scan_1_t7:portTON_Q_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  Scan_1_vTON__Q__2=state.TON_2_vQ; 
  state.Scan_1_vstate__vote__1oo7__INPUT__001__007=(Scan_1_vTON__Q__2 && state.Scan_1_vstate__vote__1oo7__INPUT__001__007__ON); 
  return 1;
 error: return 0;
}

bool act_18 () {
  /* TON_1_t5:portTON_Timer_1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.TON_1_vQ=1; 
  return 1;
 error: return 0;
}

bool act_19 () {
  /* TON_2_t5:portTON_Timer_2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.TON_2_vQ=1; 
  return 1;
 error: return 0;
}

bool act_20 () {
  /* Scan_1_t0 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  f_read_start=0; 
  return 1;
 error: return 0;
}

bool act_21 () {
  /* Scan_1_t1 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  f_read_terminate=0; 
  Scan_1_vtmp__input=f_read_output; 
  state.Scan_1_vINPUT__001__007.at[0]=Scan_1_vtmp__input.at[0]; 
  state.Scan_1_vINPUT__001__007.at[1]=Scan_1_vtmp__input.at[1]; 
  state.Scan_1_vINPUT__001__007.at[2]=Scan_1_vtmp__input.at[2]; 
  state.Scan_1_vINPUT__001__007.at[3]=Scan_1_vtmp__input.at[3]; 
  state.Scan_1_vINPUT__001__007.at[4]=Scan_1_vtmp__input.at[4]; 
  state.Scan_1_vINPUT__001__007.at[5]=Scan_1_vtmp__input.at[5]; 
  state.Scan_1_vINPUT__001__007.at[6]=Scan_1_vtmp__input.at[6]; 
  state.Scan_1_vINPUT__008=Scan_1_vtmp__input.at[7]; 
  state.Scan_1_vINPUT__009__013.at[0]=Scan_1_vtmp__input.at[8]; 
  state.Scan_1_vINPUT__009__013.at[1]=Scan_1_vtmp__input.at[9]; 
  state.Scan_1_vINPUT__009__013.at[2]=Scan_1_vtmp__input.at[10]; 
  state.Scan_1_vINPUT__009__013.at[3]=Scan_1_vtmp__input.at[11]; 
  state.Scan_1_vINPUT__009__013.at[4]=Scan_1_vtmp__input.at[12]; 
  state.Scan_1_vINPUT__014__023.at[0]=Scan_1_vtmp__input.at[13]; 
  state.Scan_1_vINPUT__014__023.at[1]=Scan_1_vtmp__input.at[14]; 
  state.Scan_1_vINPUT__014__023.at[2]=Scan_1_vtmp__input.at[15]; 
  state.Scan_1_vINPUT__014__023.at[3]=Scan_1_vtmp__input.at[16]; 
  state.Scan_1_vINPUT__014__023.at[4]=Scan_1_vtmp__input.at[17]; 
  state.Scan_1_vINPUT__014__023.at[5]=Scan_1_vtmp__input.at[18]; 
  state.Scan_1_vINPUT__014__023.at[6]=Scan_1_vtmp__input.at[19]; 
  state.Scan_1_vINPUT__014__023.at[7]=Scan_1_vtmp__input.at[20]; 
  state.Scan_1_vINPUT__014__023.at[8]=Scan_1_vtmp__input.at[21]; 
  state.Scan_1_vINPUT__014__023.at[9]=Scan_1_vtmp__input.at[22]; 
  state.Scan_1_vINPUT__024__027.at[0]=Scan_1_vtmp__input.at[23]; 
  state.Scan_1_vINPUT__024__027.at[1]=Scan_1_vtmp__input.at[24]; 
  state.Scan_1_vINPUT__024__027.at[2]=Scan_1_vtmp__input.at[25]; 
  state.Scan_1_vINPUT__024__027.at[3]=Scan_1_vtmp__input.at[26]; 
  state.Scan_1_vINPUT__28__CMZ=Scan_1_vtmp__input.at[27]; 
  return 1;
 error: return 0;
}

bool act_22 () {
  /* Scan_1_t2 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vINPUT__001__007__HH.at[0]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[0],1,28800); 
  state.Scan_1_vINPUT__001__007__HH.at[1]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[1],1,28800); 
  state.Scan_1_vINPUT__001__007__HH.at[2]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[2],1,28800); 
  state.Scan_1_vINPUT__001__007__HH.at[3]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[3],1,28800); 
  state.Scan_1_vINPUT__001__007__HH.at[4]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[4],1,28800); 
  state.Scan_1_vINPUT__001__007__HH.at[5]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[5],1,28800); 
  state.Scan_1_vINPUT__001__007__HH.at[6]=fcr_analog_to_bool(state.Scan_1_vINPUT__001__007.at[6],1,28800); 
  state.Scan_1_vINPUT__008__L=fcr_analog_to_bool(state.Scan_1_vINPUT__008,0,6563); 
  state.Scan_1_vINPUT__009__013__HH.at[0]=fcr_analog_to_bool(state.Scan_1_vINPUT__009__013.at[0],1,15600); 
  state.Scan_1_vINPUT__009__013__HH.at[1]=fcr_analog_to_bool(state.Scan_1_vINPUT__009__013.at[1],1,15600); 
  state.Scan_1_vINPUT__009__013__HH.at[2]=fcr_analog_to_bool(state.Scan_1_vINPUT__009__013.at[2],1,20400); 
  state.Scan_1_vINPUT__009__013__HH.at[3]=fcr_analog_to_bool(state.Scan_1_vINPUT__009__013.at[3],1,20400); 
  state.Scan_1_vINPUT__009__013__HH.at[4]=fcr_analog_to_bool(state.Scan_1_vINPUT__009__013.at[4],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[0]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[0],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[1]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[1],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[2]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[2],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[3]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[3],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[4]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[4],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[5]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[5],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[6]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[6],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[7]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[7],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[8]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[8],1,20400); 
  state.Scan_1_vINPUT__014__023__HH.at[9]=fcr_analog_to_bool(state.Scan_1_vINPUT__014__023.at[9],1,20400); 
  state.Scan_1_vINPUT__024__027__HH.at[0]=fcr_analog_to_bool(state.Scan_1_vINPUT__024__027.at[0],1,15600); 
  state.Scan_1_vINPUT__024__027__HH.at[1]=fcr_analog_to_bool(state.Scan_1_vINPUT__024__027.at[1],1,15600); 
  state.Scan_1_vINPUT__024__027__HH.at[2]=fcr_analog_to_bool(state.Scan_1_vINPUT__024__027.at[2],1,15600); 
  state.Scan_1_vINPUT__024__027__HH.at[3]=fcr_analog_to_bool(state.Scan_1_vINPUT__024__027.at[3],1,15600); 
  return 1;
 error: return 0;
}

bool act_23 () {
  /* Scan_1_t3 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vstate__vote__2oo7__INPUT__001__007__ON=fcr_v2oo7(state.Scan_1_vINPUT__001__007__HH.at[0],state.Scan_1_vINPUT__001__007__HH.at[1],state.Scan_1_vINPUT__001__007__HH.at[2],state.Scan_1_vINPUT__001__007__HH.at[3],state.Scan_1_vINPUT__001__007__HH.at[4],state.Scan_1_vINPUT__001__007__HH.at[5],state.Scan_1_vINPUT__001__007__HH.at[6]); 
  state.Scan_1_vstate__vote__1oo7__INPUT__001__007__ON=fcr_v1oo7(state.Scan_1_vINPUT__001__007__HH.at[0],state.Scan_1_vINPUT__001__007__HH.at[1],state.Scan_1_vINPUT__001__007__HH.at[2],state.Scan_1_vINPUT__001__007__HH.at[3],state.Scan_1_vINPUT__001__007__HH.at[4],state.Scan_1_vINPUT__001__007__HH.at[5],state.Scan_1_vINPUT__001__007__HH.at[6]); 
  state.Scan_1_vstate__vote__2oo5__INPUT__009__013=fcr_v2oo5(state.Scan_1_vINPUT__009__013__HH.at[0],state.Scan_1_vINPUT__009__013__HH.at[1],state.Scan_1_vINPUT__009__013__HH.at[2],state.Scan_1_vINPUT__009__013__HH.at[3],state.Scan_1_vINPUT__009__013__HH.at[4]); 
  state.Scan_1_vstate__vote__2oo10__INPUT__014__023=fcr_v2oo10(state.Scan_1_vINPUT__014__023__HH.at[0],state.Scan_1_vINPUT__014__023__HH.at[1],state.Scan_1_vINPUT__014__023__HH.at[2],state.Scan_1_vINPUT__014__023__HH.at[3],state.Scan_1_vINPUT__014__023__HH.at[4],state.Scan_1_vINPUT__014__023__HH.at[5],state.Scan_1_vINPUT__014__023__HH.at[6],state.Scan_1_vINPUT__014__023__HH.at[7],state.Scan_1_vINPUT__014__023__HH.at[8],state.Scan_1_vINPUT__014__023__HH.at[9]); 
  state.Scan_1_vstate__vote__2oo4__INPUT__024__027=fcr_v2oo4(state.Scan_1_vINPUT__024__027__HH.at[0],state.Scan_1_vINPUT__024__027__HH.at[1],state.Scan_1_vINPUT__024__027__HH.at[2],state.Scan_1_vINPUT__024__027__HH.at[3]); 
  return 1;
 error: return 0;
}

bool act_25 () {
  /* Scan_1_t9 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vOUTPUT__1=((((state.Scan_1_vstate__vote__2oo7__INPUT__001__007 || (state.Scan_1_vstate__vote__1oo7__INPUT__001__007 && state.Scan_1_vINPUT__008__L)) || state.Scan_1_vstate__vote__2oo5__INPUT__009__013) || state.Scan_1_vstate__vote__2oo10__INPUT__014__023) || state.Scan_1_vstate__vote__2oo4__INPUT__024__027); 
  return 1;
 error: return 0;
}

bool act_26 () {
  /* Scan_1_t10 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vOUTPUT__2=0; 
  return 1;
 error: return 0;
}

bool act_27 () {
  /* Scan_1_t11 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vOUTPUT__2=(state.Scan_1_vOUTPUT__2 || ((state.Scan_1_vstate__vote__2oo7__INPUT__001__007 || state.Scan_1_vstate__vote__1oo7__INPUT__001__007) || state.Scan_1_vINPUT__008__L)); 
  return 1;
 error: return 0;
}

bool act_28 () {
  /* Scan_1_t12 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vOUTPUT__3=((state.Scan_1_vstate__vote__2oo5__INPUT__009__013 || state.Scan_1_vstate__vote__2oo10__INPUT__014__023) || state.Scan_1_vstate__vote__2oo4__INPUT__024__027); 
  return 1;
 error: return 0;
}

bool act_29 () {
  /* Scan_1_t13 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  state.Scan_1_vOUTPUT__4=((((state.Scan_1_vstate__vote__2oo7__INPUT__001__007 || (state.Scan_1_vstate__vote__1oo7__INPUT__001__007 && state.Scan_1_vINPUT__008__L)) || state.Scan_1_vstate__vote__2oo5__INPUT__009__013) || state.Scan_1_vstate__vote__2oo10__INPUT__014__023) || state.Scan_1_vstate__vote__2oo4__INPUT__024__027); 
  return 1;
 error: return 0;
}

bool act_30 () {
  /* Scan_1_t14 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  f_write_start=0; 
  f_write_input_1.at[0]=state.Scan_1_vOUTPUT__1; 
  f_write_input_1.at[1]=state.Scan_1_vOUTPUT__2; 
  f_write_input_1.at[2]=state.Scan_1_vOUTPUT__3; 
  f_write_input_1.at[3]=state.Scan_1_vOUTPUT__4; 
  return 1;
 error: return 0;
}

bool act_31 () {
  /* Scan_1_t15 */
  bool Scan_1_vTON__Q__1;
  bool Scan_1_vTON__Q__2;
  struct a0 Scan_1_vtmp__input;
  f_write_terminate=0; 
  return 1;
 error: return 0;
}

