#ifndef _CALGO_PREDICATES_H
#define _CALGO_PREDICATES_H

#include <stdbool.h>

typedef bool (*Pred_int)(int, int);

bool pred_greater_int(int op1, int op2);
bool pred_less_int(int op1, int op2);

#endif