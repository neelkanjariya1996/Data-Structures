#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_t_ {

	int					key;
	struct tree_node_t_ *left;
	struct tree_node_t_ *right;
	int					height;

} tree_node_t;

tree_node_t*
create_node (int key)
{

	tree_node_t *new_node = NULL;

	new_node = malloc (sizeof (tree_node_t));

	if (!new_node)
		return NULL;

	new_node->key		= key;
	new_node->left		= NULL;
	new_node->right		= NULL;
	new_node->height	= 1;

	return new_node;

}

int
height (tree_node_t *node)
{

	if (!node)
		return 0;

	return node->height;

}

int
max (int a, int b)
{
	
	if (a >= b)
		return a;
	return b;

}

int
get_balance (tree_node_t *node)
{

	if (!node)
		return 0;

	return (height (node->left) - height (node->right));

}

tree_node_t*
left_rotate (tree_node_t *x)
{

	tree_node_t *y	= NULL;
	tree_node_t *t2 = NULL;

	y	= x->right;
	t2 	= y->left;

	y->left		= x;
	x->right	= t2;

	x->height = max (height (x->left), height (x->right)) + 1;
	y->height = max (height (y->left), height (y->right)) + 1;

	return y;

}

tree_node_t*
right_rotate (tree_node_t *y)
{

	tree_node_t *x	= NULL;
	tree_node_t *t2	= NULL;

	x	= y->left;
	t2	= x->right;

	y->left		= t2;
	x->right	= y;

	x->height = max (height (x->left), height (x->right)) + 1;
	y->height = max (height (y->left), height (y->right)) + 1;

	return x;

}

tree_node_t*
insert (tree_node_t *node, int key)
{

	if (!node)
		return (create_node (key));

	if (key < node->key)
		node->left = insert (node->left, key);
	else if (key > node->key)
		node->right = insert (node->right, key);
	else
		return node;

	node->height = max (height (node->left), height (node->right)) + 1;

	int balance = 0;

	balance = get_balance (node);

	if (balance > 1 && key < node->left->key)
		return right_rotate (node);

	if (balance < -1 && key > node->right->key)
		return left_rotate (node);

	if (balance > 1 && key > node->left->key) {
	
		node->left = left_rotate (node->left);
		return right_rotate (node);
	}

	if (balance < -1 && key < node->right->key) {
	
		node->right = right_rotate (node->right);
		return left_rotate (node);
	}

	return node;

}

tree_node_t*
min_val_node (tree_node_t *node)
{

	tree_node_t *current = NULL;

	current = node;
	while (current->left != NULL)
		current = current->left;

	return current;

}

tree_node_t*
delete (tree_node_t *root, int key)
{

	if (!root)
		return root;

	if (key < root->key)
		root->left = delete (root->left, key);
	else if (key > root->key)
		root->right = delete (root->right, key);
	else {
		
		if (root->left == NULL || root->right == NULL) {
		
			tree_node_t *temp = NULL;

			temp = root->left ? root->left : root->right;

			if (temp == NULL) {
			
				temp = root;
				root = NULL;
			} else {
			
				*root = *temp;
			}
			
			free (temp);
		} else {
		
			tree_node_t* temp = NULL;

			temp = min_val_node (root->right);

			root->key = temp->key;

			root->right = delete (root->right, temp->key);
		}	
	}

	if (root == NULL)
		return root;

	root->height = 1 + max (height (root->left), height (root->right));

	int balance = 0;

	balance = get_balance (root);

	if (balance > 1 && (get_balance (root->left) >= 0))
		return right_rotate (root);

	if (balance > 1 && get_balance (root->left) < 0) {
	
		root->left = left_rotate (root->left);
		return right_rotate (root);
	}

	if (balance < -1 && get_balance (root->right) <= 0)
		return left_rotate (root);

	if (balance < -1 && get_balance (root->right) > 0) {
	
		root->right = right_rotate (root->right);
		return left_rotate (root);
	}

	return root;
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

int
main ()
{

	tree_node_t *root = NULL;

	root = insert (root, 9);
	root = insert (root, 5);
	root = insert (root, 10);
	root = insert (root, 0);
	root = insert (root, 6);
	root = insert (root, 11);
	root = insert (root, -1);
	root = insert (root, 1);
	root = insert (root, 2);

	printf ("Inorder Traversal before deletion: ");
	print_inorder (root);
	printf ("\n");

	root = delete (root, 10);

	printf ("Inorder Traversal after deletion: ");
	print_inorder (root);
	printf ("\n");

	return 0;

}
