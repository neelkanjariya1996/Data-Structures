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
print_inorder (tree_node_t *node)
{

	if (!node)
		return;

	print_inorder (node->left);
	printf ("%d ", node->key);
	print_inorder (node->right);

}

void
store_inorder (tree_node_t *node, int inorder[], int *ptr_index)
{

	if (node == NULL)
		return;

	store_inorder (node->left, inorder, ptr_index);
	inorder [*ptr_index] = node->key;
	(*ptr_index)++;
	store_inorder (node->right, inorder, ptr_index);

}

int*
merge (int arr1[], int arr2[], int m, int n)
{

	int *merge_arr[(m + n)];
	int i = 0;
	int j = 0;
	int k = 0;

	while ((i < m) && (j < n)) {
	
		if (arr1[i] < arr2[j]) {
		
			merge_arr[k] = arr1[i];
			i++;
		} else if (arr1[i] >= arr2[j]) {
		
			merge_arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < m) {
	
		merge_arr[k] = arr1[i];
		i++;
		k++;
	}

	while (j < n) {
	
		merge_arr[k] = arr2[j];
		j++;
		k++;
	}
	
	return merge_arr;

}

tree_node_t*
sorted_arr_to_bst (int arr[], int start, int end)
{
		tree_node_t *root = NULL;

		if (start > end)
			return NULL;

		int mid = 0;
		mid 	= (start + end)/2;

		printf ("%d \n", arr[mid]);

		root = create_node (arr[mid]);

		root->left 	= sorted_arr_to_bst (arr, start, (mid -1));
		root->right	= sorted_arr_to_bst (arr, (mid + 1), end);

		return root;

}

tree_node_t*
merge_trees (tree_node_t *root1,
			 tree_node_t *root2,
			 int m, int n)
{

		int i = 0;
		int *arr1[m];
		store_inorder (root1, arr1, &i);

		int j = 0;
		int *arr2[n];
		store_inorder (root2, arr2, &j);
	
		int *merge_arr;
		merge_arr = merge (arr1, arr2, m, n);

		sorted_arr_to_bst (merge_arr, 0, (m + n - 1));

}

int
main ()
{

	tree_node_t *root1 		= NULL;
	tree_node_t *root2 		= NULL;
	tree_node_t *merged_tree = NULL;

	root1				= create_node (100);
	root1->left			= create_node (50);
	root1->right		= create_node (300);
	root1->left->left	= create_node (20);
	root1->left->right	= create_node (70);

	printf ("Inorder Traversal for Tree 1: ");
	print_inorder (root1);
	printf ("\n");

	root2			= create_node (80);
	root2->left		= create_node (40);
	root2->right	= create_node (120);

	printf ("Inorder Traversal for Tree 2: ");
	print_inorder (root2);
	printf ("\n");

	merged_tree = merge_trees (root1, root2, 5, 3);

	printf ("Inorder Traversal for Merged Tree: ");
	print_inorder (merged_tree);
	printf ("\n");

	return 0;

}
