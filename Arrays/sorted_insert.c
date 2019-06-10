#include <stdio.h>
#include <stdlib.h>

int
sorted_insert (int arr[], int n, 
			   int key, int capacity)
{

	if (n >= capacity) {
	
		printf ("Cannot insert the element in the array\n");
		return n;
	}

	int  i = 0;

	for (i = (n - 1); (i >= 0 && arr[i] > key); i--) {
	
		arr[i + 1] = arr[i];
	}

	arr[i + 1] = key;

	return (n + 1);

}

void
print_array (int arr[], int n)
{

	int i = 0;
	for (i = 0; i < n; i++) {
	
		printf ("%d ", arr[i]);
	}
	printf ("\n");

}

int main ()
{

	int arr[20] 	 = {1, 2, 4, 5, 6, 7};
	int n			 = 0;
	int capacity	 = 0;
	int key			 = 0;

	capacity = sizeof (arr) / sizeof (int);
	n 		 = 6;
	key		 = -3;

	printf ("Before Insertion: ");
	print_array (arr, n);

	n = sorted_insert (arr, n, key, capacity);

	printf ("After Insertion:  ");
	print_array (arr, n);

	return 0;

}
