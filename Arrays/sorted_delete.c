#include <stdio.h>
#include <stdlib.h>

int 
find_position (int arr[], int n, int key,
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
	
		return find_position (arr, n, key, (mid + 1), high);
	} else {
	
		return find_position (arr, n, key, low,  (mid - 1));
	}
	
}

int 
sorted_delete (int arr[], int n, int key)
{

	int pos = 0;

	pos = find_position (arr, n, key, 0, n);

	if (pos == -1) {
	
		printf ("%d not found in the given array\n", key);
		return n;
	}

	int i = 0;

	for (i = pos; i < n; i++) {
	
		arr[i] = arr[i + 1];
	}	

	return (n - 1);

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

	int arr[]	= {1, 4, 5, 32, 45, 67, 89, 100};
	int n		= 0;
	int key		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Before Deletion: ");
	print_array (arr, n);

	key = 0;
	n = sorted_delete (arr, n, key);

	printf ("After Deletion:  ");
	print_array (arr, n);

	return 0;

}
