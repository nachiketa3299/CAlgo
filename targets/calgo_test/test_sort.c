#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calgo/sort.h"
#include "calgo/predicates.h"
#include "calgo/print.h"

#include "calgo/bubble_sort.h"
#include "calgo/insertion_sort.h"
#include "calgo/selection_sort.h"
#include "calgo/merge_sort.h"
#include "calgo/heap_sort.h"

struct TestCase {
  SortAlgo_int sort_algo;
  char* case_name;
};

struct Pred_int_wrapper {
  Pred_int pred;
  char* name;
};

struct TestCase tcs[] = {
  (struct TestCase) { .sort_algo = bubble_sort_int, .case_name = "Bubble" },
  (struct TestCase) { .sort_algo = insertion_sort_int, .case_name = "Insertion" },
  (struct TestCase) { .sort_algo = selection_sort_int, .case_name = "Selection" },
  (struct TestCase) { .sort_algo = merge_sort_int, .case_name = "Merge"},
  (struct TestCase) { .sort_algo = heap_sort_int, .case_name = "Heap" }
};

/// @brief wrapper for strict weak ordering preds
struct Pred_int_wrapper swo_preds[] = {
  (struct Pred_int_wrapper) { .pred = greater_int, .name = "Greater" },
  (struct Pred_int_wrapper) { .pred = less_int, .name = "Less" },
};

/// @brief main testing array
int const O_ARR_INT[] = { 10, 222, 3, 152, -33, 222, 9238, 221454, -33, 223};
size_t const O_ARR_LENGTH = sizeof(O_ARR_INT) / sizeof(O_ARR_INT[0]);

int main() {
    for (size_t i = 0; i < sizeof(tcs) / sizeof(tcs[0]); ++i) {

      printf("> Before [%s] Sort:\n\t", tcs[i].case_name);
      print_arr_int(O_ARR_INT, O_ARR_LENGTH);
      printf("\n");

      for (size_t j = 0; j < sizeof(swo_preds) / sizeof(swo_preds[0]); ++j) {
        int c_arr_int[O_ARR_LENGTH];
        memcpy(c_arr_int, O_ARR_INT, O_ARR_LENGTH * sizeof(int));

        sort(tcs[i].sort_algo, c_arr_int, O_ARR_LENGTH, swo_preds[j].pred);

        printf("> After [%s] Sort(%s):\n\t", tcs[i].case_name, swo_preds[j].name);
        print_arr_int(c_arr_int, O_ARR_LENGTH);

        printf("\n");
      }

      printf("\n");
    }

  return 0;
}
