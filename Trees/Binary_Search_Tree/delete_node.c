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

tree_node_t*
min_value_node (tree_node_t *node)
{
	
	tree_node_t *curr = NULL;

	curr = node;
	while (curr && curr->left != NULL)
		curr = curr->left;

	return curr;

}

tree_node_t*
delete (tree_node_t *root, int key)
{
	
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = delete (root->left, key);
	else if (key > root->key)
		root->right = delete (root->right, key);
	else {
	
		if (root->left == NULL) {
		
			tree_node_t *temp = NULL;
			temp = root->right;
			free (root);
			return temp;
		} else if (root->right == NULL) {
		
			tree_node_t *temp = NULL;
			temp = root->left;
			free (root);
			return temp;
		} 

		tree_node_t *temp = NULL;
		
		temp = min_value_node (root->right);
		
		root->key = temp->key;

		root->right = delete (root->right, temp->key);

	}

	return root;

}

int
main ()
{

	tree_node_t *root = NULL;

	root = insert (root, 50);
	insert (root, 30);
	insert (root, 20);
	insert (root, 40);
	insert (root, 70);
	insert (root, 60);
	insert (root, 80);

	printf ("Inorder Traversal: ");
	inorder (root);
	printf ("\n");

	printf ("Delete 40\n");
	delete (root, 40);
	printf ("Inorder Traversal after deleting 40: ");
	inorder (root);
	printf ("\n");

	printf ("Delete 30\n");
	delete (root, 30);
	printf ("Inorder Traversal after deleting 30: ");
	inorder (root);
	printf ("\n");

	printf ("Delete 50\n");
	delete (root, 50);
	printf ("Inorder Traversal after deleting 50: ");
	inorder (root);
	printf ("\n");

	return 0;

}
