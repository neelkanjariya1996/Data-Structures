#include <stdio.h>
#include <stdlib.h>

void
swap (int *a, int *b)
{

	int temp = 0;

	temp	= *a;
	*a		= *b;
	*b		= temp;

}

int
left (int i)
{

	return ((2 * i) + 1);

}

int
right (int i)
{

	return ((2 * i) + 2);

}

void
heapify (int arr[], int n, int i)
{

	int largest	= i;
	int l		= left (i);
	int r		= right (i);

	if ((l < n) && (arr[l] > arr[largest])) {
	
		largest = l;
	}

	if ((r < n) && (arr[r] > arr[largest])) {
	
		largest = r;
	}

	if (largest != i) {

		swap (&arr[i], &arr[largest]);
		heapify (arr, n, largest);
	}

}

void
heap_sort (int arr[], int n)
{

	int i = 0;

	for (i = (n/2 - 1); i >= 0; i--) {
	
		heapify (arr, n, i);
	}

	for (i = (n - 1); i >= 0; i--) {
	
		swap (&arr[0], &arr[i]);

		heapify (arr, i, 0);
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

	int arr[] 	= {0, 5, 2, 8, 123, -3, -5};
	int n		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Before Sorting: ");
	print_array (arr, n);

	heap_sort (arr, n);

	printf ("After  Sorting: ");
	print_array (arr, n);

	return 0;

}
