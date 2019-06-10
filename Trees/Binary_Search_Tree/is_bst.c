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
insert (tree_node_t *node, int key)
{

	if (node == NULL)
		return create_node (key);

	if (key < node->key)
		node->left = insert (node->left, key);
	else if (key > node->key)
		node->right = insert (node->right, key);

}

int
is_bst (tree_node_t *root, 
		tree_node_t *l,
		tree_node_t *r)
{

	if (root == NULL)
		return 1;

	if (l != NULL && root->key < l->key)
		return 0;

	if (r != NULL && root->key > r->key)
		return 0;

	return (is_bst (root->left, l, root) &&
			is_bst (root->right, root, r));

}

int
main ()
{

	tree_node_t *root = NULL;

	/*
	root = insert (root, 5);
	insert (root, 2);
	insert (root, 5);
	insert (root, 1);
	insert (root, 4);
	*/

	root 				= create_node (3);
	root->left			= create_node (2);
	root->right			= create_node (5);
	root->left->left	= create_node (1);
	root->left->right	= create_node (4);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf ("\n");

	if (is_bst (root, NULL, NULL))
		printf ("The given binary tree is a binary search tree\n");
	else
		printf ("The given binary tree is not a binary search tree\n");

	return 0;	

}
