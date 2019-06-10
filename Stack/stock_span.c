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

	stack_node_t *new_stack = NULL;

	new_stack = malloc (sizeof (stack_node_t));

	if (!new_stack) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	new_stack->top		= -1;
	new_stack->capacity	= capacity;
	new_stack->array	= malloc (capacity * sizeof (int));

	if (!new_stack->array) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	return new_stack;

}

int
is_empty (stack_node_t *stack)
{

	return (stack->top == -1);

}

int
is_full (stack_node_t *stack)
{

	return (stack->top == (stack->capacity - 1));

}

void
push (stack_node_t *stack, int data)
{

	if (is_full (stack)) {
	
		return;
	}

	stack->array[++stack->top] = data;

}

int
pop (stack_node_t *stack)
{

	if (is_empty (stack)) {
	
		return INT_MIN;
	}

	return (stack->array[stack->top--]);
		
}

void
stock_span (int price[], int n, int s[])
{

	stack_node_t *stack = NULL;

	stack = create_stack (n);

	push (stack, 0);

	s[0] = 1;

	int i = 0;

	for (i = 1; i < n; i++) {
	
		while (!is_empty (stack) && price[stack->array[stack->top]] <= price[i]) {
		
			pop (stack);
		}

		s[i] = (is_empty (stack)) ? (i + 1) : (i - stack->array[stack->top]);

		push (stack, i);
	}
}

void
print_array (int s[], int n)
{

	int i = 0;

	for (i = 0; i < n; i++) {
	
		printf ("%d ",s[i]);
	}
	printf ("\n");

}

int
main ()
{

	int price[] = {80, 70, 60, 50, 40, 30, 20, 100};
	int n = 0;
	
   	n = sizeof (price)/ sizeof (int);
	
	int s[n];

	stock_span (price, n, s);

	print_array (s, n);

	return 0;

}
