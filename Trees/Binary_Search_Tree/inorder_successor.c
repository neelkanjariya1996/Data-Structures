#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t_ {

	int					key;
	struct tree_node_t_ *left;
	struct tree_node_t_ *right;

} tree_node_t;

tree_node_t*
create_node  (int key)
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
	
	return node;
	
}

tree_node_t*
min_value_node (tree_node_t *node)
{

	tree_node_t *curr = NULL;

	curr = node;
	while (curr->left != NULL)
		curr = curr->left;

	return curr;

}

tree_node_t*
inorder_successor (tree_node_t *root,
				   tree_node_t *node)
{
	
	if (node->right != NULL)
		return min_value_node (node->right);

	tree_node_t *succ = NULL;

	while (root != NULL) {
	
		if (node->key < root->key) {
		
			succ = root;
			root = root->left;
		} else if (node->key > root->key)
			root = root->right;
		 else 
			break;
	}

	return succ;

}

int
main ()
{

	tree_node_t *root = NULL;
	tree_node_t *node = NULL;
	tree_node_t *succ = NULL;

	root = insert (root, 20);
	insert (root, 8);
	insert (root, 22);
	insert (root, 4);
	insert (root, 12);
	insert (root, 10);
	insert (root, 14);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf ("\n");

	node = root->left->right->right;

	succ = inorder_successor (root, node);
	if (succ != NULL)
		printf ("The inorder successor of the node %d is %d\n", node->key, succ->key);
	else
		printf ("The inorder successor of the node %d does not exists\n", node->key);

	return 0;

}
