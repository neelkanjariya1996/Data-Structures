#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct tree_node_t_ {

	int					key;
	struct tree_node_t_ *left;
	struct tree_node_t_ *right;

} tree_node_t;

tree_node_t*
create_node (int key)
{

	tree_node_t *new_node = NULL;

	new_node = new (nothrow) tree_node_t;

	if (!new_node) {

		cout << "Memory allocation failed! " << endl;
		return NULL;
	}

	new_node->key	= key;
	new_node->left	= NULL;
	new_node->right	= NULL;

	return new_node;

}

void
get_vertical_order (tree_node_t *root, int hd, map <int, vector <int>> &m)
{

	if (root == NULL)
		return;

	m[hd].push_back (root->key);
	get_vertical_order (root->left, (hd - 1), m);
	get_vertical_order (root->right, (hd + 1), m);

}

void
print_vertical_order (tree_node_t *root)
{

	map <int, vector <int>> m;
	int hd = 0;
	get_vertical_order (root, hd, m);

	map <int, vector <int>> :: iterator it;
	for (it = m.begin (); it != m.end(); it++) {
	
		for (int i = 0; i < it->second.size(); i++) {
		
			cout << it->second[i] << " ";
		}
		cout << endl;
	}

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
	root->right->left			= create_node (6);
	root->right->right			= create_node (7);
	root->right->left->right 	= create_node (8);
	root->right->right->right 	= create_node (9);

	cout << "Vertical order Traversal: " << endl;
	print_vertical_order (root);

	return 0;

}
