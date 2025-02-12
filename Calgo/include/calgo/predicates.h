#ifndef _CALGO_PREDICATES_H
#define _CALGO_PREDICATES_H

#include <stdbool.h>

typedef 
bool 
(*Pred_int)(
  int left, int right
);

/* Strict Weak Ordering */

bool 
greater_int(
  int left, int right
);

bool 
less_int(
  int left, int right
);

/* Weak Ordering */

bool 
greater_equal_int(
  int left, int right
);

bool 
less_equal_int(
  int left, int right
);

/* Equivalence */

bool 
equal_to_int(
  int left, int right
);

bool 
not_equal_to_int(
  int left, int right
);

#endif