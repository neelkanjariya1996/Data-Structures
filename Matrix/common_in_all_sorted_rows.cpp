#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define R	4
#define C	5

int
find_common (int mat[R][C])
{

	unordered_map <int, int> count;
	int i = 0;
	int j = 0;

	for (i = 0; i < R; i++) {
	
		count[mat[i][0]]++;
		for (j = 1; j < C; j++) {
		
			if (mat[i][j] != mat[i][j - 1]) {
			
				count[mat[i][j]]++;
			}
		}
	}

	for (auto ele: count) {
	
		if (ele.second == R) {
		
			return ele.first;
		}
	}

	return -1;

}

void
print_matrix (int mat[R][C])
{

	int i = 0;
	int j = 0;

	for (i = 0; i < R; i++) {
	
		for (j = 0; j < C; j++) {
		
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

}

int
main ()
{

	int comm	= 0;
	int mat[R][C] = {
				   {1, 2, 3, 4, 5},
				   {6, 6, 7, 8, 9},
				   {10, 11, 1, 5, 7},
				   {1, 2, 3, 5, 4}
				   };

	cout << "Matrix: " << endl;
	print_matrix (mat);

	comm = find_common (mat);

	if (comm != -1) {
	
		cout << "The common element in all the rows is: " << comm << endl;
	} else {
	
		cout << "There is no common element among the rows of the given matrox" << endl;
	}

	return 0;

}
