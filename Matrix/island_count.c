#include <stdio.h>
#include <stdlib.h>

#define R	6
#define C	4

int
island_count (int mat[R][C])
{

	int count	= 0;
	int	i		= 0;
	int j		= 0;

	for (i = 0; i < R; i++) {
	
		for (j = 0; j < C; j++) {
		
			if (mat[i][j] == 'x') {
			
				if (((i == 0) || (mat[i - 1][j] == 'o')) &&
					((j == 0) || (mat[i][j - 1] == 'o'))) {
				
					count++;
				}
			}
		}
	}

	return count;

}

void
print_matrix (int mat[R][C])
{

	int i = 0;
	int j = 0;

	for (i = 0; i < R; i++) {
	
		for (j = 0; j < C; j++) {
		
			printf ("%d ", mat[i][j]);
		}
		printf ("\n");
	}

}

int
main ()
{

	int mat[R][C] = {
			  		{'o', 'x', 'x', 'x'},
			  		{'o', 'x', 'x', 'x'},
			  		{'o', 'o', 'o', 'o'},
			  		{'x', 'o', 'x', 'x'},
			  		{'o', 'o', 'o', 'o'},
			  		{'x', 'x', 'o', 'o'},
			  		};
	int count = 0;

	printf ("Matrix: \n");
	print_matrix (mat);

	count = island_count (mat);

	printf ("There are %d islands\n", count);

	return 0;

}
