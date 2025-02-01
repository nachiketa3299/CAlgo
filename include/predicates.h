#ifndef _CALGO_PREDICATES_H
#define _CALGO_PREDICATES_H

#include <stdbool.h>

typedef bool (*Pred_int)(int, int);

/* Strict Weak Ordering */

bool greater_int(int op1, int op2);

bool less_int(int op1, int op2);

/* Weak Ordering */

bool greater_equal_int(int op1, int op2);

bool less_equal_int(int op1, int op2);

/* Equivalence */

bool equal_to_int(int op1, int op2);

bool not_equal_to_int(int op1, int op2);



#endif