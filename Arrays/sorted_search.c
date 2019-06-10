#include <stdio.h>
#include <stdlib.h>

int
sorted_search (int arr[], int n, int key,
			   int low, int high)
{

	int mid = 0;

	if (low > high) {
	
		return -1;
	}
	
	mid = (low + high) / 2;

	if (arr[mid] == key) {
	
		return mid;
	} else if (arr[mid] < key) {
	
		return sorted_search (arr, n, key, (mid + 1), high);
	} else {
	
		return sorted_search (arr, n, key, low, (mid - 1));
	}

}

int
main ()
{

	int arr[]		= {0, 1, 20, 35, 56, 78, 98, 100};
	int n		 	= 0;
	int key			= 0; 
	int pos			= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Array: ");
	for (int i = 0; i < n; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

	key = 20;
	pos = sorted_search (arr, n, key, 0, n);

	if (pos == -1) {
	
		printf ("Element not found\n");
	} else {
	
		printf ("%d is located at %d position in the given array\n", key, pos);
	}

	return 0;

}
