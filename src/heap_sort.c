#include "../include/heap_sort.h"
#include "../include/heap.h"
#include "../include/swap.h"

void heap_sort_int(int* cont, size_t length, Pred_int pred) {
  make_heap_int(cont, length, pred);

  for (size_t i = length - 1; i > 0; --i) {
    swap_int(&cont[0], &cont[i]);
    bubble_down_int(cont, i, pred, 0);
  }
}