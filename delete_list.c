#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {
	int data;
	struct list_node_t_ *next;
} list_node_t;

list_node_t*
create_node (int data) {

	list_node_t *new_node = NULL;

	new_node = malloc(sizeof(list_node_t));

	if(!new_node) 
		return NULL;

	new_node->data = data;
	new_node->next = NULL;

	return new_node;

}

void
list_add_at_begin (list_node_t **head, int data) {

	list_node_t *new_node = NULL;
	list_node_t *temp = NULL;

	new_node = create_node(data);

	if(!(*head)) {
		*head = new_node;
		return;
	}

	temp = *head;
	*head = new_node;
	new_node->next = temp;

}

void
list_delete (list_node_t **head) {
	
	list_node_t *temp = NULL;
	list_node_t *temp1 = NULL;

	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}

	temp = *head;
	while (temp != NULL) {
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}

	*head = NULL;

}

void
print_list (list_node_t *node) {
	
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}

}

int
main () {
	
	list_node_t *head = NULL;

	list_add_at_begin (&(head), 0);
	list_add_at_begin (&(head), 1);
/*
	list_add_at_begin (&(head), 2);
	list_add_at_begin (&(head), 3);
	list_add_at_begin (&(head), 4);
*/
	printf("The created list is: ");
	print_list(head);
	printf("\n");

	printf("Deleting the list\n");
	list_delete(&head);
	print_list(head);
	printf("List has been deleted\n");

	return 0;

}
