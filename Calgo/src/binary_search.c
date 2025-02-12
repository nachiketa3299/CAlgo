#include "binary_search.h"

bool 
bin_search_int(
  int const *first, int const *last, 
  int target,
  Pred_int pred
) {
  while (first < last) {
    int const *mid = first + (last - first) / 2;

    if (!pred(target, *mid) && !pred(*mid, target)) {
      return true;
    }

    if (pred(*mid, target)) {
      first = mid + 1;
    } else {
      last = mid;
    }
  }

  return false;
}

int const
*bin_lbound_int(
  int const *first, int const *last, 
  int target,
  Pred_int pred
) {
  while (first < last) {
    int const *mid = first + (last - first) / 2;
    // range of left subarray: [first, mid + 1)
    // range of right subarray: [mid + 1, last)

    if (pred(*mid, target)) { // if target is always greater than left subarray
      // right subarray is more proper
      first = mid + 1;
    } else {
      // left subarray is more proper
      last = mid;
    }
  }

  return first;
}

int const
*bin_ubound_int(
  int const *first, int const *last, 
  int target,
  Pred_int pred
) {
  while (first < last) {
    int const *mid = first + (last - first) / 2;
    if (pred(target, *mid)) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }

  return first;
}

void 
bin_erange_int(
  int const *first, int const *last, 
  int const **out_lower, int const **out_upper, 
  int target,
  Pred_int pred
) {

  *out_lower = bin_lbound_int(first, last, target, pred);
  *out_upper = bin_ubound_int(first, last, target, pred);
}