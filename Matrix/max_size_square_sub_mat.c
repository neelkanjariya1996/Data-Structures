#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define R	6
#define C	5

int
min (int a, int b, int c)
{

	int m = 0;

	m = a;
	if (b < m) {
	
		m = b;
	}
	if (c < m) {
	
		m = c;
	}

	return m;

}

void
print_max_size_sub_mat (bool mat[R][C])
{

	int s[R][C];
	int i 		= 0;
	int j 		= 0;
	int max_i	= 0;
	int max_j	= 0;
	int max_s	= 0;

	for (i = 0; i < R; i++) {
	
		s[i][0] = mat[i][0];
	}

	for (i = 0; i < C; i++) {
	
		s[0][i] = mat[0][i];
	}

	for (i = 1; i < R; i++) {
	
		for (j = 1; j < C; j++) {
		
			if (mat[i][j] == 1) {
			
				s[i][j] = min (s[i][j - 1], s[i - 1][j], s[i - 1][j - 1]) + 1;
			} else {
			
				s[i][j] = 0;
			}
		}
	}

	max_s = s[0][0];
	for (i = 0; i < R; i++) {
	
		for (j = 0; j < C; j++) {
		
			if (max_s < s[i][j]) {
			
				max_s = s[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	for (i = max_i; i > (max_i - max_s); i--) {
	
		for (j = max_j; j > (max_j - max_s); j--) {
		
			printf ("%d ", mat[i][j]);
		}
		printf ("\n");
	}

}

int
main ()
{

	bool mat[R][C] = {
					 {0, 1, 1, 0, 1},
					 {1, 1, 0, 1, 0},
					 {0, 1, 1, 1, 0},
					 {1, 1, 1, 1, 0},
					 {1, 1, 1, 1, 1},
					 {0, 0, 0, 0, 0}
					 };

	print_max_size_sub_mat (mat);

	return 0;

}
