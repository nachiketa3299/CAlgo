#include "merge_sort.h"

#include <stdlib.h>
#include <string.h>

void
_merge_sort_int(
  int *first, int *last,
  Pred_int pred,
  int *buff
);

void
_merge_int(
  int *first1, int *last1,
  int *first2, int *last2,
  Pred_int pred,
  int *buff
);

void
merge_sort_int(
  int *first, int *last,
  Pred_int pred
) {
  size_t const len = last - first;
  int *buff = (int *)malloc(len * sizeof(int));

  //

  free(buff);
}

void
_merge_sort_int(
  int *first, int *last,
  Pred_int pred,
  int *buff
) {
  if (first < last - 1) {
    size_t const len = last - first;
    int *mid = first + len / 2;

    _merge_sort_int(first, mid, pred, buff);
    _merge_sort_int(mid, last, pred, buff);

    _merge_int(first, mid, mid, last, pred, buff);
  }
}

void 
_merge_int(
  int *first1, int *last1,
  int *first2, int *last2,
  Pred_int pred,
  int *buff
) {
  size_t const len1 = last1 - first1;
  size_t const len2 = last2 - first2;

  int *bfirst1 = buff, *blast1 = bfirst1 + len1;
  int *bfirst2 = blast1, *blast2 = bfirst2 + len2;

  memcpy(bfirst1, first1, len1 * sizeof(int));
  memcpy(bfirst2, first2, len2 * sizeof(int));

  int *first = first1;

  while (bfirst1 < blast1 && bfirst2 < blast2) {
    if (pred(*bfirst1, *bfirst2)) {
      *first = *bfirst1;
      ++bfirst1;
    } else {
      *first = *bfirst2;
      ++bfirst2;
    }

    ++first;
  }

  size_t const remain_len1 = blast1 - bfirst1;

  if (remain_len1 > 0) {
    memcpy(first, bfirst1, remain_len1 * sizeof(int));
    first += remain_len1;
  }

  size_t const remain_len2 = blast2 - bfirst2;

  if (remain_len2 > 0) {
    memcpy(first, bfirst2, remain_len2 * sizeof(int));
    first += remain_len2;
  }
}