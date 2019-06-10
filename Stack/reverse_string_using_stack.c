#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct stack_node_t_ {

	int			top;
	unsigned	capacity;
	int			*array;
} stack_node_t;

stack_node_t*
create_stack (unsigned capacity)
{

	stack_node_t *stack = NULL;

	stack = malloc (sizeof (stack_node_t));

	if (!stack)
		return NULL;

	stack->top		= -1;
	stack->capacity = capacity;
	stack->array	= malloc (stack->capacity * sizeof (int));

	if (!stack->array)
		return NULL;

	return stack;

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

char
peek (stack_node_t *stack)
{

	return (stack->array[stack->top]);
	
}

void
push (stack_node_t *stack, char ch)
{

	if (is_full (stack))
		return;

	if (!is_full (stack))
		stack->array[++(stack->top)] = ch;

}

char
pop (stack_node_t *stack)
{

	if (is_empty (stack))
		return INT_MIN;

	return (stack->array[stack->top--]);

}

void
reverse (char str[])
{

	stack_node_t *stack = NULL;

	stack = create_stack (strlen (str));

	if (!stack)
		return;

	int i = 0;

	for (i = 0; i < strlen (str); i++)
		push (stack, str[i]);

	for (i = 0; i < strlen (str); i++)
		str[i] = pop (stack);

}

int
main ()
{

	char str[] = "GeeksQuiz";

	reverse (str);

	printf ("Reversed string is: %s\n", str);

	return 0;

}
