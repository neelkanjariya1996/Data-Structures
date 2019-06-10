#include <stdio.h>
#include <stdlib.h>

int
rotation_count (int arr[], int n, int low, int high)
{
	
	if (n == 1)
		return 0;

	if (high < low)
		return 0;
	
	int mid	= 0;

	mid = (low + high)/2;

	if (arr[mid] < arr[mid - 1])
		return mid;

	if (arr[mid + 1] < arr[mid])
		return (mid + 1);

	if (arr[mid] < arr[n - 1])
		return rotation_count (arr, n, 0, (mid - 1));
	else
		return rotation_count (arr, n, (mid + 1), n);

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
	
	int arr[] 	= {7, 9, 11, 12, 15};
	int size	= 0;
	int count	= 0;

	size = (sizeof(arr))/(sizeof(int));

	print_array (arr, size);

	count = rotation_count (arr, size, 0, (size - 1));
	printf("The array has been rotated by %d times\n", count);

	return 0;
	
}
