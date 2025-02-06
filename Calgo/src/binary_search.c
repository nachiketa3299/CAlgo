#include "binary_search.h"

bool 
binary_search_int(
  int const* first, int const* last, 
  int target,
  Pred_int pred
) {
  while (first < last) {
    int const* mid = first + (last - first) / 2;

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

int const* 
lower_bound_int(
  int const* first, int const* last, 
  int target,
  Pred_int pred
) {
  while (first < last) {
    int const* mid = first + (last - first) / 2;
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

int const* 
upper_bound_int(
  int const* first, int const* last, 
  int target,
  Pred_int pred
) {
  while (first < last) {
    int const* mid = first + (last - first) / 2;
    if (pred(target, *mid)) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }

  return first;
}

void 
equal_range_int(
  int const* first, int const* last, 
  int const** out_lower, int const** out_upper, 
  int target,
  Pred_int pred
) {

  *out_lower = lower_bound_int(first, last, target, pred);
  *out_upper = upper_bound_int(first, last, target, pred);
}