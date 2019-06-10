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
inorder (tree_node_t *node)
{

	if (!node)
		return;

	inorder (node->left);
	printf ("%d ", node->key);
	inorder (node->right);

}

int
height (tree_node_t *root)
{

	if (root == NULL)
		return 0;

	int lheight = 0;
	int rheight = 0;

	lheight = height (root->left);
	rheight = height (root->right);

	if (lheight >= rheight)
		return (lheight + 1);
	return (rheight + 1);

}

void
print_nodes_at_k (tree_node_t *root, int k)
{

	int h 	= 0;
	h		= height (root);

	if (k > h) {
		printf ("Distance k is greater than height of the binary tree");
		return;
	}

	if (root == NULL)
		return;
	
	if (k == 0) {
		
		printf ("%d ", root->key);
		return;
	} else {
	
		print_nodes_at_k (root->left, (k - 1));
		print_nodes_at_k (root->right, (k - 1));
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
	root->right->left	= create_node (8);

	printf ("Inoder Travelsal: ");
	inorder (root);
	printf ("\n");

	int k = 3;
	printf ("Nodes at distance %d from root: ", k);
	print_nodes_at_k (root, k);
	printf ("\n");

	return 0;

}
