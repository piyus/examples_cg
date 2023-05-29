#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, const char *argv[])
{
  struct smallTy v;
  return foo_unsafe((struct largeTy*)&v);
}
