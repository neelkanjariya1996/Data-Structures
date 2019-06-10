#include <stdio.h>
#include <stdlib.h>

void
reverse_array_recursive (int arr [], int start, int end)
{

	if (start >= end)
		return;

	int temp = 0;

	temp 		= arr [start];
	arr [start] = arr [end];
	arr [end]	= temp;

	reverse_array_recursive (arr, (start + 1), (end - 1));

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

	int arr[] = {10, 23, 54, 27};
	int n	  = 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Original Array: ");
	print_array (arr, n);

	reverse_array_recursive (arr, 0, (n - 1));

	printf ("Reversed Array: ");
	print_array (arr, n);

	return 0;

}
