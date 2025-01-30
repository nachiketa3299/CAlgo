#include "../include/bubble_sort.h"
#include "../include/swap.h"

void bubble_sort_int(int* cont, size_t length, Pred_int pred) {
	for (size_t pass = 0; pass < length - 1; ++pass) {
		bool has_swapped = false;

		for (size_t cur = 0; cur < length - pass - 1; ++cur) {
			if (pred(cont[cur], cont[cur + 1])) {
				swap_int(&cont[cur], &cont[cur + 1]);
				has_swapped = true;
			}
		}

		if (!has_swapped) {
			break;
		}
	}
}
