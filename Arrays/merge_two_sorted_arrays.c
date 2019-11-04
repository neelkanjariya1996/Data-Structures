#include <stdio.h>
#include <stdlib.h>

#define NA	-1

void
print_array (int arr[], int size)
{

	int i = 0;
	for (i = 0; i < size; i++) {
		
		printf ("%d ", arr[i]);
	}
	printf ("\n");

}

void
merge (int large[], int small[], int m, int n)
{

	int lar_ind = 0;
	int sma_ind = 0;
	int fil_ind = 0;
	int i 		= 0;

	printf ("MPLUSN Array: ");
	print_array (large, m);

	printf ("N Array:      ");
	print_array (small, n);

	lar_ind = m - n - 1;
	sma_ind = n - 1;
	fil_ind = m - 1;

	while (fil_ind != 0) {
	
		if (large[lar_ind] >= small[sma_ind]) {
		
			large[fil_ind] = large[lar_ind];
			lar_ind--;
			fil_ind--;
		} else if (large[lar_ind] < small[sma_ind]) {
		
			large[fil_ind] = small[sma_ind];
			sma_ind--;
			fil_ind--;
		}
	}

	printf ("New M Plus N Array: ");
	print_array (large, m);

}

int
main ()
{

	int large[] = {2, 7, 10, NA, NA, NA, NA};
	int small[]	= {5, 8, 12, 14};
	int m		= 0;
	int n		= 0;

	m = sizeof (large) / sizeof (int);
	n = sizeof (small) / sizeof (int);

	merge (large, small, m, n);

	return 0;

}
