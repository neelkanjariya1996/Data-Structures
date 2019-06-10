#include <stdio.h>
#include <stdlib.h>

void
left_rotate_by_one (int arr[], int n)
{
	
	int temp 	= 0;
	int i		= 0;
	
	temp = arr[0];
	for (i = 0; i < (n - 1); i++)
		arr[i] = arr[i + 1];
	arr[n - 1] = temp;

}

void
left_rotate_by_d (int arr[], int n, int d)
{

	int i = 0;

	for (i = 0; i < d; i++)
		left_rotate_by_one (arr, n);

}

void
print_array (int arr[], int n)
{

	int i = 0;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

int
main ()
{
	
	int arr[] 	= {1, 2, 3, 4, 5, 6};
	int size	= 0;
	int d		= 0;

	size = (sizeof (arr))/(sizeof (int));

	print_array (arr, size);

	d = 20;
	left_rotate_by_d (arr, size, d);
	print_array (arr, size);

	return 0;

}
