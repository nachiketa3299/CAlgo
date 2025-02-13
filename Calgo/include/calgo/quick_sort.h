#ifndef _CALGO_QUICK_SORT_H
#define _CALGO_QUICK_SORT_H

#include <stddef.h>

#include "predicates.h"

void
quick_sort_int(
  int *first, int *last,
  Pred_int pred
);

#endif