#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, const char *argv[])
{
  struct smallTy *v = (struct smallTy*)malloc(sizeof(struct smallTy));
  struct largeTy *t[1];
  t[0] = (struct largeTy*)v;
  return foo_safe_ind(t);
}
