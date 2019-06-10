#include <stdio.h>
#include <stdlib.h>

void
rotated_array (int arr[], int n, int k)
{
	int mod = 0;
	int i 	= 0;

	mod = k % n;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[((mod + i) % n)]);
	}
	printf("\n");

}

void
print_array (int arr[], int n) 
{
	
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

int
main ()
{

	int arr[] 	= {1, 2, 3, 4, 5, 6, 7};
	int size	= 0;
	int k		= 0;

	size = (sizeof (arr))/(sizeof (int));

	print_array (arr, size);

	k = 8;
	rotated_array (arr, size, k);

	return 0;

}
