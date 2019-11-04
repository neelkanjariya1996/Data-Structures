#include <stdio.h>
#include <stdlib.h>

#define R	4
#define	C	4

void
spiral_print (int mat[R][C], int m, int n)
{

	int i = 0;
	int k = 0;
	int l = 0;

	/*
	 * i: iterator
	 * k: starting row index
	 * m: ending row index
	 * l: starting column index
	 * n: ending column index
	 */

	while ((k < m) && (l < n)) {
	
		for (i = l; i < n; i++) {
		
			printf ("%d ", mat[k][i]);
		}
		k++;

		for (i = k; i < m; i++) {
		
			printf ("%d ", mat[i][(n  - 1)]);
		}
		n--;

		if (k < m) {
		
			for (i = (n - 1); i >= l; i--) {
			
				printf ("%d ", mat[(m - 1)][i]);
			}
			m--;
		}

		if (l < n) {
		
			for (i = (m - 1); i >= k; i--) {
			
				printf ("%d ", mat[i][l]);
			}
			l++;
		}
	}

}

void
print_matrix (int mat[R][C], int m, int n)
{

	int i = 0;
	int j = 0;

	for (i = 0; i < m; i++) {
	
		for (j = 0; j < n; j++) {
		
			printf ("%d\t", mat[i][j]);
		}
		printf ("\n");
	}

}

int
main ()
{

	int mat[R][C] = {
					{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}
					};
	int m = 0;
	int n = 0;

	m = R;
	n = C;

	printf ("Matrix: \n");
	print_matrix (mat, m, n);

	printf ("Spiral Print: \n");
	spiral_print (mat, m, n);
	printf ("\n");

	return 0;

}
