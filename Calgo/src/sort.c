#include "sort.h"

void 
sort(
  SortFunc_int sort_algo, 
  int *first, int *last, 
  Pred_int pred
) {
  sort_algo(first, last, pred);
}