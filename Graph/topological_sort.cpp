#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{

	int V;
	list <int> *adj;
	void topological_sort_util (int v, bool visited [], stack <int> &stack);

	public: 
		Graph (int V);
		void add_edge (int v, int w);
		void print_topological_sort ();

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
Graph :: topological_sort_util (int v, bool visited [], stack <int> &stack)
{

	visited[v] = true;

	list <int> :: iterator i;

	for (i = adj[v].begin (); i != adj[v].end (); i++) {
	
		if (! (visited[*i])) {
		
			topological_sort_util (*i, visited, stack);
		}
	}

	stack.push (v);

}

void
Graph :: print_topological_sort ()
{

	bool *visited = new bool [V];

	int i = 0;

	for (i = 0; i < V; i++) {
	
		visited[i] = false;
	}

	stack <int> stack;

	for (i = 0; i < V; i++) {
	
		if (! (visited[i])) {
		
			topological_sort_util (i, visited, stack);
		}
	}

	while (stack.empty() == false) {
	
		cout << stack.top () << " ";
		stack.pop ();
	}
	cout << endl;

}

int
main ()
{

	Graph g(6);

	g.add_edge (5, 2);
	g.add_edge (5, 0);
	g.add_edge (4, 0);
	g.add_edge (4, 1);
	g.add_edge (2, 3);
	g.add_edge (3, 1);
	
	cout << "Topological sort for the graph is: ";
	g.print_topological_sort ();

	return 0;

}
