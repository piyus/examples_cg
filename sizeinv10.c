#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, const char *argv[])
{
  struct smallTy *v = (struct smallTy*)malloc(sizeof(struct smallTy));
  return foo_unsafe((struct largeTy*)v);
}
