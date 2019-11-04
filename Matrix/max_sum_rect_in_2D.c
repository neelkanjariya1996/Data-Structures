#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ROW		4
#define COL		5

int
kadane (int arr[], int *start, int *finish, int n)
{

	int max_sum 	= INT_MIN;
	int sum			= 0;
	int local_start	= 0;
	int i			= 0;

	*finish = -1;

	for (i = 0; i < n; i++) {
	
		sum = sum + arr[i];

		if (sum < 0) {
		
			sum 		= 0;
			local_start = i + 1;
		} else if (sum >= max_sum) {
	
			max_sum = sum;
			*start	= local_start;
			*finish	= i;
		}
	}

	if (*finish != -1) {
	
		return max_sum;
	}

	max_sum = arr[0];
	*start	= 0;
	*finish	= 0;

	for (i = 1; i < n; i++) {
	
		if (max_sum < arr[i]) {
		
			max_sum = arr[i];
			*start	= i;
			*finish	= i;
		}
	}

	return max_sum;

}

void
max_sum_rect (int mat[ROW][COL])
{

	int max_sum			= INT_MIN;
	int final_left		= 0;
	int final_right		= 0;
	int final_top		= 0;
	int final_bottom	= 0;
	int i 				= 0;
	int left			= 0;
	int right			= 0;
	int start			= 0;
	int finish			= 0;
	int sum				= 0;
	int temp[ROW];

	for (left = 0; left < COL; left++) {
	
		memset (temp, 0, sizeof (temp));

		for (right = left; right < COL; right++) {
		
			for (i = 0; i < ROW; i++) {
			
				temp[i] = temp[i] + mat[i][right];
			}

			sum = kadane (temp, &start, &finish, ROW);

			if (sum > max_sum) {
			
				max_sum 		= sum;
				final_left		= left;
				final_right		= right;
				final_top		= start;
				final_bottom	= finish;
			}

		}

	}

	printf ("(Top, Left)\t(%d, %d)\n", final_top, final_left);
	printf ("(Bottom, Right)\t(%d, %d)\n", final_bottom, final_right);
	printf ("Maximum sum rectangle in 2D is : %d\n", max_sum);

}

int
main ()
{

	int mat[ROW][COL] = {
						{1, 2, -1, -4, -20},
						{-8, -3, 4, 2, 1},
						{3, 8, 10, 1, 3},
						{-4, -1, 1, 7, -6}
						};

	max_sum_rect (mat);

	return 0;

}
