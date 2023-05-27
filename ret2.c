#include <stdio.h>
#include <stdlib.h>

struct node {
  int field_i;
};

int __attribute__((noinline)) *bar(int *arr, int i, int **var, struct node *n)
{
  return &arr[i];
}

void __attribute__((noinline)) foo(int i, int **var)
{
  int *x = (int*)malloc(10 * sizeof(int));
  struct node n;
  int *newarr;
  *var = &x[6];
  newarr = bar(&x[5], i, var, &n);
  newarr[0] = 40;
}

int main(int argc, const char *argv[])
{
  if (argc != 2) {
    printf("Usage:: <int>\n");
    return 0;
  }
  int i = atoi(argv[1]);
  int **var = malloc(sizeof(int*));
  foo(i, var);
  return 0;
}
