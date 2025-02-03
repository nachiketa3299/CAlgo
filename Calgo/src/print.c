#include <stdio.h>

#include "print.h"

void print_arr_int(int const* cont, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    printf("%d ", cont[i]);
  }
}