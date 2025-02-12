#ifndef _CALGO_SEARCH_H
#define _CALGO_SEARCH_H

#include <stdbool.h>

#include "predicates.h"

typedef 
bool 
(*SearchFunc_int)(
  int const *first, int const *last, 
  int target,
  Pred_int pred
);

typedef 
int const 
*(*SearchBoundFunc_int)(
  int const *first, int const *last,
  int target,
  Pred_int pred
);

typedef
void
(*SearchEqualRangeFunc_int)(
  int const *first, int const *last,
  int const **out_lower, int const **out_upper,
  int target,
  Pred_int pred
);

bool 
search_int(
  SearchFunc_int func,
  int const *first, int const *last,
  int target,
  Pred_int pred
);

int const
*lbound_int(
  SearchBoundFunc_int func,
  int const *first, int const *last,
  int target,
  Pred_int pred
);

int const
*ubound_int(
  SearchBoundFunc_int func,
  int const *first, int const *last,
  int target,
  Pred_int pred
);

void
erange_int(
  SearchEqualRangeFunc_int func,
  int const *first, int const* last,
  int const **out_lower, int const **out_upper,
  int target,
  Pred_int pred
);

#endif