#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/sort.h"
#include "./include/predicates.h"
#include "./include/print.h"

#include "./include/bubble_sort.h"
#include "./include/insertion_sort.h"
#include "./include/selection_sort.h"
#include "./include/merge_sort.h"

struct TestCase {
	SortAlgo_int sort_algo;
	char* case_name;
};

struct Pred_int_wrapper {
	Pred_int pred;
	char* pred_name;
};

struct TestCase tcs[] = {
	(struct TestCase) { .sort_algo = bubble_sort_int, .case_name = "Bubble" },
	(struct TestCase) { .sort_algo = insertion_sort_int, .case_name = "Insertion" },
	(struct TestCase) { .sort_algo = selection_sort_int, .case_name = "Selection" },
	(struct TestCase) { .sort_algo = merge_sort_int, .case_name = "Merge"}
};

struct Pred_int_wrapper preds[] = {
	(struct Pred_int_wrapper) { .pred = pred_greater_int, .pred_name = "Greater" },
	(struct Pred_int_wrapper) { .pred = pred_less_int, .pred_name = "Less" },
};

int const o_arr_int[] = { 10, 222, 3, 152, -33, 9238, 221454, 223};
size_t const o_arr_length = sizeof(o_arr_int) / sizeof(o_arr_int[0]);

int main() {
	Pred_int pred = pred_greater_int;

	for (size_t i = 0; i < sizeof(tcs) / sizeof(tcs[0]); ++i) {

		printf("> Before [%s] Sort:\n\t", tcs[i].case_name);
		print_arr_int(o_arr_int, o_arr_length);
		printf("\n");

		for (size_t j = 0; j < sizeof(preds) / sizeof(preds[0]); ++j) {
			int c_arr_int[o_arr_length];
			memcpy(c_arr_int, o_arr_int, o_arr_length * sizeof(int));

			sort(tcs[i].sort_algo, c_arr_int, o_arr_length, preds[j].pred);

			printf("> After [%s] Sort(%s):\n\t", tcs[i].case_name, preds[j].pred_name);
			print_arr_int(c_arr_int, o_arr_length);

			printf("\n");
		}

		printf("\n");
	}

	return 0;
}
