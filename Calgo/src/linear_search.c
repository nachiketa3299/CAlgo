#include "linear_search.h"

bool 
lin_search_int(
  int const *first, int const *last,
  int target,
  Pred_int pred
) {
  while (first < last) {
    if (!pred(target, *first) && !pred(*first, target)) {
      return true;
    }
    ++first;
  }

  return false;
}

int const 
*lin_lbound_int(
  int const *first, int const *last,
  int target,
  Pred_int pred
) {
  while (first < last) {
    if (!pred(*first, target)) { // first element not satisfying pred
      return first;
    }

    ++first;
  }

  return first;
}

int const 
*lin_ubound_int(
  int const *first, int const *last,
  int target,
  Pred_int pred
) {
  while (first < last) {
    if (pred(target, *first)) { // 
      return first;
    }

    ++first;
  }
  return first;
}

void
lin_erange_int(
  int const *first, int const *last,
  int const **out_lower, int const **out_upper,
  int target,
  Pred_int pred
) {
  *out_lower = lin_lbound_int(first, last, target, pred);
  *out_upper = lin_ubound_int(first, last, target, pred);
}