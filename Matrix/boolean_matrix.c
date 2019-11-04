#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define R	3
#define C	4

void
boolean_matrix (bool mat[R][C])
{

	bool row[R];
	bool col[C];

	int i = 0;
	int j = 0;

	for (i = 0; i < R; i++) {
	
		row[i] = 0;
	}

	for (i = 0; i < C; i++) {
	
		col[i] = 0;
	}

	for (i = 0; i < R; i++) {
	
		for (j = 0; j < C; j++) {
		
			if (mat[i][j] == 1) {
			
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for (i = 0; i < R; i++) {
	
		for (j = 0; j < C; j++) {
		
			if ((row[i] == 1) || col[j] == 1) {
			
				mat[i][j] = 1;
			}
		}
	}

}

void
print_matrix (bool mat[R][C]) 
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

	bool mat[R][C] = {
					 {1, 0, 0, 1},
					 {0, 0, 1, 0},
					 {0, 0, 0, 0}
					 };

	printf ("Original Matrix: \n");
	print_matrix (mat);

	boolean_matrix (mat);

	printf ("Boolean Matrix: \n");
	print_matrix (mat);
	
	return 0;

}
