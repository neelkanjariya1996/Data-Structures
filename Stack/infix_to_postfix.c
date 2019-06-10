#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct stack_node_t_ {

	int			top;
	unsigned 	capacity;
	int 		*array;
} stack_node_t;

stack_node_t*
create_stack (unsigned capacity)
{

	stack_node_t *stack = NULL;

	stack = malloc (sizeof (stack_node_t));

	if (!stack)
		return NULL;

	stack->top		= -1;
	stack->capacity	= capacity;
	stack->array	= malloc (stack->capacity * sizeof (int));

	if (!stack->array)
		return NULL;

	return stack;

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

char
peek (stack_node_t *stack)
{

	return (stack->array[stack->top]);

}

char
push (stack_node_t *stack, char op)
{

	stack->array[++stack->top] = op;

}

char
pop (stack_node_t *stack)
{

	if (is_empty (stack))
		return INT_MIN;

	if (!is_empty (stack))
		return (stack->array[stack->top--]);

	return '$';

}

int
is_operand (char ch)
{

	return ((ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z'));

}

int
precedence (char ch)
{
	
	switch (ch) {
	
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;
	}

	return -1;

}

int
infix_to_postfix (char *exp)
{

	int i = 0;
	int k = 0;

	stack_node_t *stack = NULL;

	stack = create_stack (strlen (exp));

	if (!stack)
		return -1;

	for (i = 0, k = -1; exp[i]; i++) {
	
		if (is_operand (exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push (stack, exp[i]);
		else if (exp[i] == ')') {
		
			while ((!is_empty (stack)) && (peek (stack) != '('))
				exp[++k] = pop (stack);
			if ((!is_empty (stack)) && (peek (stack) != '('))
				return -1;
			else
				pop (stack);
		} else {
		
			while ((!is_empty (stack)) && (precedence (exp[i]) <= precedence (peek (stack))))
				exp[++k] = pop (stack);
			push (stack, exp[i]);
		}
	}

	while (!is_empty (stack))
		exp[++k] = pop(stack);

	exp[++k] = '\0';
	printf ("%s ", exp);
	printf ("\n");

}

int
main ()
{

	char exp [] = "a+b*(c^d-e)^(f+g*h)-i";
	infix_to_postfix (exp);

	return 0;

}
