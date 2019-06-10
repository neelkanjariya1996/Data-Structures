#include <stdio.h>
#include <stdlib.h>

void
left_rotate_by_one (int arr[], int n) 
{

	int temp 	= 0;
	int i		= 0;

	temp = arr[0];
	for (i = 0; i < (n - 1); i++) {
		arr[i] = arr[i + 1];
	}
	arr[i] = temp;

}

void
left_rotate (int arr[], int d, int n)
{

	int i = 0;
	for (i = 0; i < d; i++) {
		left_rotate_by_one (arr, n);
	}

}

void
print_array (int arr[], int n)
{

	int i = 0;

	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int
main () {

	int arr[7] = {1, 2, 3, 4, 5, 6, 7};

	printf("Original array: ");
	print_array (arr, 7);

	printf("Rotated  array: ");
	left_rotate (arr, 8, 7);
	print_array (arr, 7);

	return 0;

}
