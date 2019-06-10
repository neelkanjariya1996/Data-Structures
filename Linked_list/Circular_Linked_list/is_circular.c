#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int	            data;
	struct list_node_t_ *next;
} list_node_t;

list_node_t*
create_node (int data)
{
	
	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if (!new_node)
		return NULL;

	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

void
non_circular_push (list_node_t **head, int data)
{

	list_node_t *new_node = NULL;
	list_node_t *temp	  = NULL;

	new_node = create_node (data);

	if ((*head) == NULL) {
		*head = new_node;
		return;
	}
	
	temp = *head;
	
	while (temp->next != NULL) { 
		temp = temp->next;
	} 

	temp->next = new_node;

}

void
circular_push (list_node_t **head, int data)
{

	list_node_t *new_node = NULL;

	new_node = create_node (data);

	new_node->next = *head;

	list_node_t *temp = NULL;

	temp =*head;

	if (*head != NULL) {

		while (temp->next != *head)
			temp = temp->next;

		temp->next = new_node;
	} else {

		new_node->next = new_node;
	}

	*head = new_node;

}

void
is_circular (list_node_t *head) 
{
	list_node_t *temp = NULL;

	temp = head;
	if (temp == NULL) {
		printf("List is circular \n");
		return;
	}

	temp = head->next;
	while (temp != NULL && temp != head)
		temp = temp->next;

	if (temp == head) {

		printf("list is circular \n");
		return;
	} else {

		printf("list is not circular \n");
		return;
	}
	
}

void
print_list (list_node_t *head) 
{

	list_node_t *temp = NULL;
/*
	temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	return;
*/
	if (head != NULL) {
		
		temp = head;
		do {

			printf ("%d ", temp->data);
			temp = temp->next;

		} while (temp != head);

	}
}

int
main ()
{

	list_node_t *head 	= NULL;
	list_node_t *head1 	= NULL;

	non_circular_push (&(head), 4);
	non_circular_push (&(head), 3);
	non_circular_push (&(head), 2);
	non_circular_push (&(head), 1);
	non_circular_push (&(head), 0);
	non_circular_push (&(head), 5);

//	print_list (head);

	//is_circular (head);

	circular_push (&(head1), 0);
	circular_push (&(head1), 1);
	circular_push (&(head1), 2);
	circular_push (&(head1), 3);
	circular_push (&(head1), 4);
	circular_push (&(head1), 5);

	print_list (head1);
	is_circular (head1);

	return 0;

}
