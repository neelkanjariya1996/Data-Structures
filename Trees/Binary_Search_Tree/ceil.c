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
	new_node->left 	= NULL;
	new_node->right	= NULL;

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
CEIL (tree_node_t *root, int input)
{

	if (root == NULL)
		return -1;

	if (root->key == input)
		return root->key;

	if (root->key < input)
		return CEIL (root->right, input);

	if (root->key > input) {
	
		int lCEIL = 0;

		lCEIL = CEIL (root->left, input);
		if (lCEIL >= input)
			return lCEIL;
		else
			return root->key;
	}

}

int
main ()
{

	tree_node_t *root = NULL;

	root				= create_node (8);
	root->left			= create_node (4);
	root->right			= create_node (12);
	root->left->left	= create_node (2);
	root->left->right	= create_node (6);
	root->right->left	= create_node (10);
	root->right->right	= create_node (14);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf ("\n");

	for (int i = 0; i < 16; i++)
		printf ("CEIL (%d)		%d\n", i, CEIL (root, i));

	return 0;

}
