#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#include "../include/predicates.h"
#include "../include/swap.h"

void bubble_down_int(int* cont, size_t length, Pred_int pred, size_t c_parent) {
  size_t l_c = 2 * c_parent + 1;
  size_t r_c = 2 * c_parent + 2;

  // initially assume that current parent is already in proper position
  size_t proper = c_parent; 

  // check if left child exists & is more proper than current proper node
  if (l_c < length && pred(cont[l_c], cont[proper])) {
    proper = l_c;
  }

  // check if right child exists & is more proper than current proper node
  if (r_c < length && pred(cont[r_c], cont[proper])) {
    proper = r_c;
  }

  // if initial assumption was wrong, swap nodes and recursively bubble down
  if (proper != c_parent) {
    swap_int(&cont[c_parent], &cont[proper]);
    bubble_down_int(cont, length, pred, proper);
  }
}

void bubble_up_int(int* cont, size_t length, Pred_int pred, size_t c_child) {
  if (c_child == 0) {
    return;
  }

  size_t parent = (c_child - 1) / 2;

  // if child is more proper, swap needed
  if (pred(cont[c_child], cont[parent])) {
    swap_int(&cont[parent], &cont[c_child]);
    bubble_up_int(cont, length, pred, parent);
  }
}

void make_heap_int(int* cont, size_t length, Pred_int pred) {
  if (length < 2) {
    return;
  }

  size_t last_parent_index = (length - 2) / 2;

  for (size_t current = last_parent_index; current != (size_t) - 1; --current) {
    bubble_down_int(cont, length, pred, current);
  }
}

void push_heap_int(int* cont, size_t length, Pred_int pred) {
  bubble_up_int(cont, length, pred, length - 1);
}

void pop_heap_int(int* cont, size_t length, Pred_int pred) {
  bubble_down_int(cont, length, pred, 0);
}