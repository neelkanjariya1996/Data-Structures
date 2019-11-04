#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define R	4
#define C	5

void
print_unique_rows (bool mat[][5])
{

	unordered_set<string> set;
	int i = 0;
	int j = 0;

	for (i = 0; i < R; i++) {
	
		string s = "";

		for (j = 0; j < C; j++) {
		
			s = s + to_string (mat[i][j]);
		}

		if (set.count (s) == 0) {
		
			set.insert (s);
			cout << s << endl;
		}
	}

}

void
print_matrix (bool mat[R][C]) 
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

	bool mat[R][C] = {
					 {0, 1, 1, 0, 1},
					 {1, 0, 1, 0, 1},
					 {0, 1, 0, 1, 0},
					 {0, 1, 1, 0, 1} 
					 };

	cout << "Matrix: " << endl;
	print_matrix (mat);

	cout << "Unique Rows: " << endl;
	print_unique_rows (mat);

	return 0;

}
