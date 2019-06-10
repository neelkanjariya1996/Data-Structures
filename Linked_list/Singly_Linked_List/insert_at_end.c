#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t_ {
       int data;
       struct  list_node_t_ *next;
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
list_add_at_end (list_node_t **head, int data) {

	list_node_t *new_node = NULL;
	list_node_t *temp = NULL;

	new_node = create_node(data);

	if(!(*head)) {
		*head = new_node;
		return;
	}

	temp = *head;
	while(temp->next) {
		temp = temp->next;
	}

	temp->next = new_node;
}

void
print_list (list_node_t *node) {

	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}

}
int
main () {

	list_node_t *head = NULL;

	list_add_at_end(&(head), 0);
	print_list(head);
	printf("\n");

	list_add_at_end(&(head), 1);
	print_list(head);
	printf("\n");

	list_add_at_end(&(head), 2);
	print_list(head);
	printf("\n");

	list_add_at_end(&(head), 3);
	print_list(head);
	printf("\n");
	
	list_add_at_end(&(head), 4);
	print_list(head);
	printf("\n");
	
	return 0;

}
