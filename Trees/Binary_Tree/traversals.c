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
print_inorder (tree_node_t *temp)
{

	if (!temp)
		return;

	print_inorder (temp->left);
	printf("%d ", temp->key);
	print_inorder (temp->right);

}

void
print_preoder (tree_node_t *temp)
{

	if (!temp)
		return;

	printf("%d ", temp->key);
	print_preoder (temp->left);
	print_preoder (temp->right);

}

void
print_postorder (tree_node_t *temp)
{
	
	if (!temp)
		return;

	print_postorder (temp->left);
	print_postorder (temp->right);
	printf("%d ", temp->key);

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

	printf("Preoder Traversal: \n");
	print_preoder (root);
	printf("\n");

	printf("Inoder Traversal: \n");
	print_inorder (root);
	printf("\n");

	printf("Postorder Traversal: \n");
	print_postorder (root);
	printf("\n");

	return 0;

}
