#include <stdio.h>
#include <stdlib.h>

void
print_leaders (int arr[], int n)
{

	int max = 0;
	int i 	= 0;

	printf ("Leaders: ");
	printf ("%d ", arr[(n - 1)]);

	max = arr[(n - 1)];

	for (i = (n - 2); i >= 0; i--) {
	
		if (arr[i] > max) {
		
			max = arr[i];
			printf ("%d ", max);
		}
	}
	printf ("\n");

}

int
main ()
{

	int arr[]	 = { 1};
	int n		 = 0;

	n = sizeof (arr) / sizeof (int);

	print_leaders (arr, n);

	return 0;

}
