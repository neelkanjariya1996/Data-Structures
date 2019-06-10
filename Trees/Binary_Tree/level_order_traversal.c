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

	new_node = malloc (sizeof(tree_node_t));

	if (!new_node)
		return NULL;

	new_node->key	= key;
	new_node->left	= NULL;
	new_node->right = NULL;

	return new_node;

}

void
print_level_order (tree_node_t *root)
{

	int h = 0;
	int i = 0;

	h = height (root);
	for (i = 1; i <= h; i++)
		print_given_level (root, i);

}

int
height (tree_node_t *node)
{

	if (node == NULL) {
		
		return 0;
	} else {
	
		int lheight = 0;
		int rheight = 0;

		lheight = height (node->left);
		rheight = height (node->right);

		if (lheight > rheight) {
			
			return (lheight + 1);
		} else {
		
			return (rheight + 1);
		}
	}

}

void
print_given_level (tree_node_t *root, int level) 
{

	if (root == NULL)
		return;

	if (level == 1)
		printf ("%d ", root->key);

	if (level > 1) {
	
		print_given_level (root->left, (level - 1));
		print_given_level (root->right, (level - 1));
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

	printf("Level order traversal of the binary tree is: ");
	print_level_order (root);
	printf("\n");

	return 0;

}
