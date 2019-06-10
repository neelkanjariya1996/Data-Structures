#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t_ {

	int					data;
	struct tree_node_t_ *left;
	struct tree_node_t_ *right;

} tree_node_t;

tree_node_t*
create_node (int data) 
{

	tree_node_t *new_node = NULL;

	new_node = malloc (sizeof (tree_node_t));

	if (!new_node)
		return NULL;

	new_node->data	= data;
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
	printf ("%d ", node->data);
	inorder (node->right);

}

tree_node_t*
insert (tree_node_t *root, int data)
{

	if (root == NULL) 
		return create_node (data);

	if (data < root->data)
		root->left = insert (root->left, data);
	else if (data > root->data)
		root->right = insert (root->right, data);

	return root;

}

tree_node_t*
search (tree_node_t *root, int data)
{

		if (root == NULL ||
			root->data == data)
			return root;

		if (data < root->data)
			return search (root->left, data);
		return search (root->right, data);

}

int
main ()
{

	tree_node_t *root 	= NULL;
	root				= insert (root, 50);

	insert (root, 30);
	insert (root, 20);
	insert (root, 40);
	insert (root, 70);
	insert (root, 60);
	insert (root, 80);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf ("\n");

	tree_node_t *s = NULL;

	s = search (root, 30);
	printf ("Search: %d\n", s->data);
	
	return 0;

}
