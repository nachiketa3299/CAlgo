#include "search.h"

bool 
search_int(
  SearchFunc_int func,
  int const *first, int const *last,
  int target,
  Pred_int pred
) {
  return func(first, last, target, pred);
}

int const
*lbound_int(
  SearchBoundFunc_int func,
  int const *first, int const *last,
  int target,
  Pred_int pred
) {
  return func(first, last, target, pred);
}

int const
*ubound_int(
  SearchBoundFunc_int func,
  int const *first, int const *last,
  int target,
  Pred_int pred
) {
  return func(first, last, target, pred);
}

void
erange_int(
  SearchEqualRangeFunc_int func,
  int const *first, int const* last,
  int const **out_lower, int const **out_upper,
  int target,
  Pred_int pred
) {
  func(first, last, out_lower, out_upper, target, pred);
}
