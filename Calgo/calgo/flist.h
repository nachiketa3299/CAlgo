#ifndef _CALGO_FLIST_H
#define _CALGO_FLIST_H

struct nd2_int;

struct nd2_int*
insert_after_int(
  struct nd2_int* piv,
  struct nd2_int* in
);

struct nd2_int*
emplace_after_int(
  struct nd2_int* piv,
  int val
);

struct nd2_int*
erase_after_int(
  struct nd2_int* piv
);

void 
push_front_int(
  struct nd2_int** fl,
  int val
);

#endif