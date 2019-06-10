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

tree_node_t*
lca (tree_node_t *root, int n1, int n2)
{

	if (root == NULL)
		return NULL;

	while (root != NULL) {
	
		if (root->key > n1 && root->key >n2)
			root = root->left;
		else if (root->key < n1 && root->key < n2)
			root = root->right;
		else
			break;

	}

	return root;

}

int
main ()
{

	tree_node_t *root 		= NULL;
	tree_node_t *lca_node 	= NULL;

	root						= create_node (20);
	root->left					= create_node (8);
	root->right					= create_node (22);
	root->left->left			= create_node (4);
	root->left->right			= create_node (12);
	root->left->right->left		= create_node (10);
	root->left->right->right	= create_node (14);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf ("\n");

	int n1 = 0;
	int n2 = 0;

	n1 = 10;
	n2 = 14;
	lca_node = lca (root, n1, n2);
	printf ("LCA of %d and %d is %d\n", n1, n2, lca_node->key);

	n1 = 14;
	n2 = 8;
	lca_node = lca (root, n1, n2);
	printf ("LCA of %d and %d is %d\n", n1, n2, lca_node->key);

	n1 = 10;
	n2 = 22;
	lca_node = lca (root, n1, n2);
	printf ("LCA of %d and %d is %d\n", n1, n2, lca_node->key);

	return 0;

}
