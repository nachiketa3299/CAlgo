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
#include "./include/heap_sort.h"

#include "./include/heap.h"

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
  (struct TestCase) { .sort_algo = merge_sort_int, .case_name = "Merge"},
  (struct TestCase) { .sort_algo = heap_sort_int, .case_name = "Heap" }
};

/// @brief wrapper for strict weak ordering preds
struct Pred_int_wrapper swo_preds[] = {
  (struct Pred_int_wrapper) { .pred = greater_int, .pred_name = "Greater" },
  (struct Pred_int_wrapper) { .pred = less_int, .pred_name = "Less" },
};

/// @brief main testing array
int const O_ARR_INT[] = { 10, 222, 3, 152, -33, 222, 9238, 221454, -33, 223};
size_t const O_ARR_LENGTH = sizeof(O_ARR_INT) / sizeof(O_ARR_INT[0]);

int main() {
  { // Testing Sorting Algorithms
    for (size_t i = 0; i < sizeof(tcs) / sizeof(tcs[0]); ++i) {

      printf("> Before [%s] Sort:\n\t", tcs[i].case_name);
      print_arr_int(O_ARR_INT, O_ARR_LENGTH);
      printf("\n");

      for (size_t j = 0; j < sizeof(swo_preds) / sizeof(swo_preds[0]); ++j) {
        int c_arr_int[O_ARR_LENGTH];
        memcpy(c_arr_int, O_ARR_INT, O_ARR_LENGTH * sizeof(int));

        sort(tcs[i].sort_algo, c_arr_int, O_ARR_LENGTH, swo_preds[j].pred);

        printf("> After [%s] Sort(%s):\n\t", tcs[i].case_name, swo_preds[j].pred_name);
        print_arr_int(c_arr_int, O_ARR_LENGTH);

        printf("\n");
      }

      printf("\n");
    }
  }

  { // Testing Heap structure
    printf(">> Sorting print ended\n\n");

    printf("> Testing Heap Functions\n\n");

    for (size_t i = 0; 
    i < sizeof(swo_preds) / sizeof(swo_preds[0]); 
    ++i) {
      int* c_arr_int = (int*)malloc(O_ARR_LENGTH * sizeof(int));
      memcpy(c_arr_int, O_ARR_INT, O_ARR_LENGTH * sizeof(int));

      size_t length = O_ARR_LENGTH;

      printf("> Before [make_heap]\n\t");
      print_arr_int(c_arr_int, length);
      printf("\n");

      make_heap_int(c_arr_int, length, swo_preds[i].pred);

      printf("> After [make_heap](%s)\n\t", swo_preds[i].pred_name);
      print_arr_int(c_arr_int, length);
      printf("\n");

      int push_val = -999;
      c_arr_int = realloc(c_arr_int, ++length * sizeof(int));
      c_arr_int[length - 1] = push_val;  

      printf("> After pushing [%d] back of array\n\t", push_val);
      print_arr_int(c_arr_int, length);
      printf("\n");

      push_heap_int(c_arr_int, length, swo_preds[i].pred);

      printf("> After [push_heap](%s)\n\t", swo_preds[i].pred_name);
      print_arr_int(c_arr_int, length);
      printf("\n\n");

      free(c_arr_int);
    }

  }

  return 0;
}
