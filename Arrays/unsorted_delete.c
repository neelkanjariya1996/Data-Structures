#include <stdio.h>
#include <stdlib.h>

int
find_position (int arr[], int n, int key)
{

	int i = 0;

	for (i = 0; i < n; i++) {
	
		if (arr[i] == key) {
		
			return i;
		}
	}

	return -1;

}

int
unsorted_delete (int arr[], int n, int key)
{

	int position = 0;
	int i		 = 0;

	position = find_position (arr, n, key);

	if (position == -1) {
	
		printf ("Element to be deleted not found in the array\n");
		return n;
	} else {
	
		for (i = position; i < n; i++) {
		
			arr[i] = arr[i + 1];
		}
		return (n - 1);
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

		int arr[] 	= {2, 5, 3, 7, 9, 10};
		int n		= 0;
		int key		= 0;

		n = sizeof (arr) / sizeof (int);

		printf ("Before Deletion: ");
		print_array (arr, n);

		key = 5;
		n = unsorted_delete (arr, n, key);

		printf ("After Deletion:  ");
		print_array (arr, n);

		return 0;

}
