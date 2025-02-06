#ifndef _CALGO_PRINT_H
#define _CALGO_PRINT_H

#include <stddef.h>
#include <stdarg.h>

/*!
 * @brief Prints an integer array of given length.
 */
void 
print_arr_int(
  int const* cont, size_t length
);

/*!
 * @brief Prints an integer array of given length with index.
 */
void 
print_arr_with_idx_int(
  int const* cont, size_t length
);

/*!
 * @brief Prints an integer array of given length with marked ranges.
 * @param[in] range_count Number of ranges to be marked.
 * @param[in] ... Pairs of `int const*` representing the start and end of each range.
 * @example 
 * print_arr_mark_range_int(cont, length, 2, f_0, l_0, f_1, l_1);
 * This marks two ranges: `[f_0, l_0)` and `[f_1, l_1)`
 * @note
 * Each range should be specified as a pair of `int const*`, 
 * where the first pointer is the inclusive start of the range,
 * ane the second pointer is the exclusive end.
 * @warning
 * Ranges must be sorted in increasing order, and must always have matching pair.
 * 
 * Otherwise, the behavior is undefined.
 */
void print_arr_mark_range_int(
  int const* cont, size_t length, 
  size_t range_count, ...
);

#endif