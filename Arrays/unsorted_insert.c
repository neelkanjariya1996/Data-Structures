#include <stdio.h>
#include <stdlib.h>

int
unsorted_insert (int arr[], int n, 
				 int key, int capacity)
{

	if (n >= capacity) {
	
		return n;
	}

	arr[n] = key;

	return (n + 1);

}

int
main ()
{

	int arr[20]		= {10, 2, 5, 73, 78, 90};
	int capacity 	= 0;
	int n 			= 0;
	int key 		= 0;
	int i			= 0;

	capacity = sizeof (arr) / sizeof (int);
	n		 = 6;
	key		 = 32;

	printf ("Before Insertion: ");
	for (i = 0; i < n; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

	n = unsorted_insert (arr, n, key, capacity);


	printf ("After Insertion:  ");
	for (i = 0; i < n; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

	return 0;

}
