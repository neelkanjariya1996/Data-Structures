#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {

	int 			data;
	struct list_node_t_	*prev;
	struct list_node_t_	*next;
} list_node_t;

list_node_t*
create_node (int data) {

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if (!new_node) {
		return NULL;
	}

	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	
	return new_node;

}

void
sorted_insert (list_node_t **head, int data) {

	list_node_t *new_node 	= NULL;
	list_node_t *temp	= NULL;
	list_node_t *temp1	= NULL;

	new_node = create_node (data);

	if ((*head) == NULL) {
		*head = new_node;
		return;
	}

	if ((*head) != NULL && (*head)->next == NULL) {
		if ((*head)->data <= new_node->data) {
			(*head)->next 	= new_node;
			new_node->prev 	= *head;
			new_node->next 	= NULL;
			return;
		} else {
			new_node->next 	= *head;
			(*head)->prev 	= new_node;
			*head 		= new_node;
			return;
		}
	}

	if ((*head) != NULL && (*head)->next != NULL) {
		temp = *head;
		while (temp != NULL && temp->next != NULL) {
			if (temp->data <= new_node->data && 
			   temp->next->data > new_node->data &&
			   temp->next != NULL) {
				temp1 		= temp->next;
				temp->next 	= new_node;
				new_node->prev 	= temp;
				new_node->next 	= temp1;
				temp1->prev 	= new_node;
				return;
			}
			if (temp->data > new_node->data) {
				new_node->next 	= temp;
				temp->prev 	= new_node;
				*head 		= new_node;
				return;
			}
			temp = temp->next;
		}
	}

	temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	if (temp->data <= new_node->data &&
	   temp->next == NULL) {
		temp->next 	= new_node;
		new_node->prev 	= temp;
		new_node->next 	= NULL;
		return;
	}

}

void
print_list (list_node_t *node) {

	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");

}

int
main () {

	list_node_t *head = NULL;

	sorted_insert (&(head), 0);
	print_list (head);
	sorted_insert (&(head), 0);
	print_list (head);
	sorted_insert (&(head), -1);
	print_list (head);
	sorted_insert (&(head), 5);
	print_list (head);
	sorted_insert (&(head), 3);
	print_list (head);
	sorted_insert (&(head), 1);
	print_list (head);
	sorted_insert (&(head), 7);
	print_list (head);
	sorted_insert (&(head), 8);
	print_list (head);
	sorted_insert (&(head), 6);
	print_list (head);
	sorted_insert (&(head), 0);
	print_list (head);
	sorted_insert (&(head), 2);
	print_list (head);
	sorted_insert (&(head), 4);
	print_list (head);
	sorted_insert (&(head), -4);
	print_list (head);

	return 0;

}
