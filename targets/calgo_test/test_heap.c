#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calgo/print.h"

#include "calgo/predicates.h"

#include "calgo/heap.h"

struct Pred_int_wrapper {
  Pred_int pred;
  char* name;
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

      printf("> After [make_heap](%s)\n\t", swo_preds[i].name);
      print_arr_int(c_arr_int, length);
      printf("\n");

      int push_val = -999;
      c_arr_int = realloc(c_arr_int, ++length * sizeof(int));
      c_arr_int[length - 1] = push_val;  

      printf("> After pushing [%d] back of array\n\t", push_val);
      print_arr_int(c_arr_int, length);
      printf("\n");

      push_heap_int(c_arr_int, length, swo_preds[i].pred);

      printf("> After [push_heap](%s)\n\t", swo_preds[i].name);
      print_arr_int(c_arr_int, length);
      printf("\n\n");

      free(c_arr_int);
    }
  return 0;
}
