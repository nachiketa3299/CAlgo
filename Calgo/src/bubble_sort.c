#include "bubble_sort.h"

#include <stdbool.h>

#include "swap.h"

void 
bubble_sort_int(
  int *first, int *last,
  Pred_int pred
) {
    size_t const len = last - first;

    for (size_t pass = 0; pass < len; ++pass) {
      int *cur = first;
      int *clast = last - 1 - pass;

      bool swapped = false;

      while (cur < clast) {
        if (!pred(*cur, *(cur + 1))) {
          swap_int(cur, cur + 1);
          swapped = true;
        }

        ++cur;
      }

      if (!swapped) {
        break;
      }
    }
  }
