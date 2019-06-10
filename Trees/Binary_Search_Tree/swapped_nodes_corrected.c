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
print_inorder (tree_node_t *node)
{

	if (!node)
		return;

	print_inorder (node->left);
	printf ("%d ", node->key);
	print_inorder (node->right);

}

void
swap (int *a, int *b)
{

	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;

}

void
correct_bst_util (tree_node_t *root,
				  tree_node_t **first,
				  tree_node_t **middle,
				  tree_node_t **last,
				  tree_node_t **prev)
{

	if (root) {
		correct_bst_util (root->left, first, middle, last, prev);

		if (*prev && (root->key) < ((*prev)->key)) {
	
			if (!(*first)) {
		
				*first 	= *prev;
				*middle = root;
			} else {
		
				*last = root;
			}
		}

		*prev = root;

		correct_bst_util (root->right, first, middle, last, prev);

	}

}

void
correct_bst (tree_node_t *root)
{

	tree_node_t *first 	= NULL;
	tree_node_t *middle	= NULL;
	tree_node_t *last	= NULL;
	tree_node_t *prev	= NULL;

	correct_bst_util (root, &first, &middle, &last, &prev);

	if (first && last)
		swap (&(first->key), &(last->key));
	else if (first && middle)
		swap (&(first->key), &(middle->key));
	else
		return;

}

int
main ()
{

	tree_node_t *root = NULL;

	root				= create_node (6);
	root->left			= create_node (10);
	root->right			= create_node (2);
	root->left->left	= create_node (1);
	root->left->right	= create_node (3);
	root->right->right	= create_node (12);
	root->right->left	= create_node (7);

	printf ("Inorder Traversal of incorrect bst: ");
	print_inorder (root);
	printf ("\n");

	correct_bst (root);

	printf ("Inorder Traversal of correct bst: ");
	print_inorder (root);
	printf ("\n");

	return 0;

}
