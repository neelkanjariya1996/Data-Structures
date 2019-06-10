#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_node_t_ {

	int			top;
	unsigned	capacity;
	int			*array;

} stack_node_t;

stack_node_t*
create_stack (unsigned capacity)
{

	stack_node_t *new_node = NULL;

	new_node = malloc (sizeof (stack_node_t));

	if (!new_node)
		return NULL;

	new_node->top		= -1;
	new_node->capacity 	= capacity;
	new_node->array 	= malloc (new_node->capacity * sizeof (int));

	return new_node;

}

int
is_full (stack_node_t *stack)
{

	return (stack->top == (stack->capacity - 1));

}

int
is_empty (stack_node_t *stack)
{

	return (stack->top == -1);

}

void
push (stack_node_t *stack, int item)
{

	if (is_full (stack))
		return;
	
	stack->array[++stack->top] = item;
	printf ("%d has been pushed to stack\n", item);

}

int
pop (stack_node_t *stack)
{

	if (is_empty (stack))
		return INT_MIN;

	return stack->array[stack->top--];

}

int 
main ()
{

	stack_node_t *stack = NULL;

	stack = create_stack (100);

	push (stack, 10);
	push (stack, 20);
	push (stack, 30);
	push (stack, 40);
	push (stack, 50);

	printf ("%d popped from stack\n", pop(stack));
	printf ("%d popped from stack\n", pop(stack));
	printf ("%d popped from stack\n", pop(stack));
	printf ("%d popped from stack\n", pop(stack));
	printf ("%d popped from stack\n", pop(stack));
	printf ("%d popped from stack\n", pop(stack));

	return 0;

}
