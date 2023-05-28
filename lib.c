#include "lib.h"

struct largeTy* foo_ret(struct largeTy *x)
{
  return x;
}

int foo_safe(struct largeTy *x)
{
  return x->v.e + x->v.a;
}

int foo_may_unsafe(struct largeTy *x, int i)
{
  return x->pad[i];
}

int foo_safe_ind(struct largeTy **v)
{
  struct largeTy *x = v[0];
  return x->v.e + x->v.a;
}

int foo_may_unsafe_ind(struct largeTy **v, int i)
{
  struct largeTy *x = v[0];
  return x->pad[i];
}
