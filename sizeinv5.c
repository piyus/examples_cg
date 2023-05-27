#include <stdio.h>
#include <stdlib.h>

struct smallTy {
  int a, b, c, d, e;
};

struct largeTy {
  struct smallTy v;
  char pad[8];
};

int __attribute__((noinline)) foo(struct largeTy *x, int i)
{
  return x->pad[i];
}

int main(int argc, const char *argv[])
{
  if (argc != 2) {
    printf("Usage:: <int>\n");
    return 0;
  }
  int i = atoi(argv[1]);
  struct smallTy v;
  return foo((struct largeTy*)&v, i);
}
