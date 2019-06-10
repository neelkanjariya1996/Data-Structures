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

int
list_length (list_node_t *node) {

	int len = 0;
	while(node != NULL) {
		len++;
		node = node->next;
	}

	return len;

}

void
print_list(list_node_t *node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}

}

int
main () {

	list_node_t *head = NULL;

	list_add_at_end(&(head), 0);
	list_add_at_end(&(head), 1);
	list_add_at_end(&(head), 2);
	list_add_at_end(&(head), 3);
	list_add_at_end(&(head), 4);
	list_add_at_end(&(head), 0);
	list_add_at_end(&(head), 1);
	list_add_at_end(&(head), 2);
	list_add_at_end(&(head), 3);
	list_add_at_end(&(head), 4);
	list_add_at_end(&(head), 0);
	list_add_at_end(&(head), 1);
	list_add_at_end(&(head), 2);
	list_add_at_end(&(head), 3);
	list_add_at_end(&(head), 4);
	list_add_at_end(&(head), 0);
	list_add_at_end(&(head), 1);
	list_add_at_end(&(head), 2);
	list_add_at_end(&(head), 3);
	list_add_at_end(&(head), 4);
	printf("The created list is: ");
	print_list(head);
	printf("\n");
	
	printf("The length is: %d\n", list_length(head));

	return 0;

}
