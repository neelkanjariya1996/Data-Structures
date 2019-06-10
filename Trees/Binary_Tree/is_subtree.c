#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t_ {

	int 				key;
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
are_identical (tree_node_t *root1,
			   tree_node_t *root2)
{

	if (root1 == NULL && root2 == NULL)
		return 1;

	if (root1 == NULL || root2 == NULL)
		return 0;

	return ((root1->key == root2->key) &&
			are_identical (root1->left, root2->left) &&
			are_identical (root1->right, root2->right));

}

int
is_subtree (tree_node_t *T,
			tree_node_t *S)
{

	if (S == NULL)
		return 1;

	if (T == NULL)
		return 0;

	if (are_identical (T, S))
		return 1;

	return (is_subtree (T->left, S) || is_subtree (T->right, S));

}

int
main ()
{

	tree_node_t *T = NULL;
	tree_node_t *S = NULL;

	T						= create_node (26);
	T->left					= create_node (10);
	T->right				= create_node (3);
	T->left->left			= create_node (4);
	T->left->right			= create_node (6);
	T->left->left->right	= create_node (30);
	T->right->right			= create_node (3);

	printf ("The Inorder Traversal of Tree T is: ");
	inorder (T);
	printf ("\n");

	S				= create_node (10);
	S->left			= create_node (4);
	S->right		= create_node (6);
	S->left->right	= create_node (30);

	printf ("The Inorder Traversal of Tree S is: ");
	inorder (S);
	printf ("\n");

	if (is_subtree (T, S))
		printf ("S is a subtree of the binary tree T\n");
	else
		printf ("S is not a subtree of the binary tree T\n");

	return 0;

}
