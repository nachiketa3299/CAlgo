#ifndef _CALGO_MERGE_SORT_H
#define _CALGO_MERGE_SORT_H

#include <stddef.h>

#include "./predicates.h"

void merge_sort_int(int* const, size_t length, Pred_int pred);

#endif