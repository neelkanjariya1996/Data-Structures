#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_node_t_ {

	int						data;
	struct stack_node_t_	*next;
} stack_node_t;

typedef struct special_stack_t_ {

	stack_node_t *special_stack;
	stack_node_t *auxilary_stack;
}special_stack_t;

stack_node_t*
create_stack (int data) 
{

	stack_node_t *new_stack = NULL;

	new_stack = malloc (sizeof (stack_node_t));

	if (!new_stack) {

		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	new_stack->data	= data;
	new_stack->next	= NULL;

	return new_stack;

}

special_stack_t*
create_special_stack (int data)
{

	special_stack_t *stack = NULL;

	stack = malloc (sizeof (special_stack_t));

	if (!stack) {
	
		printf ("Memory Allocation Failed!\n");
		return NULL;
	}

	stack->special_stack 	= create_stack (data);
	if (!stack->special_stack) {
	
		return NULL;
	}

	stack->auxilary_stack	= create_stack (data);
	if (!stack->auxilary_stack) {
	
		return NULL;
	}

	return stack;

}

int
is_empty (stack_node_t *stack) 
{

	return (!stack);

}

void
push (stack_node_t **root, int data)
{

	if (is_empty (*root)) {
	
		*root = create_stack (data);
		return;
	}

	if (!is_empty (*root)) {
	
		stack_node_t *temp = NULL;

		temp		= create_stack (data);
		temp->next	= *root;
		*root		= temp;
		printf ("%d pushed to stack\n", data);
		return;
	}

}

int
pop (stack_node_t **root)
{

	if (is_empty (*root)) {
	
		printf ("Stack Empty\n");
		return INT_MIN;
	}

	if (!is_empty (*root)) {
	
		int popped 			= 0;
		stack_node_t *temp 	= NULL;

		temp 	= *root;
		*root 	= (*root)->next;
		popped 	= temp->data;
		free (temp);
		printf ("%d popped from the stack\n", popped);
		return popped;
	}

}

int
peek (stack_node_t *root)
{
	
	if (is_empty (root)) {
	
		printf ("Stack Empty!\n");
		return INT_MIN;
	}

	return root->data;

}

void
special_stack_push (special_stack_t *stack, int data) 
{

	if ((is_empty (stack->special_stack)) &&
		(is_empty (stack->auxilary_stack))) {

		stack = create_special_stack (data);
		return;
	}

	if ((!is_empty (stack->special_stack)) &&
		(!is_empty (stack->auxilary_stack))) {
	
		if (data < peek (stack->auxilary_stack)) {
		
			push (&(stack->special_stack), data);
			push (&(stack->auxilary_stack), data);
		} else {
		
			push (&(stack->special_stack), data);
		}
	}

}

int
special_stack_pop (special_stack_t *stack)
{

	if ((is_empty (stack->special_stack)) &&
		(is_empty (stack->auxilary_stack))) {

		return INT_MIN;
	}

	if ((!is_empty (stack->special_stack)) &&
		(!is_empty (stack->auxilary_stack))) {
	
		if (peek (stack->special_stack) == peek (stack->auxilary_stack)) {

			pop (&(stack->special_stack));
			return pop (&(stack->auxilary_stack));	
		} else {
		
			return pop (&(stack->special_stack));
		}	
	}

}

int
get_min (special_stack_t *stack)
{
	
	if (!stack)
		return INT_MIN;

	return (peek (stack->auxilary_stack));

}

int
main ()
{

	special_stack_t *stack = NULL;

	special_stack_push (stack, 5);
	special_stack_push (stack, 1);
	special_stack_push (stack, 6);
	special_stack_push (stack, 7);
	special_stack_push (stack, 8);
	printf ("The min element in the stack is %d\n", get_min (stack));
	special_stack_push (stack, 0);
	printf ("The min element in the stack is %d\n", get_min (stack));
	special_stack_pop (stack);
	printf ("The min element in the stack is %d\n", get_min (stack));
	special_stack_pop (stack);
	printf ("The min element in the stack is %d\n", get_min (stack));
	special_stack_pop (stack);
	printf ("The min element in the stack is %d\n", get_min (stack));
	special_stack_pop (stack);
	printf ("The min element in the stack is %d\n", get_min (stack));
	special_stack_pop (stack);
	printf ("The min element in the stack is %d\n", get_min (stack));

	return 0;

}
