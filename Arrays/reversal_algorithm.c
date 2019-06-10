#include <stdio.h>
#include <stdlib.h>

void
reverse_array (int arr[], int start, int end)
{

	int temp = 0;

	while (start < end) {
	
		temp		= arr [start];
		arr [start]	= arr [end]; 
		arr[end]	= temp;
		start++;
		end--;
	}

}

void
reverse_algorithm (int arr[], int n, int d)
{

	reverse_array (arr, 0, (d - 1));
	reverse_array (arr, d, (n - 1));
	reverse_array (arr, 0, (n - 1));

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

	int arr[] 	= {1, 2, 3, 4, 5, 6, 7};
	int n		= 0;
	int d		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Before Rotation: ");
	print_array (arr, n);

	d = 2;
	reverse_algorithm (arr, n, d);

	printf ("After Rotation:  ");
	print_array (arr, n);

	return 0;

}
