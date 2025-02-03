#ifndef _CALGO_SORT_H
#define _CALGO_SORT_H

#include <stddef.h>
#include <stdbool.h>

#include "predicates.h"

typedef void (*SortAlgo_int)(int*, size_t, Pred_int);

/*!
 * @brief Wrapper function for general sorting
 * @param pred predicate that satisfies strict weak ordering.
 */
void sort(SortAlgo_int sort_algo, int* cont, size_t length, Pred_int pred);

#endif