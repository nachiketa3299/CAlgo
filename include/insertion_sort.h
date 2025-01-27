/// @date 2025-01-26

#ifndef _CALGO_INSERTION_SORT_H
#define _CALGO_INSERTION_SORT_H

#include <stddef.h>
#include <stdbool.h>

#include "./swap.h"

void insertion_sort_int(int* cont, size_t length, bool (*pred)(int, int));

#endif