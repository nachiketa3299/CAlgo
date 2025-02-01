#include "../include/predicates.h"

bool greater_int(int op1, int op2) {
  return op1 > op2;
}

bool equal_to_int(int op1, int op2) {
  return op1 == op2;
}

bool not_equal_to_int(int op1, int op2) {
  return op1 != op2;
}

bool less_int(int op1, int op2) {
  return op1 < op2;
}

bool greater_equal_int(int op1, int op2) {
  return op1 >= op2;
}

bool less_equal_int(int op1, int op2) {
  return op1 <= op2;
}
