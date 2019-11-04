#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct edge_t_ {

	int src;
	int dest;

} edge_t;

typedef struct graph_t_ {

	int 	V;
	int 	E;
	edge_t 	*edge;

} graph_t;

graph_t *
create_graph (int V, int E)
{

	graph_t *graph = NULL;

	graph = malloc (sizeof (graph_t));

	if (!graph) {
	
		printf ("Memory Allocation Failed!!\n");
		return NULL;
	}

	graph->V	= V;
	graph->E	= E;
	graph->edge	= malloc (graph->E * sizeof (edge_t));

	if (!graph->edge) {
	
		free (graph);
		return NULL;
	}

	return graph;

}

int
find_parent (int parent[], int i)
{

	if (parent[i] == -1) {
	
		return i;
	}

	return find_parent (parent, parent[i]);

}

void
union_of_two_subset (int parent[], int x, int y)
{

	int xset = 0;
	int yset = 0;

	xset = find_parent (parent, x);
	yset = find_parent (parent, y);

	if (xset != yset) {
	
		parent[xset] = yset;
	}

}

int
is_cyclic (graph_t *graph)
{

	int *parent = NULL;

	parent = malloc (graph->V * sizeof (int));
	memset (parent, -1, (graph->V * sizeof (int)));

	int i = 0;
	int x = 0;
	int y = 0;

	for (i = 0; i < graph->E; i++) {
	
		x = find_parent (parent, graph->edge[i].src);
		y = find_parent (parent, graph->edge[i].dest);

		if (x == y) {
		
			return 1;
		}
		
		union_of_two_subset (parent, x, y);	
	}

	return 0;

}

int
main ()
{

	int V 			= 0;
	int E 			= 0;
	graph_t *graph 	= NULL;

	V = 3;
	E = 3;

	graph = create_graph (V, E);

	graph->edge[0].src 	= 0;
	graph->edge[0].dest	= 1;

	graph->edge[1].src 	= 1;
	graph->edge[1].dest	= 2;

	graph->edge[2].src 	= 0;
	graph->edge[2].dest	= 2;

	if (is_cyclic (graph)) {
	
		printf ("Cycle Detected\n");
	} else {
	
		printf ("Cycle Not Detected\n");
	}

	return 0;

}
