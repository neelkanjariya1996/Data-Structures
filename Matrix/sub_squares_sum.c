#include <stdio.h>
#include <stdlib.h>

#define N	5

void
print_sum (int mat[][N], int k)
{

	int strip_sum[N][N];
	int sum = 0;
	int i	= 0;
	int j	= 0;

	if (k > N) {
	
		printf ("k cannot be greater than N\n");
		return;
	}

	for (j = 0; j < N; j++) {
	
		sum = 0;

		for (i = 0; i < k; i++) {
		
			sum = sum + mat[i][j];
		}
		strip_sum[0][j] = sum;

		for (i = 1; i < (N - k + 1); i++) {
		
			sum 			= sum + mat[i + k - 1][j] - mat[i - 1][j];
			strip_sum[i][j] = sum;
		}

	}

	for (i = 0; i < (N - k + 1); i++) {
	
		sum = 0;

		for (j = 0; j < k; j++) {
		
			sum = sum + strip_sum[i][j];
		}
		printf ("%d ", sum);
	
		for (j = 1; j < (N - k + 1); j++) {
		
			sum = sum + strip_sum[i][j + k - 1] - strip_sum[i][j - 1];
			printf ("%d ", sum);
		}

		printf ("\n");
	}

}

int
main ()
{

	int mat[N][N] = {
					{1, 1, 1, 1, 1},
					{2, 2, 2, 2, 2},
					{3, 3, 3, 3, 3},
					{4, 4, 4, 4, 4},
					{5, 5, 5, 5, 5}
					};
	int k = 0;

	k = 3;
	print_sum (mat, k);

	return 0;

}
