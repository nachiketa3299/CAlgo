#include <stdio.h>

#include "../include/print.h"

void print_arr_int(int const* container, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		printf("%d ", container[i]);
	}
}