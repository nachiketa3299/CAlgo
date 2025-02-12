#ifndef _CALGO_SORT_H
#define _CALGO_SORT_H

#include <stddef.h>

#include "predicates.h"

typedef
void (*SortFunc_int)(
  int *first, int *last,
  Pred_int pred
);

/*!
 * @brief Wrapper function for general sorting
 * @param pred predicate that satisfies strict weak ordering.
 */
void 
sort(
  SortFunc_int sort_algo, 
  int *first, int *last, 
  Pred_int pred
);

#endif