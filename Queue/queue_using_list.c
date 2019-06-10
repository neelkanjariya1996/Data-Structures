#include <stdio.h>
#include <stdlib.h>

typedef struct q_node_t_ {

	int					key;
	struct q_node_t_	*next;
}q_node_t;

typedef struct queue_t_ {

	q_node_t *front;
	q_node_t *rear;
}queue_t;

q_node_t*
create_q_node (int k)
{

	q_node_t *new_node = NULL;

	new_node = malloc (sizeof (q_node_t));

	if (!new_node) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	new_node->key	= k;
	new_node->next	= NULL;

	return new_node;

}

queue_t*
create_queue ()
{

	queue_t *q = NULL;

	q = malloc (sizeof (queue_t));

	if (!q) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	q->front	= NULL;
	q->rear		= NULL;

	return q;

}

void
enqueue (queue_t *q, int item)
{

	q_node_t *temp = NULL;

	temp = create_q_node (item);

	if (q->rear == NULL) {
	
		q->rear 	= temp;
		q->front	= temp;
		return;
	}	

	q->rear->next	= temp;
	q->rear			= temp;

}

q_node_t*
dequeue (queue_t *q)
{

	if (q->front == NULL) {
	
		return NULL;
	}

	q_node_t *temp 	= NULL;
	temp			= q->front;
	q->front		= q->front->next;

	if (q->front == NULL) {
	
		q->rear = NULL;
	}

	return temp;

}

int
main ()
{

	queue_t *q = NULL;

	q = create_queue ();

	enqueue (q, 10);
	enqueue (q, 20);
	dequeue (q);
	dequeue (q);
	enqueue (q, 30);
	enqueue (q, 40);
	enqueue (q, 50);

	q_node_t *temp = NULL;
	
	temp = dequeue (q);
	if (temp != NULL) {
		printf ("%d dequeued from the queue\n", temp->key);
	}

	return 0;

}
