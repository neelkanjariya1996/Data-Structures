#include <stdio.h>
#include <stdlib.h>

int
odd_count_element (int arr[], int n)
{

	int res = 0;
	int i	= 0;

	for (i = 0; i < n; i++) {
	
		res = res ^ arr[i];
	}

	return res;

}

int
main ()
{

	int arr[] 	= {1, 2, 2, 4, 3, 5, 3, 4, 5, 1, 1};
	int n		= 0;

	n = sizeof (arr) / sizeof (n);

	int odd_count = 0;

	odd_count = odd_count_element (arr, n);

	if (odd_count) {
	
		printf ("The element that is repeated odd number of times in the array is: %d\n", odd_count);
	} else {
	
		printf ("There is no element that is repeating odd number of times\n");
	}

	return 0;

}
