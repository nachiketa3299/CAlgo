#include "selection_sort.h"

#include <stddef.h>

#include "swap.h"

void 
selection_sort_int(
  int *first, int *last,
  Pred_int pred
) {

  while (first < last) {

    int * prop = first;

    for (int * cur = prop + 1; cur < last; ++cur) {
      if (pred(*cur, *prop)) {
        prop = cur;
      }
    }

    swap_int(first, prop);

    ++first;
  }
}