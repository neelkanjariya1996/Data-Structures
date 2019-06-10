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

void
pre_succ (tree_node_t *root,
		  tree_node_t **pre,
		  tree_node_t **succ,
		  int key)
{

	if (root == NULL)
		return;

	if (root->key == key) {
	
		if (root->left != NULL) {
		
			tree_node_t *curr 	= NULL;
			curr 				= root->left;
			while (curr->right)
				curr = curr->right;
			*pre = curr;
		}

		if (root->right != NULL) {
		
			tree_node_t *curr 	= NULL;
			curr				= root->right;
			while (curr->left)
				curr = curr->left;
			*succ = curr;
		}

		return;

	}
	
	if (key < root->key) {
	
		*succ = root;
		pre_succ (root->left, pre, succ, key);
	} else if (key > root->key) {
	
		*pre = root;
		pre_succ (root->right, pre, succ, key);
	}

}

int
main ()
{

	tree_node_t *root 	= NULL;
	tree_node_t *pre	= NULL;
	tree_node_t *succ	= NULL;
	int key				= 0;

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

	key = 65;
	pre_succ (root, &pre, &succ, key);
	if (pre != NULL)
		printf ("The predecessor of the key %d is %d\n", key, pre->key);
	else
		printf ("No predecessor\n");

	if (succ != NULL)
		printf ("The successor of the key %d is %d\n", key, succ->key);
	else
		printf ("No successor\n");

	return 0;

}
