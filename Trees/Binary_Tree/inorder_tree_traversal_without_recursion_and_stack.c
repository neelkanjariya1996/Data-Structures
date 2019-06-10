#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t_ {

	int					key;
	struct tree_node_t_ *left;
	struct tree_node_t_ *right;

} tree_node_t;

tree_node_t*
create_node (int key)
{

	tree_node_t *new_node = NULL;

	new_node = malloc (sizeof (tree_node_t));

	if (!new_node)
		return NULL;

	new_node->key	= key;
	new_node->left	= NULL;
	new_node->right = NULL;

	return new_node;

}

void
inorder_traversal (tree_node_t *root)
{

	tree_node_t *current 	= NULL;
	tree_node_t *previous 	= NULL;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {
	
		if (current->left == NULL) {
			
			printf ("%d ", current->key);
			current = current->right;
		} else {
		
			previous = current->left;
			while (previous->right != NULL && previous->right != current)
				previous = previous->right;

			if (previous->right == NULL) {
			
				previous->right = current;
				current			= current->left;
			} else {
			
				previous->right = NULL;
				printf ("%d ", current->key);
				current = current->right;
			}
		}
	}
}

int
main ()
{

	tree_node_t *root = NULL;

	root				= create_node (1);
	root->left			= create_node (2);
	root->right			= create_node (3);
	root->left->left	= create_node (4);
	root->left->right	= create_node (5);

	printf ("Inorder Traversal without using Recursion and Stack is: ");
	inorder_traversal (root);
	printf ("\n");

	return 0;

}
