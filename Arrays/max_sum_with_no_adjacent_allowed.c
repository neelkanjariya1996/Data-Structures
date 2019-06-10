#include <stdio.h>
#include <stdlib.h>

int
max (int a, int b)
{

	if (a >= b) {
	
		return a;
	} else {
	
		return b;
	}

}

int
max_sum (int arr[], int n)
{

	int sum1 = 0;
	int sum2 = 0;
	int i	 = 0;

	for (i = 0; i < n; i++) {
	
		if ((i % 2) == 0) {
		
			sum1 = sum1 + arr[i];
		} else {
		
			sum2 = sum2 + arr[i];
		}
	}

	return max (sum1, sum2);

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

	int arr[] 	= {10, 0, 0, 100, 100, 0, 10};
	int n		= 0;
	int sum		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Array: ");
	print_array (arr, n);

	sum = max_sum (arr, n);

	printf ("The max sum of the array where adjacent elements are not allowed is : %d\n", sum);

	return 0;

}
