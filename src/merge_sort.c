#include <stdlib.h>
#include <string.h>

#include "../include/merge_sort.h"

void _merge_sort_int(int*, int*, Pred_int, size_t, size_t);
void _merge_int(int*, int*, Pred_int, size_t, size_t, size_t);

void merge_sort_int(int* cont, size_t length, Pred_int pred) {
  int* buff = (int*)malloc(sizeof(int) * length);
  _merge_sort_int(cont, buff, pred, 0, length);
  free(buff);
}

/// @param iend end of index (inclusive)
void _merge_sort_int(int* cont, int* buff, Pred_int pred, size_t begin, size_t end) {
  if (begin < end - 1) {
    size_t mid = begin + (end - begin) / 2;

    _merge_sort_int(cont, buff, pred, begin, mid);
    _merge_sort_int(cont, buff, pred, mid + 1, end);

    _merge_int(cont, buff, pred, begin, mid, end);
  }
}

// First subarray is [begin..mid]
// Second subarray is [mid+1..end]
void _merge_int(
  int* cont, int* buff, 
  Pred_int pred, 
  size_t begin, size_t mid, size_t end
  ) {

  size_t slength1 = mid - begin;
  size_t slength2 = end - mid;

  int* sarr1 = cont + begin;
  int* sarr2 = cont + mid;

  int* sbuff1 = buff;
  int* sbuff2 = buff + slength1;

  memcpy(sbuff1, sarr1, slength1 * sizeof(int));
  memcpy(sbuff2, sarr2, slength2 * sizeof(int));

  size_t sarr1_idx = 0;
  size_t sarr2_idx = 0;
  size_t cur = begin;

  while (sarr1_idx < slength1 && sarr2_idx < slength2) {
    if (!pred(sbuff1[sarr1_idx], sbuff2[sarr2_idx])) {
      cont[cur] = sbuff1[sarr1_idx];
      ++sarr1_idx;
    }
    else {
      cont[cur] = sbuff2[sarr2_idx];
      ++sarr2_idx;
    }
    ++cur;
  }

  while (sarr1_idx < slength1) {
    cont[cur++] = sbuff1[sarr1_idx++];
  }

  while (sarr2_idx < slength2) {
    cont[cur++] = sbuff2[sarr2_idx++];
  }
}