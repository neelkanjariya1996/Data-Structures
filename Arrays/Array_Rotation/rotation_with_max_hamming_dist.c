#include <stdio.h>
#include <stdlib.h>

void
print_array (int arr[], int n)
{

	int i = 0;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

int
maximum_hamming_dist (int arr[], int n)
{

	if (n == 1)
		return 0;

	int cpy_arr[n];
	int i 		= 0;
	int j 		= 0;
	int max_ham = 0;

	for (i = 0; i < (n); i++)
		cpy_arr[i] = arr[i];

	for (j = 0; j < n; j++) {

		int curr_ham	= 0;
		int temp 		= 0;

		temp = cpy_arr[0];
		for (i = 0; i < (n - 1); i++)
			cpy_arr[i] = cpy_arr[i + 1];
		cpy_arr[i] = temp;

		for (i = 0; i < (n); i++)
			if (cpy_arr[i] != arr[i])
				curr_ham++;

		if (curr_ham == n)
			return n;

		if (curr_ham > max_ham)
			max_ham = curr_ham;

	}

	return max_ham;

}

int
main ()
{

	int arr[] 	= {2, 1};
	int size 	= 0;
	int max_ham	= 0;

	size = (sizeof (arr))/(sizeof (int));

	print_array (arr, size);

	max_ham = maximum_hamming_dist (arr, size);
	printf("The maximu hamming distance is : %d\n", max_ham);

	return 0;

}
