#include <stdio.h>
#include <stdlib.h>

int
max_sum (int arr[], int n)
{
	int i 			= 0;
	int arr_sum 	= 0;
	int max_sum 	= 0;
	int curr_val 	= 0;
	int next_val 	= 0;

	for (i = 0; i < n; i++) {
		arr_sum 	= arr_sum + arr[i];
		curr_val 	= curr_val + (i * arr[i]);
	}

	max_sum = curr_val;

	for (i = 0; i < n; i++) {
		next_val = curr_val - (arr_sum - arr[i - 1]) + (arr[i - 1] * (n -1));
		curr_val = next_val;
		if (next_val > max_sum)
			max_sum = next_val;
	}

	return max_sum;

}

void
print_array (int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int
main ()
{
	int arr[] 	= {8, 3, 1, 2};
	int sum 	= 0;

	print_array (arr, 4);

	sum = max_sum (arr, 4);
	printf("%d \n", sum);

	return 0;

}
