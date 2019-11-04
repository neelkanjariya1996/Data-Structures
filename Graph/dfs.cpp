#include <iostream>
#include <list>

using namespace std;

class Graph 
{

	int V;
	list <int> *adj;

	void dfs_util (int v, bool visited[]);
	public:
		Graph (int V);
		void add_edge (int v, int w);
		void dfs (int v);

};

Graph :: Graph (int V)
{

	this->V	= V;
	adj		= new list <int> [V];

}

void
Graph :: add_edge (int v, int w)
{

	adj[v].push_back (w);

}

void
Graph :: dfs_util (int v, bool visited[])
{

	visited[v] = true;
	cout << v << " ";

	list <int> :: iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); i++) {
	
		if (! (visited [*i])) {
		
			dfs_util (*i, visited);
		}
	}

}

void
Graph :: dfs (int v)
{

	bool *visited = new bool [V];

	for (int i = 0; i < V; i++) {
	
		visited[i] = false;
	}

	dfs_util (v, visited);

}

int
main ()
{

	Graph g(4);

	g.add_edge (0, 1);
	g.add_edge (0, 2);
	g.add_edge (1, 2);
	g.add_edge (2, 0);
	g.add_edge (2, 3);
	g.add_edge (3, 3);

	cout << "Depth First Traversal starting from vertex 2 " << endl;
	g.dfs (2);
	cout << endl;

	return 0;

}
