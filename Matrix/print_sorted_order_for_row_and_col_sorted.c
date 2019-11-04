#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF	INT_MAX
#define N	4

void
youngify (int mat[][N], int i, int j)
{

	int down_val 	= 0;
	int right_val	= 0;

	down_val 	= ((i + 1) < N) ? mat[i + 1][j] : INF;
	right_val	= ((j + 1) < N) ? mat[i][j + 1] : INF;

	if ((down_val == INF) && (right_val == INF)) {
	
		return;
	}

	if (down_val < right_val) {

		mat[i][j] 		= down_val;
		mat[i + 1][j] 	= INF;
		youngify (mat, (i + 1), j);
	} else if (down_val >= right_val) {
	
		mat[i][j]		= right_val;
		mat[i][j + 1]	= INF;
		youngify (mat, i, (j + 1));
	}

}

int
extract_min (int mat[][N])
{

	int ret = 0;

	ret = mat[0][0];
	mat[0][0] = INF;
	youngify (mat, 0, 0);
	return ret;

}

void
print_sorted (int mat[][N])
{

	int i = 0;

	for (i = 0; i < (N * N); i++) {
	
		printf ("%d ", extract_min (mat));	
	}
	printf ("\n");

}

int
main ()
{

	int mat[N][N] = {
					{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}
					};

	print_sorted (mat);

	return 0;

}
