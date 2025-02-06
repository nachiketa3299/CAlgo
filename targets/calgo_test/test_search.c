#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calgo/print.h"
#include "calgo/merge_sort.h"
#include "calgo/predicates.h"

#include "calgo/binary_search.h"

struct Pred_int_wrapper {
  Pred_int pred;
  char* name;
};

struct Pred_int_wrapper swo_preds[] = {
  (struct Pred_int_wrapper) { .pred = greater_int, .name = "Greater" },
  (struct Pred_int_wrapper) { .pred = less_int, .name = "Less"}
};

/// @brief main testing array
int O_ARR_INT[] = { 0, 10, 20, 30, 40, 50, 50, 50, 60, 60, 60, 70, 70 };
size_t const O_ARR_LENGTH = sizeof(O_ARR_INT) / sizeof(O_ARR_INT[0]);

int const TARGETS[] = { 10, 25, 30, 50, 65, 70, 1000, -1000 };
size_t const TARGETS_LENGTH = sizeof(TARGETS) / sizeof(TARGETS[0]);

int main() {

  for (int pc = 0; pc < sizeof(swo_preds) / sizeof(swo_preds[0]); ++pc) {
    int* c_arr_int = (int*)malloc(O_ARR_LENGTH * sizeof(int));
    memcpy(c_arr_int, O_ARR_INT, O_ARR_LENGTH * sizeof(int));

    merge_sort_int(c_arr_int, O_ARR_LENGTH, swo_preds[pc].pred);

    int const* begin = c_arr_int;
    int const* end = c_arr_int + O_ARR_LENGTH;

    for (int tc = 0; tc < TARGETS_LENGTH; ++tc) {
      printf(">> Testing Binary Search (tc: %d, pred: %s):\n", tc, swo_preds[pc].name);

      int const target = TARGETS[tc];
      int const* l_ptr, *u_ptr;

      equal_range_int(begin, end, &l_ptr, &u_ptr, target, swo_preds[pc].pred);

      if (binary_search_int(begin, end, target, swo_preds[pc].pred)) {
        printf("\t> Target [%d] is in array.\n", target);
      } else {
        printf("\t> Target [%d] is not in array.\n", target);
      }

      int const l_idx = l_ptr - begin;
      int const u_idx = u_ptr - begin;

      printf("\t> [l_idx, u_idx): [%d, %d)\n", l_idx, u_idx);

      printf("\t> result: ");

      print_arr_mark_range_int(c_arr_int, O_ARR_LENGTH, 1, l_ptr, u_ptr);

      printf("\n\n");
    }
  }

  return 0;
}
