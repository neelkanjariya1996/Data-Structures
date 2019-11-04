#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void
first_k_elements (int arr[], int n, int k)
{

	sort (arr, arr + n, greater <int>());

	int i = 0;
	for (i = 0; i < k; i++) {
	
		cout << arr[i] << " ";
	}
	cout << endl;

}

int
main ()
{

	int arr[] 	= {-4, 8, 2, 100, 32, 67, 29, 0, -23, 56};
	int n		= 0;
	int k		= 0;

	n = sizeof (arr) / sizeof (int);

	k = 3;
	first_k_elements (arr, n, k);

	return 0;

}
