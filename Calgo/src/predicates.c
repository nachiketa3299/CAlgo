#include "predicates.h"

bool 
greater_int(
  int left, int right
) {
  return left > right;
}

bool 
less_int(
  int left, int right
) {
  return left < right;
}

bool 
greater_equal_int(
  int left, int right
) {
  return left >= right;
}

bool 
less_equal_int(
  int left, int right
) {
  return left <= right;
}

bool 
equal_to_int(
  int left, int right
) {
  return left == right;
}

bool 
not_equal_to_int(
  int left, int right
) {
  return left != right;
}