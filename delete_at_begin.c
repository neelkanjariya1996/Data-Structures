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
list_delete_at_begin (list_node_t **head) {

	list_node_t *temp = NULL;
	
	if (*head == NULL)
		return;

	temp = *head;
	*head = temp->next;
	printf("\nDeleting %d\n", temp->data);
	free(temp);

}

void
print_list(list_node_t *node) {

	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}

}

int
main () {

	list_node_t *head = NULL;

	list_add_at_begin(&(head),4);
	list_add_at_begin(&(head),3);
/*
	list_add_at_begin(&(head),2);
	list_add_at_begin(&(head),1);
	list_add_at_begin(&(head),0);
*/
	printf("The created list is: ");
	print_list(head);
	printf("\n");

	printf("Deleting nodes from beginning: \n");
/*
	printf("Deleting 0: ");
	list_delete_at_begin(&(head));
	print_list(head);
	printf("\n");

	printf("Deleting 1: ");
	list_delete_at_begin(&(head));
	print_list(head);
	printf("\n");

	printf("Deleting 2: ");
	list_delete_at_begin(&(head));
	print_list(head);
	printf("\n");
*/
	printf("List before deleting: ");
	print_list(head);
	list_delete_at_begin(&(head));
	printf("list after deleting from beginning:");
	print_list(head);
	printf("\n");
	
	printf("List before deleting: ");
	print_list(head);
	list_delete_at_begin(&(head));
	printf("list after deleting from beginning:");
	print_list(head);
	printf("\n");
	
	return 0;

}
