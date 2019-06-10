#include <stdio.h>
#include <stdlib.h>

int
min_element (int arr[], int n, int low, int high)
{

	if (n == 1)
		return arr[0];

	if (high < low)
		return arr[0];

	int mid = 0;

	mid = (low + high)/2;
	
	if (arr[mid] < arr[mid - 1])
		return arr[mid];

	if (arr[mid + 1] < arr[mid])
		return arr[mid + 1];

	if (arr[mid] < arr[n - 1])
		return min_element (arr, n, 0, (mid - 1));
	else
		return min_element (arr, n, (mid + 1), (n - 1));

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

	int arr[]	= {7, 1};
	int size	= 0;
	int min_ele = 0;
	
	size = (sizeof(arr))/(sizeof(int));

	print_array (arr, size);

	min_ele = min_element (arr, size, 0, (size - 1));
    printf("The minimum element in the array is %d\n", min_ele);

	return 0;

}
