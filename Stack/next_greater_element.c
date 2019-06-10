#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_node_t_ {

	int						data;
	struct stack_node_t_	*next;
} stack_node_t;

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

int
is_empty (stack_node_t *root)
{

	return (!root);

}

void
push (stack_node_t **root, int data)
{

	if (*root == NULL) {
	
		*root = create_stack (data);
		return;
	}

	if (!is_empty (*root)) {
	
		stack_node_t *new_node = NULL;

		new_node 		= create_stack (data);
		new_node->next 	= *root;
		*root			= new_node;
	}

}

int
pop (stack_node_t **root)
{

	if (is_empty (*root)) {
	
		return INT_MIN;
	}

	if (!is_empty (*root)) {
	
		stack_node_t *temp 	= NULL;
		int popped			= 0;

		temp	= *root;
		*root	= (*root)->next;
		popped	= temp->data;
		free (temp);

		return popped;
	}

}

void
print_next_greater_element (int arr[], int n)
{

	stack_node_t *stack = NULL;
	stack				= create_stack (arr[0]);

	int i		= 0;
	int element	= 0;
	int next	= 0;

	for (i = 1; i < n; i++) {
	
		next = arr[i];

		if (!is_empty (stack)) {
		
			element = pop (&stack);
			while (element < next) {
			
				printf ("%d	%d\n", element, next);
				if (is_empty (stack)) {
				
					break;
				}
			}
			pop (&stack);
		}

		if (element > next){

			push (&stack, element);
		}

		push (&stack, next);
	}

	while (!is_empty (stack)) {

		element = pop (&stack);
		next	= -1;
		printf ("%d	%d\n", element, next);
	}

}

int
main ()
{

	int arr[]	= {11, 13, 21, 3};
	int	n		= 0;

	n = sizeof (arr)/ sizeof (int);

	print_next_greater_element (arr, n);

	return 0;

}
