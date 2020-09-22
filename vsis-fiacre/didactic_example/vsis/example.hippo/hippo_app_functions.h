
#ifndef _APP_FUNCTIONS_
#define _APP_FUNCTIONS_
/* fiacre headers */
void initial();

struct a0 {
  bool at[8];
};

struct a1 {
  bool at[4];
};

struct a0 f_read();

int f_write(struct a1);

// fiacre type bindings
typedef struct a0 INPUT_c;
typedef struct a1 OUTPUT_c;

#endif