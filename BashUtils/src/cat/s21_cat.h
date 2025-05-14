#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flag {
  int error;
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags;

int ParceFlags(int argc, char *argv[], flags *flag);
void FlagsProcess(char *argv[], flags *flag);

#endif
