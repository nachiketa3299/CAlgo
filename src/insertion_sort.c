#include <stddef.h>
#include <stdbool.h>

#include "../include/insertion_sort.h"

void insertion_sort_int(int* cont, size_t length, bool (*pred)(int, int)) {
	for (size_t sorted = 0; sorted < length - 1; ++sorted) {
		size_t to_insert = sorted + 1;

		while (to_insert > 0 && !pred(cont[to_insert], cont[to_insert - 1])) {
			swap_int(&cont[to_insert], &cont[to_insert - 1]);
			--to_insert;
		}
	}
}