
#ifndef FIACRE_H
#define FIACRE_H

/* suitable for frac-2.5.0 */
#define VERSION 

#include <stdbool.h>
//typedef int bool;

/* macros and primitives for tts .c files */

/* for sprint_state */

/* as of frac 2.3.0, value printer is parameterized for fiacre or json, using that structure: */
struct pmap {
  /* queue left bracket; separator; right bracket */
  struct {struct { int z; char *s; } l; struct { int z; char *s; } s; struct { int z; char *s; } r;  } q;
  /* array left bracket; separator; right bracket */
  struct {struct { int z; char *s; } l; struct { int z; char *s; } s; struct { int z; char *s; } r;  } a;
  /* record left bracket; binding symbol; separator; right bracket */
  struct {struct { int z; char *s; } l; struct { int z; char *s; } b;  struct { int z; char *s; } s; struct { int z; char *s; } r;  } r;
  /* 1-ary construction left bracket; binding symbol; rightbracket */
  struct {struct { int z; char *s; } l; struct { int z; char *s; } b; struct { int z; char *s; } r;  } c;
  /* name formatting: extra chars % name size and format string */
  struct { int z; char *f; } n;
};
const struct pmap jsonPmap = {{{1,"["},{1,","},{1,"]"}},{{1,"["},{1,","},{1,"]"}},{{1,"{"},{1,":"},{1,","},{1,"}"}},{{1,"{"},{1,":"},{1,"}"}},{2,"\"%s\""}};
const struct pmap fcrPmap   = {{{2,"{|"},{1,","},{2,"|}"}},{{1,"["},{1,","},{1,"]"}},{{1,"{"},{1,"="},{1,","},{1,"}"}},{{0,""},{1,"("},{1,")"}},{0,"%s"}};

/* put symbol/value/name */
#define PUTS(x) {avail -= x.z; if (avail>=0) {buff += sprintf(buff,"%s",x.s);}}
#define PUTV(f,v) {avail -= sprintf(tmpbuff,f,v); if (avail>=0) {buff += sprintf(buff,f,v);}}
#define PUTN(sz,x,n) {avail -= sz + x.z; if (avail>=0) {buff += sprintf(buff,x.f,n);}}


/* exception handling */

/* as of  frac-2.4.0, the fiacre library  provides two options for  handling the
   exceptions raised  in fiacre code:  exceptions can  be handled either  by the
   frac  library, by  printing  an error  message on  the  terminal and  exiting
   (option 1),  or by  the client  of the tts  (e.g.  sift  or play,  option 2).
   Option  1 is  the default,  option  2 is  set  if the  client calls  function
   set_exceptions.   If you  want  to  forbid the  client  to handle  exceptions
   (forcing option 1), just compile the tts with flag -DHANDLEEXN. */

int exnno = 0;      /* holds exception number if any was raised */

#define EXNCOUNT 21    /* number of different exceptions; must be < 100 */

char *exnMessages[EXNCOUNT] = {
  "no exception was raised",
  "interval value out of range after negation",
  "interval value out of range after coercion",
  "interval value out of range after addition",
  "interval value out of range after subtraction",
  "interval value out of range after multiplication",
  "interval value out of range after division",
  "interval value out of range after modulo",
  "nat value out of range after negation",
  "nat value out of range after coercion",
  "nat value out of range after addition",
  "nat value out of range after subtraction",
  "nat value out of range after multiplication",
  "nat value out of range after division",
  "nat value out of range after modulo",
  "taking first of an empty queue",
  "enqueing an element into a full queue",
  "appending an element to a full queue",
  "dequeuing an empty queue",
  "match error in function",
  "assertion violation"
};

static int exnhandler = 0 /* 1 */;      /* tells if tts client handles exceptions (default does not) */

/* from ttsapi version 2 */
/* enables exn handling by client and returns exnMessages and its size */
char **set_exceptions (int *sz, int **no) {
#ifndef HANDLEEXN
  exnhandler = 1;
#endif
  *sz = EXNCOUNT;
  *no = &exnno;
  return exnMessages;
}

#if defined ALT
/* reinitializes exception number to 0; returns previous value */
int get_exception () {
  int was = exnno;
  exnno = 0;
  return was;
}
#endif

void Raise (int no) {
  if (exnhandler) {
    exnno=no;
  } else {
    if (no >= 100) {
      fprintf(stderr,"FIACRE error at line %d: %s\n",no/100,exnMessages[no%100]); fflush(stderr);
    } else {
      fprintf(stderr,"FIACRE error: %s\n",exnMessages[no]); fflush(stderr);
    }
    exit(1);
  }
}

#define RAISE(no) {Raise(no); goto error;}
#define CALLFUN(ty,e) ({ty r = e; if (exnno) goto error; r;}) 

/* for interval arithmetics */

#define IMINUS(x,l,h)  ({int r= -x; if (r<l || r>h) {RAISE(1);} r;})
#define ICOERCE(x,l,h) ({int r=x; if (r<l || r>h) {RAISE(2);} r;})
#define IADD(x,y,l,h)  ({int r=x + y; if (r<l || r>h) {RAISE(3);} r;})


/* I leave it here so we have ane example on how to change the macro to identify where the pb is
   comming from. FFI 11-Dec-2018 */
/* #define IADD(x,y,l,h)  ({int r=x + y;\ */
/* if (r<l || r>h) {\ */
/*   printf("Line %d in file %s\nx = %d, y = %d, l = %d, h = %d\n", __LINE__, __FILE__,x,y,l,h); \ */
/*   RAISE(3);} r;}) */

#define ISUB(x,y,l,h)  ({int r=x - y; if (r<l || r>h) {RAISE(4);} r;})
#define IMUL(x,y,l,h)  ({int r=x * y; if (r<l || r>h) {RAISE(5);} r;})
#define IDIV(x,y,l,h)  ({int r=x / y; if (r<l || r>h) {RAISE(6);} r;})
#define IMOD(x,y,l,h)  ({int r=x % y; if (r<l || r>h) {RAISE(7);} r;})

/* for natural integer arithmetics */

#define NMINUS(x)  ({int r= -x; if (r<0) {RAISE(8);} r;})
#define NCOERCE(x) ({int r=x; if (r<0) {RAISE(9);} r;})
#define NADD(x,y)  ({int r=x + y; if (r<0) {RAISE(10);} r;})
#define NSUB(x,y)  ({int r=x - y; if (r<0) {RAISE(11);} r;})
#define NMUL(x,y)  ({int r=x * y; if (r<0) {RAISE(12);} r;})
#define NDIV(x,y)  ({int r=x / y; if (r<0) {RAISE(13);} r;})
#define NMOD(x,y)  ({int r=x % y; if (r<0) {RAISE(14);} r;})

/* for queues */

#define EMPTY(q)          ((q).len==0)
#define FULL(q,n)         ((q).len==(n))
#define FIRST(q)          ({if (EMPTY(q)) {RAISE(15);} (q).at[0];})
#define LENGTH(q)         ((q).len)
/* beware: must work even if r=q */
#define ENQUEUE(r,q,e,sz) {int i; \
                           if (FULL(q,sz)) {RAISE(16);};					\
			   for (i=0; i<(q).len; i++) {(r).at[i]=(q).at[i];}; \
			   (r).at[i]=(e); \
                           (r).len = (q).len + 1;}
#define APPEND(r,q,e,sz)  {int i;		      \
                           if (FULL(q,sz)) {RAISE(17);};					\
			   for (i=(q).len; i>0; i--) {(r).at[i]=(q).at[i-1];}; \
			   (r).at[i]=(e); \
			   (r).len = (q).len + 1;}
#define DEQUEUE(r,q)      {int i; \
                           if (EMPTY(q)) {RAISE(18);};		  \
			   (r).len = (q).len - 1; \
			   for (i=0; i<(r).len; i++) {(r).at[i]=(q).at[i+1];}}

/* for other dymanic errors */

// match error in a fiacre function
#define MATCHERROR(line) {RAISE(100*line+19);}

// assertion violation
#define FCR_ASSERT(line) ({RAISE(100*line+20); 0;})

#endif
