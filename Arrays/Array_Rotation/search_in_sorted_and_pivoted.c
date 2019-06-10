#include <stdio.h>
#include <stdlib.h>

int
binary_search (int arr[], int low, int high, int key)
{

	if (low > high)
		return -1;

	int mid = 0;

	mid = (low + high)/2;

	if (key == arr[mid])
		return mid;

	if (key > arr[mid])
		return binary_search (arr, (mid + 1), high, key);
	return binary_search (arr, low, (mid - 1), key);

}

int
find_pivot (int arr[], int low, int high)
{

	if (high < low)
		return -1;

	if (high == low)
		return low;

	int mid = 0;
	
	mid = (low + high)/2;
	if (mid < high && arr[mid] > arr[mid + 1])
		return mid;
	if (mid > low && arr[mid] < arr[mid - 1])
		return (mid - 1);
	if (arr[low] >= arr[mid])
		return find_pivot (arr, low, (mid - 1));
	return find_pivot (arr, (mid + 1), high);

}

int
search_index (int arr[], int n, int key)
{

	int pivot = 0;

	pivot = find_pivot (arr, 0, (n -1));

	if (pivot == -1)
		return binary_search (arr, 0, (n - 1), key);

	if (pivot == key)
		return pivot;

	if (arr[0] <= key)
		return binary_search (arr, 0, (pivot - 1), key);
	return binary_search (arr, (pivot + 1), (n - 1), key);

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

	int key 	= 0;
	int index 	= 0;
	int arr[7] 	= {3, 4, 5, 6, 7, 1, 2};

	print_array (arr, 7);

	key = 1;
	index = search_index (arr, 7, key);

	printf("The index of the key %d is: %d", key, index);

	return 0;

}
