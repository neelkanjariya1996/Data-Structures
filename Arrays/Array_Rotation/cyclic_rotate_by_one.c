#include <stdio.h>
#include <stdlib.h>

void
cyclic_rotate_by_one (int arr[], int n)
{

	int i 		= 0;
	int temp 	= 0;

	temp = arr[n - 1];
	for (i = (n - 1); i > 0; i--) {
	
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;

}

void
print_array (int arr[], int n)
{
	int i = 0;
	for (i = 0; i  < n; i++) {
	
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int
main ()
{

	int arr[5] = {1, 2, 3, 4, 5};

	printf("original array: ");
	print_array (arr, 5);

	printf("rotated  array: ");
	cyclic_rotate_by_one (arr, 5);
	print_array (arr, 5);

	return 0;

}
