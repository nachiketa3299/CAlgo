#ifndef _CALGO_SELECTION_SORT_H
#define _CALGO_SELECTION_SORT_H

#include <stddef.h>
#include <stdbool.h>

#include "./predicates.h"

void selection_sort_int(int* cont, size_t length, Pred_int pred);

#endif