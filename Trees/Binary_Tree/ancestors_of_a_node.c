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

	new_node->key 	= key;
	new_node->left	= NULL;
	new_node->right = NULL;

	return new_node;

}

void
inorder (tree_node_t *node)
{

	if (!node)
		return;

	inorder (node->left);
	printf ("%d ", node->key);
	inorder (node->right);

}

int
print_ancestors (tree_node_t *root, int target)
{

	if (root == NULL)
		return 0;

	if (root->key == target)
		return 1;

	if (print_ancestors (root->left, target) ||
		print_ancestors (root->right, target)) {
		
		printf ("%d ", root->key);
		return 1;
	}

	return 0;

}

int
main ()
{

	tree_node_t *root = NULL;

	root					= create_node (1);
	root->left				= create_node (2);
	root->right				= create_node (3);
	root->left->left		= create_node (4);
	root->left->right		= create_node (5);
	root->left->left->left	= create_node (7);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf("\n");

	int target = 0;

	target = 7;
	printf ("The ancestors of the node %d are: ", target);
	print_ancestors (root, target);
	printf ("\n");

	return 0;

}
