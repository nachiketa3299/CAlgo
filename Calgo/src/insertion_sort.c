#include <stddef.h>
#include <stdbool.h>

#include "insertion_sort.h"
#include "predicates.h"
#include "swap.h"

void insertion_sort_int(int* cont, size_t length, Pred_int pred) {
  for (size_t sorted = 0; sorted < length - 1; ++sorted) {
    size_t to_insert = sorted + 1;

    while (to_insert > 0 && pred(cont[to_insert], cont[to_insert - 1])) {
      swap_int(&cont[to_insert], &cont[to_insert - 1]);
      --to_insert;
    }
  }
}