#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

#define V	4

bool
is_bipartite_util (int G[][V], int src, int color_arr [])
{

	color_arr [src] = 1;

	queue <int> q;
	q.push (src);

	while (! (q.empty ())) {
	
		int u = q.front ();
		q.pop ();

		if (G[u][u] == 1) {
		
			return false;
		}

		int v = 0;
		for (v = 0; v < V; v++) {
		
			if (G[u][v] && (color_arr[v] == -1)) {
			
				color_arr [v] = 1 - color_arr [u];
				q.push (v);
			} else if (G[u][v] && (color_arr [u] == color_arr [v])) {
			
				return false;
			}
		}
	}

	return true;

}

bool
is_bipartite (int G[][V])
{

	int color_arr [V];

	int i = 0;
	for (i = 0; i < V; i++) {
	
		color_arr [i] = -1;
	}

	for (i = 0; i < V; i++) {
	
		if (color_arr [i] == -1) {
		
			if (is_bipartite_util (G, i, color_arr) == false) {
			
				return false;
			}
		}
	}

	return true;

}

int 
main ()
{

	int G[V][V] = 	{
					{0, 0, 1, 1},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}
					};

	if (is_bipartite (G)) {
	
		cout << "Bipartite" << endl;
	} else {
	
		cout << "Not Bipartite" << endl;
	}

	return 0;

}
