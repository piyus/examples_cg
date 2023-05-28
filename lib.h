#ifndef _LIB_H_
#define _LIB_H_

struct smallTy {
  int a, b, c, d, e, f;
};

struct largeTy {
  struct smallTy v;
  char g;
  char pad[7];
};

struct largeTy* foo_ret(struct largeTy *x);
int foo_safe(struct largeTy *x);
int foo_unsafe(struct largeTy *x);
int foo_may_unsafe(struct largeTy *x, int i);
int foo_safe_ind(struct largeTy **v);
int foo_may_unsafe_ind(struct largeTy **v, int i);

#endif
