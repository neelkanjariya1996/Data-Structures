#include <stdio.h>
#include <stdlib.h>

int
find_candidate (int arr[], int n)
{

	int maj_ind	= 0;
	int count	= 0;
	int i		= 0;

	maj_ind = 0;
	count	= 1;

	for (i = 1; i < n; i++) {
	
		if (arr[maj_ind] == arr[i]) {
		
			count++;
		} else {
		
			count--;
		}

		if (count == 0) {
		
			maj_ind = i;
			count	= 1;
		}
	}

	return arr[maj_ind];

}

int
is_majority (int arr[], int n, int can)
{

	int count	= 0;
	int i		= 0;

	for (i = 0; i < n; i++) {
	
		if (arr[i] == can) {
		
			count++;
		}
	}

	if (count > (n / 2)) {
	
		return 1;
	} else {
	
		return 0;
	}

}

void
print_majority_element (int arr[], int n)
{

	int can = 0;
	int maj = 0;

	can = find_candidate (arr, n);

	maj = is_majority (arr, n, can);

	if (maj) {
	
		printf ("The majority element is %d\n", can);
	} else {
	
		printf ("No majority element exists\n");
	}

	return;

}

int
main ()
{

	int arr[] 	= {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1};
	int n		= 0;

	n = sizeof (arr) / sizeof (int);

	print_majority_element (arr, n);

	return 0;

}
