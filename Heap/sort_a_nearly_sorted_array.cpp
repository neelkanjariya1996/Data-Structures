#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void
sort_k (int arr[], int n, int k)
{

	priority_queue <int, vector <int>, greater <int>> pq (arr, arr + k + 1);

	int index 	= 0;
	int i		= 0;

	for (i = (k + 1); i < n; i++) {
	
		arr[index] = pq.top ();
		index++;
		pq.pop ();
		pq.push (arr[i]);
	}

	while (pq.empty () == false) {
	
		arr[index] = pq.top ();
		index++;
		pq.pop ();
	}

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

int
main ()
{

	int arr[] 	= {2, 6, 3, 12, 56, 8};
	int n		= 0;
	int k		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Before Sorting: ");
	print_array (arr, n);

	k = 3;
	sort_k (arr, n, k);

	printf ("After  Sorting: ");
	print_array (arr, n);

	return 0;

}
