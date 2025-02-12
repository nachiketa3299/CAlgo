#ifndef _CALGO_SELECTION_SORT_H
#define _CALGO_SELECTION_SORT_H

#include <stddef.h>
#include <stdbool.h>

#include "predicates.h"

/*!
 * @param pred predicate that satisfies strict weak ordering.
 */
void 
selection_sort_int(
  int *first, int *last,
  Pred_int pred
);

#endif