#include <stddef.h>

#include "selection_sort.h"
#include "swap.h"

void selection_sort_int(int* cont, size_t length, Pred_int pred) {
  for (size_t anch = 0; anch < length; ++anch) {
    size_t prop = anch;
    for (size_t cur = anch + 1; cur < length; ++cur) {
      if (pred(cont[cur], cont[prop])) {
        prop = cur;
      }
    }
    swap_int(&cont[anch], &cont[prop]);
  }
}