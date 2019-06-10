#include <stdio.h>
#include <stdlib.h>

int
find_position_element (int arr[], int n, int element)
{

		int i = 0;

		for (i = 0; i < n; i++) {
		
			if (arr[i] == element)
				return i;
		}

		return -1;

}

int
main ()
{

	int arr[] 		= {0, 1, 3, 5, 2, 9};
	int n			= 0;
	int element		= 0;
	int position	= 0;

	n = sizeof (arr) / sizeof (int);

	element	 = 100;
	position = find_position_element (arr, n, element);

	if (position == -1) {
	
		printf ("Element not found\n");
	} else {
	
		printf ("Element found at location %d.\n", position);
	}

	return 0;

}
