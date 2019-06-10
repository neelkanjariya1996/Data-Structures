#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int					key;
	struct list_node_t_ *prev;
	struct list_node_t_ *next;

} list_node_t;

list_node_t*
create_node (int key)
{

	list_node_t *new_node = NULL;

	new_node = malloc (sizeof (list_node_t));

	if (!new_node)
		return NULL;

	new_node->key	= key;
	new_node->prev	= NULL;
	new_node->next	= NULL;

	return new_node;

}

void
push (list_node_t **head, int key)
{

	list_node_t *new_node = NULL;

	new_node = create_node (key);
	
	new_node->next = *head;

	if ((*head) != NULL)
		(*head)->prev = new_node;

	*head = new_node;

}

void
print_list (list_node_t *head)
{

	if (head == NULL)
		return;

	list_node_t *temp = NULL;
	temp = head;
	while (temp) {
	
		printf ("%d ", temp->key);
		temp = temp->next;
	}
	printf ("\n");

}

int
nodes_count (list_node_t *head)
{
	
	list_node_t *temp = NULL;

	if (head == NULL)
		return 0;

	int count = 0;

	temp = head;
	while (temp) {
	
		count++;
		temp = temp->next;
	}

	return count;

}

list_node_t*
dll_to_bst_util (list_node_t **head, int n)
{

	if (n <= 0)
		return NULL;

	list_node_t *left = NULL;

	left = dll_to_bst_util (head, n/2);

	list_node_t *root = NULL;

	root = *head;

	root->prev = left;
	
	*head = (*head)->next;

	root->next = dll_to_bst_util (head, (n - n/2 - 1));

	return root;

}

list_node_t*
dll_to_bst (list_node_t *head)
{

	if (head == NULL)
		return NULL;

	int n = 0;

	n = nodes_count (head);

	return dll_to_bst_util (&head, n);

}

void
preorder (list_node_t *node)
{
	
	if (!node)
		return;

	printf ("%d ", node->key);
	preorder (node->prev);
	preorder (node->next);

}

int
main ()
{

	list_node_t *head = NULL;

	push (&(head), 7);
	push (&(head), 6);
	push (&(head), 5);
	push (&(head), 4);
	push (&(head), 3);
	push (&(head), 2);
	push (&(head), 1);

	printf ("The given Doubly Linked List is: ");
	print_list (head);
	
	list_node_t *root = NULL;
	root = dll_to_bst (head);

	printf ("Preorder Traversal: ");
	preorder (root);
	printf ("\n");

	return 0;

}
