#ifndef _CALGO_HEAP_SORT_H
#define _CALGO_HEAP_SORT_H

#include <stddef.h>

#include "predicates.h"

/*!
 * @param inverted_pred predicate that satisfies strict weak ordering.
 * @warning
 * Unlike other sorting functions, heap_sort expects opposite predicates.
 * 
 * Example:
 * 
 * For descending order: pass a "greater than" comparison. (a > b)
 * For ascending order: pass a "less than" comparison. (a < b)
 */
void heap_sort_int(int* cont, size_t length, Pred_int inverted_pred);

#endif