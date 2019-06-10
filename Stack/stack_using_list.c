#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_node_t_ {

	int						data;
	struct stack_node_t_ 	*next; 

} stack_node_t;

stack_node_t*
create_node (int data)
{

	stack_node_t *new_node = NULL;

	new_node = malloc (sizeof (stack_node_t));

	if (!new_node)
		return NULL;

	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

int
is_empty (stack_node_t *root)
{

	return (!root);

}

void
push (stack_node_t **root, int data)
{

	stack_node_t *temp = create_node (data);
	
	temp->next 	= *root;
	*root		= temp;
	printf ("%d pushed to stack\n", data);

}

int
pop (stack_node_t **root)
{

	if (is_empty (*root))
		return INT_MIN;

	stack_node_t *temp = NULL;

	temp	= *root;
	*root	= (*root)->next;
	int popped	= temp->data;
	free (temp);

	return popped;

}

int
peek (stack_node_t *root)
{

	if (is_empty (root))
		return INT_MIN;

	return root->data;

}

int
main ()
{

	stack_node_t *root = NULL;

	push (&root, 10);
	push (&root, 20);
	push (&root, 30);
	push (&root, 40);
	push (&root, 50);

	printf ("%d popped from the stack\n", pop (&root));
	printf ("%d popped from the stack\n", pop (&root));
	printf ("%d popped from the stack\n", pop (&root));
	printf ("%d popped from the stack\n", pop (&root));
	printf ("%d popped from the stack\n", pop (&root));
	printf ("%d popped from the stack\n", pop (&root));

	return 0;

}
