#ifndef _CALGO_BINARY_SEARCH_H
#define _CALGO_BINARY_SEARCH_H

#include <stddef.h>
#include <stdbool.h>

#include "predicates.h"

bool 
bin_search_int(
  int const *first, int const *last, 
  int target,
  Pred_int pred
);

/*!
 *@brief Searches for the first element in partitioned range `[first, last)` which is not ordered before `value`
 */
int const
*bin_lbound_int(
  int const *first, int const *last, 
  int target,
  Pred_int pred
);

int const
*bin_ubound_int(
  int const *first, int const *last, 
  int target,
  Pred_int pred
);

void 
bin_erange_int(
  int const *first, int const *last, 
  int const **out_lower, int const **out_upper, 
  int target,
  Pred_int pred
);

#endif

