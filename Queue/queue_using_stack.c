#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_t_ {

	int				key;
	struct stack_t_	*next;
} stack_t;

stack_t *
create_stack (int key)
{

	stack_t *new_stack = NULL;

	new_stack = malloc (sizeof (stack_t));

	if (!new_stack) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	new_stack->key	= key;
	new_stack->next	= NULL;

	return new_stack;

}

int
is_empty (stack_t *root)
{

	return (!root);

}

void
push (stack_t **root, int key)
{

	if (*root == NULL) {

		*root = create_stack (key);	
		return;
	}

	if (!is_empty (*root)) {
	
		stack_t *temp 	= create_stack (key);
		temp->next		= *root;
		*root			= temp;
	}

}

int
pop (stack_t **root)
{

	if (*root == NULL) {
	
		return INT_MIN;
	}

	if (!is_empty (*root)) {
	
		int popped 		= 0;
		stack_t *temp 	= NULL;

		temp 	= *root;
		*root	= (*root)->next;
		popped	= temp->key;
		free (temp);
		return popped;
	}

}

int
top (stack_t *root)
{

	if (is_empty (root)) {
	
		return INT_MIN;
	}

	return (root->key);

}

typedef struct queue_t_ {

	stack_t *s1;
	stack_t *s2;
}queue_t;

queue_t*
create_queue ()
{

	queue_t *q = NULL;

	q = malloc (sizeof (queue_t));

	if (!q) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	q->s1 = NULL;
	q->s2 = NULL;

	return q;

}

void
enqueue (queue_t *q, int key)
{

	if (q == NULL) {
	
		return;
	}

	while (!is_empty (q->s1)) {
	
		push (&(q->s2), top (q->s1));
		pop (&(q->s1));
	}

	push (&(q->s1), key);
	printf ("%d enqueued to the queue\n", q->s1->key);

	while (!is_empty (q->s2)) {
	
		push (&(q->s1), top (q->s2));
		pop (&(q->s2));
	}

}

int
dequeue (queue_t *q)
{

	if (is_empty (q->s1)) {
	
		printf ("Queue is empty\n");
		return INT_MIN;
	}

	int x = 0;

	x = top (q->s1);
	pop (&(q->s1));
	return x;

}

int
main ()
{

	queue_t *q = NULL;

	q = create_queue ();

	enqueue (q, 1);
	enqueue (q, 2);
	enqueue (q, 3);

	printf ("%d dequeued from the queue\n", dequeue (q));
	printf ("%d dequeued from the queue\n", dequeue (q));
	printf ("%d dequeued from the queue\n", dequeue (q));
	printf ("%d dequeued from the queue\n", dequeue (q));

	return 0;

}
