#include <stdio.h>
#include "./include/bubble_sort.h"
#include "./include/insertion_sort.h"

bool pred_greater_int(int op1, int op2) {
	return op1 > op2;
}

bool pred_less_int(int op1, int op2) {
	return op1 < op2;
}

int main() {

	int arr[] = { 10, 222, 3, 152, -33};
	size_t length = sizeof(arr) / sizeof(arr[0]);

	printf("* Before: ");
	print_arr_int(arr, length);
	printf("\n");

	insertion_sort_int(arr, length, pred_greater_int);

	printf("* After greater: ");
	print_arr_int(arr, length);
	printf("\n");

	insertion_sort_int(arr, length, pred_less_int);

	printf("* After less: ");
	print_arr_int(arr, length);

	return 0;
}
