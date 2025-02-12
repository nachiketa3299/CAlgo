#include "swap.h"

void 
swap_int(
  int *a, int *b
) {
  int const temp = *a;

  *a = *b;
  *b = temp;
}