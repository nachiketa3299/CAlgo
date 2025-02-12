#ifndef _CALGO_MERGE_SORT_H
#define _CALGO_MERGE_SORT_H

#include <stddef.h>

#include "predicates.h"

/*!
 * @param pred predicate that satisfies strict weak ordering.
 */
void
merge_sort_int(
  int *first, int *last,
  Pred_int pred
);

#endif