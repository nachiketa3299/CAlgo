#include "insertion_sort.h"

#include <stddef.h>
#include <stdbool.h>

#include "predicates.h"
#include "swap.h"

void
insertion_sort_int(
  int *first, int *last,
  Pred_int pred
) {

  for (int *unsorted = first + 1; unsorted < last; ++unsorted) {

    int *cur = unsorted;

    while (cur > first && !pred(*(cur - 1), *cur)) {
      swap_int(cur - 1, cur);
      --cur;
    }
  }
}