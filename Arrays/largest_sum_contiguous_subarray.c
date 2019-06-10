#include <stdio.h>
#include <stdlib.h>

int
max (int a, int b)
{

	if (a >= b) {
	
		return a;
	}

	return b;

}

int
largest_sum (int arr[], int n)
{

	int curr_max 	= arr[0];
	int max_so_far 	= arr[0];
	int i			= 0;

	for (i = 1; i < n; i++) {
	
		curr_max 	= max (arr[i], (curr_max + arr[i]));
		max_so_far	= max (max_so_far, curr_max);
	}

	return max_so_far;

}

int
main ()
{

	int arr[] 	= {-3, -4, -2, -10, -4, -5, -2, -1};
	int n		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("The largest sum that is possible in a contiguous subarray is: %d\n", largest_sum (arr, n));

	return 0;

}
