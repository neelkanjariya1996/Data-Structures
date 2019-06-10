#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int					data;
	struct list_node_t_ *next;
} list_node_t;

list_node_t*
create_node (int data)
{

	list_node_t *new_node = NULL;

	new_node = malloc (sizeof (list_node_t));

	if (!new_node)
		return NULL;

	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

void
push (list_node_t **head, int data)
{

	list_node_t *new_node = NULL;

	new_node = create_node (data);

	new_node->next = *head;

	*head = new_node;

}

int
is_present (list_node_t *head, int data)
{

	list_node_t *temp = NULL;

	temp = head;

	while (temp != NULL) {
	
		if (temp->data == data)
			return 1;
		temp = temp->next;
	}

	return 0;

}

void
print_list (list_node_t *node)
{

	while (node != NULL) {
	
		printf ("%d ", node->data);
		node = node->next;
	}
	printf ("\n");

}

list_node_t*
get_union (list_node_t *head1,
		   list_node_t *head2) 
{

	list_node_t *result	= NULL;
	list_node_t *temp1	= NULL;
	list_node_t *temp2	= NULL;

	temp1 = head1;
	temp2 = head2;

	while (temp1 != NULL) {
	
		push (&result, temp1->data);
		temp1 = temp1->next;
	}

	while (temp2 != NULL) {
	
		if (!is_present (result, temp2->data))
			push (&result, temp2->data);
		temp2 = temp2->next;
	}

	return result;

}

list_node_t*
get_intersection (list_node_t *head1,
				  list_node_t *head2)
{

	list_node_t *result = NULL;
	list_node_t *temp1	= NULL;

	temp1 = head1;

	while (temp1 != NULL) {
	
		if (is_present (head2, temp1->data))
			push (&result, temp1->data);
		temp1 = temp1->next;
	}

	return result;

}

int
main ()
{

	list_node_t *head1 	= NULL;
	list_node_t *head2 	= NULL;
	list_node_t *inst  	= NULL;
	list_node_t *unin	= NULL;

	push (&head1, 20);
	push (&head1, 4);
	push (&head1, 15);
	push (&head1, 10);

	printf ("List1: ");
	print_list (head1);

	push (&head2, 10);
	push (&head2, 2);
	push (&head2, 4);
	push (&head2, 8);
	
	printf ("List2: ");
	print_list (head2);

	unin = get_union (head1, head2);

	printf ("Union: ");
	print_list (unin);

	inst = get_intersection (head1, head2);
	
	printf ("Intersection: ");
	print_list (inst);

	return 0;

}
