#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, const char *argv[])
{
  if (argc != 2) {
    printf("Usage:: <int>\n");
    return 0;
  }
  int i = atoi(argv[1]);
  struct smallTy v;
  struct largeTy *t = foo_ret((struct largeTy*)&v);
  return t->pad[i];
}
