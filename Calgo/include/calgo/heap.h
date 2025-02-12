#ifndef _CALGO_HEAP_H
#define _CALGO_HEAP_H

#include <stddef.h>

#include "predicates.h"

/*!
 * @brief Recursively bubbles down a node until it satisfies the heap property.
 * @param c_parent Index of current parent node being tested
 * @details 
 * Starting from the current parent node, this function does:
 * 1. Compares the parent with both children.
 * 2. If either child is more proper according to given predicates, 
 *    swaps with that child.
 * 3. Recursively continues this process if swap happened, with previous parent.
*/
void
bubble_down_int(
  int *first, int *last,
  Pred_int pred,
  size_t c_parent
);

/*!
 * @brief Recursively bubbles up a node until it satisfies the heap property.
 * @param c_child Indes of current child node being tested
 * @details
 * Starting from the given child node, this function does:
 * 1. Compares the child with its parent
 * 2. If current child is more proper than its parent according to given predicates, 
 *    swap happens.
 * 3. Recursively continues this process if swap happened, with previous child.
 */
void
bubble_up_int(
  int *first, int *last,
  Pred_int pred,
  size_t c_child
);

/*! 
 * @brief Convert given range of array into a heap.
 * @details
 * This is O(n), but honestly, I have no idea whats going on and even don't care.
 * If you're curious, go wrestle with some math poops on Wiki or something.
 * (I'm not getting involved.)
 */
void 
make_heap_int(
  int *first, int *last,
  Pred_int pred
);

/*!
 * @brief 
 * Insert the element at the index `length - 1` into the heap 
 * `[cont, cont + length - 1)`.  
 * The heap after insertion will be `[cont, cont + length)`
 * @param pred predicate that satisfies strict weak ordering.
 */
void
push_heap_int(
  int *first, int *last,
  Pred_int pred
);

/*!
 * @brief
 * Swaps the vale in the position `cont` and the value in the index `length - 1`
 * and makes the subrange `[cont, cont + length - 1)` into a heap.
 * This has the effect of removing the first element 
 * from the heap `[cont, cont + length)`
 * @param pred predicate that satisfies strict weak ordering.
 */
void 
pop_heap_int(
  int *first, int *last,
  Pred_int pred
);

#endif