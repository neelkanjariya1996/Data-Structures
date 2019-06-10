#include <stdio.h>
#include <stdlib.h>

void
swap (int *a, int *b)
{

	int temp = 0;

	temp = *a;
	*a	 = *b;
	*b	 = temp;

}

int
partition (int arr[], int si, int ei)
{

	int x = 0;
	int i = 0;
	int j = 0;

	x = arr[ei];
	i = (si - 1);

	for (j = si; j <= (ei - 1); j++) {
	
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
two_sum (int arr[], int n, int sum)
{

	int low		= 0;
	int high	= 0;

	quick_sort (arr, 0, (n - 1));

	low		= 0;
	high	= (n - 1);

	while (low < high) {
	
		if ((arr[low] + arr[high]) == sum) {
		
			return 1;
		} else if ((arr[low] + arr[high]) < sum) {
		
			low++;
		} else if ((arr[low] + arr[high]) > sum) {
		
			high--;
		}
	}

	return -1;

}

int
main ()
{

	int arr[]		= {3, 1, 0, 2, 4, 5};
	int n			= 0;
	int sum			= 0;
	int i			= 0;
	int is_two_sum	= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Array: ");
	for (i = 0; i < n; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

	sum 		= 50;
	is_two_sum 	= two_sum (arr, n, sum);

	if (is_two_sum == -1) {
	
		printf ("No two elements exists in the array whose sum is %d\n", sum);
	} else {
	
		printf ("There exists two elements in the array whose sum is %d\n", sum);
	}

	return 0;

}
