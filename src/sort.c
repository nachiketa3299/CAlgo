#include "../include/sort.h"

void sort(SortAlgo_int sort_algo, int* cont, size_t length, Pred_int pred) {
	sort_algo(cont, length, pred);
}