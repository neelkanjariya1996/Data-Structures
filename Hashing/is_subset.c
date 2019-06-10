#include <stdio.h>
#include <stdlib.h>

void
swap (int *a, int *b)
{
	
	int temp = 0;

	temp 	= *a;
	*a		= *b;
	*b		= temp;

}

int
partition (int arr[], int si, int ei)
{

	int x = 0;
	int i = 0;
	int j = 0;

	x = arr[ei];
	i = (si - 1);

	for (j = si; j <= (ei -1); j++) {
	
		if (arr[j] <= x) {
		
			i++;
			swap (&arr[i], &arr[j]);
		}
	}
	swap (&arr[i + 1], &arr[ei]);

	return (i + 1);

}

void
quick_sort (int arr[], int si, int ei)
{

	int pi = 0;

	if (si < ei) {
	
		pi = partition (arr, si, ei);
		quick_sort (arr, si, (pi - 1));
		quick_sort (arr, (pi + 1), ei);
	}

}

int
binary_Search (int arr[], int low, int high, int x)
{
	
	if (low > high)
		return -1;

	if (high >= low) {
	int mid = 0;

	mid = (low + high)/2;
		if (arr[mid] == x)
			return 1;
		else if (arr[mid] > x)
			return binary_Search (arr, low, (mid -1), x);
		else if (arr[mid] < x)
			return binary_Search (arr, (mid + 1), high, x);
	}

	return -1;

}

int
is_subset (int arr1[], int arr2[], int m, int n)
{

	quick_sort (arr1, 0, (m -1));

	for (int i = 0; i < n; i++) {
	
		if (binary_Search (arr1, 0, (m - 1), arr2[i]) == -1)
			return 0;
	}

	return 1;

}

int
main ()
{

	int arr1[] = {11, 1, 13, 21, 3, 7};
	int arr2[] = {11, 3, 7, 1};

	int m = 0;
	int n = 0;

	m = sizeof (arr1)/ sizeof (int);
	n = sizeof (arr2)/ sizeof (int);

	if (is_subset (arr1, arr2, m, n))
		printf ("Array 2 is a subset of Array 1\n");
	else
		printf ("Array 2 is not a subset of Array 1\n");

	return 0;

}
