#include <stdio.h>
#include <stdlib.h>

int
search_in_sorted_and_pivoted (int arr[], int key,
							  int low, int high)
{

	int mid = 0;

	if (low > high) {
	
		return -1;
	}

	mid = (low + high) / 2;

	if (arr[mid] == key) {
	
		return mid;
	}

	if (arr[low] <= arr[mid]) {
	
		if (key >= arr[low] && key <= arr[mid]) {
		
			return search_in_sorted_and_pivoted (arr, key, low, (mid - 1));
		} else {
		
			return search_in_sorted_and_pivoted (arr, key, (mid + 1), high);
		}
	}

	if (key >= arr[mid] && key <= arr[high]) {
	
		return search_in_sorted_and_pivoted (arr, key, (mid + 1), high);		
	} else {
	
		return search_in_sorted_and_pivoted (arr, key, low, (mid - 1));
	}

}

void
print_array (int arr[], int n)
{

	int i = 0;

	for (i = 0; i < n; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

}

int
main ()
{

	int arr[] 	= {4, 5, 6, 7, 8, 9, 1, 2, 3};
	int n		= 0;
	int key		= 0;
	int result	= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Array: ");
	print_array (arr, n);

	key = 6;
	result = search_in_sorted_and_pivoted (arr, key, 0, (n - 1));

	if (result != -1) {

		printf ("The index of element %d in the array is %d\n", key, result);
	} else {
	
		printf ("%d not found in the array\n", key);
	}
	return 0;

}
