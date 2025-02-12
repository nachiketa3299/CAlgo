#include "heap_sort.h"

#include "heap.h"
#include "swap.h"

void 
heap_sort_int(
  int *first, int *last, 
  Pred_int inverted_pred
) {
  make_heap_int(first, last, inverted_pred);
  size_t const len = last - first;

  for (int *cur = last - 1; cur > first; --cur) {
    swap_int(first, cur);
    bubble_down_int(first, cur, inverted_pred, 0);
  }
}