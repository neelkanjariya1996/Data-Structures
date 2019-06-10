#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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

void
push (stack_node_t *stack, char ch)
{

	if (is_full (stack))
		return;

	if (!is_full (stack)) {
	
		stack->array[++stack->top] = ch;
		return;
	}

}

char
pop (stack_node_t *stack)
{

	if (!is_empty (stack)) {
		
		return (stack->array[stack->top--]);
	}

}

int
is_matching_parentheses (char ch1, char ch2)
{

	if (ch1 == '(' && ch2 == ')')
		return 1;
	else if (ch1 == '{' && ch2 == '}')
		return 1;
	else if (ch1 == '[' && ch2 == ']')
		return 1;
	else
		return 0;

}

int
is_parantheses_balance (char exp[])
{

	stack_node_t *stack = NULL;

	stack = create_stack (strlen(exp));
	if (!stack)
		return 0;

	int  i = 0;

	while (exp[i]) {
	
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push (stack, exp[i]);

		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
		
			if (is_empty (stack))
				return 0;
			else if (!(is_matching_parentheses (pop(stack), exp[i])))
				return 0;
		}
		
		i++;
	}

	if (is_empty (stack))
		return 1;
	else 
		return 0;

}

int
main ()
{

	char exp[] = "{}()()([({[]()})])";

	if (is_parantheses_balance (exp))
		printf ("The parantheses are balanced\n");
	else
		printf ("The parantheses are not balanced\n");

	return 0;

}
