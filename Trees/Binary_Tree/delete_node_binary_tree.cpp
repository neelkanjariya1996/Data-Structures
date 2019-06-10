#include <iostream>
#include <queue>

using namespace std;

typedef struct tree_node_t_ {

	int					key;
	struct tree_node_t_ *left;
	struct tree_node_t_ *right;

} tree_node_t;

tree_node_t*
create_node (int key)
{

	tree_node_t *new_node = new(nothrow) tree_node_t;

	if (!new_node)
		cout << "Memory allocation failed " << endl;

	new_node->key	= key;
	new_node->left	= NULL;
	new_node->right = NULL;

	return new_node;

}

void
inorder (tree_node_t *temp)
{

	if (!temp)
		return;

	inorder (temp->left);
	cout << temp->key << " ";
	inorder (temp->right);

}

void
delete_deepest (tree_node_t *root, tree_node_t *d_node)
{

	queue <tree_node_t*> q;
	q.push (root);

	tree_node_t *temp = NULL;

	while (!q.empty ()) {

		temp = q.front ();
		q.pop ();

		if (temp == d_node) {
	
			temp = NULL;
			delete (d_node);
			return;
		}

		if (temp->right) {
	
			if (temp->right == d_node) {
		
				temp->right = NULL;
				delete (d_node);
				return;
			} else {
		
				q.push (temp->right);
			}

		}

		if (temp->left) {
	
			if (temp->left == d_node) {
		
				temp->left = NULL;
				delete (d_node);
				return;
			} else {
		
				q.push (temp->left);
			}

		}
	
	}

}

void
deletion (tree_node_t *root, int key)
{

	tree_node_t *temp 		= NULL;
	tree_node_t *key_node 	= NULL;

	queue <tree_node_t*> q;
	q.push (root);

	while (!q.empty ()) {
	
		temp = q.front ();
		q.pop ();

		if (temp->key == key)
			key_node = temp;

		if (temp->left)
			q.push (temp->left);

		if (temp->right)
			q.push (temp->right);

	}

	if (temp->key != key) {
	
		cout << "Key not present " << endl;
		return;
	}

	int x = temp->key;
	delete_deepest (root, temp);
	key_node->key = x;

}

int
main ()
{

	tree_node_t *root 	= create_node (10);
	root->left			= create_node (11);
	root->left->left	= create_node (7);
	root->left->right	= create_node (12);
	root->right			= create_node (9);
	root->right->left	= create_node (15);
	root->right->right  = create_node (8);

	cout << "Inorder Traversal before deletion " << endl;
	inorder (root);
	cout << endl;

	int key = 11;
	deletion (root, key);

	cout << "Inorder Traversal after deletion " << endl;
	inorder (root);
	cout << endl;

	return 0;

}
