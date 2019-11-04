#include <stdio.h>
#include <stdlib.h>

void
fill_o_and_x (int m, int n)
{

	char a[m][n];
	int k 	= 0;
	int l 	= 0;
	int i 	= 0;
	int j 	= 0;
	int r 	= 0;
	int c 	= 0;
	char x 	= 0;

	r = m; // rows
	c = n; // columns

	/*
	 * i: iterator
	 * k: starting row index
	 * m: ending row index
	 * l: starting column index
	 * n: ending column index
	 */

	x = 'X';

	while ((k < m) && (l < n)) {
	
		for (i = l; i < n; i++) {
		
			a[k][i] = x;
		}
		k++;

		for (i = k; i < m; i++) {
		
			a[i][n - 1] = x;
		}
		n--;

		if (k < m) {
		
			for (i = (n -1); i >= l; i--) {
			
				a[m - 1][i] = x;
			}
			m--;
		}

		if (l < n) {
		
			for (i = (m - 1); i >= k; i--) {
			
				a[i][l] = x;
			}
			l++;
		}

		x = (x == 'O') ? 'x' : 'O';
	}	

	/*
	 * print the matrix
	 */

	for (i = 0; i < r; i++) {
	
		for (j = 0; j < c; j++) {
		
			printf ("%c ", a[i][j]);
		}
		printf ("\n");
	}

}

int
main ()
{

	int m = 0;
	int n = 0;

	m = 4;
	n = 4;
	printf ("Output for m = %d, n = %d\n", m, n);
	fill_o_and_x (m, n);

	m = 6;
	n = 6;
	printf ("Output for m = %d, n = %d\n", m, n);
	fill_o_and_x (m, n);

	return 0;

}
