#include <stdio.h>
#include <stdlib.h>

#include "print.h"

void print_arr_int(int const* cont, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    printf("%d ", cont[i]);
  }
}

void print_arr_with_idx_int(int const* cont, size_t length) {
  for (int i = 0; i < length; ++i) {
    printf("(%d)%d ", i, cont[i]);
  }
}

void 
print_arr_mark_range_int(
  int const* cont, size_t length, 
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

	int const* end = cont + length;

	size_t r_idx = 0;

	while (cont < end) {
		if (r_idx % 2 == 0 && args[r_idx] == cont) {
			printf("[ ");
			++r_idx;
		}

		printf("%d", *cont);

		if (r_idx % 2 != 0 && args[r_idx] == cont) {
			printf(" )");
			++r_idx;
		}

    printf(" ");
		++cont;
	}

	if (r_idx % 2 == 0 && args[r_idx] == cont) {
		printf("[");
		++r_idx;
	}

	if (r_idx % 2 != 0 && args[r_idx] == cont) {
		printf(")");
		++r_idx;
	}


	free(args);
}