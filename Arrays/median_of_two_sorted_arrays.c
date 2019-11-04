#include <stdio.h>
#include <stdlib.h>

int
median (int arr[], int n)
{

	if ((n % 2) == 0) {
	
		return ((arr[n/2] + arr[n/2 - 1] )/ 2);
	}

	return arr[n/2];

}

int
max (int a, int b)
{

	if (a >= b) {
	
		return a;
	}

	return b;

}

int
min (int a, int b)
{

	if (a <= b) {
	
		return a;
	}

	return b;

}

int
get_median (int arr1[], int arr2[], int n)
{

	if (n <= 0) {
	
		return -1;
	}

	if (n == 1) {
	
		return ((arr1[0] + arr2[0]) / 2);
	}

	if (n == 2) {
	
		return ((max (arr1[0], arr2[0]) + min (arr1[1], arr2[1])) / 2);
	}

	int m1 = 0;
	int m2 = 0;

	m1 = median (arr1, n);
	m2 = median (arr2, n);

	if (m1 == m2) {
	
		return m1;
	}

	if (m1 < m2) {
	
		if ((n % 2) == 0) {
		
			return get_median(arr1 + n/2 - 1, arr2, n - n/2 + 1);
		}
		return get_median(arr1 + n/2, arr2, n - n/2);
	}

	if (m1 > m2) {
	
		if ((n % 2) == 0) {
				
			return get_median (arr1, arr2 + n/2 - 1, n - n/2 + 1);
		}
		return get_median (arr1, arr2 + n/2, n - n/2);
	}

}

int
main ()
{

	int arr1[] 	= {1, 2, 3, 6};
	int arr2[] 	= {4, 6, 8, 10};
	int n1		= 0;
	int n2		= 0;

	n1 = sizeof (arr1) / sizeof (int);
	n2 = sizeof (arr2) / sizeof (int);

	if (n1 == n2) {
	
		printf ("Median of the two arrays is: %d\n", get_median (arr1, arr2, n1));
	} else {
	
		printf ("Doesn't work for arrays of unequal size\n");
	}

	return 0;

}
