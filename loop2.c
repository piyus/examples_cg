#include <stdio.h>
#include <stdlib.h>

void __attribute__((noinline)) foo(int n, int *arr, int n_iter)
{
  int i, v;
  for (i = 0; i < n_iter; i++) {
    v = rand();
    if (v > 1) { // very likely
      arr[i] = v;
    }
  }
}

int main(int argc, const char *argv[])
{
  if (argc != 3) {
    printf("Usage:: <n_elem> <n_iter>\n");
    return 0;
  }
  int n = atoi(argv[1]);
  int n_iter = atoi(argv[2]);
  int *arr = malloc(sizeof(int) * n);
  foo(n, arr, n_iter);
  return 0;
}
