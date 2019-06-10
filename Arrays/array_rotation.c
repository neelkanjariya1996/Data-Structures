#include <stdio.h>
#include <stdlib.h>

void
left_rotate_by_one (int arr[], int n)
{

	int temp = 0;
	int i	 = 0;

	temp = arr[0];
	for (i = 0; i < (n - 1); i++) {
	
		arr[i] = arr[i + 1];
	}
	arr[i] = temp;

}

void
left_rotate (int arr[], int n, int d)
{

	int i = 0;
	for (i = 0; i < d; i++) {
	
		left_rotate_by_one (arr, n);
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

	int arr[] 	= {1, 2, 3, 4, 5, 6};
	int n		= 0;
	int d		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Before Rotation: ");
	print_array (arr, n);

	d = 2;
	left_rotate (arr, n, d);

	printf ("After  Rotation: ");
	print_array (arr, n);

	return 0;

}
