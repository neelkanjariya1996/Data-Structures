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

int
height (tree_node_t *tree)
{

	if (tree == NULL)
		return 0;

	int lheight = 0;
	int rheight = 0;

	lheight = height (tree->left);
	rheight = height (tree->right);

	if (lheight >= rheight)
		return (lheight + 1);
	return (rheight + 1);

}

void
inorder (tree_node_t *node)
{

	if (!node)
		return;

	inorder (node->left);
	printf("%d ", node->key);
	inorder (node->right);

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

	printf ("Inoder Travelsal: ");
	inorder (root);
	printf ("\n");

	printf("The height of the tree is: %d\n", height (root));

	return 0;

}
