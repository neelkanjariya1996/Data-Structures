#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_node_t_ {

	int		 top;
	unsigned capacity;
	int 	 *array;
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
	stack->array	= malloc (stack->capacity * sizeof (stack_node_t));

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
push (stack_node_t *stack, char op)
{

	if (!is_full (stack))
		stack->array[++stack->top] = op;

}

char
pop (stack_node_t *stack)
{

	if (!is_empty (stack))
		return (stack->array[stack->top--]);
	return '$';

}

int
postfix_evaluation (char *exp)
{

	stack_node_t *stack = NULL;

	stack = create_stack (strlen (exp));

	if (!stack)
		return -1;

	for (int i = 0; exp[i]; i++) {
	
		if (isdigit (exp[i]))
			push (stack, exp[i] - '0');
		else {
		
			int val1 = pop (stack);
			int val2 = pop (stack);
			switch (exp[i]) {
			
				case '+':
					push (stack, (val2 + val1));
					break;
				case '-':
					push (stack, (val2 - val1));
					break;
				case '*':
					push (stack, (val2 * val1));
					break;
				case '/':
					push (stack, (val2/val1));
					break;
			}
		}
	}

	return (pop (stack));

}

int
main ()
{

	char exp[] = "231*+9-";
	
	printf ("Postfix Evaluation: %d\n",postfix_evaluation (exp));

	return 0;

}
