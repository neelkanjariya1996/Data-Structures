#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct two_stacks_t_ {

	int			top1;
	int 		top2;
	unsigned	capacity;
	int			*array;
} two_stacks_t;

two_stacks_t*
create_two_stacks (unsigned capacity)
{

	two_stacks_t *stack = NULL;

	stack = malloc (sizeof (two_stacks_t));

	if (!stack)
		return NULL;

	stack->top1		= -1;
	stack->top2		= capacity;
	stack->capacity	= capacity;
	stack->array	= malloc (stack->capacity * sizeof (int));

	if (!stack->array)
		return NULL;

	return stack;

}

void
push1 (two_stacks_t *stack, int x)
{

	if (stack->top1 < stack->top2 - 1) {
	
		stack->top1++;
		stack->array[stack->top1] = x;
		printf ("%d pushed to stack 1\n", x);
	} else {
	
		printf ("Stack Overflow\n");
		return;
	}

}

void
push2 (two_stacks_t *stack, int x)
{

	if (stack->top1 < stack->top2 - 1) {
	
		stack->top2--;
		stack->array[stack->top2] = x;
		printf ("%d pushed to stack 2\n", x);
	} else {
	
		printf ("Stack Overflow\n");
		return;
	}

}

int
pop1 (two_stacks_t *stack)
{

	if (stack->top1 >= 0) {
	
		int x = stack->array[stack->top1];
		stack->top1--;
		return x;
	} else {
	
		printf ("Stack Underflow\n");
		return -1;
	}

}

int
pop2 (two_stacks_t *stack)
{

	if (stack->top2 < stack->capacity) {
	
		int x = stack->array[stack->top2];
		stack->top2++;
		return x;
	} else {
	
		printf ("Stack Underflow\n");
		return -1;
	}

}

int
main ()
{

	two_stacks_t *stack = NULL;

	stack = create_two_stacks (5);

	push1 (stack, 5);
	push2 (stack, 10);
	push2 (stack, 15);
	push1 (stack, 11);
	push2 (stack, 7);

	printf ("Popped element from stack 1 is : %d \n", pop1 (stack));

	push2 (stack, 40);

	printf ("Popped element from stack 2 is : %d\n", pop2 (stack));

	return 0;

}
