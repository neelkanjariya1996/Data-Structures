#include <stdio.h>
#include <stdlib.h>

int
max_sum (int arr[], int n)
{

	int i 			= 0;
	int curr_val 	= 0;
	int max_val		= 0;
	int arr_sum		= 0;

	for (i = 0; i < n; i++) {
		arr_sum = arr_sum + arr[i];
		curr_val = curr_val + (i * arr[i]);
	}

	max_val = curr_val;

	for (i = 1; i < n; i++) {
		curr_val = curr_val + arr_sum - (n * arr[n - i]);
		if (curr_val > max_val)
			max_val = curr_val;
	}

	return max_val;

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

	int max_val = 0;
	int arr[]	= {2, 10, 1, 20};

	print_array (arr, 4);

	max_val = max_sum (arr, 4);
	printf("The maximu value of the sum(i * arr[i]) is %d\n", max_val);

	return 0;

}
