#include "heap.h"

#include <string.h>
#include <stdlib.h>

#include "predicates.h"
#include "swap.h"

void
bubble_down_int(
  int *first, int *last,
  Pred_int pred,
  size_t c_parent
) {
  size_t const l_c = 2 * c_parent + 1;
  size_t const r_c = 2 * c_parent + 2;
  size_t const len = last - first;

  // initially assume that current parent is already in a proper position
  size_t proper = c_parent;

  // check if left child exists & is more proper than current proper node
  if (l_c < len && pred(first[l_c], first[proper])) {
    proper = l_c;
  }

  // check if right child exists & is more proper than current proper node
  if (r_c < len && pred(first[r_c], first[proper])) {
    proper = r_c;
  }

  // if initial assumption was wrong, swap nodes and recurse
  if (proper != c_parent) {
    swap_int(first + c_parent, first + proper);
    bubble_down_int(first, last, pred, proper);
  }
}

void 
bubble_up_int(
  int *first, int *last,
  Pred_int pred,
  size_t c_child
) {
  // reaching root node is base case of recursion
  if (c_child == 0) {
    return;
  }

  size_t const parent = (c_child - 1) / 2;

  // if child is more proper, swap and recurse
  if (pred(first[c_child], first[parent])) {
    swap_int(first + c_child, first + parent);
    bubble_up_int(first, last, pred, parent);
  }
}

void 
make_heap_int(
  int *first, int *last,
  Pred_int pred
) {
  size_t const len = last - first;
  size_t const l_parent = (len - 2) / 2; // last parent node's index

  // TODO: maybe `size_t` as a counting variable is not good...
  for (size_t cur = l_parent; cur != (size_t) - 1; --cur) {
    bubble_down_int(first, last, pred, cur);
  }
}

void
push_heap_int(
  int *first, int *last,
  Pred_int pred
) {
  bubble_up_int(first, last, pred, last - first - 1);
}

void 
pop_heap_int(
  int *first, int *last,
  Pred_int pred
) {
  bubble_down_int(first, last, pred, 0);
}