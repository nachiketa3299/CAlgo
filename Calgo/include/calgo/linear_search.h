#ifndef _CALGO_LINEAR_SEARCH_H
#define _CALGO_LINEAR_SEARCH_H

#include <stdbool.h>

#include "predicates.h"

bool 
lin_search_int(
  int const *first, int const *last,
  int target,
  Pred_int pred
);

int const 
*lin_lbound_int(
  int const *first, int const *last,
  int target,
  Pred_int pred
);

int const 
*lin_ubound_int(
  int const *first, int const *last,
  int target,
  Pred_int pred
);

void
lin_erange_int(
  int const *first, int const *last,
  int const **out_lower, int const **out_upper,
  int target,
  Pred_int pred
);

#endif