#include <stdio.h>
#include <stdlib.h>

void
search (int mat[4][4], int n, int x) 
{

	int i 			= 0;
	int j 			= 0;
	int smallest 	= 0;
	int largest		= 0;

	smallest = mat[0][0];
	largest	 = mat[n - 1][n - 1];

	if (x < smallest || x > largest) {
		
		printf ("%d not found in the matrix\n", x);
		return;
	}

	i = 0;
	j = (n - 1);

	while (i < n && j >= 0) {
	
		if (mat[i][j] == x) {
		
			printf ("%d is found at [%d][%d] in the matrix\n", x, i, j);
			return;
		}

		if (mat[i][j] < x) {
		
			i++;
		} else {
		
			j--;
		}
	}

	printf ("%d not found in the matrix\n", x);

	return;

}

int
main ()
{

	int mat[4][4] = { 
					{10, 20, 30, 40}, 
					{15, 25, 35, 45},
					{27, 29, 37, 48},
					{32, 33, 39, 50},
					};
	int n = 0;
	int x = 0;

	n = 4;
	x = 50;

	search (mat, n, x);

	return 0;

}
