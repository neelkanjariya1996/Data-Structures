#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct queue_t_ {

	int			front;
	int			rear;
	int 		size;
	unsigned 	capacity;
	int			*array;
} queue_t;

queue_t *
create_queue (unsigned capacity)
{

	queue_t *new_queue = NULL;

	new_queue = malloc (sizeof (queue_t));

	if (!new_queue) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	new_queue->capacity	= capacity;
	new_queue->front	= 0;
	new_queue->rear		= new_queue->capacity - 1;
	new_queue->size		= 0;
	new_queue->array	= malloc (new_queue->capacity * sizeof (int));

	if (!new_queue->array) {
	
		free (new_queue);
		return NULL;
	}

	return new_queue;

}

bool
is_full (queue_t *queue)
{

	return (queue->size == queue->capacity - 1);

}

bool
is_empty (queue_t *queue)
{

	return (queue->size == 0);

}

void
enqueue (queue_t *queue, int item)
{

	if (is_full (queue)) {
	
		printf ("Queue Overflow!\n");
		return;
	}

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size++;
	printf ("%d enqueued to the queue\n", item);

	return;

}

int
dequeue (queue_t *queue)
{

	if (is_empty (queue)) {
	
		printf ("Queue Underflow!\n");
		return INT_MIN;
	}

	int item = 0;

	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	
	return item;

}

int
front (queue_t *queue) 
{

	if (is_empty (queue)) {
	
		printf ("Queu Underflow!\n");
		return INT_MIN;
	}

	return queue->array[queue->front];

}

int
rear (queue_t *queue) 
{

	if (is_empty (queue)) {
	
		printf ("Queue Underflow!\n");
		return INT_MIN;
	}

	return queue->array[queue->rear];

}

int
main ()
{

	queue_t *queue = NULL;

	queue = create_queue (10);

	enqueue (queue, 0);
	enqueue (queue, 1);
	enqueue (queue, 2);
	enqueue (queue, 3);
	enqueue (queue, 4);
	
	printf ("%d dequeued from the queue\n", dequeue (queue));
	printf ("%d is at the front of the queue\n", front (queue));
	printf ("%d is at the rear of the queue\n", rear (queue));
	printf ("%d dequeued from the queue\n", dequeue (queue));
	printf ("%d is at the front of the queue\n", front (queue));
	printf ("%d is at the rear of the queue\n", rear (queue));
	printf ("%d dequeued from the queue\n", dequeue (queue));
	printf ("%d is at the front of the queue\n", front (queue));
	printf ("%d is at the rear of the queue\n", rear (queue));
	printf ("%d dequeued from the queue\n", dequeue (queue));
	printf ("%d is at the front of the queue\n", front (queue));
	printf ("%d is at the rear of the queue\n", rear (queue));
	printf ("%d dequeued from the queue\n", dequeue (queue));
	printf ("%d is at the front of the queue\n", front (queue));
	printf ("%d is at the rear of the queue\n", rear (queue));

	return 0;

}
