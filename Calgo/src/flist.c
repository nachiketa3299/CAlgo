#include <stdlib.h>
#include <stddef.h>

#include "flist.h"

struct nd2_int {
  int val;
  struct nd2_int* next;
  struct nd2_int* prev;
};

struct nd2_int*
insert_after_int(
  struct nd2_int* piv,
  struct nd2_int* in
) {
  struct nd2_int* prev_next = piv->next;

  piv->next = in;

  in->prev = piv;
  in->next = prev_next;

  if (prev_next != NULL) {
    prev_next->prev = in;
  }

  return in;
}

struct nd2_int*
emplace_after_int(
  struct nd2_int* piv,
  int val
) {
  struct nd2_int* in = 
    (struct nd2_int*)malloc(sizeof(struct nd2_int));

  return insert_after_int(piv, in);
}

struct nd2_int*
erase_after_int(
  struct nd2_int* piv
) {
  if (piv->next == NULL) {
    return piv->next;
  }

  struct nd2_int* target = piv->next;
  struct nd2_int* nnext = target->next;

  piv->next = nnext;

  if (nnext != NULL) {
    nnext->prev = piv;
  }

  // target to erase is now isolated

  free(target);

  return piv->next;
}

void 
push_front_int(
  struct nd2_int** fl,
  int val
) {
  struct nd2_int* in = 
    (struct nd2_int*)malloc(sizeof(struct nd2_int));
  
  in->val = val;
  in->next = *fl;
  *fl = in;
}