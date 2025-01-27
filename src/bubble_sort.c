#include "../include/bubble_sort.h"

void bubble_sort_int(int* container, size_t length, bool (*pred)(int, int)) {
	size_t outer = 0;

	while (outer < length - 1) {
		size_t inner = outer + 1;

		bool has_swapped = false;

		while (inner <  length) {
			if (pred(container[outer], container[inner])) {
				swap_int(&container[outer], &container[inner]);
				has_swapped = true;
			}

			++inner;
		}

		if (!has_swapped) {
			break;
		}

		++outer;
	}
}
