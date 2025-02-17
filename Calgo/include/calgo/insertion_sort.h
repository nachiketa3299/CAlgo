#ifndef _CALGO_INSERTION_SORT_H
#define _CALGO_INSERTION_SORT_H

#include <stddef.h>

#include "predicates.h"

/*!
 * @param pred predicate that satisfies strict weak ordering.
 */
void
insertion_sort_int(
  int *first, int *last,
  Pred_int pred
);

#endif