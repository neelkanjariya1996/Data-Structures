#include <stdio.h>
#include <stdlib.h>

typedef struct deque_t_ {

	int size;
	int front;
	int rear;
	int *arr;
}deque_t;

deque_t*
create_deque (int size)
{

	deque_t *dq = NULL;

	dq = malloc (sizeof (deque_t));

	if (!dq) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	dq->size = size;
	dq->front	= -1;
	dq->rear	= 0;
	dq->arr		= malloc (dq->size * sizeof (int));

	if (!dq->arr) {
	
		free (dq);
		return NULL;
	}

	return dq;

}

int
is_full (deque_t *dq)
{

	return ((dq->front == 0 && dq->rear == (dq->size - 1)) ||
			dq->front == (dq->rear + 1));

}

int
is_empty (deque_t *dq)
{

	return (dq->front == -1);

}

void
insert_front (deque_t *dq, int data)
{

	if (is_full (dq)) {
	
		printf ("Deque Overflow!\n");
		return;
	}

	if (dq->front == -1) {
	
		dq->front = 0;
		dq->rear  = 0;
	} else if (dq->front == 0) {
	
		dq->front = dq->size - 1;
	} else {
	
		dq->front = dq->front - 1;
	}

	dq->arr[dq->front] = data;

}

void
insert_rear (deque_t *dq, int data)
{

	if (is_full (dq)) {
	
		printf ("Deque Overflow!\n");
		return;
	}

	if (dq->front == -1) {
	
		dq->front	= 0;
		dq->rear	= 0;
	} else if (dq->rear == (dq->size - 1)) {
	
		dq->rear = 0;
	} else {
	
		dq->rear = dq->rear + 1;
	}

	dq->arr[dq->rear] = data;

}

void
delete_front (deque_t *dq)
{

	if (is_empty (dq)) {
	
		printf ("Deque Underflow!\n");
		return;
	}

	if (dq->front == dq->rear) {
	
		dq->front 	= -1;
		dq->rear	= -1;
	} else if (dq->front == (dq->size - 1)) {
	
		dq->front = 0;
	} else {
	
		dq->front = dq->front + 1;
	}

}

void
delete_rear (deque_t *dq)
{

	if (is_empty (dq)) {
	
		printf ("Deque Underflow!\n");
		return;
	}

	if (dq->front == dq->rear) {
	
		dq->front 	= -1;
		dq->rear	= -1;
	} else if (dq->rear == 0) {
	
		dq->rear = dq->size - 1;
	} else {
	
		dq->rear = dq->rear - 1;
	}

}

int
get_front (deque_t *dq)
{

	if (is_empty (dq)) {
	
		printf ("Deque Underflow!\n");
		return -1;
	}

	return dq->arr[dq->front];

}

int 
get_rear (deque_t *dq)
{

	if (is_empty (dq) || dq->rear < 0) {
	
		printf ("Deque Underflow!\n");
		return -1;
	}

	return dq->arr[dq->rear];

}

int
main ()
{

	deque_t *dq = NULL;

	dq = create_deque (5);

	printf ("Insert %d at rear end\n", 5);
	insert_rear (dq, 5);

	printf ("Insert %d at rear end\n", 10);
	insert_rear (dq, 10);

	printf ("Get rear element: %d\n", get_rear (dq));

	printf ("Delete rear element\n");
	delete_rear (dq);

	printf ("Get rear element: %d\n", get_rear (dq));

	printf ("Insert %d at front end\n", 15);
	insert_front (dq, 15);

	printf ("Get front element: %d\n", get_front (dq));

	printf ("Delete front element\n");
	delete_front (dq);

	printf ("Get front element: %d\n", get_front (dq));

	return 0;

}
