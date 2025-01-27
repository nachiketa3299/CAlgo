/// @date 2025-01-26

#ifndef _CALGO_BUBBLE_SORT_H
#define _CALGO_BUBBLE_SORT_H

#include <stddef.h>
#include <stdbool.h>

#include "./swap.h"
#include "./print.h"

void bubble_sort_int(int* container, size_t length, bool (*pred)(int, int));

#endif