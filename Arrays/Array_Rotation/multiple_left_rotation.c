#include <stdio.h>
#include <stdlib.h>

void
left_rotate (int arr[], int n, int k)
{
	int i = 0;

	for (i = k; i < (k + n); i++)
		printf("%d ", arr[i%n]);
	printf("\n");

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
main ()
{

	int arr[] 	= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size	= 0;
	int i		= 0;

	size = (sizeof(arr))/(sizeof(int));

	print_array (arr, size);

	for (i = 0; i <= size; i++) {
		printf("k = %d\n", i);
		left_rotate (arr, size, i);
		printf("\n");
	}

	return 0;

}
