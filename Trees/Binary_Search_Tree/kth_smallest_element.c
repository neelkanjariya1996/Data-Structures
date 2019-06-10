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

int
node_count (tree_node_t *root)
{

	if (root == NULL)
		return 0;

	return (node_count (root->left) +
			node_count (root->right) + 
			1);

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
kth_smallest_element_util (tree_node_t *root, int arr[], int *i)
{

	if (root == NULL)
		return;

	kth_smallest_element_util (root->left, arr, i);
	arr[*i] = root->key;
	(*i)++;
	kth_smallest_element_util (root->right, arr, i);

}

int
kth_smallest_element (tree_node_t *root, int k, int n)
{

	int arr[n];

	int i = 0;

	kth_smallest_element_util (root, arr, &i);

	return arr[(k - 1)];

}

int
main ()
{

	tree_node_t *root = NULL;

	root						= create_node (20);
	root->left					= create_node (8);
	root->right					= create_node (22);
	root->left->left			= create_node (4);
	root->left->right			= create_node (12);
	root->left->right->left		= create_node (10);
	root->left->right->right	= create_node (14);

	printf ("Inorder Traversal: ");
	print_inorder (root);
	printf ("\n");

	int n 	= 0;
	n		= node_count (root);

	int k 			= 0;
	int kth_small	= 0;

	k = 10;

	if (k < n) {
		
		kth_small = kth_smallest_element (root, k, n);
		printf ("The %d smallest node in the tree is %d\n", k, kth_small);
	} else
		printf ("There is no such element\n");

	return 0;

}
