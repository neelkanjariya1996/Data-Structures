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

tree_node_t*
insert (tree_node_t *node, int key)
{

	if (node == NULL)
		return create_node (key);

	if (key < node->key)
		node->left = insert (node->left, key);
	else if (key > node->key)
		node->right = insert (node->right, key);
	
	return node;

}

int
min_val_node (tree_node_t *node) 
{

	tree_node_t *curr = NULL;

	curr = node;
	while (curr && curr->left != NULL)
		curr = curr->left;

	return curr->key;

}

int
main ()
{

		tree_node_t *root = NULL;

		root = insert (root, 4);
		insert (root, 2);
		insert (root, 1);
		insert (root, 3);
		insert (root, 6);
		insert (root, 5);

		printf ("Inorder Traversal: ");
		inorder (root);
		printf ("\n");

		printf ("Minimum value node in the given binary search tree is: %d\n", min_val_node (root));

		return 0;

}
