#include <stdio.h>
#include <stdlib.h>

#include "print.h"

void 
print_arr_int(
  int const* first, int const* last
) {

  while (first < last) {
    printf("%d ", *first);
    ++first;
  }
}

void 
print_arr_with_idx_int(
  int const* first, int const* last
) {
  int const* cur = first;

  while (first < last) {
    printf("(%d)%d ", (size_t)(cur - first), *cur);
  }
}

void 
print_arr_mark_range_int(
  int const* first, int const* last,
  size_t range_count, ...
) {

  va_list ap;

  size_t arg_len = range_count * 2;
  int const** args = (int const**)malloc(arg_len * sizeof(int const*));

  va_start(ap, range_count);
  for (int i = 0; i < arg_len; ++i) {
    args[i] = va_arg(ap, int const*);
  }
  va_end(ap);

  size_t r_idx = 0;

  while (first < last) {
    if (r_idx % 2 == 0 && args[r_idx] == first) {
      printf("[ ");
      ++r_idx;
    }

    printf("%d", *first);

    if (r_idx % 2 != 0 && args[r_idx] == first) {
      printf(" )");
      ++r_idx;
    }

    printf(" ");
    ++first;
  }

  if (r_idx % 2 == 0 && args[r_idx] == first) {
    printf("[");
    ++r_idx;
  }

  if (r_idx % 2 != 0 && args[r_idx] == first) {
    printf(")");
    ++r_idx;
  }

  free(args);
}