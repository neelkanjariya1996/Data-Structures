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
partitioning (int arr[], int si, int ei)
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

	int pi  = 0;

	if (si < ei) {

		pi = partitioning (arr, si, ei);
		quick_sort (arr, si, (pi -1));
		quick_sort (arr, (pi + 1), ei);
	}

}

int
is_two_sum (int arr[], int n, int sum)
{

	quick_sort (arr, 0, (n -1));

	int l = 0;
	int r = 0;

	l = 0;
	r = n - 1;

	while (l < r) {

		if ((arr[l] + arr[r]) == sum)
			return 1;
		else if ((arr[l] + arr[r]) < sum)
			l++;
		else if ((arr[l] + arr[r]) > sum)
			r--;
	}

	return 0;

}

int
main ()
{

	int arr[] 	= {1, 4, 45, 6, 10, -8};
	int n		= 0;
	int sum		= 0;

	n = sizeof (arr)/ sizeof (int);

	sum = 1;

	if (is_two_sum (arr, n, sum))
		printf ("Array has two elements with the given sum\n");
	else
		printf ("Array does not have two elements with given sum\n");

	return 0;

}
