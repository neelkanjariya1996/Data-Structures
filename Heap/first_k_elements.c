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
/*
void
heapify (int arr[], int n, int i)
{

	if (i >= n/2) {
	
		return;
	}

	int smallest 	= i;
	int l			= left (i);
	int r			= right (i);

	if ((l < n) && (arr[l] < arr[smallest])) {
	
		smallest = l;
	}

	if ((r < n) && (arr[r] < arr[smallest])) {
	
		smallest = r;
	}

	if (smallest != i) {
	
		swap (&arr[i], &arr[smallest]);
		heapify (arr, n, smallest);
	}

}
*/

void
heapify (int arr[], int n, int i)
{

	if (i >= n/2) {
	
		return;
	}

	int smallest;
	int l = left (i);
	int r = right (i);

	smallest = arr[l] < arr[i] ? l : i;

	if (r < n) {
	
		smallest = arr[r] < arr[smallest] ? r : smallest;
	}

	if (smallest != i) {
	
		swap (&arr[i], &arr[smallest]);
		heapify (arr, n, smallest);
	}

}

void
build_heap (int arr[], int k)
{

	int i = 0;
	for (i = (k/2 - 1); i >= 0; i--) {
	
		heapify (arr, k, i);
	}

}

void
first_k_elements (int arr[], int n, int k)
{

	build_heap (arr, k);

	int i = 0;

	for (i = k; i < n; i++) {
	
		if (arr[0] > arr[i]) {
		
			continue;
		} else {
		
			arr[0] = arr[i];
			heapify (arr, n, 0);
		}
	}

	printf ("First k largest elements: ");
	for (i = 0; i < k; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

}

int
main ()
{

	int arr[] 	= {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
	int n		= 0;
	int k		= 0;

	n = sizeof (arr) / sizeof (int);

	k = 3;
	first_k_elements (arr, n, k);

	return 0;

}
