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
  return x->pad[0];
}

int main(int argc, const char *argv[])
{
  struct smallTy *v = (struct smallTy*)malloc(sizeof(struct smallTy));
  return foo((struct largeTy*)v);
}
