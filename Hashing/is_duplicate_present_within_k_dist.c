#include <stdio.h>
#include <stdlib.h>
	
int
is_duplicate_present (int arr[], int n, int k)
{

	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++) {
	

		for (j = (i + 1); j <= (i + k); j++) {
		
			if (arr[i] == arr[j])
				return 1;
		}
	}

	return 0;

}

int
main ()
{

	int arr[] = {10, 5, 3, 4, 6, 5};

	int n = 0;
	int k = 0;

	n = sizeof (arr)/ sizeof (int);

	k = 3;

	if (!is_duplicate_present (arr, n, k))
		printf ("No duplicates are present \n");
	else
		printf ("Duplicates are present\n");

	return 0;

}
