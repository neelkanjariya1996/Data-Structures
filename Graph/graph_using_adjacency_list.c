#include <stdio.h>
#include <stdlib.h>

typedef struct adj_list_node_t_ {

	int						dest;
	struct adj_list_node_t_ *next;
} adj_list_node_t;

typedef struct adj_list_t_ {

	adj_list_node_t *head;
} adj_list_t;

typedef struct graph_t_ {

	int			V;
	adj_list_t 	*array;
} graph_t;

adj_list_node_t *
create_adj_list_node_t (int dest)
{

	adj_list_node_t *new_node = NULL;

	new_node = malloc (sizeof (adj_list_node_t));

	if (!new_node) {
	
		printf ("Memory Allocation Failed!!\n");
		return NULL;
	}

	new_node->dest = dest;
	new_node->next = NULL;

	return new_node;

}

graph_t *
create_graph_t (int V)
{

	graph_t *graph = NULL;

	graph = malloc (sizeof (graph_t));

	if (!graph) {
	
		printf ("Memory Allocation Failed!!\n");
		return NULL;
	}

	graph->V		= V;
	graph->array	= malloc (graph->V * sizeof (adj_list_t));
	
	if (!graph->array) {
	
		free (graph);
		return NULL;
	}

	int i = 0;
	for (i = 0; i < graph->V; i++) {
	
		graph->array[i].head = NULL;
	}

	return graph;

}

void
add_edge (graph_t *graph, int src, int dest)
{

	adj_list_node_t *new_node = NULL;

	new_node 				= create_adj_list_node_t (dest);
	new_node->next			= graph->array[src].head;
	graph->array[src].head	= new_node;

	new_node				= create_adj_list_node_t (src);
	new_node->next			= graph->array[dest].head;
	graph->array[dest].head	= new_node;

}

void
print_graph (graph_t *graph)
{

	int v = 0;

	for (v = 0; v < graph->V; v++) {
	
		adj_list_node_t *pcrawl = NULL;

		pcrawl = graph->array[v].head;
		printf ("\nAdjacency list of vertex %d\n", v);
		printf ("head");
		while (pcrawl) {
		
			printf ("-> %d ", pcrawl->dest);
			pcrawl = pcrawl->next;
		}
		printf ("\n");
	}

}

int
main ()
{

	int V			= 0;
	graph_t *graph 	= NULL;

	V		= 5;
	graph	= create_graph_t (V);

	add_edge (graph, 0, 1);
	add_edge (graph, 0, 4);
	add_edge (graph, 1, 2);
	add_edge (graph, 1, 3);
	add_edge (graph, 1, 4);
	add_edge (graph, 2, 3);
	add_edge (graph, 3, 4);

	print_graph (graph);

	return 0;

}
