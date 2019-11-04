#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph 
{

	int V;
	list <int> *adj;
	bool is_cyclic_util (int v, bool visited [], int parent);

	public:
		Graph (int V);
		void add_edge (int v, int w);
		bool is_cyclic ();

};

Graph :: Graph (int V)
{

	this->V = V;
	adj		= new list <int> [V];

}

void
Graph :: add_edge (int v, int w)
{

	adj[v].push_back (w);
	adj[w].push_back (v);

}

bool
Graph :: is_cyclic_util (int v, bool visited [], int parent)
{

	visited[v] = true;

	list <int> :: iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); i++) {
	
		if (! (visited[*i])) {
		
			if (is_cyclic_util (*i, visited, v)) {
					
				return true;				
			}
		} else if (*i != parent) {
		
			return true;
		}
	}

	return false;

}

bool
Graph :: is_cyclic ()
{

	bool *visited = new bool [V];

	int i = 0;
	for (i = 0; i < V; i++) {
	
		visited[i] = false;
	}

	for (i = 0; i < V; i++) {
	
		if (!visited[i]) {
		
			if (is_cyclic_util (i, visited, -1)) {
			
				return true;
			}
		}
	}

	return false;

}

int
main ()
{

	Graph g1(5);

	g1.add_edge(1, 0);
	g1.add_edge(0, 2);
	g1.add_edge(2, 0);
	g1.add_edge(0, 3);
	g1.add_edge(3, 4);

	if (g1.is_cyclic ()) {
	
		cout << "cycle detected for graph 1" << endl;
	} else {
	
		cout << "cycle not detected for graph 1" << endl;
	}

	Graph g2(3);

	g2.add_edge (0, 1);
	g2.add_edge (1, 2);

	if (g2.is_cyclic ()) {
	
		cout << "cycle detected for graph 2" << endl;
	} else {
	
		cout << "cycle not detected for graph 2" << endl;
	}

	return 0;

}
