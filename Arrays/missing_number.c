#include <stdio.h>
#include <stdlib.h>

int
missing_number (int arr[], int n)
{

	int x1 	= 0;
	int x2 	= 0;
	int i	= 0;
	
	x1 = arr[0];
	x2 = 1;

	for (i = 1; i < n; i++) {
	
		x1 = x1 ^ arr[i];
	}

	for (i = 2; i <= (n + 1); i++) {
	
		x2 = x2 ^ i;
	}

	return (x1 ^ x2);

}

int
main ()
{

	int arr[] 	= {2, 3, 4, 5, 6, 7};
	int n		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("The missing number is %d\n", missing_number (arr, n));

	return 0;

}
