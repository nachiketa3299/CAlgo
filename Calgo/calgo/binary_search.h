#ifndef _CALGO_BINARY_SEARCH
#define _CALGO_BINARY_SEARCH

#include <stddef.h>
#include <stdbool.h>

#include "predicates.h"

bool 
binary_search_int(
  int const* first, int const* last, 
  int target,
  Pred_int pred
);

/*!
 * @brief Searches for the first element in partitioned range `[first, last)` which is not ordered before `value`
*/
int const* 
lower_bound_int(
  int const* first, int const* last, 
  int target,
  Pred_int pred
);

int const* 
upper_bound_int(
  int const* first, int const* last, 
  int target,
  Pred_int pred
);

void 
equal_range_int(
  int const* first, int const* last, 
  int const** out_lower, int const** out_upper, 
  int target,
  Pred_int pred
);

#endif

