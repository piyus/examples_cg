#include <stdio.h>
#include <stdlib.h>

struct smallTy {
  int a, b, c, d, e;
};

struct largeTy {
  struct smallTy v;
  char pad[8];
};

int __attribute__((noinline)) foo(struct largeTy *x)
{
  return (int)x->pad[0];
}

int main(int argc, const char *argv[])
{
  struct smallTy v;
  return foo((struct largeTy*)&v);
}
