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

	tree_node_t *new_node = new (nothrow) tree_node_t;

	if (!new_node) {
		
		cout << "Memory Allocation Failed" << endl;
		return NULL;
	}

	new_node->key 	= key;
	new_node->left	= NULL;
	new_node->right = NULL;

	return new_node;

}

int 
max_width (tree_node_t *root)
{

	if (root == NULL)
		return 0;

	queue <tree_node_t*> q;
	q.push (root);

	int result = 0;
	
	while (!q.empty ()) {
	
		int count 	= 0;
		count		= q.size();

		result = max (count, result);

		while (count--) {
			
			tree_node_t *temp = NULL;

			temp = q.front ();
			q.pop ();

			if (temp->left != NULL)
				q.push (temp->left);
			if (temp->right != NULL)
				q.push (temp->right);
		}

	}

	return result;

}

void
inorder (tree_node_t *node)
{

	if (!node)
		return;

	inorder (node->left);
	cout << node->key << " ";
	inorder (node->right);

}

int
main ()
{

	tree_node_t *root = NULL;

	root						= create_node (1);
	root->left					= create_node (2);
	root->right					= create_node (3);
	root->left->left			= create_node (4);
	root->left->right			= create_node (5);
	root->right->right			= create_node (8);
	root->right->right->left	= create_node (6);
	root->right->right->right	= create_node (7);

	cout << "Inorder Traversal: ";
	inorder (root);
	cout << endl;

	cout << "Maximum Width is: " << max_width (root) << endl;

	return 0;

}
