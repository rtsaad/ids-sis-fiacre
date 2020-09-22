
#ifndef _APP_FUNCTIONS_
#define _APP_FUNCTIONS_
/* fiacre headers */
void initial();

struct a0 {
  int at[29];
};

struct a1 {
  bool at[4];
};

struct a2 {
  int at[7];
};

struct a3 {
  bool at[7];
};

struct a4 {
  int at[5];
};

struct a5 {
  bool at[5];
};

struct a6 {
  int at[10];
};

struct a7 {
  bool at[10];
};

struct a8 {
  int at[4];
};

struct a0 f_read();

int f_write(struct a1);

int f_print_b(bool);

int f_print_n(int);

// fiacre type bindings
typedef struct a0 INPUT_c;
typedef struct a1 OUTPUT_c;

#endif