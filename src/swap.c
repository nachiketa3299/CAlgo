#include "../include/swap.h"

void swap_int(int* a, int* b) {
  int temp = *a;

  *a = *b;
  *b = temp;
}