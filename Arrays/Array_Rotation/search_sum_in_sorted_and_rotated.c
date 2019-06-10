#include <stdio.h>
#include <stdlib.h>

int
is_sum (int arr[], int sum, int n)
{

	int l = 0;
	int r = 0;
	int i = 0;

	for (i = 0; i < (n - 1); i++) {
	
		if (arr[i + 1] < arr[i]) {
			break;	
		}

	}

	l = (i + 1) % n;
	r = i;

	while (l != r) {
	
		if (arr[l] + arr[r] == sum)
			return 1;

		if ((arr[l] + arr[r] < sum))
			l = (l + 1) % n;
		else
			r = (r + n - 1) % n;
	}
		
	return -1;

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
	
	int found 	= 0;
	int sum 	= 0;
	int arr[7] 	= {3, 4, 5, 6, 7, 1, 2};

	print_array (arr, 7);

	sum = 1;
	found = is_sum (arr, 7, sum);
	if (found == 1)
		printf("A pair is found in the array with sum = %d \n", sum);
	else
		printf("Pair not found in the array with sum = %d \n", sum);

	return 0;

}
