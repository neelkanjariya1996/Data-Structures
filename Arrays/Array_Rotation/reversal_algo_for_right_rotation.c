#include <stdio.h>
#include <stdlib.h>

void
left_rotate_by_one (int arr[], int n)
{
	
	int i		= 0;
	int temp 	= 0;

	temp = arr[0];
	for (i = 0; i < (n - 1); i++)
		arr[i] = arr[i + 1];
	arr[i] = temp;

}

void
right_rotate (int arr[], int n, int d)
{
	
	if (n == 1)
		return;

	if (d > n)
		d = d%n;

	int left_rotate = 0;
	int i			= 0;

	left_rotate = (n - d);

	for (i = 0; i < left_rotate; i++)
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
	int arr[]	= {121, 232};
	int k		= 0;
	int size	= 0;

	size = (sizeof (arr))/(sizeof (int));

	print_array (arr, size);

	k = 3;
	right_rotate (arr, size, k);
	print_array (arr, size);

	return 0;

}
