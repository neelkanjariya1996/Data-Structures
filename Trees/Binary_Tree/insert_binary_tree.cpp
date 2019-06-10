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

	tree_node_t *temp = new(nothrow) tree_node_t;

	if (!temp)
		cout << "Memory allocation failed \n" << endl;

	temp->key	= key;
	temp->left	= NULL;
	temp->right	= NULL;

	return temp;

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
insert (tree_node_t *temp, int key)
{

	queue <tree_node_t*> q;
	q.push (temp);

	while (!q.empty()) {
	
		tree_node_t *temp1 = q.front();
		q.pop ();

		if (!temp1->left) {
			temp1->left = create_node (key);
			break;

		} else {
			q.push (temp1->left);

		}

		if (!temp1->right) {
			temp1->right = create_node (key);
			break;

		} else {
			q.push (temp1->right);

		}

	}

}

int
main ()
{

	tree_node_t *root 	= create_node (10);
	root->left 			= create_node (11);
	root->left->left	= create_node (7);
	root->right			= create_node (9);
	root->right->left	= create_node (15);
	root->right->right  = create_node (8);

	cout << "Inorder Traversal before insertion " << endl;
	inorder (root);
	cout << endl;

	int key = 12;
	insert (root, key);

	cout << "Inoder Traversal after insertion " << endl;
	inorder (root);
	cout << endl;

	return 0;

}
