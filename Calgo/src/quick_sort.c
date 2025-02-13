#include "quick_sort.h"
#include "swap.h"

void
quick_sort_int(
  int *first, int *last,
  Pred_int pred
) {
  if (first >= last) {
    return;
  }

  int *pivot = first;
  int *fip = first + 1, *lip = last - 1;

  while (fip <= lip) {
    while (fip   < last && pred(*fip, *pivot)) ++fip;
    while (first < lip  && pred(*pivot, *lip)) --lip;
    if    (fip   < lip) swap_int(fip++, lip--);
  }

  // now, pivot is in proper place
  swap_int(pivot, lip);

  quick_sort_int(first, lip, pred);
  quick_sort_int(lip + 1,   last,    pred);
}